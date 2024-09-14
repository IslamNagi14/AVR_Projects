/*
 * ADC_Prog.c
 *
 *  Created on: Sep 4, 2024
 *      Author: Islam Nagi
 */

#include"../../LIB/StdTypes.h"
#include"../../LIB/errorStatuse.h"
#include"ADC_Config.h"
#include"ADC_Priv.h"
#include"interrupt.h"

static volatile void (*ADC_PfunISRfun)(void) = NULL;

/*===================================================================================================================================*/
ES_t ADC_enuINIT(void)
{
	ES_t Local_enuErrorState = ES_NOK;


#if ADC_PRES == ADC_PRES_128
	ADCSRA|=7;
#elif ADC_PRES == ADC_PRES_64
	ADCSRA|=(3<<1);
#elif ADC_PRES == ADC_PRES_32
	ADCSRA|=5;
#elif ADC_PRES == ADC_PRES_16
	ADCSRA|=4;
#elif ADC_PRES == ADC_PRES_8
	ADCSRA|=3;
#elif ADC_PRES == ADC_PRES_4
	ADCSRA|=2;
#elif ADC_PRES == ADC_PRES_2
	ADCSRA|=1;
#else
#error"Wrong Prescaler Selection"
#endif



#if ADC_VOLTAGE_REF == ADC_AREF_REF
	ADMUX&=~(3<<6);
#elif ADC_VOLTAGE_REF == ADC_AVCC_REF
	ADMUX|=(1<<6);
#elif ADC_VOLTAGE_REF == ADC_INTERNAL_REF
	ADMUX|=(3<<6);
#else
#error"Wrong Voltage reference Selection"
#endif


#if ADC_ADJ == ADC_RIGHT_ADJ
	ADMUX&=~(1<<5);
#elif ADC_ADJ == ADC_LEFT_ADJ
	ADMUX|=(1<<5);
#else
#error"Wrong Adjust Selection"

#endif


	return Local_enuErrorState;
}
/*===================================================================================================================================*/
ES_t ADC_enuStartConversion(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	 ADCSRA|=(1<<6);

	return Local_enuErrorState;
}
/*===================================================================================================================================*/
ES_t ADC_enuPollingSystem(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	while(((ADCSRA>>4)&1) == 0);
	ADCSRA|=(1<<4);

	return Local_enuErrorState;
}
/*===================================================================================================================================*/
ES_t ADC_enuReadHighVal(u8 *Copy_Pu8Value)
{
	ES_t Local_enuErrorState = ES_NOK;
 u8 temp = 0;
#if ADC_ADJ == ADC_RIGHT_ADJ
 temp = (ADCL>>2);
 temp |= (ADCH<<6);
#elif ADC_ADJ == ADC_LEFT_ADJ
 temp = ADCH;
#else
#error"ADC ADJ is Wrong"
#endif
 *Copy_Pu8Value = temp ;
	return Local_enuErrorState;
}
/*===================================================================================================================================*/
ES_t ADC_enuRead(u16 *Copy_Pu16Value)
{
	ES_t Local_enuErrorState = ES_NOK;

#if ADC_ADJ == ADC_RIGHT_ADJ
	*Copy_Pu16Value = ADCL;
	(*Copy_Pu16Value) |= ((u16)ADCH<<8);
#elif ADC_ADJ == ADC_LEFT_ADJ
	*Copy_Pu16Value = (ADCL>>6);
	*Copy_Pu16Value |=((u16)ADCH<<2);

#else
#error"ADC ADJ is Wrong"
#endif

	return Local_enuErrorState;
}
/*===================================================================================================================================*/
ES_t ADC_enuEnableInterrupt()
{
	ES_t Local_enuErrorState = ES_NOK;
	ADCSRA|=(1<<3);

	return Local_enuErrorState;
}
/*===================================================================================================================================*/
ES_t ADC_enuDisableInterrupt()
{
	ES_t Local_enuErrorState = ES_NOK;
	ADCSRA&=~(1<<3);

	return Local_enuErrorState;
}
/*===================================================================================================================================*/
ES_t ADC_enuEnableADC(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	ADCSRA|=(1<<7);
	return Local_enuErrorState;
}
/*===================================================================================================================================*/
ES_t ADC_enuDisableADC(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	ADCSRA&=~(1<<7);
	return Local_enuErrorState;
}
/*===================================================================================================================================*/
ES_t ADC_enuSelectChannel(u8 Copy_u8ChannelID)
{
	ES_t Local_enuErrorState = ES_NOK;
	ADMUX&=~(0x1f<<0);

	switch(Copy_u8ChannelID)
	{
	case ADC_CHANNEL_0:
		break;
	case ADC_CHANNEL_1:
		ADMUX|=1;
			break;
	case ADC_CHANNEL_2:
		ADMUX|=2;
			break;
	case ADC_CHANNEL_3:
		ADMUX|=3;
			break;
	case ADC_CHANNEL_4:
		ADMUX|=4;
			break;
	case ADC_CHANNEL_5:
		ADMUX|=5;
			break;
	case ADC_CHANNEL_6:
		ADMUX|=6;
			break;
	case ADC_CHANNEL_7:
		ADMUX|=7;
			break;
			default:
				Local_enuErrorState = ES_Out_Of_Range;
	}

	return Local_enuErrorState;
}
/*===================================================================================================================================*/
ES_t ADC_enuEnableTriggMod(u8 Copy_u8TrigerringSource)
{
	ES_t Local_enuErrorState = ES_NOK;


	SFIOR&=~(7<<5);
#if Copy_u8TrigerringSource == FREE_RUNNING

#elif Copy_u8TrigerringSource == ANALOG_COMPARATOR
	SFIOR|=(1<<5);
#elif Copy_u8TrigerringSource == EXTERNAL_INTERRUPT0
	SFIOR|=(2<<5);
#elif Copy_u8TrigerringSource == TIMER_COUNTER0_Compare_Match
	SFIOR|=(3<<5);
#elif Copy_u8TrigerringSource == TIMER_COUNTER0_OVERFLOW
	SFIOR|=(4<<5);
#elif Copy_u8TrigerringSource == TIMER_COUNTER1_Compare_Match_B
	SFIOR|=(5<<5);
#elif Copy_u8TrigerringSource == TIMER_COUNTER1_OVERFLOW
	SFIOR|=(6<<5);
#elif Copy_u8TrigerringSource == TIMER_COUNTER1_CAPTURE_EVENT
	SFIOR|=(7<<5);

#endif
	ADCSRA|=(1<<5);
	return Local_enuErrorState;
}
/*===================================================================================================================================*/
ES_t ADC_enuDisableTriggaringMod(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	ADCSRA&=~(1<<5);

	return Local_enuErrorState;
}
/*===================================================================================================================================*/
ES_t ADCE_enuCallBack(void (*Copy_PfunAPPfun)(void))
{
	ES_t Local_enuErrorState = ES_NOK;

	ADC_PfunISRfun = Copy_PfunAPPfun;

	return Local_enuErrorState;
}
ISR(VECT_ADC)
{
	if(ADC_PfunISRfun)
		ADC_PfunISRfun();
}
