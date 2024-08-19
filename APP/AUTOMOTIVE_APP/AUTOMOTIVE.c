/*
 * AUTOMOTIVE.c
 *
 *  Created on: Jan 29, 2024
 *      Author: hetta
 */

#include"AUTOMOTIVE.h"


/**************************************************************************
* description :	This function moves the servo 0 to 90 to 180 and back
* based on the last angle stored in Local_u8CurrentAngle static variable
* *************************************************************************/

uint8 MoveServo180Degrees(void)
{
	static uint8 Local_u8CurrentAngle = 0;

	/* inc_flag is used rotate the servo on the
	 * specified angles Clock wise or anti clock wise */
	static uint8 Local_u8IncFlag = 1;

	uint8 Local_u8Direction = ' ';

	if(Local_u8IncFlag)
	{
		Local_u8CurrentAngle += 50;
	}
	else
	{
		Local_u8CurrentAngle -= 50;
	}

	switch(Local_u8CurrentAngle)
	{
	case 0:
		Local_u8Direction = 'L';
		break;
	case 50:
		Local_u8Direction = 'C';
		break;
	case 100:
		Local_u8Direction = 'R';
		break;
	default:
		Local_u8Direction = ' ';
		break;
	}

	/* rotate servo according to changes */
	HAL_SERVO_voidRotateToAngle(Local_u8CurrentAngle);

/*	This ensures that the motor changes direction when it reaches the endpoints*/
	if(Local_u8CurrentAngle <= 1 || Local_u8CurrentAngle >= 100)
	{
		Local_u8IncFlag = !Local_u8IncFlag;
	}
	else
	{
		/*Do Nothing */
	}
	_delay_ms(SERVO_u8_DELAY);
	return Local_u8Direction;
}

/*******************************************************************************
* description :	check if USS measured distance lower than the critical value
* if true then move according to the direction of Servo motor (Copy_u8Dirction)
* ******************************************************************************/

void CheckObstacle_MoveAccordingly(u32 Copy_32USSDistance, uint8 Copy_u8Dirction)
{
	if(Copy_32USSDistance <= CRITICAL_u8_DISTANCE)
	{
		HAL_MOTOR_voidSetMotorsPWMDutyCycle(100);

		switch(Copy_u8Dirction)
		{
		case 'L':
			HAL_MOTOR_u8MoveMotor(MOTOR1, MOTOR_u8_ANTICLOCKWISE);
			HAL_MOTOR_voidStopMotor(MOTOR2);
			_delay_ms(CAR_u16_OBSTCALE_SKIP_TIME);
			break;
		case 'R':
			HAL_MOTOR_u8MoveMotor(MOTOR2, MOTOR_u8_ANTICLOCKWISE);
			HAL_MOTOR_voidStopMotor(MOTOR1);
			_delay_ms(CAR_u16_OBSTCALE_SKIP_TIME);
			break;
		case 'C':
			HAL_MOTOR_u8MoveMotor(MOTOR1, MOTOR_u8_ANTICLOCKWISE);
			HAL_MOTOR_u8MoveMotor(MOTOR2, MOTOR_u8_CLOCKWISE);
			_delay_ms(CAR_u16_OBSTCALE_SKIP_TIME);
		}
	}
	else
	{
		/* set speed of the motor by chaning dutycycle */
		HAL_MOTOR_voidSetMotorsPWMDutyCycle(100);
		HAL_MOTOR_u8MoveMotor(MOTOR1, MOTOR_u8_CLOCKWISE);
		HAL_MOTOR_u8MoveMotor(MOTOR2, MOTOR_u8_CLOCKWISE);
	}

}


/*******************************************************************************
* description :	this function returns a string of 3 letters
* descriping the current direction the car is taking
* ******************************************************************************/

char* charptrCarDirection(u32 Copy_32USSDistance, uint8 Copy_u8Dirction)
{

	static char Local_carDir[3] = "F \0";
	Local_carDir[0] = 'F';
	Local_carDir[1] = ' ';
	if(Copy_32USSDistance <= CRITICAL_u8_DISTANCE)
	{
		switch(Copy_u8Dirction)
		{
		case 'L':
			/* Backward - Right */
			Local_carDir[0] = 'B';
			Local_carDir[1] = 'R';
			break;
		case 'R':
			/* Backward - Left */
			Local_carDir[0] = 'B';
			Local_carDir[1] = 'L';
			break;
		case 'C':
			/* rotate arount it self */
			Local_carDir[0] = 'R';
			Local_carDir[1] = 'R';
			break;
		}
	}
	Local_carDir[2] = '\0';
	return Local_carDir;
}
