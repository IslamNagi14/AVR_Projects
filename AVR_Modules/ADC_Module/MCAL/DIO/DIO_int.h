/*
 * DIO_int.h
 *
 *  Created on: Sep 17, 2024
 *      Author: Islam Nagi
 */

#ifndef DIO_INT_H_
#define DIO_INT_H_

#include"../../LIB/StdTypes.h"
#include"../../LIB/errorStatuse.h"

ES_t DIO_enuINIT(void);
ES_t DIO_enuSetPinDir(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8Direction);
ES_t DIO_enuSetPinVal(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8Value);
ES_t DIO_enuToggelPin(u8 Copy_u8PortId,u8 Copy_u8PinId);
ES_t DIO_enuGetPinVal(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 *Copy_u8Value);

ES_t DIO_enuSetPortDir(u8 Copy_u8PortId,u8 Copy_u8Direction);
ES_t DIO_enuSetPortVal(u8 Copy_u8PortId,u8 Copy_u8Value);
ES_t DIO_enuGetPortVal(u8 Copy_u8PortId,u8 *Copy_u8Value);
ES_t DIO_enuToggelPort(u8 Copy_u8PortId);


#define DIO_u8PORTA			0
#define DIO_u8PORTB			1
#define DIO_u8PORTC			2
#define DIO_u8PORTD			3


#define DIO_u8PIN0			0
#define DIO_u8PIN1			1
#define DIO_u8PIN2			2
#define DIO_u8PIN3			3
#define DIO_u8PIN4			4
#define DIO_u8PIN5			5
#define DIO_u8PIN6			6
#define DIO_u8PIN7			7

#define DIO_u8HIGH			1
#define DIO_u8LOW			0

#define DIO_u8INPUT			0
#define DIO_u8OUTPUT		1

#define DIO_u8PULL_UP		1
#define DIO_u8FLOAT			0

#endif /* DIO_INT_H_ */
