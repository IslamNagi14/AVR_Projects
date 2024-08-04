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
	DDRA = 0xff;

	while(1)
	{
		int i = 0;
		for(;i<=7;i++)
		{
			PORTA |= (1<<i);
			_delay_ms(300);
		}
	i= 0;
		for(;i<=7;i++)
		{
			PORTA &= ~(1<<i);
			_delay_ms(300);
		}

	}

	return 0;
}

