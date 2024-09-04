/*
 * main.c
 *
 *  Created on: Sep 4, 2024
 *      Author: Islam Nagi
 */

#include"../LIB/StdTypes.h"
#include"../LIB/errorStatuse.h"

#include"../MCAL/DIO/DIO_int.h"
#include"../MCAL/EXTI/EXTI_Config.h"
#include"../MCAL/EXTI/EXTI_Int.h"
#include"../MCAL/GIE/GIE_int.h"
#include"../HAL/LCD/LCD_int.h"
#include"../HAL/LCD/LCD_Config.h"
#include"../MCAL/ADC/ADC_Config.h"
#include"../MCAL/ADC/ADC_int.h"
#include<util/delay.h>

int main()
{

	DIO_enuSetPortDir(DIO_u8PORTC,0xff);

	DIO_enuSetPINDir(DIO_u8PORTA,DIO_u8PIN0,DIO_INPUT);
	ADC_enuEnableADC();
	ADC_enuINIT();
	ADC_enuSelectChannel(ADC_CHANNEL_0);
	ADC_enuDisableTriggaringMod();
	//ADC_enuDisableInterrupt();
	//ADC_enuStartConversion();

	u8 adcread =0;
	//u16 adc16 = 0;




	while(1)
	{


		ADC_enuStartConversion();
		ADC_enuPollingSystem();
		ADC_enuReadHighVal(&adcread);
		//DIO_enuSetPortVAL(DIO_u8PORTC,adcread);
		DIO_u8PORTC = 0xff;
		/*if(adcread<=100)
		{
			DIO_enuSetPINVAL(DIO_u8PORTC,DIO_u8PIN3,DIO_LOW);
			DIO_enuSetPINVAL(DIO_u8PORTC,DIO_u8PIN4,DIO_LOW);
		}
		else
		{
			DIO_enuSetPINVAL(DIO_u8PORTC,DIO_u8PIN3,DIO_HIGH);
			DIO_enuSetPINVAL(DIO_u8PORTC,DIO_u8PIN4,DIO_HIGH);
		}*/



		/*ADC_enuSelectChannel(ADC_CHANNEL_3);
		ADC_enuPollingSystem();
		ADC_enuReadHighVal(&adcread1);
		DIO_enuSetPortVAL(DIO_u8PORTC,adcread1);*/




	}


	return 0;
}












