/*
 * main.c
 *
 *  Created on: Aug 21, 2024
 *      Author: Islam Nagi
 */

typedef unsigned char u8;
#include <util/delay.h>
#define DDRA 	*((u8*)0x3A)
#define PORTA	*((u8*)0x3B)
#define PINA	*((volatile u8*)0x39)
#define DDRB	*((u8*)0x37)
#define PORTB	*((u8*)0x38)
#define PINB	*((volatile u8*)0x36)
int main()
{
	DDRA |=(1<<0); //pin0 in porta is output
	DDRA |=(1<<1); //pin1 in porta is output
	//PORTA &=~(1<<0);//initialize leds off
	//PORTA &=~(1<<1);//initialize leds off
    PORTA = 0;
	DDRB &=~(1<<0);//pin0 in portb is input
	DDRB &=~(1<<1);//pin1 in portb is input
	DDRB &=~(1<<2);//pin2 in portb is input
	PORTB |=(1<<0);//sw is pulled_up
	PORTB |=(1<<1);//sw is pulled_up
	PORTB |=(1<<2);//sw is pulled_up
	while(1)
	{
		PORTA &=~(1<<0);
		PORTA &=~(1<<1);
		if(!((PINB>>0)&1))
		{
			PORTA |=(1<<0);
			while(!((PINB>>0)&1));
		}

		if(!((PINB>>1)&1))
		{

			PORTA |=(1<<1);
			while(!((PINB>>1)&1));

		}
		if(!((PINB>>2)&1))
		{
			PORTA |=(1<<0);
			PORTA |=(1<<1);
			while(!((PINB>>2)&1));
		}


	}
return 0;
}
