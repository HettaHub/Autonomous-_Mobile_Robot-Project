/*
 * ULTRASONIC.h
 *
 *  Created on: Jan 29, 2024
 *      Author: hetta
 */

#ifndef HAL_ULTRASONIC_ULTRASONIC_H_
#define HAL_ULTRASONIC_ULTRASONIC_H_


#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/INTERRUPT/EXTERNAL/INTERRUPT.h"
#include "../../MCAL/Timer/TIMER.h"
#include <string.h>
#include <util/delay.h>

#define TIMER1_MAX_COUNT 65535
#define USS_u8_TRIGGER_PORT		PortC
#define USS_u8_TRIGGER_PIN		Pin3

/*********************************************************************
 * the echo pin will be PD6 the only input capture pin in atmega32

 *********************************************************************/

/*
		 distance in cm = 17150 * TIMER
		 = 17150 x (TIMER value) x 0.0625 x 10^-6 cm
		 = (TIMER value) * (0.343 / 320)
		 = 1/923.94
*/

void HAL_USS_voidInit(void);
void HAL_setICP_RisingEdge(void);
void HAL_setICP_FallingEdge(void);
void HAL_stopTimer1(void);
void HAL_Clear_Timer1Flags(void);
u32 HAL_calcuteDistance(void);
u32 HAL_USS_u32GetDistance(void);

#endif /* HAL_ULTRASONIC_ULTRASONIC_H_ */
