/*
 * LCD_interfacing.c
 *
 *  Created on: Dec 9, 2023
 *      Author: hetta
 */

#include"LCD_config.h"

static u8 INIT_STEP_FINISH = 0;



				/*INIT*/

STD_TYPE HAL_LCD_u8_Init(void)
{
	MCAL_DIO_u8_SetPortDirection(PortA ,PORT_OUTPUT);
	MCAL_DIO_u8_SetPortDirection(PortB ,PORT_OUTPUT);

	_delay_ms(30);

		/*FUNCTION SET*/
	HAL_LCD_u8_WriteCMD(0x20);
	HAL_LCD_u8_WriteCMD(0x20);
	HAL_LCD_u8_WriteCMD(0x80); // N=1 , F=0

	_delay_ms(1);

		/*DISPLAY CONTROL*/
	HAL_LCD_u8_WriteCMD(0x00);
	HAL_LCD_u8_WriteCMD(0xf0); // D=1 , C=1 , B=1

	_delay_ms(1);

		/*DISPLAY CLEAR*/
	HAL_LCD_u8_WriteCMD(0x00);
	HAL_LCD_u8_WriteCMD(0x10);

	_delay_ms(2);

	INIT_STEP_FINISH = 1;
}




			/*WRITE COMMAND*/

STD_TYPE HAL_LCD_u8_WriteCMD(u8 CMD)
{
	MCAL_DIO_u8_SetPinValue(PortB , Pin1 , PIN_LOW);			//	RS	=	0
	MCAL_DIO_u8_SetPinValue(PortB , Pin2 , PIN_LOW);			//	RW	=	0


	MCAL_DIO_u8_SetPinValue(PortA , Pin4 , GET_BIT(CMD,4));		//	DB4
	MCAL_DIO_u8_SetPinValue(PortA , Pin5 , GET_BIT(CMD,5));		//	DB5
	MCAL_DIO_u8_SetPinValue(PortA , Pin6 , GET_BIT(CMD,6));		//	DB6
	MCAL_DIO_u8_SetPinValue(PortA , Pin7 , GET_BIT(CMD,7));		//	DB7

	MCAL_DIO_u8_SetPinValue(PortB , Pin3	, PIN_HIGH);

	_delay_ms(1);

	MCAL_DIO_u8_SetPinValue(PortB , Pin3	, PIN_LOW);


	if(INIT_STEP_FINISH)
	{
	MCAL_DIO_u8_SetPinValue(PortA , Pin4 , GET_BIT(CMD,0));		//	DB4
	MCAL_DIO_u8_SetPinValue(PortA , Pin5 , GET_BIT(CMD,1));		//	DB5
	MCAL_DIO_u8_SetPinValue(PortA , Pin6 , GET_BIT(CMD,2));		//	DB6
	MCAL_DIO_u8_SetPinValue(PortA , Pin7 , GET_BIT(CMD,3));		//	DB7

	MCAL_DIO_u8_SetPinValue(PortB , Pin3	, PIN_HIGH);

	_delay_ms(1);

	MCAL_DIO_u8_SetPinValue(PortB , Pin3	, PIN_LOW);

	_delay_ms(2);
	}
}




			/*WRITE DATA*/

STD_TYPE HAL_LCD_u8_WriteData(u8 DATA)
{
	MCAL_DIO_u8_SetPinValue(PortB , Pin1 , PIN_HIGH);			//	RS	=	1
	MCAL_DIO_u8_SetPinValue(PortB , Pin2 , PIN_LOW);			//	RW	=	0


	MCAL_DIO_u8_SetPinValue(PortA , Pin4 , GET_BIT(DATA,4));	//	DB4
	MCAL_DIO_u8_SetPinValue(PortA , Pin5 , GET_BIT(DATA,5));	//	DB5
	MCAL_DIO_u8_SetPinValue(PortA , Pin6 , GET_BIT(DATA,6));	//	DB6
	MCAL_DIO_u8_SetPinValue(PortA , Pin7 , GET_BIT(DATA,7));	//	DB7

	MCAL_DIO_u8_SetPinValue(PortB , Pin3	, PIN_HIGH);

	_delay_ms(1);

	MCAL_DIO_u8_SetPinValue(PortB , Pin3	, PIN_LOW);


	if(INIT_STEP_FINISH)
	{
	MCAL_DIO_u8_SetPinValue(PortA , Pin4 , GET_BIT(DATA,0));	//	DB4
	MCAL_DIO_u8_SetPinValue(PortA , Pin5 , GET_BIT(DATA,1));	//	DB5
	MCAL_DIO_u8_SetPinValue(PortA , Pin6 , GET_BIT(DATA,2));	//	DB6
	MCAL_DIO_u8_SetPinValue(PortA , Pin7 , GET_BIT(DATA,3));	//	DB7

	MCAL_DIO_u8_SetPinValue(PortB , Pin3	, PIN_HIGH);

	_delay_ms(1);

	MCAL_DIO_u8_SetPinValue(PortB , Pin3	, PIN_LOW);

	_delay_ms(2);
	}
}




			/*WRITE STRING*/
STD_TYPE HAL_LCD_u8_WriteString(u8 *STRING , u8 ROW , u8 COL)
{
	HAL_LCD_u8_GoTo(ROW , COL);
    u8 Index = 0;
    u8 Line0 = 0;

    while ((STRING[Index] != '\0') && ((ROW * 16) + (Index + COL)) < 32)
    {
        if (((ROW * 16) + (Index + COL)) < 16)
        {
            HAL_LCD_u8_WriteData(STRING[Index]);
            Index++;
        }
        else if ((((ROW * 16) + (Index + COL)) == 16) && (Line0 == 0))
        {
        	HAL_LCD_u8_GoTo(1, 0);
            Line0++;
        }
        else if ((((ROW * 16) + (Index + COL)) < 32 ) && (Line0 == 1))
        {
        	HAL_LCD_u8_WriteData(STRING[Index]);
        	Index++;
        }
        else
        {
            // DO NOTHING
        }
    }
}

				/*GOTO*/

STD_TYPE HAL_LCD_u8_GoTo(u8 ROW , u8 COL)
{
	u8 Address;

	if((ROW<2)&&(COL<16))
	{
		Address = (ROW * 0x40) +COL;
		Address = MCAL_DIO_u8_SetPinValue(Address,DDRAM,PIN_HIGH); //DDRAM SET BIT NO.7 1
		HAL_LCD_u8_WriteCMD(Address);
	}
}




			 /*CUSTOMIZATION STORE*/

STD_TYPE HAL_LCD_u8_StoreCustom(u8 *Pattern , u8 Index)
{
	u8 Address;
	if(Index <8)
	{
		Address = Index * 8;
		Address = SET_BIT(Address,6); //CGRAM SET BIT NO.6 1
		Address = CLR_BIT(Address,7); //CGRAM SET BIT NO.7 0
		HAL_LCD_u8_WriteCMD(Address);
		for(Index = 0 ; Index < 8 ; Index++)
		{
			HAL_LCD_u8_WriteData(Pattern[Index]);
		}
	}
	HAL_LCD_u8_WriteCMD(0x02);
}




			/*CUSTOMIZATION DISPLAY*/

STD_TYPE HAL_LCD_u8_DisplayCustom(u8 Index , u8 ROW , u8 COL)
{

	HAL_LCD_u8_GoTo(ROW , COL);
	HAL_LCD_u8_WriteData(Index);

}






