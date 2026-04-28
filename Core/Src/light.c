//
// Created by yyq on 2026/4/28.
//

#include "../Inc/light.h"
#include <math.h>

TIM_HandleTypeDef LEDTIM;
uint32_t LEDCH;
int Max_ZKB = 99;

float ADC_verf(const float VerfValue) {
    return 1.2f * 4095.0f / VerfValue;
}

float ADC2Resistance(const float adc_value) {
    const float R2 = 5100.0f;
    return 4095 * R2 / adc_value - R2;
}

float resistance2Temperature(const float R) {
    const float B = 3987.0f;
    const float T0 = 298.15f;
    const float R0 = 10000.0f;
    return T0 * B / (B + T0 * logf(R / R0)) - 273.15f;
}

float dl_value(const float Verf, const uint16_t ADCvalue) {
    return (2.45f - Verf / 4095.0f * (float)ADCvalue) / 0.4f;
}

void light_init(const TIM_HandleTypeDef ledtim, const uint32_t ledch) {
    LEDTIM = ledtim;
    LEDCH = ledch;
    __HAL_TIM_SET_COMPARE(&LEDTIM, LEDCH, 0);
}

void LEDCompare(const int zkb) {
    if (zkb <= Max_ZKB) {
        __HAL_TIM_SET_COMPARE(&LEDTIM, LEDCH, zkb);
    } else {
        __HAL_TIM_SET_COMPARE(&LEDTIM, LEDCH, Max_ZKB);
    }
}

void LED_Breath(const int delay) {
    for (int i = 0;i < 100; i++) {
        LEDCompare(i);
        HAL_Delay(delay);
    }
    for (int i = 99;i >= 0; i--) {
        LEDCompare(i);
        HAL_Delay(delay);
    }
}

int LED_TempCtrl(const float temp) {
    static float buffer[5] = {0.0f}; // 存储最近5次输入
    static int index = 0;             // 当前写入位置的索引
    static float sum = 0.0f;          // 当前窗口内的累加和
    static int count = 0;             // 已输入的总次数（用于前4次的均值计算）

    float t = 0;
    float value = 0;

    if (temp >= 65.0f) {
        t = 1;
    } else if (temp <= 50.0f) {
        t = 99;
    } else {
        float i = 65.0f - temp;
        // 99 / 15 = 6.6
        t = 6.6f * i;
    }

    value = (t - 32) / 50.0f; // 计算补偿比例
    if (value < 0.0f) {
        value = 0.0f; // 防止value为负
    }
    t = t + value; // 在温度低于60时对占空比进行补偿以压榨散热潜力

    if (count >= 5) {
        sum -= buffer[index];
    }
    buffer[index] = t;
    sum += t;
    index = (index + 1) % 5;
    if (count < 5) {
        count++;
    }

    Max_ZKB = (int)(sum / (float)count); // 修改最高占空比 限制最大亮度以防止过温
    if (Max_ZKB > 99) {
        Max_ZKB = 99; // 结果校验防止超标
    }

    return Max_ZKB;
}
