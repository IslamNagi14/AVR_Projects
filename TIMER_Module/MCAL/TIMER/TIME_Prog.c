/*
 * TIME_Prog.c
 *
 *  Created on: Sep 8, 2024
 *      Author: Islam Nagi
 */


#include"../../LIB/StdTypes.h"
#include"../../LIB/errorStatuse.h"

#include"../DIO/DIO_int.h"
#include"interrupt.h"
#include"TIME_Config.h"
#include"TIME_Prive.h"

/*=================================================TIMER0========================================*/
static void(*EXTI0_PFunINIT[3])(void*) = {NULL,NULL,NULL};
static void*EXTI0_PparameterINIT[3] = {NULL,NULL,NULL};
static u32 Global0_u32PreLoad = 0;
static u32 Global0_u32NUM_INIOverFlows = 0;
ES_t TIMER0_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;
#if  TIMER0_MODE == WGM_NORMAL
	TCCR0 &=~(1<<3);
	TCCR0 &=~(1<<6);

#if COMP_MATCH_OUTPUT0 == COM_NORMAL_PORT
	TCCR0 &=~(1<<4);
	TCCR0 &=~(1<<5);
#elif COMP_MATCH_OUTPUT0 == COM_TOGGEL_OC
	TCCR0 |=(1<<4);
	TCCR0 &=~(1<<5);
#elif COMP_MATCH_OUTPUT0 == COM_CLEAR_OC
	TCCR0 &=~(1<<4);
	TCCR0 |=(1<<5);
#elif COMP_MATCH_OUTPUT0 == COM_SET_OC
	TCCR0 |=(1<<4);
	TCCR0 |=(1<<5);
#else
#error"NOT CORRECT compare output mode"
#endif


#elif TIMER0_MODE == WGM_CTC
	TCCR0 &=~(1<<6);
	TCCR0 |=(1<<3);
#if COMP_MATCH_OUTPUT0 == COM_NORMAL_PORT
	TCCR0 &=~(1<<4);
	TCCR0 &=~(1<<5);
#elif COMP_MATCH_OUTPUT0 == COM_TOGGEL_OC
	TCCR0 |=(1<<4);
	TCCR0 &=~(1<<5);
#elif COMP_MATCH_OUTPUT0 == COM_CLEAR_OC
	TCCR0 &=~(1<<4);
	TCCR0 |=(1<<5);
#elif COMP_MATCH_OUTPUT0 == COM_SET_OC
	TCCR0 |=(1<<4);
	TCCR0 |=(1<<5);
#else
#error"NOT CORRECT compare output mode"
#endif

#elif TIMER0_MODE == WGM_FAST_PWM
	TCCR0 |=(1<<3);
	TCCR0 |=(1<<6);
#if COMP_MATCH_OUTPUT0 == COM_NORMAL_PORT
	TCCR0 &=~(1<<4);
	TCCR0 &=~(1<<5);
#elif COMP_MATCH_OUTPUT0 == COM_NON_INVERTING
	TCCR0 &=~(1<<4);
	TCCR0 |=(1<<5);
#elif COMP_MATCH_OUTPUT0 == COM_INVERTING
	TCCR0 |=(1<<4);
	TCCR0 |=(1<<5);
#else
#error"NOT CORRECT compare output mode"
#endif

#elif TIMER0_MODE == WGM_PWM_PHCORRECT
	TCCR0 |=(1<<3);
	TCCR0 &=~(1<<6);
#if COMP_MATCH_OUTPUT0 == COM_NORMAL_PORT
	TCCR0 &=~(1<<4);
	TCCR0 &=~(1<<5);
#elif COMP_MATCH_OUTPUT0 == COM_NON_INVERTING
	TCCR0 &=~(1<<4);
	TCCR0 |=(1<<5);
#elif COMP_MATCH_OUTPUT0 == COM_INVERTING
	TCCR0 |=(1<<4);
	TCCR0 |=(1<<5);
#else
#error"NOT CORRECT compare output mode"
#endif

#else
#error"NOT CORRECT Wave Generation Mode"
#endif

#if TIMER0_PRES == NO_CLOCKSOURCE
	TCCR0 |=0;
