#include "at24c02.h"
#include <string.h>

static I2C_HandleTypeDef *eeprom_hi2c;
static GPIO_TypeDef *eeprom_wp_port;
static uint16_t eeprom_wp_pin;
static uint8_t busy_flag = 0;

void EEPROM_Init(I2C_HandleTypeDef *hi2c, GPIO_TypeDef *wp_port, uint16_t wp_pin)
{
    eeprom_hi2c = hi2c;
    eeprom_wp_port = wp_port;
    eeprom_wp_pin = wp_pin;
    EEPROM_WriteProtect(0);
}

void EEPROM_WriteProtect(const uint8_t enable)
{
    if (enable)
        HAL_GPIO_WritePin(eeprom_wp_port, eeprom_wp_pin, GPIO_PIN_SET);
    else
        HAL_GPIO_WritePin(eeprom_wp_port, eeprom_wp_pin, GPIO_PIN_RESET);
}

uint8_t EEPROM_IsReady(void)
{
    uint8_t dummy = 0;
    if (HAL_I2C_Master_Transmit(eeprom_hi2c, AT24C02_ADDR, &dummy, 0, 2) == HAL_OK)
        return 1;
    return 0;
}

static uint8_t EEPROM_WaitReady(void)
{
    uint32_t start = HAL_GetTick();
    while (!EEPROM_IsReady())
    {
        if (HAL_GetTick() - start >= 20)
            return 1;
    }
    return 0;
}

uint8_t EEPROM_WriteByte(uint16_t mem_addr, uint8_t data)
{
    return EEPROM_WriteBytes(mem_addr, &data, 1);
}

uint8_t EEPROM_WriteBytes(uint16_t mem_addr, const uint8_t *data, uint16_t len)
{
    if (data == NULL || len == 0)
        return 1;
    if (mem_addr >= AT24C02_CAPACITY)
        return 1;
    if (HAL_GPIO_ReadPin(eeprom_wp_port, eeprom_wp_pin) == GPIO_PIN_SET)
        return 1;
    if (mem_addr + len > AT24C02_CAPACITY)
        len = AT24C02_CAPACITY - mem_addr;

    while (len > 0)
    {
        uint8_t page_remain = AT24C02_PAGE_SIZE - (mem_addr % AT24C02_PAGE_SIZE);
        uint8_t chunk = (len < page_remain) ? len : page_remain;

        uint8_t buf[9];
        buf[0] = (uint8_t)mem_addr;
        memcpy(&buf[1], data, chunk);

        if (HAL_I2C_Master_Transmit_DMA(eeprom_hi2c, AT24C02_ADDR, buf, chunk + 1) != HAL_OK)
            return 2;
        uint32_t dma_start = HAL_GetTick();
        while (HAL_I2C_GetState(eeprom_hi2c) != HAL_I2C_STATE_READY)
        {
            if (HAL_GetTick() - dma_start >= 100)
                return 2;
        }

        busy_flag = 1;

        len -= chunk;
        mem_addr += chunk;
        data += chunk;

        if (len > 0)
        {
            if (EEPROM_WaitReady())
            {
                busy_flag = 0;
                return 2;
            }
            busy_flag = 0;
        }
    }

    return 0;
}

uint8_t EEPROM_ReadByte(uint16_t mem_addr, uint8_t *data)
{
    return EEPROM_ReadBytes(mem_addr, data, 1);
}

uint8_t EEPROM_ReadBytes(uint16_t mem_addr, uint8_t *data, uint16_t len)
{
    if (data == NULL || len == 0)
        return 1;
    if (mem_addr >= AT24C02_CAPACITY)
        return 1;
    if (mem_addr + len > AT24C02_CAPACITY)
        len = AT24C02_CAPACITY - mem_addr;

    if (busy_flag)
    {
        if (EEPROM_WaitReady())
        {
            busy_flag = 0;
            return 2;
        }
        busy_flag = 0;
    }

    uint8_t addr = (uint8_t)mem_addr;
    if (HAL_I2C_Master_Transmit_DMA(eeprom_hi2c, AT24C02_ADDR, &addr, 1) != HAL_OK)
        return 2;
    uint32_t dma_start = HAL_GetTick();
    while (HAL_I2C_GetState(eeprom_hi2c) != HAL_I2C_STATE_READY)
    {
        if (HAL_GetTick() - dma_start >= 100)
            return 2;
    }

    if (HAL_I2C_Master_Receive_DMA(eeprom_hi2c, AT24C02_ADDR, data, len) != HAL_OK)
        return 2;
    dma_start = HAL_GetTick();
    while (HAL_I2C_GetState(eeprom_hi2c) != HAL_I2C_STATE_READY)
    {
        if (HAL_GetTick() - dma_start >= 100)
            return 2;
    }

    return 0;
}
