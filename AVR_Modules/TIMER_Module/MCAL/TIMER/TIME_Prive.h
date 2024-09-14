/*
 * TIME_Prive.h
 *
 *  Created on: Sep 8, 2024
 *      Author: Islam Nagi
 */

#ifndef MCAL_TIMER_TIME_PRIVE_H_
#define MCAL_TIMER_TIME_PRIVE_H_

#include"../../LIB/StdTypes.h"
#include"../../LIB/errorStatuse.h"
/*TCCR*/
#define TCCR0  			*(volatile u8*)0x53
#define TCCR1A  		*(volatile u8*)0x4F
#define TCCR1B 			*(volatile u8*)0x5E
#define TCCR2 			*(volatile u8*)0x45


/*TCNT*/
#define TCNT0  			*(volatile u8*)0x52
#define TCNT1H  		*(volatile u8*)0x4d
#define TCNT1L 			*(volatile u8*)0x4c
#define TCNT1  			*(volatile u16*)0x4c
#define TCNT2  			*(volatile u8*)0x44


/*OCR*/
#define OCR0  			*(volatile u8*)0x5C

#define OCR1AH  		*(volatile u8*)0x4B
#define OCR1AL	 		*(volatile u8*)0x4A

#define OCR1A  			*(volatile u16*)0x4A

#define OCR1BH 			*(volatile u8*)0x49
#define OCR1BL			*(volatile u8*)0x48

#define OCR1B			*(volatile u16*)0x48

#define OCR2 			*(volatile u8*)0x43


/*TIMSK*/
#define TIMSK  			*(volatile u8*)0x59


/*TIFR*/
#define TIFR			*(volatile u8*)0x58


/*             Waveform Generation Mode                                 */
#define WGM_NORMAL				0
#define WGM_PWM_PHCORRECT		1
#define WGM_CTC					2
#define WGM_FAST_PWM			3
/*==================================================================*/

/*             Compare Output Mode_nonPWM                                  */
#define COM_NORMAL_PORT			0
#define COM_TOGGEL_OC			1
#define COM_CLEAR_OC			2
#define COM_SET_OC				3
/*==================================================================*/

/*             Compare Output Mode_FASTPWM                                  */
#define COM_NORMAL_PORT			0
#define COM_NON_INVERTING		2
#define COM_INVERTING			3
/*==================================================================*/

/*             Compare Output Mode_PHCORRECTPWM                                  */
#define COM_NORMAL_PORT			0
#define COM_NON_INVERTING		2
#define COM_INVERTING			3
/*==================================================================*/

#define NO_CLOCKSOURCE			0
#define NO_PRESC				1
#define PRESC_8					8
#define PRESC_64				64
#define PRESC_256				256
#define PRESC_1024				1024
#define EXTCLOCK_FALLINGEDGE	6
#define EXTCLOCK_RISINGEDGE		7




#endif /* MCAL_TIMER_TIME_PRIVE_H_ */