#elif TIMER0_PRES == NO_PRESC
	TCCR0 |=1;
#elif TIMER0_PRES == PRESC_8
	TCCR0 |=2;
#elif TIMER0_PRES == PRESC_64
	TCCR0 |=3;
#elif TIMER0_PRES == PRESC_256
	TCCR0 |=4;
#elif TIMER0_PRES == PRESC_1024
	TCCR0 |=5;
#elif TIMER0_PRES == EXTCLOCK_FALLINGEDGE
	TCCR0 |=6;
#elif TIMER0_PRES == EXTCLOCK_RISINGEDGE
	TCCR0 |=7;

#else
#error"NOT CORRECT PRESCALING"
#endif
	return Local_enuErrorState;
}

ES_t TIMER0_enuGenerateFastPWM(f32 Copy_f32VolteVAL)
{	ES_t Local_enuErrorState = ES_NOK;
#if TIMER2_MODE == WGM_FAST_PWM || TIMER2_MODE == WGM_PWM_PHCORRECT
#if COMP_MATCH_OUTPUT0 == COM_NON_INVERTING
	OCR0 = (u8)((Copy_f32VolteVAL/5)*(Copy_f32VolteVAL/5)*256);
#elif COMP_MATCH_OUTPUT0 == COM_INVERTING
	 OCR0 = (u8)(255 - ((Copy_f32VolteVAL/5)*(Copy_f32VolteVAL/5)*256));
#else
#error"OC0 has a wrong configuration"
#endif
#endif
	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ES_t TIMER0_enuEnableInterrupt(void)
{	ES_t Local_enuErrorState = ES_NOK;
	TIMSK|=(1<<1);
	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}
ES_t TIMER0_enuDisableInterrupt(void)
{	ES_t Local_enuErrorState = ES_NOK;
	TIMSK&=~(1<<1);
	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ES_t TIMER0_enuSet_PINOCR0_VAL(u8 Copy_u8OCR0_VAL)
{
	ES_t Local_enuErrorState = ES_NOK;
	OCR0 = Copy_u8OCR0_VAL;
	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}
ES_t TIMER0_enuSet_preload(u8 Copy_u8Preload)
{
	ES_t Local_enuErrorState = ES_NOK;
	TCNT0 = Copy_u8Preload;
	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}
ES_t TIMER0_enuSet_AsychDelay(u32 Copy_u32Time,void (*Copy_PfunApp)(void*),void * Copy_vidPParameter)
{
	ES_t Local_enuErrorState = ES_NOK;
	TIMSK&=~(1<<0);
	f32 Local_f32OVERflowTime = (256*((f32)TIMER0_PRES/F_CPU))*1000;
	f32 Local_f32NUM_OverFlows = (Copy_u32Time/Local_f32OVERflowTime);
	u32 Local_u32NUM_INIOverFlows;
	if((Local_f32NUM_OverFlows -(u32)Local_f32NUM_OverFlows) !=0.0)
	{

		Local_u32NUM_INIOverFlows = (u32)Local_f32NUM_OverFlows+1;
		Local_f32NUM_OverFlows = Local_f32NUM_OverFlows - (u32)Local_f32NUM_OverFlows;
		u8 Local_u8PreLoad = 256 - (Local_f32NUM_OverFlows * 256);
		Global0_u32PreLoad = Local_u8PreLoad;
	}
	else
	{
		Local_u32NUM_INIOverFlows = (u32)Local_f32NUM_OverFlows;
	}
	Global0_u32NUM_INIOverFlows = Local_u32NUM_INIOverFlows;
	if(Copy_PfunApp)
	{
		EXTI0_PFunINIT[0] = Copy_PfunApp;
		EXTI0_PparameterINIT[0] = Copy_vidPParameter;
	}
	else
	{
		Local_enuErrorState = ES_NULLPOINTER;

	}
	TIMSK|=(1<<0);
	return Local_enuErrorState;
}

ES_t TIMER0_enuSetSychDelay(u32 Copy_u32Time)
{
	ES_t Local_enuErrorState = ES_NOK;

	TIMSK&=~(1<<0);
	f32 Local_f32OVERflowTime = (256*((f32)TIMER0_PRES/F_CPU)*1000);
	f32 Local_f32NUM_OverFlows = (Copy_u32Time/Local_f32OVERflowTime);

	if((Local_f32NUM_OverFlows -(u32)Local_f32NUM_OverFlows) !=0.0)
	{

		u32 Local_u32NUM_INIOverFlows = (u32)Local_f32NUM_OverFlows+1;
		Local_f32NUM_OverFlows = Local_f32NUM_OverFlows - (u32)Local_f32NUM_OverFlows;
		u8 Local_u8PreLoad = 256 - (Local_f32NUM_OverFlows * 256);
		TCNT0 = Local_u8PreLoad;
		while(Local_u32NUM_INIOverFlows>0)
		{
			while(((TIFR>>0)&1) == 0);
			TIFR|=(1<<0);
			Local_u32NUM_INIOverFlows--;
		}


	}
	else
	{
		u32 Local_u32NUM_INIOverFlows = (u32)Local_f32NUM_OverFlows;
		while(Local_u32NUM_INIOverFlows>0)
		{
			while(((TIFR>>0)&1) == 0);
			TIFR|=(1<<0);
			Local_u32NUM_INIOverFlows--;
		}
	}



	return Local_enuErrorState;
}

ES_t TIMER0_enuSet_CTC_callback(void (*A_ptr_to_func)(void),void *Copy_vidPParameter)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(A_ptr_to_func)
	{
		EXTI0_PFunINIT[1] = A_ptr_to_func;
		EXTI0_PparameterINIT[1] = Copy_vidPParameter;

	}

	return Local_enuErrorState;
}

ISR(VECT_TIMER0_OVF)
{
	if(EXTI0_PFunINIT[0])
	{
		static u32 Local_u32counts = 0;
		Local_u32counts++;
		if(Local_u32counts == Global0_u32NUM_INIOverFlows)
		{
			TCNT0 = Global0_u32PreLoad;
			EXTI0_PFunINIT[0](EXTI0_PparameterINIT[0]);
			Local_u32counts =0;

		}
	}
}

ISR(VECT_TIMER0_COMP)
{
	if(EXTI0_PFunINIT[1])
	{
		EXTI0_PFunINIT[0](EXTI0_PparameterINIT[1]);
	}
}



/*=================================================TIMER2========================================*/

static void(*EXTI2_PFunINIT[3])(void*) = {NULL,NULL,NULL};
static void*EXTI2_PparameterINIT[3] = {NULL,NULL,NULL};
static u32 Global2_u32PreLoad = 0;
static u32 Global2_u32NUM_INIOverFlows = 0;
ES_t TIMER2_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;
#if  TIMER2_MODE == WGM_NORMAL
	TCCR2 &=~(1<<3);
	TCCR2 &=~(1<<6);

#if COMP_MATCH_OUTPUT2 == COM_NORMAL_PORT
	TCCR2 &=~(1<<4);
	TCCR2 &=~(1<<5);
#elif COMP_MATCH_OUTPUT2 == COM_TOGGEL_OC
	TCCR2 |=(1<<4);
	TCCR2 &=~(1<<5);
#elif COMP_MATCH_OUTPUT2 == COM_CLEAR_OC2
	TCCR2 &=~(1<<4);
	TCCR2 |=(1<<5);
#elif COMP_MATCH_OUTPUT2 == COM_SET_OC
	TCCR2 |=(1<<4);
	TCCR2 |=(1<<5);
#else
#error"NOT CORRECT compare output mode"
#endif


#elif TIMER2_MODE == WGM_CTC
	TCCR2 &=~(1<<6);
	TCCR2 |=(1<<3);
#if COMP_MATCH_OUTPUT2 == COM_NORMAL_PORT
	TCCR2 &=~(1<<4);
	TCCR2 &=~(1<<5);
#elif COMP_MATCH_OUTPUT2 == COM_TOGGEL_OC0
	TCCR2 |=(1<<4);
	TCCR2 &=~(1<<5);
#elif COMP_MATCH_OUTPUT2 == COM_CLEAR_OC0
	TCCR2 &=~(1<<4);
	TCCR2 |=(1<<5);
#elif COMP_MATCH_OUTPUT2 == COM_SET_OC0
	TCCR2 |=(1<<4);
	TCCR2 |=(1<<5);
#else
#error"NOT CORRECT compare output mode"
#endif

#elif TIMER0_MODE == WGM_FAST_PWM
	TCCR2 |=(1<<3);
	TCCR2 |=(1<<6);
#if COMP_MATCH_OUTPUT2 == COM_NORMAL_PORT
	TCCR2 &=~(1<<4);
	TCCR2 &=~(1<<5);
#elif COMP_MATCH_OUTPUT2 == COM_NON_INVERTING
	TCCR2 &=~(1<<4);
	TCCR2 |=(1<<5);
#elif COMP_MATCH_OUTPUT2 == COM_INVERTING
	TCCR2 |=(1<<4);
	TCCR2 |=(1<<5);
#else
#error"NOT CORRECT compare output mode"
#endif

#elif TIMER2_MODE == WGM_PWM_PHCORRECT
	TCCR2 |=(1<<3);
	TCCR2 &=~(1<<6);
#if COMP_MATCH_OUTPUT2 == COM_NORMAL_PORT
	TCCR2 &=~(1<<4);
	TCCR2 &=~(1<<5);
#elif COMP_MATCH_OUTPUT2 == COM_NON_INVERTING
	TCCR2 &=~(1<<4);
	TCCR2 |=(1<<5);
#elif COMP_MATCH_OUTPUT2 == COM_INVERTING
	TCCR2 |=(1<<4);
	TCCR2 |=(1<<5);
#else
#error"NOT CORRECT compare output mode"
#endif

#else
#error"NOT CORRECT Wave Generation Mode"
#endif

#if TIMER2_PRES == NO_CLOCKSOURCE
	TCCR2 |=0;
#elif TIMER2_PRES == NO_PRESC
	TCCR2 |=1;
#elif TIMER2_PRES == PRESC_8
	TCCR2 |=2;
#elif TIMER2_PRES == PRESC_64
	TCCR2 |=3;
#elif TIMER2_PRES == PRESC_256
	TCCR2 |=4;
#elif TIMER2_PRES == PRESC_1024
	TCCR2 |=5;
#elif TIMER2_PRES == EXTCLOCK_FALLINGEDGE
	TCCR2 |=6;
#elif TIMER2_PRES == EXTCLOCK_RISINGEDGE
	TCCR2 |=7;

#else
#error"NOT CORRECT PRESCALING"
#endif
	return Local_enuErrorState;
}

