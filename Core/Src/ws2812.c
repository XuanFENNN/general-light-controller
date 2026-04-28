//
// Created by yyq on 2026/4/28.
//

#include "ws2812.h"

TIM_HandleTypeDef RGBTIM;
uint32_t RGBCH;

void ws2812_init(const TIM_HandleTypeDef rgbTIM, const uint32_t rgbCH) {
    RGBTIM = rgbTIM;
    RGBCH = rgbCH;
    __HAL_TIM_SET_COMPARE(&RGBTIM, RGBCH, 0);
}

/*void RGB_set(int num, uint8_t r, uint8_t g, uint8_t b) {
    HAL_Delay(1);
}*/
