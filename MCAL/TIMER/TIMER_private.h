/*
 * TIMER_private.h
 *
 *  Created on: Jan 27, 2024
 *      Author: hetta
 */

#ifndef MCAL_TIMER_TIMER_PRIVATE_H_
#define MCAL_TIMER_TIMER_PRIVATE_H_


#define TIFR		 *((volatile uint8*)0x58)
#define TIFR_TOV0		0
#define TIFR_OCF0		1
#define TIFR_TOV1		2
#define TIFR_OCF1B		3
#define TIFR_OCF1A		4
#define TIFR_ICF1		5
#define TIFR_TOV2		6
#define TIFR_OCF2		7


/************************************************************************
 * description :	Timer Counter Control Register 0
 * **********************************************************************/

#define TCCR0		*((volatile uint8*)0x53)
#define TCCR0_CS00		0
#define TCCR0_CS01		1
#define TCCR0_CS02		2
#define TCCR0_WGM01		3
#define TCCR0_COM00		4
#define TCCR0_COM01		5
#define TCCR0_WGM00		6
#define TCCR0_FOC0		7

/************************************************************************
 * description :	timer1 Control register B
 * **********************************************************************/

#define TCCR1B		*((volatile uint8*)0x4E)
#define TCCR1B_CS10		0
#define TCCR1B_CS11		1
#define TCCR1B_CS12		2
#define TCCR1B_WGM12	3
#define TCCR1B_WGM13	4
#define TCCR1B_ICES1	6
#define TCCR1B_ICNC1	7


/************************************************************************
 * description :	timer1 Control register A
 * **********************************************************************/


#define TCCR1A		*((volatile uint8*)0x4F)
#define TCCR1A_WGM10	0
#define TCCR1A_WGM11	1
#define TCCR1A_FOC1B	2
#define TCCR1A_FOC1A	3
#define TCCR1A_COM1B0	4
#define TCCR1A_COM1B1	5
#define TCCR1A_COM1A0	6
#define TCCR1A_COM1A1	7


/************************************************************************
 * description :	timer0 count register
 * **********************************************************************/

#define TCNT0		 *((volatile uint8*)0x52)


/************************************************************************
 * description :	timer1 count register low byte
 * description :	timer1 count register high byte
 * **********************************************************************/

#define TCNT1L		 *((volatile uint8*)0x4C)
#define TCNT1H		 *((volatile uint8*)0x4D)

#define OCR0		 *((volatile uint8*)0x5c)
#define OCR1AH		 *((volatile uint8*)0x4B)
#define OCR1AL		 *((volatile uint8*)0x5A)



#define TIMSK		 *((volatile uint8*)0x59)


/************************************************************************
 * description :	timer0 mask reg
 * description :	timer0 overflow interrupt enable
 * **********************************************************************/

#define TIMSK_TOIE0		0
#define TIMSK_OCIE0		1


/************************************************************************
 * description :	timer 1 mask reg
 * **********************************************************************/

#define TIMSK_TOIE1		2
#define TIMSK_TOIE2		6


#define ICR1H		 *((volatile uint8*)0x47)
#define ICR1L		 *((volatile uint8*)0x46)




#endif /* MCAL_TIMER_TIMER_PRIVATE_H_ */
