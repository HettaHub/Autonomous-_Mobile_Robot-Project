/*
 * SERVO.h
 *
 *  Created on: Jan 29, 2024
 *      Author: hetta
 */

#ifndef HAL_SERVOMOTOR_SERVO_H_
#define HAL_SERVOMOTOR_SERVO_H_

#include "../../MCAL/Timer/TIMER.h"
#include "../../MCAL/DIO/DIO.h"
#include <util/delay.h>

#define SERVO_u8_PORT		PortD
#define SERVO_u8_PIN		Pin5


void HAL_SERVO_voidRotateToAngle(uint8 Copy_u8AngleValue);

#endif /* HAL_SERVOMOTOR_SERVO_H_ */
