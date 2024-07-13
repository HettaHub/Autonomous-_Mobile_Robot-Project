/*
 * INTERRUPT_private.h
 *
 *  Created on: Dec 10, 2023
 *      Author: hetta
 */

#ifndef MCAL_INTERRUPT_INTERRUPT_PRIVATE_H_
#define MCAL_INTERRUPT_INTERRUPT_PRIVATE_H_



#define ENABLED		1
#define DISABLED	2

#define EXTI_u8_INT0		0
#define EXTI_u8_INT1		1
#define EXTI_u8_INT2		2


#define LOW_LEVEL		1
#define ON_CHANGE		2
#define FALLING_EDGE	3
#define RISING_EDGE		4



/************************************************************************
 * description :	MCU control register
 * description :	Int (0,1) Sense control (Bit 0,1)
 * **********************************************************************/

#define MCUCR 			*((volatile uint8*) 0x55)
#define MCUCR_ISC11		3
#define MCUCR_ISC10		2
#define MCUCR_ISC01		1
#define MCUCR_ISC00		0


/************************************************************************
 * description :	MCU control and status register
 * **********************************************************************/

#define MCUCSR 			*((volatile uint8*) 0x54)
#define MCUCSR_ISC2		6

#define GICR 			*((volatile uint8*) 0x5B)
#define GICR_INT1		7
#define GICR_INT0		6
#define GICR_INT2		5

#endif /* MCAL_INTERRUPT_INTERRUPT_PRIVATE_H_ */
