/*
 * main.c
 *
 *  Created on: Sep 25, 2024
 *      Author: Islam Nagi
 */

#include"../LIB/StdTypes.h"
#include"../LIB/errorStatuse.h"
#include"../MCAL/DIO/DIO_int.h"
#include"../MCAL/EXTI/EXTI_int.h"
#include"../MCAL/EXTI/EXTI_Config.h"
#include"../MCAL/GEI/GEI_int.h"
#include"../MCAL/ADC/ADC_int.h"
#include<util/delay.h>

extern EXTI_t EXTI_AstrINTConfig[INT_NUMBERS];
void read(void *p)
{
	ADC_enuRead((u16*)p);
}

int main(void)
{
	u16 adcread = 0;
	DIO_enuSetPortDir(DIO_u8PORTA,DIO_u8INPUT);
	DIO_enuSetPortDir(DIO_u8PORTC,0xff);
	DIO_enuSetPinDir(DIO_u8PORTD,DIO_u8PIN2,DIO_u8INPUT);

	EXTI_enuINIT(EXTI_AstrINTConfig);
	EXTI_enuSetSenseLevel(0,EXTI_u8ANY_LOGIC_CHANGE);
	EXTI_enuEnableEXINT(0);

	ADC_enuINIT();
	ADC_enuSelectChannel(ADC_u8Channel0);
	ADC_enuEnsableAutoTriggeringMode(ADC_External_Interrupt_Request_0);
	ADC_enuEnableADC();
	ADC_enuEnableINT();
	ADC_enuCallBackFUN(read,&adcread);
	ADC_enuStartConversion();

	GEI_enuEnableGINT();

	while(1)
	{
		/*ADC_enuSelectChannel(ADC_u8Channel3);
			ADC_enuStartConversion();
			ADC_enuPollingConv();
			_delay_ms(1000);
		ADC_enuSelectChannel(ADC_u8Channel0);
		ADC_enuPollingConv();*/
		DIO_enuSetPortVal(DIO_u8PORTC,adcread);

	}

	return 0;
}
