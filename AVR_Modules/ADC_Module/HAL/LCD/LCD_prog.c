/*
 * LCD_prog.c
 *
 *  Created on: Aug 31, 2024
 *      Author: Islam Nagi
 */



#include "../../LIB/StdTypes.h"
#include "../../LIB/errorStatuse.h"

#include"LCD_private.h"
#include"LCD_Config.h"
#include"../../MCAL/DIO/DIO_int.h"


#include<util/delay.h>

ES_t LCD_enuINIT(void)
{
	//ES_t Local_enuErrorState = ES_NOK;
	_delay_ms(40);
	DIO_enuSetPINDir(EN_Port,EN_Pin,DIO_OUTPUT);
	DIO_enuSetPINDir(RS_Port,RS_Pin,DIO_OUTPUT);
	DIO_enuSetPINDir(RW_Port,RW_Pin,DIO_OUTPUT);
	DIO_enuSetPINDir(DB4_Port,DB4_Pin,DIO_OUTPUT);
	DIO_enuSetPINDir(DB5_Port,DB5_Pin,DIO_OUTPUT);
	DIO_enuSetPINDir(DB6_Port,DB6_Pin,DIO_OUTPUT);
	DIO_enuSetPINDir(DB7_Port,DB7_Pin,DIO_OUTPUT);

#if LCDMODE == EIGHTMODE
	DIO_enuSetPINDir(DB0_Port,DB0_Pin,DIO_OUTPUT);
	DIO_enuSetPINDir(DB1_Port,DB1_Pin,DIO_OUTPUT);
	DIO_enuSetPINDir(DB2_Port,DB2_Pin,DIO_OUTPUT);
	DIO_enuSetPINDir(DB3_Port,DB3_Pin,DIO_OUTPUT);
#endif
	DIO_enuSetPINVAL(RS_Port,RS_Pin,DIO_LOW);
	LCD_VidDOPRVTask(SETFUN);
	_delay_ms(1);
	LCD_VidDOPRVTask(DISPON_OFF);
		_delay_ms(1);
		LCD_VidDOPRVTask(DISP_CLEAR);
	_delay_ms(1.5);
	LCD_VidDOPRVTask(ENTRYSET);

	return 0;//Local_enuErrorState;
}

static inline void LCD_VidDOPRVTask(u8 Copy_u8Commnd)
{

		DIO_enuSetPINVAL(EN_Port,EN_Pin,DIO_LOW);
		DIO_enuSetPINVAL(RW_Port,RW_Pin,DIO_LOW);
		DIO_enuSetPINVAL(DB4_Port,DB4_Pin,(Copy_u8Commnd>>4)&1);
		DIO_enuSetPINVAL(DB5_Port,DB5_Pin,(Copy_u8Commnd>>5)&1);
		DIO_enuSetPINVAL(DB6_Port,DB6_Pin,(Copy_u8Commnd>>6)&1);
		DIO_enuSetPINVAL(DB7_Port,DB7_Pin,(Copy_u8Commnd>>7)&1);
		DIO_enuSetPINVAL(DB0_Port,DB0_Pin,(Copy_u8Commnd>>0)&1);
		DIO_enuSetPINVAL(DB1_Port,DB1_Pin,(Copy_u8Commnd>>1)&1);
		DIO_enuSetPINVAL(DB2_Port,DB2_Pin,(Copy_u8Commnd>>2)&1);
		DIO_enuSetPINVAL(DB3_Port,DB3_Pin,(Copy_u8Commnd>>3)&1);
		DIO_enuSetPINVAL(EN_Port,EN_Pin,DIO_HIGH);
		_delay_ms(10);
		DIO_enuSetPINVAL(EN_Port,EN_Pin,DIO_LOW);


}


ES_t LCD_enuSndComnd(u8 Copy_u8Commnd)
{
	ES_t Local_enuErrorState = ES_NOK;
	DIO_enuSetPINVAL(EN_Port,EN_Pin,DIO_LOW);
	DIO_enuSetPINVAL(RS_Port,RS_Pin,DIO_LOW);
	DIO_enuSetPINVAL(RW_Port,RW_Pin,DIO_LOW);
	DIO_enuSetPINVAL(DB4_Port,DB4_Pin,(Copy_u8Commnd>>4)&1);
	DIO_enuSetPINVAL(DB5_Port,DB5_Pin,(Copy_u8Commnd>>5)&1);
	DIO_enuSetPINVAL(DB6_Port,DB6_Pin,(Copy_u8Commnd>>6)&1);
	DIO_enuSetPINVAL(DB7_Port,DB7_Pin,(Copy_u8Commnd>>7)&1);
	DIO_enuSetPINVAL(DB0_Port,DB0_Pin,(Copy_u8Commnd>>0)&1);
	DIO_enuSetPINVAL(DB1_Port,DB1_Pin,(Copy_u8Commnd>>1)&1);
	DIO_enuSetPINVAL(DB2_Port,DB2_Pin,(Copy_u8Commnd>>2)&1);
	DIO_enuSetPINVAL(DB3_Port,DB3_Pin,(Copy_u8Commnd>>3)&1);
	DIO_enuSetPINVAL(EN_Port,EN_Pin,DIO_HIGH);
	_delay_ms(10);
	DIO_enuSetPINVAL(EN_Port,EN_Pin,DIO_LOW);


	return Local_enuErrorState;
}
ES_t LCD_enuDispChar(u8 Copy_u8Char)
{
	ES_t Local_enuErrorState = ES_NOK;

	DIO_enuSetPINVAL(RS_Port,RS_Pin,DIO_HIGH);
	LCD_VidDOPRVTask(Copy_u8Char);
	return Local_enuErrorState;
}
