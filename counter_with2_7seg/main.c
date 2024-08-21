/*
 * main.c
 *
 *  Created on: Aug 21, 2024
 *      Author: Islam Nagi
 */

#include <util/delay.h>

typedef unsigned char u8;

#define DDRA	*((u8*)0x3A)
#define PORTA	*((u8*)0x3B)
#define PINA	*((volatile u8*)0x39)
#define DDRB	*((u8*)0x37)
#define PORTB	*((u8*)0x38)
#define DDRD	*((u8*)0x31)
#define PORTD   *((u8*)0x32)
#define PIND	*((volatile u8*)0x30)
int main()
{
	u8 number = 50;
	u8 seg[] ={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	DDRA = 0xff;// common A
	DDRB = 0xff;// common B
	DDRD&=~(1<<0);//pin0 in port d is input++
	DDRD&=~(1<<1);//pin1 in port d is input--
	PORTD |=(1<<0); //sw is pulled_up
	PORTD |=(1<<1); //sw is pulled_up
	PORTA = seg[number % 10];
	PORTB = seg[number / 10];

	while(1)
	{

		if(!((PIND>>0)&1))
		{
			number++;
			if(number == 100)
				number = 0;
			PORTA = seg[number % 10];
			PORTB = seg[number / 10];
			while(!((PIND>>0)&1));
		}

		if(!((PIND>>1)&1))
			{
				if(number == 0)
					number = 100;
				number--;

				PORTA = seg[number % 10];
				PORTB = seg[number/ 10];

				while(!((PIND>>1)&1));
			}



	}






}


