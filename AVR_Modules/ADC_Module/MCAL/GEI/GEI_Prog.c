/*
 * GEI_Prog.c
 *
 *  Created on: Sep 24, 2024
 *      Author: Islam Nagi
 */

#include"../../LIB/StdTypes.h"
#include"../../LIB/errorStatuse.h"
#include"GEI_Prive.h"
ES_t GEI_enuEnableGINT(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	SREG|=(1<<7);
	return Local_enuErrorState;
}
ES_t GEI_enuDisableGINT(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	SREG|=(1<<7);
	return Local_enuErrorState;
}
