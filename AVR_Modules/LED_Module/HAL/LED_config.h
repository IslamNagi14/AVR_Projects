/*
 * LED_config.h
 *
 *  Created on: Aug 25, 2024
 *      Author: Islam Nagi
 */

#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_
#include "../LIB/StdTypes.h"
#include "../LIB/errorStatuse.h"
#define LED_NUMBER  	 3
#define LED_u8OFF     	 0
#define LED_u8ON    	 1

#define LED_u8SINK 		 0
#define LED_u8SOURCE	 1
typedef struct
{
	u8 LED_u8PortID;
	u8 LED_u8PinID;
	u8 LED_u8Connection;
	u8 LED_u8Val;
}LED_t;

#endif /* LED_CONFIG_H_ */
