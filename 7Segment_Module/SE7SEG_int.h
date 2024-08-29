/*
 * SE7SEG_int.h
 *
 *  Created on: Aug 26, 2024
 *      Author: Islam Nagi
 */

#ifndef SE7SEG_INT_H_
#define SE7SEG_INT_H_
#include"StdTypes.h"
#include "errorStatuse.h"

ES_t SE7SEG_enuINIT(SE7SEG_t *Copy_AStr_SE7SEG);
ES_t SE7SEG_enuSetSE7SegVal(SE7SEG_t *Copy_SE7SEG,u8 Copy_u8ValSE7);
ES_t SE7SEG_enuSetUPSE7Seg(SE7SEG_t *Copy_SE7SEG,SETUP_t * SegSetUP,u8 Copy_u8CONECTSE7);
ES_t SE7SEG_enuEnableSE7Seg(SE7SEG_t *Copy_SE7SEG,SETUP_t  Copy_pstr_EnPIN);
ES_t SE7SEG_enuDisableSE7Seg(SE7SEG_t *Copy_SE7SEG,SETUP_t  Copy_pstr_EnPIN);
ES_t SE7SEG_enuSetDOTSE7Seg(SE7SEG_t *Copy_SE7SEG,SETUP_t  Copy_pstr_EnPIN,u8 Copy_u8STATESE7);
ES_t SE7SEG_enuClearSE7Seg(SE7SEG_t *Copy_SE7SEG);
ES_t SE7SEG_enuSetPin(SE7SEG_t *Copy_SE7SEG,u8 Copy_u8PortSE7,u8 Copy_u8PinSE7,u8 Copy_u8STATESE7);



#endif /* SE7SEG_INT_H_ */
