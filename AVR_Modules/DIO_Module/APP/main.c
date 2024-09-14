/*
 * main.c
 *
 *  Created on: Aug 25, 2024
 *      Author: Islam Nagi
 */
#include "../LIB/StdTypes.h"
#include "../LIB/errorStatuse.h"
#include "../MCAL/DIO/DIO_int.h"
#include <util/delay.h>

int main()
{
	DIO_enuInit();
	DIO_enuSetPortDir(DIO_u8PORTA,0xff);
	//u8 seg[] ={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	//u8 num = 0;
	while(1)
	{

		DIO_enuSetPINVAL(DIO_u8PORTA,DIO_u8PIN3,DIO_HIGH);
		DIO_enuSetPINVAL(DIO_u8PORTA,DIO_u8PIN4,DIO_HIGH);
		_delay_ms(500);

		 DIO_enuSetPINVAL(DIO_u8PORTA,DIO_u8PIN2,DIO_HIGH);
		 DIO_enuSetPINVAL(DIO_u8PORTA,DIO_u8PIN5,DIO_HIGH);
		 _delay_ms(500);

		 DIO_enuSetPINVAL(DIO_u8PORTA,DIO_u8PIN6,DIO_HIGH);
		DIO_enuSetPINVAL(DIO_u8PORTA,DIO_u8PIN1,DIO_HIGH);
		_delay_ms(500);

		DIO_enuSetPINVAL(DIO_u8PORTA,DIO_u8PIN0,DIO_HIGH);
        DIO_enuSetPINVAL(DIO_u8PORTA,DIO_u8PIN7,DIO_HIGH);
        _delay_ms(500);

        DIO_enuToggelPIN(DIO_u8PORTA,DIO_u8PIN0);
        DIO_enuToggelPIN(DIO_u8PORTA,DIO_u8PIN7);
        _delay_ms(500);

        DIO_enuToggelPIN(DIO_u8PORTA,DIO_u8PIN6);
        DIO_enuToggelPIN(DIO_u8PORTA,DIO_u8PIN1);
        _delay_ms(500);

        DIO_enuToggelPIN(DIO_u8PORTA,DIO_u8PIN2);
        DIO_enuToggelPIN(DIO_u8PORTA,DIO_u8PIN5);
        _delay_ms(500);



	}

	return 0;

}

