/*
 * EXTI_Int.h
 *
 *  Created on: Sep 2, 2024
 *      Author: Islam Nagi
 */

#ifndef EXTI_INT_H_
#define EXTI_INT_H_

#include"../../LIB/errorStatuse.h"
#include"../../LIB/StdTypes.h"

ES_t EXTI_enuInit(EXTI_t * Copy_pstrEXTIConfig);
ES_t EXTI_enuSetSenceMode(u8 Copy_u8EXTI_ID, u8 Copy_u8SenceLevel);
ES_t EXTI_enuEnableINT(u8 Copy_u8EXTI_ID);
ES_t EXTI_enuDisableINT(u8 Copy_u8EXTI_ID);

ES_t EXTI_enuCallBackF(void(*Copy_PFunApp)(void),u8 Copy_u8EXTI_ID);

#endif /* EXTI_INT_H_ */
