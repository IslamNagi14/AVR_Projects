/*
 * ADC_Prive.h
 *
 *  Created on: Sep 24, 2024
 *      Author: Islam Nagi
 */

#ifndef MCAL_ADC_ADC_PRIVE_H_
#define MCAL_ADC_ADC_PRIVE_H_


#define ADCL		*((volatile u8*)0x24)
#define ADCH		*((volatile u8*)0x25)
#define	ADCSRA		*((volatile u8*)0x26)
#define	ADMUX		*((volatile u8*)0x27)
#define	SFIOR		*((volatile u8*)0x50)



/*									ADMUX PINS										*/
#define MUX0			0
#define MUX1			1
#define MUX2			2
#define MUX3			3
#define MUX4			4
#define ADLAR			5
#define REFS0			6
#define REFS1			7
/*									ADCSRA PINS										*/
#define ADPS0			0
#define ADPS1			1
#define ADPS2			2
#define ADIE			3
#define ADIF			4
#define ADATE			5
#define ADSC			6
#define ADEN			7

/*									SFIOR PINS										*/
#define ADTS2			7
#define ADTS1			6
#define ADTS0			5


#define AVCC			45
#define AREF			96
#define INTERNAL_REF	34

#define LEFT_ADJUST		1
#define RIGHT_ADJUST	0

#define Channel0			0
#define Channel1			1
#define Channel2			2
#define Channel3			3
#define Channel4			4
#define Channel5			5
#define Channel6			6
#define Channel7		    7

#define PRES_2			2
#define PRES_4			4
#define PRES_8			8
#define PRES_16			16
#define PRES_32			32
#define PRES_64			64
#define PRES_128		128


#define FREE_RUNNING					0
#define Analog_Comparator				1
#define External_Interrupt_Request_0	2
#define Timer_Counter0_Compare_Match	3
#define Timer_Counter0_Overflow			4
#define Timer_Counter1_Compare_Match_B	5
#define Timer_Counter1_Overflow			6
#define Timer_Counter1_Capture_Event	7


#endif /* MCAL_ADC_ADC_PRIVE_H_ */
