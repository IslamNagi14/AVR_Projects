/*
 * LM_Config.c
 *
 *  Created on: Sep 7, 2024
 *      Author: Islam Nagi
 */
#include"../LIB/StdTypes.h"
#include"../LIB/errorStatuse.h"

#include"../MCAL/DIO/DIO_int.h"

#include"LM_Config.h"

LM_t LM_Astr[NUMBER_LM] =
{
		{DIO_u8PIN0},
		{DIO_u8PIN2},
		{DIO_u8PIN4},
		{DIO_u8PIN6},
};
