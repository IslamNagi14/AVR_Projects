/*
 * ADC_int.h
 *
 *  Created on: Sep 4, 2024
 *      Author: Islam Nagi
 */

#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_

#include"../../LIB/StdTypes.h"
#include"../../LIB/errorStatuse.h"


ES_t ADC_enuINIT(void);

ES_t ADC_enuStartConversion(void);

ES_t ADC_enuPollingSystem(void);

ES_t ADC_enuReadHighVal(u8 *Copy_Pu8Value);

ES_t ADC_enuRead(u16 *Copy_Pu16Value);

ES_t ADC_enuEnableInterrupt();

ES_t ADC_enuDisableInterrupt();

ES_t ADC_enuEnableADC(void);

ES_t ADC_enuDisableADC(void);

ES_t ADC_enuSelectChannel(u8 Copy_u8ChannelID);

ES_t ADC_enuEnableTriggMod(u8 Copy_u8TrigerringSource);

ES_t ADC_enuDisableTriggaringMod(void);
ES_t ADCE_enuCallBack(void (*Copy_PfunAPPfun)(void));
/*===================================================================================================================================*/
#define ADC_PRES_2								2
#define ADC_PRES_4								4
#define ADC_PRES_8								8
#define ADC_PRES_16								16
#define ADC_PRES_32								32
#define ADC_PRES_64								64
#define ADC_PRES_128							128
/*===================================================================================================================================*/
#define ADC_AREF_REF							33
#define ADC_AVCC_REF							5
#define ADC_INTERNAL_REF						256
/*===================================================================================================================================*/
#define ADC_CHANNEL_0							22
#define ADC_CHANNEL_1	   						1
#define ADC_CHANNEL_2							2
#define ADC_CHANNEL_3	 						3
#define ADC_CHANNEL_4							4
#define ADC_CHANNEL_5							5
#define ADC_CHANNEL_6							6
#define ADC_CHANNEL_7							7
/*===================================================================================================================================*/
#define ADC_RIGHT_ADJ							45
#define ADC_LEFT_ADJ							11
/*===================================================================================================================================*/
#define ADC_FREE_RUNNING						12
#define ADC_ANALOG_COMPARATOR					45
#define ADC_EXTERNAL_INTERRUPT0					56
#define ADC_TIMER_COUNTER0_Compare_Match		23
#define ADC_TIMER_COUNTER0_OVERFLOW				51
#define ADC_TIMER_COUNTER1_Compare_Match_B		28
#define ADC_TIMER_COUNTER1_OVERFLOW				9
#define ADC_TIMER_COUNTER1_CAPTURE_EVENT		4
#endif /* MCAL_ADC_ADC_INT_H_ */
