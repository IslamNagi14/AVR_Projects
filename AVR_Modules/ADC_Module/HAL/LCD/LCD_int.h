/*
 * LCD_int.h
 *
 *  Created on: Aug 31, 2024
 *      Author: Islam Nagi
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_


#include "../../LIB/StdTypes.h"
#include "../../LIB/errorStatuse.h"

ES_t LCD_enuINIT(void);
ES_t LCD_enuSndComnd(u8 Copy_u8Commnd);
ES_t LCD_enuDispChar(u8 Copy_u8Char);

#endif /* LCD_INT_H_ */
