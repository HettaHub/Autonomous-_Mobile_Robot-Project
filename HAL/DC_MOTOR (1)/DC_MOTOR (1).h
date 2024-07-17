/*
 * DC_MOTOR.h
 *
 *  Created on: Jan 28, 2024
 *      Author: hetta
 */

#ifndef HAL_DC_MOTOR_DC_MOTOR_H_
#define HAL_DC_MOTOR_DC_MOTOR_H_

#include "../../MCAL/Timer/TIMER.h"
#include "../../MCAL/DIO/DIO.h"

/* 4 bits unsigned integer */

struct Motor
{
	uint8 motor_u8_port 		: 4;
	uint8 motor_u8_pin1 		: 4;
	uint8 motor_u8_pin2 		: 4;
};
struct Motor MOTOR1, MOTOR2;

#define MOTOR_u8_CLOCKWISE			0
#define MOTOR_u8_ANTICLOCKWISE		1

void HAL_InitMotors(void);
STD_TYPE HAL_MOTOR_u8MoveMotor(struct Motor Copy_Motor , uint8 Copy_u8Dirction);
void HAL_MOTOR_voidStopMotor(struct Motor Copy_Motor);
void HAL_MOTOR_voidSetMotorsPWMDutyCycle(uint8 Copy_u8DutyCycle);


#endif /* HAL_DC_MOTOR_DC_MOTOR_H_ */
