/*
 * TIME_Config.h
 *
 *  Created on: Sep 8, 2024
 *      Author: Islam Nagi
 */

#ifndef MCAL_TIMER_TIME_CONFIG_H_
#define MCAL_TIMER_TIME_CONFIG_H_

#include"../../LIB/StdTypes.h"
#include"../../LIB/errorStatuse.h"
#include"TIME_int.h"

/*=================================================TIMER0========================================*/
#define TIMER0_MODE     		TIM_WGM_NORMAL

#define COMP_MATCH_OUTPUT0		TIM_COM_NORMAL_PORT

#define TIMER0_PRES			 	TIM_PRESC_1024
/*=================================================TIMER2========================================*/
#define TIMER2_MODE     		TIM_WGM_PWM_PHCORRECT

#define COMP_MATCH_OUTPUT2		TIM_COM_NON_INVERTING

#define TIMER2_PRES			 	TIM_PRESC_1024




#endif /* MCAL_TIMER_TIME_CONFIG_H_ */
