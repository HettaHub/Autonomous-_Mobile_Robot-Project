/*
 * LCD_PRIVATE.h
 *
 *  Created on: Dec 9, 2023
 *      Author: hetta
 */

#ifndef HAL_LCD_LCD_PRIVATE_H_
#define HAL_LCD_LCD_PRIVATE_H_

#include <util/delay.h>
#include "../../MCAL/DIO/DIO_config.h"


STD_TYPE HAL_LCD_u8_Init();
STD_TYPE HAL_LCD_u8_WriteCMD(u8 CMD);
STD_TYPE HAL_LCD_u8_WriteData(u8 DATA);
STD_TYPE HAL_LCD_u8_WriteString(u8 *STRING , u8 ROW , u8 COL);
STD_TYPE HAL_LCD_u8_GoTo(u8 ROW , u8 COL);
STD_TYPE HAL_LCD_u8_StoreCustom(u8 *Pattern , u8 Index);
STD_TYPE HAL_LCD_u8_DisplayCustom(u8 Index , u8 ROW , u8 COL);

#endif /* HAL_LCD_LCD_PRIVATE_H_ */
