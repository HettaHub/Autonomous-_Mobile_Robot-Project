/*
 * GIE_private.h
 *
 *  Created on: Jan 28, 2024
 *      Author: hetta
 */

#ifndef MCAL_INTERRUPT_GIE_GIE_PRIVATE_H_
#define MCAL_INTERRUPT_GIE_GIE_PRIVATE_H_

/************************************************************************
 * description :	Status Register
 * **********************************************************************/

#define SREG 		*((volatile uint8*) 0x5F)

/************************************************************************
 * description :	Interrupt bit
 * **********************************************************************/

#define SREG_I 		7

#endif /* MCAL_INTERRUPT_GIE_GIE_PRIVATE_H_ */
