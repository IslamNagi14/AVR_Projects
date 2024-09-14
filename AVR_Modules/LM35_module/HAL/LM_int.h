/*
 * LM_int.h
 *
 *  Created on: Sep 7, 2024
 *      Author: Islam Nagi
 */

#ifndef LM_INT_H_
#define LM_INT_H_

#include"../LIB/StdTypes.h"
#include"../LIB/errorStatuse.h"


ES_t LM_enuINIT(LM_t *Copy_StrA_LM);
ES_t LM_enuGetTemp(u8 Copy_u16Channelnum,f32*Copy_f32Temp);



#endif /* LM_INT_H_ */
