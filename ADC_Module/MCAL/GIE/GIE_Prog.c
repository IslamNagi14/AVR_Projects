/*
 * GIE_Prog.c
 *
 *  Created on: Sep 3, 2024
 *      Author: Islam Nagi
 */

#include"../../LIB/StdTypes.h"
#include"../../LIB/errorStatuse.h"
#include"GIE_Priv.h"

ES_t GIE_enuEnable(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	  SREG|=(1<<7);

	return Local_enuErrorState;
}

ES_t GIE_enuDisable(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	SREG&=~(1<<7);

	return Local_enuErrorState;
}

