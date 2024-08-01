/*
 * SERVO.c
 *
 *  Created on: Jan 29, 2024
 *      Author: hetta
 */

#include "SERVO.h"

void HAL_SERVO_voidRotateToAngle(uint8 Copy_u8AngleValue)
{
	if (Copy_u8AngleValue <= 0)
	{
		Copy_u8AngleValue = 1;
	}

	// casting for more accurate in calculations
	float32 Local_DelayValue = (1009.0f * (float32)Copy_u8AngleValue) / 50.0;

	MCAL_DIO_u8_SetPinValue(SERVO_u8_PORT, SERVO_u8_PIN, PIN_HIGH);

	_delay_us(Local_DelayValue);

	MCAL_DIO_u8_SetPinValue(SERVO_u8_PORT, SERVO_u8_PIN, PIN_LOW);

}
