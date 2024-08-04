/*
 * main.c
 *
 *  Created on: Aug 4, 2024
 *      Author: Islam Nagi
 */

#include <util/delay.h>

typedef unsigned char u8;

#define DDRA	*((u8*)0x3A)
#define PORTA	*((u8*)0x3B)
#define PINA	*((volatile u8*)0x39)

int main(void)
{
DDRA |= (1<<2);

while(1)
{
	PORTA |= (1<<2);
	_delay_ms(1000);

	PORTA &= ~(1<<2);
	_delay_ms(1000);
}

	return 0;
}
