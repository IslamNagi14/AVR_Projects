/*
 * LED_int.h
 *
 *  Created on: Aug 25, 2024
 *      Author: Islam Nagi
 */

#ifndef LED_INT_H_
#define LED_INT_H_

#include"errorStatuse.h"
#include"StdTypes.h"

ES_t LED_enuINIT(LED_t *Copy_AStr_LEDs);
ES_t LED_enuSETUP(LED_t *Copy_StrLED,LED_t Copy_StrINFO);

ES_t LED_enuSetState(LED_t *Copy_A_LED,u8 Copy_u8Led_SVal);
//ES_t LED_enuGetState(LED_t *Copy_A_LED,u8 *Copy_u8Led_State);

#endif /* LED_INT_H_ */