ES_t TIMER2_enuGenerateFastPWM(f32 Copy_f32VolteVAL)
{	ES_t Local_enuErrorState = ES_NOK;
#if TIMER2_MODE == WGM_FAST_PWM || TIMER2_MODE == WGM_PWM_PHCORRECT
#if COMP_MATCH_OUTPUT2 == COM_NON_INVERTING
	OCR2 = (u8)((Copy_f32VolteVAL/5)*(Copy_f32VolteVAL/5)*256);
#elif COMP_MATCH_OUTPUT2 == COM_INVERTING
	 OCR2 = (u8)(255 - ((Copy_f32VolteVAL/5)*(Copy_f32VolteVAL/5)*256));
#else
#error"OC2 has a wrong configuration"
#endif
#endif
	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ES_t TIMER2_enuEnableInterrupt(void)
{	ES_t Local_enuErrorState = ES_NOK;
	TIMSK|=(1<<7);
	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}
ES_t TIMER2_enuDisableInterrupt(void)
{	ES_t Local_enuErrorState = ES_NOK;
	TIMSK&=~(1<<7);
	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ES_t TIMER2_enuSet_PINOCR2_VAL(u8 Copy_u8OCR0_VAL)
{
	ES_t Local_enuErrorState = ES_NOK;
	OCR2 = Copy_u8OCR0_VAL;
	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}
ES_t TIMER2_enuSet_preload(u8 Copy_u8Preload)
{
	ES_t Local_enuErrorState = ES_NOK;
	TCNT2 = Copy_u8Preload;
	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}
ES_t TIMER2_enuSet_AsychDelay(u32 Copy_u32Time,void (*Copy_PfunApp)(void*),void * Copy_vidPParameter)
{
	ES_t Local_enuErrorState = ES_NOK;
	TIMSK&=~(1<<7);
	f32 Local_f32OVERflowTime = (256*((f32)TIMER2_PRES/F_CPU))*1000;
	f32 Local_f32NUM_OverFlows = (Copy_u32Time/Local_f32OVERflowTime);
	u32 Local_u32NUM_INIOverFlows;
	if((Local_f32NUM_OverFlows -(u32)Local_f32NUM_OverFlows) !=0.0)
	{

		Local_u32NUM_INIOverFlows = (u32)Local_f32NUM_OverFlows+1;
		Local_f32NUM_OverFlows = Local_f32NUM_OverFlows - (u32)Local_f32NUM_OverFlows;
		u8 Local_u8PreLoad = 256 - (Local_f32NUM_OverFlows * 256);
		Global2_u32PreLoad = Local_u8PreLoad;
	}
	else
	{
		Local_u32NUM_INIOverFlows = (u32)Local_f32NUM_OverFlows;
	}
	Global2_u32NUM_INIOverFlows = Local_u32NUM_INIOverFlows;
	if(Copy_PfunApp)
	{
		EXTI2_PFunINIT[0] = Copy_PfunApp;
		EXTI2_PparameterINIT[0] = Copy_vidPParameter;
	}
	else
	{
		Local_enuErrorState = ES_NULLPOINTER;

	}
	TIMSK|=(1<<7);
	return Local_enuErrorState;
}

ES_t TIMER2_enuSetSychDelay(u32 Copy_u32Time)
{
	ES_t Local_enuErrorState = ES_NOK;

	TIMSK&=~(1<<7);
	f32 Local_f32OVERflowTime = (256*((f32)TIMER2_PRES/F_CPU)*1000);
	f32 Local_f32NUM_OverFlows = (Copy_u32Time/Local_f32OVERflowTime);

	if((Local_f32NUM_OverFlows -(u32)Local_f32NUM_OverFlows) !=0.0)
	{

		u32 Local_u32NUM_INIOverFlows = (u32)Local_f32NUM_OverFlows+1;
		Local_f32NUM_OverFlows = Local_f32NUM_OverFlows - (u32)Local_f32NUM_OverFlows;
		u8 Local_u8PreLoad = 256 - (Local_f32NUM_OverFlows * 256);
		TCNT2 = Local_u8PreLoad;

		while(Local_u32NUM_INIOverFlows>0)
		{
			while(((TIFR>>6)&1) == 0);
			TIFR|=(1<<6);
			Local_u32NUM_INIOverFlows--;
		}


	}
	else
	{
		u32 Local_u32NUM_INIOverFlows = (u32)Local_f32NUM_OverFlows;
		while(Local_u32NUM_INIOverFlows>0)
		{
			while(((TIFR>>6)&1) == 0);
			TIFR|=(1<<6);
			Local_u32NUM_INIOverFlows--;
		}
	}



	return Local_enuErrorState;
}

ES_t TIMER2_enuSet_CTC_callback(void (*A_ptr_to_func)(void),void *Copy_vidPParameter)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(A_ptr_to_func)
	{
		EXTI2_PFunINIT[1] = A_ptr_to_func;
		EXTI2_PparameterINIT[1] = Copy_vidPParameter;

	}

	return Local_enuErrorState;
}

ISR(VECT_TIMER2_OVF)
{
	if(EXTI2_PFunINIT[0])
	{
		static u32 Local_u32counts = 0;
		Local_u32counts++;
		if(Local_u32counts == Global0_u32NUM_INIOverFlows)
		{
			TCNT2 = Global2_u32PreLoad;
			EXTI2_PFunINIT[0](EXTI2_PparameterINIT[0]);
			Local_u32counts =0;

		}
	}
}

ISR(VECT_TIMER2_COMP)
{
	if(EXTI2_PFunINIT[1])
	{
		EXTI2_PFunINIT[0](EXTI0_PparameterINIT[1]);
	}
}

