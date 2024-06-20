/*
 * DIO.h
 *
 *  Created on: Dec 11, 2023
 *      Author: hetta
 */

#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/Macros.h"
#include "DIO_private.h"
#include "DIO_config.h"
void MCAL_DIO_u8_SetPortDirection( u8 Loc_u8PortID , u8 Loc_u8Direction );
void MCAL_DIO_u8_SetPinDirection( u8 Loc_u8PortID , u8 Loc_u8PinID , u8 Loc_u8Direction );
void MCAL_DIO_u8_SetPortValue( u8 Loc_u8PortID , u8 Loc_u8PortValue );
void MCAL_DIO_u8_SetPinValue( u8 Loc_u8PortID , u8 Loc_u8PinID , u8 Loc_u8PinValue );
STD_TYPE MCAL_DIO_u8_GetPortValue( u8 Loc_u8PortID , u8 *Loc_Pu8PortValue );
STD_TYPE MCAL_DIO_u8_GetPinValue( u8 Loc_u8PortID , u8 Loc_u8PinID , u8 *Loc_Pu8PinValue );
void MCAL_DIO_u8_TogPort( u8 Loc_u8PortID );
void MCAL_DIO_u8_TogPin( u8 Loc_u8PortID , u8 Loc_u8PinID );

#endif /* MCAL_DIO_DIO_H_ */
