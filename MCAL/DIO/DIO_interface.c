/*
 * DIO.C

 *
 *  Created on: Sep 23, 2023
 *      Author: ahett
 */

#include "DIO.h"

							/*SET Port Direction*/

void MCAL_DIO_u8_SetPortDirection( u8 Loc_u8PortID , u8 Loc_u8Direction )
{

	if( (Loc_u8PortID <= PortD) && (Loc_u8Direction <= PORT_OUTPUT ) )
	{

		if(Loc_u8Direction == PORT_OUTPUT)
		{

			if(Loc_u8PortID == PortA)
			{
				DDRA_REG = PORT_OUTPUT;
			}

			else if(Loc_u8PortID == PortB)
			{
				DDRB_REG = PORT_OUTPUT;
			}

			else if(Loc_u8PortID == PortC)
			{
				DDRC_REG = PORT_OUTPUT;
			}

			else if(Loc_u8PortID == PortD)
			{
				DDRD_REG = PORT_OUTPUT;
			}

			else
			{
				// DO NOTHING
			}

		}

		else if(Loc_u8Direction == PORT_INPUT)
		{

			if(Loc_u8PortID == PortA)
			{
				DDRA_REG = PORT_INPUT;
			}

			else if(Loc_u8PortID == PortB)
			{
				DDRB_REG = PORT_INPUT;
			}

			else if(Loc_u8PortID == PortC)
			{
				DDRC_REG = PORT_INPUT;
			}

			else if(Loc_u8PortID == PortD)
			{
				DDRD_REG = PORT_INPUT;
			}

			else
			{
				// DO NOTHING
			}

		}

		else
		{
			// DO NOTHING
		}

	}

	else
	{
		// DO NOTHING
	}


}




							/*SET PIN DIRECTION*/

void MCAL_DIO_u8_SetPinDirection( u8 Loc_u8PortID , u8 Loc_u8PinID , u8 Loc_u8Direction )
{

    if (( Loc_u8PortID <= PortD ) && ( Loc_u8PinID <= Pin7 ) && ( Loc_u8Direction <= PIN_OUTPUT ) )
    {

		if( Loc_u8Direction == PIN_OUTPUT )
		{

			if( Loc_u8PortID == PortA )
			{
				SET_BIT( DDRA_REG , Loc_u8PinID );
			}

			else if( Loc_u8PortID == PortB )
			{
				SET_BIT( DDRB_REG , Loc_u8PinID );
			}

			else if( Loc_u8PortID == PortC )
			{
				SET_BIT( DDRC_REG , Loc_u8PinID );
			}

			else if( Loc_u8PortID == PortD )
			{
				SET_BIT( DDRD_REG , Loc_u8PinID );
			}

			else
			{
				// DO NOTHING
			}

		}

		else if( Loc_u8Direction == PIN_INPUT )
		{

			if( Loc_u8PortID == PortA )
			{
				CLR_BIT( DDRA_REG , Loc_u8PinID );
			}

			else if( Loc_u8PortID == PortB )
			{
				CLR_BIT( DDRB_REG , Loc_u8PinID );
			}

			else if( Loc_u8PortID == PortC )
			{
				CLR_BIT( DDRC_REG , Loc_u8PinID );
			}

			else if( Loc_u8PortID == PortD )
			{
				CLR_BIT( DDRD_REG , Loc_u8PinID );
			}

			else
			{
				// DO NOTHING
			}

		}

		else
		{
			// DO NOTHING
		}

    }

	else
	{
		// DO NOTHING
	}


}



							/*SET PORT VALUE*/

void MCAL_DIO_u8_SetPortValue( u8 Loc_u8PortID , u8 Loc_u8PortValue )
{

	if(( Loc_u8PortID <= PortD ) && ( Loc_u8PortValue <= Port_HIGH ))
	{

			if( Loc_u8PortID == PortA )
			{
				PORTA_REG = Loc_u8PortValue;
			}

			else if( Loc_u8PortID == PortB )
			{
				PORTB_REG = Loc_u8PortValue;
			}

			else if( Loc_u8PortID == PortC )
			{
				PORTC_REG = Loc_u8PortValue;
			}

			else if( Loc_u8PortID == PortD )
			{
				PORTD_REG = Loc_u8PortValue;
			}

			else
			{
				// DO NOTHING
			}

		}
	else
	{
		// Do nothing
	}

}




							/*SET PIN VALUE*/

