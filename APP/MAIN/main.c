/*
// assignment 1

#include <avr/io.h>
#include <util/delay.h>

void main(void)
{
    DDRC = 0b10000100;
    DDRD = 0b00001000;

    while (1)
    {
        if (((PINB >> 0) & 1) == 1)
        {
        	while(1)
        	{
            PORTC = 0b10000100;
            PORTD = 0b00001000;
        	}
        }

        if (((PIND >> 6) & 1) == 1)
        {
        	while(1)
        	{
         	PORTC = 0b10000100;
            PORTD = 0b00001000;
            _delay_ms(1000);
            PORTC = 0b00000000;
            PORTD = 0b00000000;
            _delay_ms(1000);
            PORTC = 0b10000100;
            PORTD = 0b00001000;
        	}
        }

        if (((PIND >> 2) & 1) == 1)
        {
        	while(1)
        	{
            PORTC = 0b00000100;
            _delay_ms(1000);
            PORTC = 0b00000000;

            PORTC = 0b10000000;
            _delay_ms(1000);
            PORTC = 0b00000000;

            PORTD = 0b00001000;
            _delay_ms(1000);
            PORTD = 0b00000000;

            PORTC = 0b10000000;
            _delay_ms(1000);
            PORTC = 0b00000000;
        	}
        }

    }

}

//assignment 2

  #include<avr/io.h>
#include<util/delay.h>
void main (void)
{
	DDRC=0b10000100;
	DDRB=0b00000000;
	while(1)
	{

		if(((PINB>>0)&1)==1)
		{
			PORTC=0b0000000;
			_delay_ms(1);
			PORTC=0b10000000;
		}

	}
}



#include <avr\io.h>
#include <util/delay.h>

#define LOW 0x00
#define HIGH 0xFF

#define set_command (0b00101000)
#define display_control_command (0b00001111)
#define display_clear_command (0b00000001)
#define entry_command (0b00000110)

void main(void)
{

		DDRB=0b00001110;
		DDRA=0b11110000;

/////////////////////////////////////////
	_delay_ms(50);

		PORTB=0b00001000;
		PORTA=set_command;
		PORTB=0b00001000;
		_delay_ms(100);
		PORTB=0b00000000;
		PORTA=set_command<<4;
		PORTB=0b00001000;
		_delay_ms(100);
		PORTB=00000000;
		_delay_ms(50);

////////////////////////////////////////////


		PORTB=0b00001000;
		PORTA=display_control_command;
		PORTB=0b00001000;
		_delay_ms(100);
		PORTB=0b00000000;
		PORTA=display_control_command<<4;
		PORTB=0b00001000;
		_delay_ms(100);
		PORTB=0b00000000;
		_delay_ms(50);

////////////////////////////////////////////


		PORTB=0b00001000;
		PORTA=display_clear_command;
		PORTB=0b00001000;
		_delay_ms(100);
		PORTB=0b00000000;
		PORTA=display_clear_command<<4;
		PORTB=0b00001000;
		_delay_ms(100);
		PORTB=0b00000000;
		_delay_ms(50);

//////////////////////////////////////////////


		PORTB=0b00001000;
		PORTA=entry_command;
		PORTB=0b00001000;
		_delay_ms(100);
		PORTB=00000000;
		PORTA=entry_command<<4;
		PORTB=0b00001000;
		_delay_ms(100);
		PORTB=0b00000000;
		_delay_ms(50);

/////////////////////////////////////////////


		PORTB=0b00001000;
		PORTA=entry_command;
		PORTB=0b00001000;
		_delay_ms(100);
		PORTB=0b00000000;
		PORTA=entry_command<<4;
		PORTB=0b00001000;
		_delay_ms(100);
		PORTB=0b00000000;
		_delay_ms(50);

		PORTB=0b00001010;
		PORTA='"';
		PORTB=0b00001010;
		_delay_ms(100);
		PORTB=0b00000010;
		PORTA='"'<<4;
		PORTB=0b00001010;
		_delay_ms(100);
		PORTB=0b00000010;

		PORTB=0b00001010;
		PORTA='M';
		PORTB=0b00001010;
		_delay_ms(100);
		PORTB=0b00000010;
		PORTA='M'<<4;
		PORTB=0b00001010;
		_delay_ms(100);
		PORTB=0b00000010;

		PORTB=0b00001010;
		PORTA='O';
		PORTB=0b00001010;
		_delay_ms(100);
		PORTB=0b00000010;
		PORTA='O'<<4;
		PORTB=0b00001010;
		_delay_ms(100);
		PORTB=0b00000010;

		PORTB=0b00001010;
		PORTA='H';
		PORTB=0b00001010;
		_delay_ms(100);
		PORTB=0b00000010;
		PORTA='H'<<4;
		PORTB=0b00001010;
		_delay_ms(100);
		PORTB=0b00000010;

		PORTB=0b00001010;
		PORTA='A';
		PORTB=0b00001010;
		_delay_ms(100);
		PORTB=0b00000010;
		PORTA='A'<<4;
		PORTB=0b00001010;
		_delay_ms(100);
		PORTB=0b00000010;

		PORTB=0b00001010;
		PORTA='M';
		PORTB=0b00001010;
		_delay_ms(100);
		PORTB=0b00000010;
		PORTA='M'<<4;
		PORTB=0b00001010;
		_delay_ms(100);
		PORTB=0b00000010;

		PORTB=0b00001010;
		PORTA='E';
		PORTB=0b00001010;
		_delay_ms(100);
		PORTB=0b00000010;
		PORTA='E'<<4;
		PORTB=0b00001010;
		_delay_ms(100);
		PORTB=0b00000010;

		PORTB=0b00001010;
		PORTA='D';
		PORTB=0b00001010;
		_delay_ms(100);
		PORTB=0b00000010;
		PORTA='D'<<4;
		PORTB=0b00001010;
		_delay_ms(100);
		PORTB=0b00000010;


		PORTB=0b00001010;
		PORTA=' ';
		PORTB=0b00001010;
		_delay_ms(100);
		PORTB=0b00000010;
		PORTA=' '<<4;
		PORTB=0b00001010;
		_delay_ms(100);
		PORTB=0b00000010;

		PORTB=0b00001010;
		PORTA='A';
		PORTB=0b00001010;
		_delay_ms(100);
		PORTB=0b00000010;
		PORTA='A'<<4;
		PORTB=0b00001010;
		_delay_ms(100);
		PORTB=0b00000010;

		PORTB=0b00001010;
		PORTA='H';
		PORTB=0b00001010;
		_delay_ms(100);
		PORTB=0b00000010;
		PORTA='H'<<4;
		PORTB=0b00001010;
		_delay_ms(100);
		PORTB=0b00000010;

		PORTB=0b00001010;
		PORTA='M';
		PORTB=0b00001010;
		_delay_ms(100);
		PORTB=0b00000010;
		PORTA='M'<<4;
		PORTB=0b00001010;
		_delay_ms(100);
		PORTB=0b00000010;

		PORTB=0b00001010;
		PORTA='E';
		PORTB=0b00001010;
		_delay_ms(100);
		PORTB=0b00000010;
		PORTA='E'<<4;
		PORTB=0b00001010;
		_delay_ms(100);
		PORTB=0b00000010;

		PORTB=0b00001010;
		PORTA='D';
		PORTB=0b00001010;
		_delay_ms(100);
		PORTB=0b00000010;
		PORTA='D'<<4;
		PORTB=0b00001010;
		_delay_ms(100);
		PORTB=0b00000010;

		PORTB=0b00001010;
		PORTA='.';
		PORTB=0b00001010;
		_delay_ms(100);
		PORTB=0b00000010;
		PORTA='.'<<4;
		PORTB=0b00001010;
		_delay_ms(100);
		PORTB=0b00000010;

		PORTB=0b00001010;
		PORTA='"';
		PORTB=0b00001010;
		_delay_ms(100);
		PORTB=0b00000010;
		PORTA='"'<<4;
		PORTB=0b00001010;
		_delay_ms(100);
		PORTB=0b00000010;



	while(1)

	{


	}
}


#include <avr\io.h>
#include <util/delay.h>
#include"../MCAL/DIO.h"

void main (void)
{
	DDRC=0b00001111;
	PORTC=0b11111111;

		DDRD=0xff;
		DDRA=0b00001000;
		PORTD=0b00000000;
		PORTA=0b00000000;

		u8 Button=5;
		u8 col=0;
		u8 row=0;
		u8 x=5;
		u8 a[4][4]={{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'*','0','#','B'}};
		while(1)
		{

			u8 c=3;
			for (col=0; col<4;col++)
			{
				CLR_BIT(PORTC,col);
				u8 r=3;
				for(row=4;row<8;row++)
				{
					x=GET_BIT(PinC,row);
					if(x==0)
					{
						_delay_ms(5);
						x=GET_BIT(PinC,row);
						if(x==1)
						{
							Button=a[r][c];
						}
					}
					r--;
				}
				SET_BIT(PORTC,col);
				c--;
			}
			if(Button == '1')
			{

				PORTD=0b00001000;
				_delay_ms(2000);

			}
			if (Button == '3')
			{
				PORTD=0b00000000;
			}

		}

}



#include "main.h"
#include <avr\interrupt.h>
#include <avr\io.h>

void main (void)
{
	HAL_LED_u8LedInint(PortC, 2);
	HAL_BUZZER_u8BuzzerInint(PortA , 3);
	HAL_PUSH_BUTTON_u8ButtonInint(PortD , 2);
	APP_PINGPONG_u8INIT();
	SET_BIT(MCUCR , 1);
	CLR_BIT(MCUCR , 0);
	SET_BIT( SREG, 7);
	SET_BIT(GICR , 6);
	while(1)
	{
		APP_PINGPONG_u8APP();
	}

}

ISR(INT0_vect)
{
	HAL_LED_u8LedMode(PortC, 2 , LED_ON );
	TOG_BIT(PORTA,3);
}

EXTI_CALLBACK(void)
{
}


#include "main.h"
#include <avr\interrupt.h>
#include <avr\io.h>
volatile u16 x;
 volatile uint16_t U32X;

void main (void)
{
	//ADCSRA = 0b10001111;
	SET_BIT(ADMUX, 0);
	SET_BIT(ADMUX, 6);
	SET_BIT(ADCSRA, 0);
	SET_BIT(ADCSRA, 1);
	SET_BIT(ADCSRA, 2);
	SET_BIT(ADCSRA, 3);
	SET_BIT(ADCSRA, 7);
//	ADMUX = (1 << REFS0) | (1 << MUX0);
//	ADCSRA = (1 << ADEN) | (1 << ADIE) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
	ADMUX = 0b01000001;
		CLR_BIT(SFIOR , 5);
		CLR_BIT(SFIOR , 6);
		CLR_BIT(SFIOR , 7);
	SET_BIT(SREG, 7);
//	sei();


	HAL_LED_u8LedInint(PortD, 3);
	HAL_LED_u8LedInint(PortC, 7);
	HAL_LED_u8LedInint(PortC, 2);

	while(1)
	{
		SET_BIT(ADCSRA , 6);
		if((x<=1000) )
		{
			HAL_LED_u8LedMode(PortC, 2 , LED_ON );
			HAL_LED_u8LedMode(PortC, 7 , LED_OFF );
			HAL_LED_u8LedMode(PortD, 3 , LED_OFF );
		}
		else if( (x>1000) && (x<=2000) )
		{
			HAL_LED_u8LedMode(PortC, 2 , LED_OFF );
			HAL_LED_u8LedMode(PortC, 7 , LED_ON );
			HAL_LED_u8LedMode(PortD, 3 , LED_OFF );
		}
		else if( (x>2000) && (x<=3000) )
		{
			HAL_LED_u8LedMode(PortC, 2 , LED_OFF );
			HAL_LED_u8LedMode(PortC, 7 , LED_OFF );
			HAL_LED_u8LedMode(PortD, 3 , LED_ON );
		}
		else if( (x>3000) && (x<=4000) )
		{
			HAL_LED_u8LedMode(PortC, 2 , LED_ON );
			HAL_LED_u8LedMode(PortC, 7 , LED_ON );
			HAL_LED_u8LedMode(PortD, 3 , LED_ON );
		}

	}

}

ISR(ADC_vect)
{
	u16 read = ADC;
	x=(((u32)read*5000)/1024);
//	uint16_t adcResult = ADC;
//	U32X = ((uint32_t)adcResult  * 5000) / 1024;
}


#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint16_t U32X;

ISR(ADC_vect)
{
    uint16_t adcResult = ADC;
      U32X = ((uint32_t)adcResult  * 5000) / 1024;
}

void main(void)
{
    ADMUX = (1 << REFS0) | (1 << MUX0);
    ADCSRA = (1 << ADEN) | (1 << ADIE) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
    sei();

    DDRC |= (1 << PC2) | (1 << PC7);
    DDRD |= (1 << PD3);

    while (1)
    {
        ADCSRA |= (1 << ADSC);

        if (U32X >= 0 && U32X <= 1000) {
            PORTC |= (1 << PC2);
            PORTC &= ~(1 << PC7);
            PORTD &= ~(1 << PD3);
        } else if (U32X > 1000 && U32X <= 2000) {
            PORTC &= ~(1 << PC2);
            PORTC |= (1 << PC7);
            PORTD &= ~(1 << PD3);
        } else if (U32X > 2000 && U32X <= 5000) {
            PORTC &= ~(1 << PC2);
            PORTC &= ~(1 << PC7);
            PORTD |= (1 << PD3);
        }
    }

}
#include "main.h"
#include <avr/io.h>
#include <avr/interrupt.h>



volatile u16  count = 0;

void main(void)
{
	HAL_LED_u8LedInint(PortC,2);

	SET_BIT(SREG,7);
	CLR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
	SET_BIT(TIMSK,1);
	OCR0 = 199;
	while(1)
	{
		if(count == 1250)
		{
			HAL_LED_u8LedMode(PortC,2,LED_TOG);
			count = 0;
		}
	}
}

ISR(TIMER0_COMP_vect)
{
	count++;
}



#include "main.h"
#include <util/delay.h>

void main (void)
{
	u8 Loc_u8_Return_Value = E_NOT_OK;

	APP_SEGAPP_u8INIT();

	while(1)
	{
	Loc_u8_Return_Value = APP_SEGAPP_u8INC();
	Loc_u8_Return_Value = APP_SEGAPP_u8DEC();

	}
	 _delay_ms(1000);

}




#include "main.h"
#include <avr/io.h>
#include <avr/interrupt.h>

void main(void)
{

	MCAL_DIO_u8SetPinDirection(  PortD , Pin5 , PIN_OUTPUT);

	SET_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1B,WGM13);
	SET_BIT(TCCR1B,WGM12);


	CLR_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);

	ICR1 = 39999;
	OCR1A = 1999;

	CLR_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);


		while(1)
		{
			OCR1A = 1999;
			_delay_ms(1000);
			OCR1A = 2999;
			_delay_ms(1000);
			OCR1A = 3999;
			_delay_ms(1000);
			OCR1A = 2999;
			_delay_ms(1000);
			OCR1A = 1999;
			_delay_ms(1000);
		}
}




#include "main.h"
#include <avr/io.h>
#include <avr/interrupt.h>

void main(void)
{
	MCAL_DIO_u8SetPinDirection( PortD , Pin3 ,  PIN_OUTPUT );

	CLR_BIT(WDTCR,WDP0);
	SET_BIT(WDTCR,WDP1);
	SET_BIT(WDTCR,WDP2);

	SET_BIT(WDTCR,WDE);
	_delay_ms(200);

	MCAL_DIO_u8SetPinValue( PortD ,  Pin3 , PIN_HIGH );

	SET_BIT(WDTCR,WDE);
	SET_BIT(WDTCR,WDTOE);
	WDTCR = PORT_LOW ;

}

#include "main.h"


int main (void)
{
    HAL_LCD_u8_Init();
    u8 M[] = {
    		0b00000,
    		0b00000,
    		0b00000,
    		0b00111,
    		0b00101,
    		0b11111,
    		0b00000,
    		0b00000
    };
    u8 O[] = {
    		0b00000,
    		0b10000,
    		0b01000,
    		0b00100,
    		0b00010,
    		0b11111,
    		0b00000,
    		0b00000
    };

    u8 H[] = {
    		0b00000,
    		0b00000,
    		0b00000,
    		0b01110,
    		0b01010,
    		0b11111,
    		0b00000,
    		0b00000
    };
    u8 A[] = {
    		0b00000,
    		0b00000,
    		0b00000,
    		0b00100,
    		0b00100,
    		0b11111,
    		0b00000,
    		0b00000
    };
    u8 E[] = {
    		0b00000,
    		0b00000,
    		0b01010,
    		0b10101,
    		0b10001,
    		0b01010,
    		0b00100,
    		0b00000
    };


    HAL_LCD_u8_StoreCustom(E,0);
    HAL_LCD_u8_StoreCustom(A,1);
    HAL_LCD_u8_StoreCustom(H,2);
    HAL_LCD_u8_StoreCustom(O,3);
    HAL_LCD_u8_StoreCustom(M,4);
    HAL_LCD_u8_StoreCustom(E,0);


    HAL_LCD_u8_DisplayCustom(0,0,6);
    HAL_LCD_u8_DisplayCustom(1,0,7);
    HAL_LCD_u8_DisplayCustom(2,0,8);
    HAL_LCD_u8_DisplayCustom(3,0,9);
    HAL_LCD_u8_DisplayCustom(4,0,10);
    HAL_LCD_u8_DisplayCustom(0,0,11);

    HAL_LCD_u8_GoTo(0,0);

	return 0;
}
*/

