//
// Created by yyq on 2026/4/28.
//

#ifndef WS2812_H
#define WS2812_H

#include "main.h"

void ws2812_init(TIM_HandleTypeDef rgbTIM, uint32_t rgbCH);
//void RGB_set(int num, uint8_t r, uint8_t g, uint8_t b);

#endif //WS2812_H
