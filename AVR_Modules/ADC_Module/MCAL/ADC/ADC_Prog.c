/*
 * ADC_Prog.c
 *
 *  Created on: Sep 24, 2024
 *      Author: Islam Nagi
 */

#include"../../LIB/StdTypes.h"
#include"../../LIB/errorStatuse.h"
#include"ADC_Prive.h"
#include"ADC_Config.h"
#include"../EXTI/interrupt.h"

static volatile void (*ADC_PvidFUN)(void*) = NULL;
static volatile void *ADC_Pvidpara = NULL;
ES_t ADC_enuINIT(void)
{
	ES_t Local_enuErrorState = ES_NOK;

#if VOLTAGE_REF == AREF
	ADMUX &= ~(MASK_NUM<<REFS0);
	ADMUX &= ~(MASK_NUM<<REFS1);
#elif VOLTAGE_REF == AVCC
	ADMUX |= (MASK_NUM<<REFS0);
	ADMUX &= ~(MASK_NUM<<REFS1);

#elif VOLTAGE_REF == INTERNAL_REF
	ADMUX |= (MASK_NUM<<REFS0);
	ADMUX |= (MASK_NUM<<REFS1);
#else
#error"Wrong Reference Voltage"
#endif

#if ADJUSTMENT == LEFT_ADJUST
	ADMUX|=(MASK_NUM<<ADLAR);
#elif ADJUSTMENT == RIGHT_ADJUST
	ADMUX&=~(MASK_NUM<<ADLAR);
#else
#error"Wrong ADJUSTMENT"
#endif

#if PRESCALER == PRES_2
	ADCSRA |= (MASK_NUM<<ADPS0);
	ADCSRA &= ~(MASK_NUM<<ADPS1);
	ADCSRA &= ~(MASK_NUM<<ADPS2);
#elif PRESCALER == PRES_4
	ADCSRA &= ~(MASK_NUM<<ADPS0);
	ADCSRA |= (MASK_NUM<<ADPS1);
	ADCSRA &= ~(MASK_NUM<<ADPS2);
#elif PRESCALER == PRES_8
	ADCSRA |= (MASK_NUM<<ADPS0);
	ADCSRA |= (MASK_NUM<<ADPS1);
	ADCSRA &= ~(MASK_NUM<<ADPS2);
#elif PRESCALER == PRES_16
	ADCSRA &= ~(MASK_NUM<<ADPS0);
	ADCSRA &=~ (MASK_NUM<<ADPS1);
	ADCSRA |= (MASK_NUM<<ADPS2);
#elif PRESCALER == PRES_32
	ADCSRA |= (MASK_NUM<<ADPS0);
	ADCSRA &= ~(MASK_NUM<<ADPS1);
	ADCSRA |= (MASK_NUM<<ADPS2);
#elif PRESCALER == PRES_64
	ADCSRA &= ~(MASK_NUM<<ADPS0);
	ADCSRA |= (MASK_NUM<<ADPS1);
	ADCSRA |= (MASK_NUM<<ADPS2);
#elif PRESCALER == PRES_128
	ADCSRA |= (MASK_NUM<<ADPS0);
	ADCSRA |= (MASK_NUM<<ADPS1);
	ADCSRA |= (MASK_NUM<<ADPS2);
#else
#error"Wrong Prescaler selection"
#endif
	return Local_enuErrorState;
}
ES_t ADC_enuSetRefVoltage(u8 Copy_u8SelectedVolt)
{
	ES_t Local_enuErrorState = ES_NOK;
	switch(Copy_u8SelectedVolt)
	{
	case AREF:
		ADMUX &= ~(MASK_NUM<<REFS0);
		ADMUX &= ~(MASK_NUM<<REFS1);
		break;
	case AVCC:
		ADMUX |= (MASK_NUM<<REFS0);
		ADMUX &= ~(MASK_NUM<<REFS1);
		break;

	case INTERNAL_REF:
		ADMUX |= (MASK_NUM<<REFS0);
		ADMUX |= (MASK_NUM<<REFS1);
		break;
	default:
		Local_enuErrorState = ES_Out_Of_Range;break;
	}

	return Local_enuErrorState;
}
ES_t ADC_enuSetAdjust(u8 Copy_u8SelectedADJ)
{
	ES_t Local_enuErrorState = ES_NOK;

	switch(Copy_u8SelectedADJ)
	{
	case LEFT_ADJUST:
		ADMUX|=(MASK_NUM<<ADLAR);break;
	case RIGHT_ADJUST:
		ADMUX&=~(MASK_NUM<<ADLAR);break;
	default:
		Local_enuErrorState = ES_Out_Of_Range;break;
	}


	return Local_enuErrorState;
}
ES_t ADC_enuSelectChannel(u8 Copy_u8SelectedChannel)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Channel7 < Copy_u8SelectedChannel)
	{
		ADMUX&=~(31<<0);  // 31 --> 0001 1111
		switch(Copy_u8SelectedChannel)
		{
		case Channel0:
			break;
		case Channel1:
			ADMUX|= Channel1;
			break;
		case Channel2:
			ADMUX|= Channel2;
			break;
		case Channel3:
			ADMUX|= Channel3;
			break;
		case Channel4:
			ADMUX|= Channel4;
			break;
		case Channel5:
			ADMUX|= Channel5;
			break;
		case Channel6:
			ADMUX|= Channel6;
			break;
		case Channel7:
			ADMUX|= Channel7;
			break;

		}
	}
	else
	{
		Local_enuErrorState = ES_Out_Of_Range;
	}


	return Local_enuErrorState;
}
ES_t ADC_enuEnableADC(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	ADCSRA |= (MASK_NUM<<ADEN);

	return Local_enuErrorState;
}
ES_t ADC_enuDisableADC(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	ADCSRA &= ~(MASK_NUM<<ADEN);

	return Local_enuErrorState;
}
ES_t ADC_enuStartConversion(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	ADCSRA|=(MASK_NUM<<ADSC);

	return Local_enuErrorState;
}
ES_t ADC_enuEnableINT(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	ADCSRA|=(MASK_NUM<<ADIE);

	return Local_enuErrorState;
}
ES_t ADC_enuDisableINT(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	ADCSRA &= ~(MASK_NUM<<ADIE);

	return Local_enuErrorState;
}
ES_t ADC_enuSetPrescaler(u8 Copy_u8SelectedPres)
{
	ES_t Local_enuErrorState = ES_NOK;
	switch(Copy_u8SelectedPres)
	{
	case  PRES_2:
		ADCSRA |= (MASK_NUM<<ADPS0);
		ADCSRA &= ~(MASK_NUM<<ADPS1);
		ADCSRA &= ~(MASK_NUM<<ADPS2);
		break;
	case PRES_4:
		ADCSRA &= ~(MASK_NUM<<ADPS0);
		ADCSRA |= (MASK_NUM<<ADPS1);
		ADCSRA &= ~(MASK_NUM<<ADPS2);
		break;
	case PRES_8:
		ADCSRA |= (MASK_NUM<<ADPS0);
		ADCSRA |= (MASK_NUM<<ADPS1);
		ADCSRA &= ~(MASK_NUM<<ADPS2);
		break;
	case PRES_16:
		ADCSRA &= ~(MASK_NUM<<ADPS0);
		ADCSRA &=~ (MASK_NUM<<ADPS1);
		ADCSRA |= (MASK_NUM<<ADPS2);
		break;
	case PRES_32:
		ADCSRA |= (MASK_NUM<<ADPS0);
		ADCSRA &= ~(MASK_NUM<<ADPS1);
		ADCSRA |= (MASK_NUM<<ADPS2);
		break;
	case PRES_64:
		ADCSRA &= ~(MASK_NUM<<ADPS0);
		ADCSRA |= (MASK_NUM<<ADPS1);
		ADCSRA |= (MASK_NUM<<ADPS2);
		break;
	case PRES_128:
		ADCSRA |= (MASK_NUM<<ADPS0);
		ADCSRA |= (MASK_NUM<<ADPS1);
		ADCSRA |= (MASK_NUM<<ADPS2);
		break;
	default:
		Local_enuErrorState = ES_Out_Of_Range;
	}
	return Local_enuErrorState;
}
ES_t ADC_enuDisableAutoTriggeringMode()
{
	ES_t Local_enuErrorState = ES_NOK;

	ADCSRA &= ~(MASK_NUM<<ADATE);

	return Local_enuErrorState;
}
ES_t ADC_enuEnsableAutoTriggeringMode(u8 Copy_u8SelectedMode)
{
	ES_t Local_enuErrorState = ES_NOK;

	ADCSRA |= (MASK_NUM<<ADATE);
	if(Timer_Counter1_Capture_Event >= Copy_u8SelectedMode)
	{
		//SFIOR &= ~(7<<ADTS0);//--> Sfior : 000- ----
		switch (Copy_u8SelectedMode)
		{
		case FREE_RUNNING:
			SFIOR&=~(MASK_NUM<<ADTS0);
			SFIOR&=~(MASK_NUM<<ADTS1);
			SFIOR&=~(MASK_NUM<<ADTS2);break;
		case Analog_Comparator:
			SFIOR|=(MASK_NUM<<ADTS0);
			SFIOR&=~(MASK_NUM<<ADTS1);
			SFIOR&=~(MASK_NUM<<ADTS2);break;
		case External_Interrupt_Request_0:
			SFIOR&=~(MASK_NUM<<ADTS0);
			SFIOR|=(MASK_NUM<<ADTS1);
			SFIOR&=~(MASK_NUM<<ADTS2);break;
		case Timer_Counter0_Compare_Match:
			SFIOR|=(MASK_NUM<<ADTS0);
			SFIOR|=(MASK_NUM<<ADTS1);
			SFIOR&=~(MASK_NUM<<ADTS2);break;
		case Timer_Counter0_Overflow:
			SFIOR&=~(MASK_NUM<<ADTS0);
			SFIOR&=~(MASK_NUM<<ADTS1);
			SFIOR|=(MASK_NUM<<ADTS2);break;
		case Timer_Counter1_Compare_Match_B:
			SFIOR|=(MASK_NUM<<ADTS0);
			SFIOR&=~(MASK_NUM<<ADTS1);
			SFIOR|=(MASK_NUM<<ADTS2);break;
		case Timer_Counter1_Overflow:
			SFIOR&=~(MASK_NUM<<ADTS0);
			SFIOR|=(MASK_NUM<<ADTS1);
			SFIOR|=(MASK_NUM<<ADTS2);break;
		case Timer_Counter1_Capture_Event:
			SFIOR|=(MASK_NUM<<ADTS0);
			SFIOR|=(MASK_NUM<<ADTS1);
			SFIOR|=(MASK_NUM<<ADTS2);break;

		}
	}
	else
	{
		Local_enuErrorState = ES_Out_Of_Range;
	}

	return Local_enuErrorState;
}

