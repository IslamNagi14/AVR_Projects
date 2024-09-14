/*
 * LM_Prog.c
 *
 *  Created on: Sep 7, 2024
 *      Author: Islam Nagi
 */

#include"../LIB/StdTypes.h"
#include"../LIB/errorStatuse.h"

#include"../MCAL/DIO/DIO_int.h"
#include"../MCAL/ADC/ADC_int.h"
#include"LM_Config.h"
#include"LM_Prive.h"

ES_t LM_enuINIT(LM_t *Copy_StrA_LM)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_StrA_LM)
	{
		ADC_enuINIT();
		u8 Local_iterator = 0;
		for(Local_iterator = 0;Local_iterator < NUMBER_LM;Local_iterator++)
		{
			DIO_enuSetPINDir(DIO_u8PORTA,Copy_StrA_LM[Local_iterator].LM_Pin,DIO_INPUT);
		}
	}
	else
	{
		Local_enuErrorState = ES_NULLPOINTER;
	}
	return Local_enuErrorState;
}
ES_t LM_enuGetTemp(u8 Copy_u16Channelnum,f32 *Copy_f32Temp)
{
	ES_t Local_enuErrorState = ES_NOK;
	u16 Celsius = 0;
	ADC_enuSelectChannel(Copy_u16Channelnum);
	ADC_enuStartConversion();
	ADC_enuPollingSystem();
	ADC_enuRead(Celsius);
	*Copy_f32Temp = (Celsius*4.88)/10.0;

	return Local_enuErrorState;
}
