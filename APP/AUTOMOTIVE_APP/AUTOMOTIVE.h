/*
 * AUTOMOTIVE.h
 *
 *  Created on: Jan 29, 2024
 *      Author: hetta
 */

#ifndef APP_AUTOMOTIVE_APP_AUTOMOTIVE_H_
#define APP_AUTOMOTIVE_APP_AUTOMOTIVE_H_

#include "../../HAL/DC_MOTOR/DC_MOTOR.h"
#include "../../HAL/ULTRASONIC/ULTRASONIC.h"
#include "../../HAL/LCD/LCD_config.h"
#include "../../HAL/SERVOMOTOR/SERVO.h"

#define CRITICAL_u8_DISTANCE 		80
#define CAR_u16_OBSTCALE_SKIP_TIME 	1000
#define SERVO_u8_DELAY				200



uint8 MoveServo180Degrees(void);
void voidInitMotors(void);
void CheckObstacle_MoveAccordingly(u32 Copy_32USSDistance, u8 Copy_u8Dirction);


#endif /* APP_AUTOMOTIVE_APP_AUTOMOTIVE_H_ */
