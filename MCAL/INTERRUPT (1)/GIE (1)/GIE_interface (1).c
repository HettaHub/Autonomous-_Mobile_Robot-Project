/*
 * GIE_interface.c
 *
 *  Created on: Jan 28, 2024
 *      Author: hetta
 */

#include "../../DIO/DIO.h"
#include "GIE.h"

void MCAL_GIE_voidEnableGlobal(void)
{
	__asm volatile("SEI");
}

void MCAL_GIE_voidDisableGlobal(void)
{
	__asm volatile("CLI");
}
