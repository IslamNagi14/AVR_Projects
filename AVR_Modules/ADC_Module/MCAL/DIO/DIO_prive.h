/*
 * DIO_prive.h
 *
 *  Created on: Sep 17, 2024
 *      Author: Islam Nagi
 */

#ifndef DIO_PRIVE_H_
#define DIO_PRIVE_H_

#define PINA			*(volatile u8*)0x39
#define PORTA			*(volatile u8*)0x3B
#define DDRA			*(volatile u8*)0x3A

#define PINB			*(volatile u8*)0x36
#define PORTB			*(volatile u8*)0x38
#define DDRB			*(volatile u8*)0x37

#define PINC			*(volatile u8*)0x33
#define PORTC			*(volatile u8*)0x35
#define DDRC			*(volatile u8*)0x34

#define PIND			*(volatile u8*)0x30
#define PORTD			*(volatile u8*)0x32
#define DDRD			*(volatile u8*)0x31

#define DIO_PORTA			0
#define DIO_PORTB			1
#define DIO_PORTC			2
#define DIO_PORTD			3

#define DIO_PIN0			0
#define DIO_PIN1			1
#define DIO_PIN2			2
#define DIO_PIN3			3
#define DIO_PIN4			4
#define DIO_PIN5			5
#define DIO_PIN6			6
#define DIO_PIN7			7


#define HIGH			1
#define LOW				0

#define INPUT			0
#define OUTPUT			1

#define PULL_UP			1
#define FLOAT			0

#define CONC_HELP(P0,P1,P2,P3,P4,P5,P6,P7)				0b##P0##P1##P2##P3##P4##P5##P6##P7
#define CONC(P0,P1,P2,P3,P4,P5,P6,P7)					CONC_HELP(P0,P1,P2,P3,P4,P5,P6,P7)


#endif /* DIO_PRIVE_H_ */
