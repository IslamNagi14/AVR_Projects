/*
 * main.c
 *
 *  Created on: Sep 10, 2024
 *      Author: Islam Nagi
 */


#include"../LIB/StdTypes.h"
#include"../LIB/errorStatuse.h"

#include"../MCAL/GIE/GIE_int.h"
#include"../MCAL/DIO/DIO_int.h"
#include"../MCAL/TIMER/TIME_Config.h"
#include"../MCAL/TIMER/TIME_int.h"
#include"../MCAL/TIMER/interrupt.h"
#include"util/delay.h"
/*void togg(void)
{
	DIO_enuToggelPIN(DIO_u8PORTA,DIO_u8PIN2);
}*/

int main()
{




	//DIO_enuSetPINDir(DIO_u8PORTB,DIO_u8PIN3,DIO_OUTPUT);
	DIO_enuSetPINDir(DIO_u8PORTD,DIO_u8PIN7,DIO_OUTPUT);
	TIMER0_enuInit();
	TIMER2_enuInit();
   // TIMER0_enuGenerateFastPWM(4.5);
	//TIMER0_enuEnableInterrupt();
	TIMER2_enuGeneratePWM(1.5);
	GIE_enuEnable();

	while(1)
	{
		/*DIO_enuSetPINVAL(DIO_u8PORTA,DIO_u8PIN4,DIO_HIGH);
		_delay_ms(1000);
		DIO_enuSetPINVAL(DIO_u8PORTA,DIO_u8PIN4,DIO_LOW);*/





	}


	return 0;
}
/*ISR(VECT_TIMER0_COMP)
{
	DIO_enuToggelPIN(DIO_u8PORTA,DIO_u8PIN2);
}*/
