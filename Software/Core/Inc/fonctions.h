/*
 * fonctions.h
 *
 *  Created on: Dec 6, 2023
 *      Author: grego
 */

#ifndef INC_FONCTIONS_H_
#define INC_FONCTIONS_H_

#include "main.h"
#include "gpio.h"
#include "stm32g4xx_hal.h"
#include "math.h"
#include "stdio.h"
#include "usart.h"
#include "tim.h"
#include "adc.h"


void filtre(void);
void PWM(uint8_t Hall_A, uint8_t Hall_B, uint8_t Hall_C);
int adc_value(void);
void error(void);

#endif /* INC_FONCTIONS_H_ */