ES_t ADC_enuPollingConv(void)
{
	ES_t Local_enuErrorState  = ES_NOK;

	while(((ADCSRA>>ADIF)&MASK_NUM) == 0);
	ADCSRA|= (MASK_NUM<<ADIF);
	return Local_enuErrorState;
}

ES_t ADC_enuRead(u16 *Copy_Pu16Value)
{
	ES_t Local_enuErrorState  = ES_NOK;
	if(Copy_Pu16Value)
	{
		switch((ADMUX>>ADLAR)&1)
		{
		case LEFT_ADJUST:
			*Copy_Pu16Value = (ADCL>>6);
			*Copy_Pu16Value |= ((u16)ADCH<<2);
			break;
		case RIGHT_ADJUST:
			*Copy_Pu16Value = ADCL;
			*Copy_Pu16Value |= ((u16)ADCH<<8);
			break;
		}
	}
	else
	{
		Local_enuErrorState = ES_NULLPOINTER;
	}

	return Local_enuErrorState;
}
ES_t ADC_enuReadHIGHvalue(u8 *Copy_Pu8Value)
{
	ES_t Local_enuErrorState  = ES_NOK;
	if(Copy_Pu8Value)
	{
		switch((ADMUX>>ADLAR)&1)
		{
		case LEFT_ADJUST:
			*Copy_Pu8Value = ADCH;
			break;
		case RIGHT_ADJUST:
			*Copy_Pu8Value = (ADCL>>2);
			*Copy_Pu8Value |= (ADCH<<6);
			break;
		}
	}
	else
	{
		Local_enuErrorState = ES_NULLPOINTER;
	}
	return Local_enuErrorState;
}

ES_t ADC_enuCallBackFUN(void (*Copy_PvidFUN)(void*),void *Copy_PvidPara)
{
	ES_t Local_errorState = ES_OK;

	if(Copy_PvidFUN)
	{
		ADC_PvidFUN = Copy_PvidFUN;
		ADC_Pvidpara = Copy_PvidPara;
	}
	else
	{
		Local_errorState = ES_NULLPOINTER;
	}

	return Local_errorState;
}

ISR(VECT_ADC)
{
	if(ADC_PvidFUN)
	{
		ADC_PvidFUN(ADC_Pvidpara);
	}
}
