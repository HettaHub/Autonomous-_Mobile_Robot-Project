/*
 * INTERRUPT.h
 *
 *  Created on: Dec 11, 2023
 *      Author: hetta
 */

#ifndef MCAL_INTERRUPT_INTERRUPT_H_
#define MCAL_INTERRUPT_INTERRUPT_H_

#include "INTERRUPT_config.h"
#include"INTERRUPT_private.h"
#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/Macros.h"
#include"../../DIO/DIO.h"

void MCAL_EXTI_voidInit(void);
uint8 MCAL_EXTI_u8SetSenseControl(uint8 Copy_u8IntNum,uint8 Copy_u8Sense);
uint8 MCAL_EXTI_u8EnableInt(uint8 Copy_u8IntNum);
uint8 MCAL_EXTI_u8DisableInt(uint8 Copy_u8IntNum);
uint8 MCAL_EXTI_u8SetCallBack(uint8 Copy_u8IntNum , void (*Copy_pvCallBackFunc)(void));

#endif /* MCAL_INTERRUPT_INTERRUPT_H_ */
