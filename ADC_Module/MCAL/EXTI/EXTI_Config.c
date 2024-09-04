/*
 * EXTI_Config.c
 *
 *  Created on: Sep 2, 2024
 *      Author: Islam Nagi
 */

#include"../../LIB/errorStatuse.h"
#include"../../LIB/StdTypes.h"
#include"EXTI_Config.h"
#include"EXTI_Priv.h"
EXTI_t EXTI_AstrEXTConfig[3] =
{
		{ACTIVE,RISING_EDGE},
		{DEACTIVE},
		{DEACTIVE}
};

