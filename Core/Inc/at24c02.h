#ifndef __AT24C02_H
#define __AT24C02_H

#include "stm32f1xx_hal.h"

#define AT24C02_ADDR        0xA0
#define AT24C02_PAGE_SIZE   8
#define AT24C02_CAPACITY    256

void EEPROM_Init(I2C_HandleTypeDef *hi2c, GPIO_TypeDef *wp_port, uint16_t wp_pin);

// 返回值: 0=成功, 1=参数错误, 2=写保护/超时/DMA错误
uint8_t EEPROM_WriteByte(uint16_t mem_addr, uint8_t data);
uint8_t EEPROM_WriteBytes(uint16_t mem_addr, const uint8_t *data, uint16_t len);

// 返回值: 0=成功, 1=参数错误, 2=超时/DMA错误
uint8_t EEPROM_ReadByte(uint16_t mem_addr, uint8_t *data);
uint8_t EEPROM_ReadBytes(uint16_t mem_addr, uint8_t *data, uint16_t len);

uint8_t EEPROM_IsReady(void);
void EEPROM_WriteProtect(uint8_t enable);

#endif
