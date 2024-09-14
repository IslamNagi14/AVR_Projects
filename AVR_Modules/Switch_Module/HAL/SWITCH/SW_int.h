/*
 * SE_int.h
 *
 *  Created on: Aug 28, 2024
 *      Author: Islam Nagi
 */

#ifndef SW_INT_H_
#define SW_INT_H_

#include"../../LIB/errorStatuse.h"
#include"../../LIB/StdTypes.h"

ES_t SW_enuINIT(SW_t * Copy_enuSWITCHs);
ES_t SW_enuSETUP(SW_t *Copy_StrSWITCH,SW_t Copy_StrINFO);
ES_t SW_enuGetState(SW_t *Copy_StrSWITCH,u8 *Copy_u8SWVal);
ES_t SW_enuSetSWConnection();




#endif /* SW_INT_H_ */
