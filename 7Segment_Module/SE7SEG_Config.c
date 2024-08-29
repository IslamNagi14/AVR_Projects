/*
 * 7SEG_Config.c
 *
 *  Created on: Aug 26, 2024
 *      Author: Islam Nagi
 */
#include"StdTypes.h"
#include"errorStatuse.h"
#include"DIO_int.h"
#include"SE7SEG_Config.h"


SE7SEG_t AStr_SE7SEG[SE7SEG_u8NUMBER]=
{
		{
				{
						{DIO_u8PORTA,DIO_u8PIN0},
						{DIO_u8PORTA,DIO_u8PIN1},
						{DIO_u8PORTA,DIO_u8PIN2},
						{DIO_u8PORTA,DIO_u8PIN3},
						{DIO_u8PORTA,DIO_u8PIN4},
						{DIO_u8PORTA,DIO_u8PIN5},
						{DIO_u8PORTA,DIO_u8PIN6}
				},
				SE7SEG_u8CAnod
		},
		{
				{
						{DIO_u8PORTA,DIO_u8PIN0},
						{DIO_u8PORTA,DIO_u8PIN1},
						{DIO_u8PORTA,DIO_u8PIN2},
						{DIO_u8PORTA,DIO_u8PIN3},
						{DIO_u8PORTA,DIO_u8PIN4},
						{DIO_u8PORTA,DIO_u8PIN5},
						{DIO_u8PORTA,DIO_u8PIN6}
				},
				SE7SEG_u8CAnod
		}
};
