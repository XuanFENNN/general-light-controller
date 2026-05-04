//
// Created by yyq on 2026/4/28.
//

#ifndef LIGHT_H
#define LIGHT_H
#include "main1.h"
#include <string.h>

extern int WeightCot;

float ADC_verf(float VerfValue);
float ADC2Resistance(float adc_value);
float resistance2Temperature(float R);
float dl_value(float Verf, uint16_t ADCvalue);
void light_init(TIM_HandleTypeDef ledtim, uint32_t ledch);
void LEDCompare(int zkb);
void LED_Breath(int delay);
int LED_TempCtrl(float temp);

#endif //LIGHT_H
