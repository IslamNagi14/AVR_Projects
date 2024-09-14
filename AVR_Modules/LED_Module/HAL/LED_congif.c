/*
 * LED_congif.c
 *
 *  Created on: Aug 25, 2024
 *      Author: Islam Nagi
 */

#include "../LIB/StdTypes.h"
#include "../LIB/errorStatuse.h"
#include "LED_config.h"
#include "../MCAL/DIO_int.h"
#include "../MCAL/DIO_config.h"
#include "LED_int.h"
LED_t LEDsARR[LED_NUMBER] =
{
		{DIO_u8PORTA,DIO_u8PIN2,LED_u8SINK,LED_u8ON},
		{DIO_u8PORTB,DIO_u8PIN4,LED_u8SOURCE,LED_u8OFF},
		{DIO_u8PORTC,DIO_u8PIN1,LED_u8SINK,LED_u8ON}
};
