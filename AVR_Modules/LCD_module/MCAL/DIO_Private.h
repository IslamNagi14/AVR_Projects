/*
 * Private.h
 *
 *  Created on: Aug 22, 2024
 *      Author: Islam Nagi
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

#define DIO_MASK_BIT 1

#define INPUT  		 0
#define OUTPUT  	 1

#define HIGH     	 1
#define LOW  		 0
#define PULLUP		 1
#define FLOAT  		 0

#define DIO_PORTA    0
#define DIO_PORTB    1
#define DIO_PORTC    2
#define DIO_PORTD    3

#define DIO_PIN0     0
#define DIO_PIN1     1
#define DIO_PIN2     2
#define DIO_PIN3     3
#define DIO_PIN4     4
#define DIO_PIN5     5
#define DIO_PIN6     6
#define DIO_PIN7     7




#define DDRA	*((u8*)0x3A)
#define PORTA	*((u8*)0x3B)
#define PINA	*((volatile u8*)0x39)

#define DDRB	*((u8*)0x37)
#define PORTB	*((u8*)0x38)
#define PINB	*((volatile u8*)0x36)

#define DDRC	*((u8*)0x34)
#define PORTC   *((u8*)0x35)
#define PINC	*((volatile u8*)0x33)

#define DDRD	*((u8*)0x31)
#define PORTD   *((u8*)0x32)
#define PIND	*((volatile u8*)0x30)

#define HELP_CONC(b7,b6,b5,b4,b3,b2,b1,b0)  0b##b7##b6##b5##b4##b3##b2##b1##b0
#define CONC(b7,b6,b5,b4,b3,b2,b1,b0) 		HELP_CONC(b7,b6,b5,b4,b3,b2,b1,b0)


#endif /* DIO_PRIVATE_H_ */
