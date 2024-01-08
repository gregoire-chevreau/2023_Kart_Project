/*
 * fonctions.c
 *
 *  Created on: Dec 6, 2023
 *      Author: grego
 */

#include "fonctions.h"

extern uint8_t Hall_A;
extern uint8_t Hall_B;
extern uint8_t Hall_C;

uint32_t ADC_Value = 0;

void filtre(void){}

int adc_value(void)
{
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
	ADC_Value = HAL_ADC_GetValue(&hadc1);
	return ADC_Value;
}

void PWM(uint8_t Hall_A, uint8_t Hall_B, uint8_t Hall_C)
{
	if(Hall_A == 0 && Hall_B == 1 && Hall_C == 0)
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);	//AH
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);	//AL
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 0);	//BH
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 1);	//BL
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 0);	//CH
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, 0);	//CL
	}
	else if (Hall_A == 0 && Hall_B == 1 && Hall_C == 1)
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, 1);
	}
	else if (Hall_A == 0 && Hall_B == 0 && Hall_C == 1)
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 1);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, 1);
	}
	else if (Hall_A == 1 && Hall_B == 0 && Hall_C == 1)
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 1);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 1);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, 0);
	}
	else if (Hall_A == 1 && Hall_B == 0 && Hall_C == 0)
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 1);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 1);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, 0);
	}
	else if (Hall_A == 1 && Hall_B == 1 && Hall_C == 0)
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 1);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 1);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, 0);
	}
//	else
//	{
//		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0);
//		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);
//		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 0);
//		//HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 0);
//		//HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 0);
//		//HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, 0);
//		//HAL_Delay(wait_time);
//	}
}

void error(void)
{
	//Erreur sur PA12/PA11 et PB12
	int Error_A;
	int Error_B;
	int Error_C;

	Error_A = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_12);
	Error_B = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_11);
	Error_C = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_12);

	if (Error_A == 1)
	{
		NVIC_SystemReset();
	}
	else if (Error_B == 1)
	{
		NVIC_SystemReset();
	}
	else if (Error_C == 1)
	{
		NVIC_SystemReset();
	}
}
