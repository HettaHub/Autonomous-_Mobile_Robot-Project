/*
 * DC_interface.c
 *
 *  Created on: Jan 28, 2024
 *      Author: hetta
 */

#include "DC_MOTOR.h"


/**************************************************************************
* description :	sets port and pin numbers of the connected motors
* *************************************************************************/

void HAL_InitMotors(void)
{
	MOTOR1.motor_u8_port = PortB;
	MOTOR1.motor_u8_pin1 = Pin4;
	MOTOR1.motor_u8_pin2 = Pin5;

	MOTOR2.motor_u8_port = PortB;
	MOTOR2.motor_u8_pin1 = Pin6;
	MOTOR2.motor_u8_pin2 = Pin7;
}


/************************************************************************
 * description :	set motor Dirction CW or ACW
 * **********************************************************************/

STD_TYPE HAL_MOTOR_u8MoveMotor(struct Motor Copy_Motor , uint8 Copy_u8Dirction)
{
	uint8 Local_u8ErrorState = OK;
	switch(Copy_u8Dirction)
	{
	case MOTOR_u8_CLOCKWISE:
		MCAL_DIO_u8_SetPinValue(Copy_Motor.motor_u8_port , Copy_Motor.motor_u8_pin1, PIN_LOW);
		MCAL_DIO_u8_SetPinValue(Copy_Motor.motor_u8_port , Copy_Motor.motor_u8_pin2, PIN_HIGH);
		break;
	case MOTOR_u8_ANTICLOCKWISE:
		MCAL_DIO_u8_SetPinValue(Copy_Motor.motor_u8_port , Copy_Motor.motor_u8_pin1, PIN_LOW);
		MCAL_DIO_u8_SetPinValue(Copy_Motor.motor_u8_port , Copy_Motor.motor_u8_pin2, PIN_HIGH);
		break;
	default:
		Local_u8ErrorState = NOK;
		break;
	}
	return Local_u8ErrorState;
}


/*********************************************************************************************
 * description :	this function stops pin1 and pin2 of the motor does not affect PWM
 * *******************************************************************************************/

void HAL_MOTOR_voidStopMotor(struct Motor Copy_Motor)
{
	MCAL_DIO_u8_SetPinValue(Copy_Motor.motor_u8_port , Copy_Motor.motor_u8_pin1, PIN_LOW);
	MCAL_DIO_u8_SetPinValue(Copy_Motor.motor_u8_port , Copy_Motor.motor_u8_pin2, PIN_LOW);
}



/************************************************************************
 * description :	control motor speed from PWM pin at OC0 (PWM0)
 * **********************************************************************/

void HAL_MOTOR_voidSetMotorsPWMDutyCycle(uint8 Copy_u8DutyCycle)
{
	MCAL_PWM_SetDutyCycle(Copy_u8DutyCycle);
	return;
}
