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
	u8 segcath[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f},count = 0;
	DDRA &=~(1<<0); //pin0 is input
	DDRA &=~(1<<1); //pin1 is input
	PORTA |=(1<<0);// sw is pulled up;
	PORTA |=(1<<1);// sw is pulled up;
	DDRB = 0xff;
	PORTB = segcath[count];//start up view
	while(1)
	{
		if(!((PINA>>0)&1))//add
		{
			if(count == 9)
				continue;
			PORTB = segcath[++count];
			while(!((PINA>>0)&1));
		}
		if(!((PINA>>1)&1))//sub
		{
			if(count == 0)
				continue;
			PORTB = segcath[--count];
			while(!((PINA>>1)&1));
		}

	}



}
