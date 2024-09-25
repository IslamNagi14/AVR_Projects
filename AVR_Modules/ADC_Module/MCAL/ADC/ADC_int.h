/*
 * ADC_int.h
 *
 *  Created on: Sep 24, 2024
 *      Author: Islam Nagi
 */

#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_

#include"../../LIB/StdTypes.h"
#include"../../LIB/errorStatuse.h"

ES_t ADC_enuINIT(void);
ES_t ADC_enuSetRefVoltage(u8 Copy_u8SelectedVolt);
ES_t ADC_enuSetAdjust(u8 Copy_u8SelectedADJ);
ES_t ADC_enuSelectChannel(u8 Copy_u8SelectedChannel);
ES_t ADC_enuRead(u16 *Copy_Pu16Value);
ES_t ADC_enuReadHIGHvalue(u8 *Copy_Pu8Value);
ES_t ADC_enuPollingConv(void);
ES_t ADC_enuEnableADC(void);
ES_t ADC_enuDisableADC(void);
ES_t ADC_enuStartConversion(void);
ES_t ADC_enuEnableINT(void);
ES_t ADC_enuDisableINT(void);
ES_t ADC_enuSetPrescaler(u8 Copy_u8SelectedPres);
ES_t ADC_enuDisableAutoTriggeringMode();
ES_t ADC_enuEnsableAutoTriggeringMode(u8 Copy_u8SelectedMode);

ES_t ADC_enuCallBackFUN(void (*Copy_PvidFUN)(void*),void *Copy_PvidPara);


#define ADC_AVCC			45
#define ADC_AREF			96
#define ADC_INTERNAL_REF	34

#define ADC_LEFT_ADJUST		1
#define ADC_RIGHT_ADJUST	0

#define ADC_u8Channel0			0
#define ADC_u8Channel1			1
#define ADC_u8Channel2			2
#define ADC_u8Channel3			3
#define ADC_u8Channel4			4
#define ADC_u8Channel5			5
#define ADC_u8Channel6			6
#define ADC_u8Channel7		    7


#define ADC_PRES_2			2
#define ADC_PRES_4			4
#define ADC_PRES_8			8
#define ADC_PRES_16			16
#define ADC_PRES_32			32
#define ADC_PRES_64			64
#define ADC_PRES_128		128

#define ADC_FREE_RUNNING					0
#define ADC_Analog_Comparator				1
#define ADC_External_Interrupt_Request_0	2
#define ADC_Timer_Counter0_Compare_Match	3
#define ADC_Timer_Counter0_Overflow			4
#define ADC_Timer_Counter1_Compare_Match_B	5
#define ADC_Timer_Counter1_Overflow			6
#define ADC_Timer_Counter1_Capture_Event	7
#endif /* MCAL_ADC_ADC_INT_H_ */
