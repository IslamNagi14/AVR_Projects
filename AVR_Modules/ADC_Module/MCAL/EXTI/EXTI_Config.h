/*
 * EXTI_Config.h
 *
 *  Created on: Sep 22, 2024
 *      Author: Islam Nagi
 */

#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

#include"../../LIB/errorStatuse.h"
#include"../../LIB/StdTypes.h"
typedef struct
{
	u8 State;
	u8 SenseLevel;
}EXTI_t;

#define INT_NUMBERS			3

#endif /* EXTI_CONFIG_H_ */
