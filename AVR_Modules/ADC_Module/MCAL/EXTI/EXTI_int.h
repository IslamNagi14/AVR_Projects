/*
 * EXTI_int.h
 *
 *  Created on: Sep 22, 2024
 *      Author: Islam Nagi
 */

#ifndef EXTI_INT_H_
#define EXTI_INT_H_

#include"../../LIB/StdTypes.h"
#include"../../LIB/errorStatuse.h"
#include"EXTI_Config.h"

ES_t EXTI_enuINIT(EXTI_t * Copy_PAryOFINT);
ES_t EXTI_enuSetSenseLevel(u8 Copy_u8INT_ID,u8 Copy_u8State);
ES_t EXTI_enuEnableEXINT(u8 Copy_u8INT_ID);
ES_t EXTI_enuDisableEXINT(u8 Copy_u8INT_ID);
ES_t EXTI_enuCallBack(void * Copy_PvidFun,void * Copy_enuPvidPara,u8 Copy_u8INT_ID);

#define EXTI_u8ACTIVE				10
#define EXTI_u8DEACTIVE				45

#define EXTI_u8FALLINGEDGE			56
#define EXTI_u8RISINGEDGE			12
#define EXTI_u8LOWLEVEL				20
#define EXTI_u8ANY_LOGIC_CHANGE		89


#endif /* EXTI_INT_H_ */
