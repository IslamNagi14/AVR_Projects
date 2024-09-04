/*
 * EXTI_Priv.h
 *
 *  Created on: Sep 2, 2024
 *      Author: Islam Nagi
 */

#ifndef EXTI_PRIV_H_
#define EXTI_PRIV_H_
#include"../../LIB/errorStatuse.h"
#include"../../LIB/StdTypes.h"

#define MCUCR				*((volatile u8*)0x55)
#define MCUCSR				*((volatile u8*)0x54)
#define GICR				*((volatile u8*)0x5B)
#define GIFR				*((volatile u8*)0x5A)

#define ACTIVE				1
#define DEACTIVE			0

#define FALLING_EDGE		0
#define RISING_EDGE			1
#define LOW_LEVEL			2
#define ANY_LOGICAL_CHANGE	3


#endif /* EXTI_PRIV_H_ */
