/*
 * ADC_Priv.h
 *
 *  Created on: Sep 4, 2024
 *      Author: Islam Nagi
 */

#ifndef MCAL_ADC_ADC_PRIV_H_
#define MCAL_ADC_ADC_PRIV_H_


#define ADMUX			(*(u8*)0X27)

#define ADCSRA			(*(u8*)0X26)

#define SFIOR			(*(u8*)0X50)

#define ADCH			(*(volatile u8*)0X27)

#define ADCL			(*(volatile u8*)0X27)
        /*===================================================================================================================================*/
#define PRES_2			2
#define PRES_4			4
#define PRES_8			8
#define PRES_16			16
#define PRES_32			32
#define PRES_64			64
#define PRES_128		128
           /*===================================================================================================================================*/
#define AREF_REF		33
#define AVCC_REF		5
#define INTERNAL_REF	256
           /*===================================================================================================================================*/
#define CHANNEL_0	0
#define CHANNEL_1	1
#define CHANNEL_2	2
#define CHANNEL_3	3
#define CHANNEL_4	4
#define CHANNEL_5	5
#define CHANNEL_6	6
#define CHANNEL_7	7
             /*===================================================================================================================================*/
#define RIGHT_ADJ		45
#define LEFT_ADJ		11

             /*===================================================================================================================================*/
#define FREE_RUNNING						12
#define ANALOG_COMPARATOR					45
#define EXTERNAL_INTERRUPT0					56
#define TIMER_COUNTER0_Compare_Match		23
#define TIMER_COUNTER0_OVERFLOW				51
#define TIMER_COUNTER1_Compare_Match_B		28
#define TIMER_COUNTER1_OVERFLOW				9
#define TIMER_COUNTER1_CAPTURE_EVENT		4














#endif /* MCAL_ADC_ADC_PRIV_H_ */