#include "main.h"

int main (void)
{

		MCAL_DIO_u8_SetPortDirection(PortA,PORT_OUTPUT);
		MCAL_DIO_u8_SetPortDirection(PortB,PORT_OUTPUT);
		MCAL_DIO_u8_SetPinDirection(PortC,Pin0,PIN_OUTPUT);
		MCAL_DIO_u8_SetPinDirection(PortC,Pin1,PIN_OUTPUT);
		MCAL_DIO_u8_SetPinDirection(PortC,Pin2,PIN_OUTPUT);
		MCAL_DIO_u8_SetPinDirection(PortC,Pin3,PIN_OUTPUT);
		MCAL_DIO_u8_SetPinDirection(PortD,Pin5,PIN_OUTPUT);


		HAL_LCD_u8_Init();

		HAL_USS_voidInit();

		MCAL_PWM_VoidInit();

		HAL_InitMotors();

		while(1)
		{
			/* Moves the servo 0 to 90 to 180 and back */

			uint8 Local_u8ServoDirection = MoveServo180Degrees();

			/* get distance in cm from ultra sonic sensor */

			u32 Local_u32distance = HAL_USS_u32GetDistance();

			HAL_LCD_u8_WriteString("distance:",0,0);

			/* print distance of ultrasonic to CLCD */

			HAL_LCD_u8_WriteData((u32)Local_u32distance);

			HAL_LCD_u8_WriteString("srvo:",0,1);

			/* print current servo direction on CLCD */
			HAL_LCD_u8_WriteData(Local_u8ServoDirection);

			HAL_LCD_u8_WriteString(" dir:",1,0);

			char* Local_charptrCarDir = charptrCarDirection(Local_u32distance, Local_u8ServoDirection);

			/* print current car direction to CLCD */

			HAL_LCD_u8_WriteString(Local_charptrCarDir,1,1);

			CheckObstacle_MoveAccordingly(Local_u32distance, Local_u8ServoDirection);

			_delay_ms(500);

			/* clear CLCD */
			HAL_LCD_u8_WriteCMD(CLEAR);
		}
		return 0;
}




