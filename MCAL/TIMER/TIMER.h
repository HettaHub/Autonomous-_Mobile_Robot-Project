/*
 * TIMER.h
 *
 *  Created on: Jan 27, 2024
 *      Author: hetta
 */

#ifndef MCAL_TIMER_TIMER_H_
#define MCAL_TIMER_TIMER_H_

#define TIMER0	0
#define TIMER1	1
#define TIMER2	2

#include "TIMER_private.h"
#include "TIMER_config.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/Macros.h"
#include "../INTERRUPT/EXTERNAL/INTERRUPT.h"
#include "../INTERRUPT/GIE/GIE.h"
#include"../DIO/DIO.h"

void MCAL_TIMER0_VoidInit(void);
uint8 MCAL_TIMER_Ovf_u8Enable(uint8 Copy_u8TimerNumber);
uint8 MCAL_TIMER_Ovf_u8Disable(uint8 Copy_u8TimerNumber);
uint8 MCAL_TIMER0_ovf_u8SetCallBack(void(*Copy_pvCallBackFunc)(void));
void MCAL_Timer0_voidSetTimerValue(uint8 Copy_u8Value);


#endif /* MCAL_TIMER_TIMER_H_ */
