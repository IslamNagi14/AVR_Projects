/*
 * SW_Config.c
 *
 *  Created on: Aug 28, 2024
 *      Author: Islam Nagi
 */

#include"../../LIB/errorStatuse.h"
#include"../../LIB/StdTypes.h"

#include"SW_Config.h"

#include"../../MCAL/DIO_int.h"

SW_t Switches[SW_u8SwNUMS] =
{
		{DIO_u8PORTA,DIO_u8PIN0,DIO_FLOAT},
		{DIO_u8PORTA,DIO_u8PIN1,DIO_FLOAT},
		{DIO_u8PORTA,DIO_u8PIN5,DIO_FLOAT}
};
