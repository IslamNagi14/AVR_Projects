/*
 * main.c
 *
 *  Created on: Aug 26, 2024
 *      Author: Islam Nagi
 */

#include"../LIB/StdTypes.h"
#include"../LIB/errorStatuse.h"
#include"../MCAL/DIO_int.h"
#include"../HAL/SE7SEG_Config.h"
#include"../HAL/SE7SEG_int.h"
#include<util/delay.h>

int main()
{
	extern SE7SEG_t AStr_SE7SEG[SE7SEG_u8NUMBER];
	SETUP_t SE7Seg_0[SE7Pin_u8NUMBER] = {
			{DIO_u8PORTA,DIO_u8PIN0},
			{DIO_u8PORTA,DIO_u8PIN1},
			{DIO_u8PORTA,DIO_u8PIN2},
			{DIO_u8PORTA,DIO_u8PIN3},
			{DIO_u8PORTA,DIO_u8PIN4},
			{DIO_u8PORTA,DIO_u8PIN5},
			{DIO_u8PORTA,DIO_u8PIN6}
	};
	SETUP_t SE7Seg_1[SE7Pin_u8NUMBER] = {
				{DIO_u8PORTA,DIO_u8PIN0},
				{DIO_u8PORTA,DIO_u8PIN1},
				{DIO_u8PORTA,DIO_u8PIN2},
				{DIO_u8PORTA,DIO_u8PIN3},
				{DIO_u8PORTA,DIO_u8PIN4},
				{DIO_u8PORTA,DIO_u8PIN5},
				{DIO_u8PORTA,DIO_u8PIN6}
		};

	SETUP_t SE7Seg_Epin_0 = {DIO_u8PORTA,DIO_u8PIN7};
	SETUP_t SE7Seg_DOT0 = {DIO_u8PORTB,DIO_u8PIN0};
	DIO_enuInit();
	SE7SEG_enuINIT(AStr_SE7SEG);
	SE7SEG_enuSetUPSE7Seg(&AStr_SE7SEG[0],SE7Seg_0,SE7SEG_u8CAnod);
	SE7SEG_enuSetUPSE7Seg(&AStr_SE7SEG[1],SE7Seg_1,SE7SEG_u8Ccath);

	SE7SEG_enuDisableSE7Seg(&AStr_SE7SEG[0],SE7Seg_Epin_0);
	//SE7SEG_enuDisableSE7Seg(&AStr_SE7SEG[1],SE7Seg_Epin_1);
	while(1)
	{

				SE7SEG_enuSetSE7SegVal(&AStr_SE7SEG[0],5+2);
				SE7SEG_enuEnableSE7Seg(&AStr_SE7SEG[0],SE7Seg_Epin_0);
				SE7SEG_enuSetDOTSE7Seg(&AStr_SE7SEG[0],SE7Seg_DOT0,SE7SEG_u8TurnOn);
				_delay_ms(1000);
				SE7SEG_enuClearSE7Seg(&AStr_SE7SEG[0]);
				SE7SEG_enuSetDOTSE7Seg(&AStr_SE7SEG[0],SE7Seg_DOT0,SE7SEG_u8TurnOff);
				_delay_ms(500);
				SE7SEG_enuSetSE7SegVal(&AStr_SE7SEG[0],14-11);
				_delay_ms(1000);




	}
}
