/*
 * TIME_int.h
 *
 *  Created on: Sep 8, 2024
 *      Author: Islam Nagi
 */

#ifndef MCAL_TIMER_TIME_INT_H_
#define MCAL_TIMER_TIME_INT_H_

#include"../../LIB/StdTypes.h"
#include"../../LIB/errorStatuse.h"


ES_t TIMER0_enuInit(void);
ES_t TIMER0_enuSet_PINOCR0_VAL(u8 Copy_u8OCR0_VAL);
ES_t TIMER0_enuSet_preload(u8 Copy_u8Preload);
ES_t TIMER0_enuSet_AsychDelay(u32 Copy_u32Time,void (*Copy_PfunApp)(void*),void*);
ES_t TIMER0_enuSet_CTC_callback(void (*A_ptr_to_func)(void),void *);
ES_t TIMER0_enuSetSychDelay(u32 Copy_u32Time);
ES_t TIMER0_enuDisableInterrupt(void);
ES_t TIMER0_enuEnableInterrupt(void);
ES_t TIMER0_enuGeneratePWM(f32 Copy_f32VolteVAL);

ES_t TIMER2_enuInit(void);
ES_t TIMER2_enuGeneratePWM(f32 Copy_f32VolteVAL);
ES_t TIMER2_enuEnableInterrupt(void);
ES_t TIMER2_enuDisableInterrupt(void);
ES_t TIMER2_enuSet_PINOCR2_VAL(u8 Copy_u8OCR0_VAL);
ES_t TIMER2_enuSet_preload(u8 Copy_u8Preload);
ES_t TIMER2_enuSet_AsychDelay(u32 Copy_u32Time,void (*Copy_PfunApp)(void*),void * Copy_vidPParameter);
ES_t TIMER2_enuSetSychDelay(u32 Copy_u32Time);
ES_t TIMER2_enuSet_CTC_callback(void (*A_ptr_to_func)(void),void *Copy_vidPParameter);
/*
ES_t TIMER_enuStop_timer(void);
ES_t MTIMER1_init_FAST_PWM(void);
ES_t MTIMER1_voidSet_OCR1A_value(u16 A_OCR0_value);
ES_t MTIMER1_voidSet_OVF_callback(void (*A_ptr_to_func)(void));
ES_t MTIMER1_voidSet_ICU_callback(void (*A_ptr_to_func)(void));
ES_t MTIMER1_init_ICU();*/

/*             Waveform Generation Mode                                 */
#define TIM_WGM_NORMAL				0
#define TIM_WGM_PWM_PHCORRECT		1
#define TIM_WGM_CTC					2
#define TIM_WGM_FAST_PWM			3
/*==================================================================*/

/*             Compare Output Mode_nonPWM                                  */
#define TIM_COM_NORMAL_PORT			0
#define TIM_COM_TOGGEL_OC			1
#define TIM_COM_CLEAR_OC			2
#define TIM_COM_SET_OC				3
/*==================================================================*/

/*             Compare Output Mode_FASTPWM                                  */
#define TIM_COM_NORMAL_PORT			0
#define TIM_COM_NON_INVERTING		2
#define TIM_COM_INVERTING			3
/*==================================================================*/

/*             Compare Output Mode_PHCORRECTPWM                                  */
#define TIM_COM_NORMAL_PORT			0
#define TIM_COM_NON_INVERTING		2
#define TIM_COM_INVERTING			3
/*==================================================================*/

#define TIM_NO_CLOCKSOURCE			0
#define TIM_NO_PRESC				1
#define TIM_PRESC_8					8
#define TIM_PRESC_64				64
#define TIM_PRESC_256				256
#define TIM_PRESC_1024				1024
#define TIM_EXTCLOCK_FALLINGEDGE	6
#define TIM_EXTCLOCK_RISINGEDGE		7


#endif /* MCAL_TIMER_TIME_INT_H_ */
