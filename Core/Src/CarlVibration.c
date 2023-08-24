/*
 * CarlVibration.c
 *
 *  Created on: Aug 23, 2023
 *      Author: Carl
 */

#include "CarlVibration.h"

extern TIM_HandleTypeDef htim17;

#define Tim_Vibration htim17

void VibrateStart()
{
	HAL_TIM_PWM_Stop(&Tim_Vibration, TIM_CHANNEL_1);
	uint8_t vibration = 250;
	HAL_TIM_PWM_Start(&Tim_Vibration, TIM_CHANNEL_1);
}
void VibrateStop()
{
	HAL_TIM_PWM_Stop(&Tim_Vibration, TIM_CHANNEL_1);
}
void Vibrate(uint16_t time)
{
	  uint8_t vibration = 250;
	  HAL_TIM_PWM_Stop(&Tim_Vibration, TIM_CHANNEL_1);
	  Tim_Vibration.Instance->CCR1 = vibration;
	  HAL_TIM_PWM_Start(&Tim_Vibration, TIM_CHANNEL_1);
	  HAL_Delay(time);
	  HAL_TIM_PWM_Stop(&Tim_Vibration, TIM_CHANNEL_1);
}

