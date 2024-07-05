/*
 * TIMER_interface.c
 *
 *  Created on: Jan 27, 2024
 *      Author: hetta
 */


#include "TIMER.h"

static void (*Timer0ovf_pvCallBackFunc)(void) = NULL;


void MCAL_TIMER0_VoidInit(void)
{
	/*Wave generation mode : Normal*/
		CLR_BIT(TCCR0,TCCR0_WGM00);
		CLR_BIT(TCCR0,TCCR0_WGM01);

	/*No Oc0*/
		CLR_BIT(TCCR0,TCCR0_COM00);
		CLR_BIT(TCCR0,TCCR0_COM01);

	/*CLK SET PRESCALER = 64*/
		SET_BIT(TCCR0,TCCR0_CS00);
		SET_BIT(TCCR0,TCCR0_CS01);
		CLR_BIT(TCCR0,TCCR0_CS02);
	/*Compare mode interrupt enable*/
		SET_BIT(TIMSK,TIMSK_OCIE0);
}

uint8 MCAL_TIMER_Ovf_u8Enable(uint8 Copy_u8TimerNumber)
{
	uint8 Local_u8ErrorState = OK;

	switch(Copy_u8TimerNumber)
	{
	case TIMER0:
		SET_BIT(TIMSK, TIMSK_TOIE0);
		break;
	case TIMER1:
		SET_BIT(TIMSK, TIMSK_TOIE1);
		break;
	case TIMER2:
		SET_BIT(TIMSK, TIMSK_TOIE2);
		break;
	default:
		Local_u8ErrorState = NOK;
		break;
	}
	return Local_u8ErrorState;

}


uint8 MCAL_TIMER_Ovf_u8Disable(uint8 Copy_u8TimerNumber)
{
	uint8 Local_u8ErrorState = OK;
	switch(Copy_u8TimerNumber)
	{
	case TIMER0:
		CLR_BIT(TIMSK, TIMSK_TOIE0);
		break;
	case TIMER1:
		CLR_BIT(TIMSK, TIMSK_TOIE1);
		break;
	case TIMER2:
		CLR_BIT(TIMSK, TIMSK_TOIE2);
		break;
	default:
		Local_u8ErrorState = NOK;
		break;
	}
	return Local_u8ErrorState;

}



uint8 MCAL_TIMER0_ovf_u8SetCallBack(void(*Copy_pvCallBackFunc)(void))
{
	uint8 Local_u8ErrorState=OK;
			if(Copy_pvCallBackFunc!=NULL)
			{
				Timer0ovf_pvCallBackFunc = Copy_pvCallBackFunc;

			}
			else
			{
				Local_u8ErrorState=NULL_POINTER;
			}

			return Local_u8ErrorState;
}

void MCAL_Timer0_voidSetTimerValue(uint8 Copy_u8Value)
{
	TCNT0 = Copy_u8Value;
}



/************************************************************************
 * description :	Timer 0 Overflow ISR
 * **********************************************************************/
void __vector_11(void) __attribute__((signal));

void __vector_11(void)
{
	if(Timer0ovf_pvCallBackFunc!=NULL)
	{
		Timer0ovf_pvCallBackFunc();
	}
	else
	{
		/*Do nothing*/
	}

}


/************************************************************************
 * description :	Timer 0 Compare ISR
 * **********************************************************************/

void __vector_10(void) __attribute__((signal));

void __vector_10(void)
{
	if(Timer0ovf_pvCallBackFunc!=NULL)
		{
			Timer0ovf_pvCallBackFunc();
		}
		else
		{
			/*Do nothing*/
		}
}
