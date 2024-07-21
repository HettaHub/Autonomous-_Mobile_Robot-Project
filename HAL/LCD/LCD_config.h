/*
 * LCD_config.h
 *
 *  Created on: Dec 9, 2023
 *      Author: hetta
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_

#include"../../MCAL/DIO/DIO_config.h"
#include"LCD_private.h"

	/*FUNCTION SET*/
#define N 1	// (2-LINE)
#define F 0 // (5*7) DOTS

	/*DISPLAY CONTROL*/
#define D 0	// DISPLAY OFF
#define C 0	// CURSOR OFF
#define B 0	// BLINK OFF

	/*CLEAR*/
#define CLEAR 0X01	// CLEAR LCD

	/*ENTRY MODE (DEFAULT)*/
#define i/d	1	// +1 (INCREMENT MODE)
#define S	0	// NO DISPLAY SHIFT OPERATION


#define DDRAM	7



#endif /* HAL_LCD_LCD_CONFIG_H_ */
