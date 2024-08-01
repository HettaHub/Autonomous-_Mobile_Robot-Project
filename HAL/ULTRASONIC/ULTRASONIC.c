/*
 * ULTRASONIC.c
 *
 *  Created on: Jan 29, 2024
 *      Author: hetta
 */

#include"ULTRASONIC.h"



static u16 volatile TIMER1_OVER_FLOW = 0;

void HAL_USS_voidInit(void)
{
	 //  enable global interrupt
	MCAL_GIE_voidEnableGlobal();

	// enable over flow interrupt for timer 1
	MCAL_TIMER_Ovf_u8Enable(TIMER1);

	// normal counter
	TCCR1A = 0;
}


/************************************************************************
 * description :	RisingEdge(input capture pin ICP1)
 * **********************************************************************/

void HAL_setICP_RisingEdge(void)
{
	/* wait for rising edge on USS_ECHO pin (input capture pin ICP1)*/

	/* set capture on rising edge */
	SET_BIT(TCCR1B, TCCR1B_ICES1);

	/* start timer with no prescaler */
	SET_BIT(TCCR1B, TCCR1B_CS10);
}


/************************************************************************
 * description :	FallingEdge(input capture pin ICP1)
 * **********************************************************************/

void HAL_setICP_FallingEdge(void)
{
	// Capture on falling edge
	CLR_BIT(TCCR1B, TCCR1B_ICES1);

	// start count no prescaler
	SET_BIT(TCCR1B, TCCR1B_CS10);
}

void HAL_stopTimer1(void)
{
	CLR_BIT(TCCR1B, TCCR1B_CS10);
}


/************************************************************************
 * description :	clear flags
 * **********************************************************************/

void HAL_Clear_Timer1Flags(void)
{
	/* Clear ICP flag (Input Capture flag) */
	SET_BIT(TIFR, TIFR_ICF1);

	/* Clear Timer Overflow flag */
	SET_BIT(TIFR, TIFR_TOV1);
}


u32 HAL_calcuteDistance(void)
{
	/* current count */
	u32 count  = (u16)ICR1L;

	count += TIMER1_MAX_COUNT * TIMER1_OVER_FLOW;

	return (u32)((float32)count / 923.94);
}


u32 HAL_USS_u32GetDistance(void)
{

/**************************************************************
*  global interrupt is enabled
*  timer 1 over flow is enabled
*	register TCCR1A set as normal = 0
* *************************************************************/

	/* send 10us pulse to trigger pin */
	MCAL_DIO_u8_SetPinValue(USS_u8_TRIGGER_PORT , USS_u8_TRIGGER_PIN , PIN_HIGH);
	_delay_us(10);
	MCAL_DIO_u8_SetPinValue(USS_u8_TRIGGER_PORT , USS_u8_TRIGGER_PIN , PIN_LOW);

	/* Clear Timer1 counter */
	TCNT1H = 0;
	TCNT1L = 0;

	/* set capture on rising edge and start timer */
	HAL_setICP_RisingEdge();

	/* clear TIMER1 ovf and ICP flag from TIFR*/
	HAL_Clear_Timer1Flags();

	/* when ICP1 receives a rising edge TIFR_ICF1 in TIFR will get triggered*/

	/* wait for rising edge */
	while ((TIFR & (1 << TIFR_ICF1)) == 0);

	/* Clear Timer1 counter */
	TCNT1H = 0;
	TCNT1L = 0;

	/* set capture on falling edge and start timer */
	HAL_setICP_FallingEdge();

	/* clear TIMER1 ovf and ICP flag from TIFR*/
	HAL_Clear_Timer1Flags();

	TIMER1_OVER_FLOW = 0;

	while ((TIFR & (1 << TIFR_ICF1)) == 0);/* Wait for falling edge */

	return HAL_calcuteDistance();
}


void __vector_9(void) __attribute__((signal));

void __vector_9(void)
{
	TIMER1_OVER_FLOW++;
}