void MCAL_DIO_u8_SetPinValue( u8 Loc_u8PortID , u8 Loc_u8PinID , u8 Loc_u8PinValue )
{

	if(( Loc_u8PortID <= PortD ) && ( Loc_u8PinID <= Pin7 ) && ( Loc_u8PinValue <= PIN_HIGH ))
	{

		if( Loc_u8PinValue == PIN_HIGH )
		{

			if( Loc_u8PortID == PortA )
			{
				SET_BIT( PORTA_REG , Loc_u8PinID );
			}

			else if( Loc_u8PortID == PortB )
			{
				SET_BIT(PORTB_REG,Loc_u8PinID);
			}

			else if( Loc_u8PortID == PortC )
			{
				SET_BIT(PORTC_REG,Loc_u8PinID);
			}

			else if( Loc_u8PortID == PortD )
			{
				SET_BIT(PORTD_REG,Loc_u8PinID);
			}

			else
			{
				// DO NOTHING
			}

		}



		else if( Loc_u8PinValue == PIN_LOW )
		{

		    if( Loc_u8PortID == PortA )
			{
				CLR_BIT( PORTA_REG, Loc_u8PinID );
			}

		    else if( Loc_u8PortID == PortB )
			{
				CLR_BIT(PORTB_REG,Loc_u8PinID);
			}

		    else if( Loc_u8PortID == PortC )
			{
				CLR_BIT(PORTC_REG,Loc_u8PinID);
			}

		    else if( Loc_u8PortID == PortD )
			{
				CLR_BIT(PORTD_REG,Loc_u8PinID);
			}

			else
			{
				// DO NOTHING
			}

		}

		else
		{
			// DO NOTHING
		}

	}

	else
	{
		// DO NOTHING
	}

}




							/*GET PORT VALUE*/

STD_TYPE MCAL_DIO_u8GetPortValue( u8 Loc_u8PortID , u8 *Loc_Pu8PortValue )
{
	u8 Loc_u8_Return_Value = NOK;

	if(( Loc_u8PortID <= PortD ))
	{

		if( Loc_u8PortID == PortA )
		{
			*Loc_Pu8PortValue= PORTA_REG;
			Loc_u8_Return_Value = OK;
		}

		else if( Loc_u8PortID == PortB )
		{
			*Loc_Pu8PortValue= PORTB_REG;
			Loc_u8_Return_Value = OK;
		}

		else if( Loc_u8PortID == PortC )
		{
			*Loc_Pu8PortValue= PORTC_REG;
			Loc_u8_Return_Value = OK;
		}

		else if( Loc_u8PortID == PortD )
		{
			*Loc_Pu8PortValue= PORTD_REG;
			Loc_u8_Return_Value = OK;
		}

		else
		{
			// DO NOTHING
		}


	}

	else
	{
		// DO NOTHING
	}

	return Loc_u8_Return_Value ;

}




 							/*GET PIN VALUE*/

 STD_TYPE MCAL_DIO_u8GetPinValue( u8 Loc_u8PortID , u8 Loc_u8PinID , u8 *Loc_Pu8PinValue )
 {
 	u8 Loc_u8_Return_Value = NOK;

 	if(( Loc_u8PortID <= PortD ) && ( Loc_u8PinID <= Pin7 ))
 	{

 		if( Loc_u8PortID == PortA )
 		{
 			*Loc_Pu8PinValue= GET_BIT( PINA_REG , Loc_u8PinID );
 			Loc_u8_Return_Value = OK;
 		}

 		else if( Loc_u8PortID == PortB )
 		{
 			*Loc_Pu8PinValue= GET_BIT( PINB_REG , Loc_u8PinID );
 			Loc_u8_Return_Value = OK;
 		}

 		else if( Loc_u8PortID == PortC )
 		{
 			*Loc_Pu8PinValue= GET_BIT( PINC_REG , Loc_u8PinID );
 			Loc_u8_Return_Value = OK;
 		}

 		else if( Loc_u8PortID == PortD )
 		{
 			*Loc_Pu8PinValue= GET_BIT( PIND_REG , Loc_u8PinID );
 			Loc_u8_Return_Value = OK;
 		}

 		else
 		{
 			// DO NOTHING
 		}


 	}

 	else
 	{
 		// DO NOTHING
 	}

 	return Loc_u8_Return_Value ;

 }



							/*TOG PORT*/

 void MCAL_DIO_u8_TogPort( u8 Loc_u8PortID )
 {

	if( ( Loc_u8PortID <= PortD ) )
	{

		if( Loc_u8PortID == PORTA_REG )
		{
			PORTA_REG = ~ PORTA_REG;
		}

		else if( Loc_u8PortID == PortB )
		{
			PORTB_REG = ~ PORTB_REG;
		}

		else if( Loc_u8PortID == PortC )
		{
			PORTC_REG = ~ PORTC_REG;
		}

		else if( Loc_u8PortID == PortD )
		{
			PORTD_REG = ~ PORTD_REG;
		}

		else
		{
			// DO NOTHING
		}


	}

	else
	{
		// DO NOTHING
	}

 }




 							/*TOG PIN*/

void MCAL_DIO_u8_TogPin( u8 Loc_u8PortID , u8 Loc_u8PinID )
 {

	if( ( Loc_u8PortID <= PortD ) && (Loc_u8PinID <= Pin7 ) )
	{

		if( Loc_u8PortID == PortA )
		{
			TOG_BIT( PORTA_REG , Loc_u8PinID );
		}

		else if( Loc_u8PortID == PortB )
		{
			TOG_BIT( PORTB_REG , Loc_u8PinID );
		}

		else if( Loc_u8PortID == PortC )
		{
			TOG_BIT( PORTC_REG , Loc_u8PinID );
		}

		else if( Loc_u8PortID == PortD )
		{
			TOG_BIT( PORTD_REG , Loc_u8PinID );
		}

		else
		{
			// DO NOTHING
		}

	}

	else
	{
		// DO NOTHING
	}
 }
