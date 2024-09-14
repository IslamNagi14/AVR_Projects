/*
 * main.c
 *
 *  Created on: Sep 11, 2024
 *      Author: Islam Nagi
 */


#include"../LIB/StdTypes.h"
#include"../LIB/errorStatuse.h"
#include"../MCAL/DIO_int.h"
#include"../HAL/LCD/LCD_Config.h"
#include"../HAL/LCD/LCD_int.h"
#include"../HAL/KEYPAD/KYPAD_int.h"
#include"../HAL/KEYPAD/KYPAD_Config.h"
#include<util/delay.h>
int main()
{
	LCD_enuINIT();
	KYPAD_enuINIT();
	DIO_enuSetPINDir(DIO_u8PORTC,DIO_u8PIN1,DIO_OUTPUT);
	LCD_enuDispString("Welcome in CAT ");
	u32 op1 = 0;
	u32 op2 = 0;
	u8 oper = 0;
	u32 res = 0;
	u8 p =0;
	u8 flag =0;
	_delay_ms(1000);
	LCD_enuClearLCD();
	while(1)
	{

		KYPAD_enuGetChar(&p);
		if(p ==0xff)
			continue;
		else if(p == 'O')
		{
			LCD_enuClearLCD();
			   op1 = 0;
			   op2 = 0;
			   oper = 0;
			   res = 0;
		}
		else
		{

			LCD_enuDispChar(p);
		}
		if(flag == 0 && p!= 'O'&& p!= '+'&& p!= '/'&& p!= '-'&& p!= '*' && p!= 0xff)
		{
			op1 = op1 * 10 + p;
		}
		if(p == '+' || p == '/' || p == '-' || p == '*')
		{
			oper = p;
			flag = 1;
		}
		if(flag == 1 && p!= 'O'&& p!= '+'&& p!= '/'&& p!= '-'&& p!= '*' && p!= 0xff)
		{
			op2 = op2 * 10 + p;
		}
		if(p == '=')
		{
			switch(oper)
			{
			case '+':
				res = op1 + op2;
				break;
			case '-':
				res = op1 - op2;
				break;
			case '*':
				res = op1 * op2;
				break;
			case '/':
				if(op2 == 0)
				{
					LCD_enuClearLCD();
					LCD_enuDispString("Math Error!!");
					break;
				}
				res = op1/op2;
				break;
			case '=':
					res = op1;
			}
			LCD_enuSetCurser(1,2);
			LCD_enuDispChar(res);
		}


	}
	return 0;
}
