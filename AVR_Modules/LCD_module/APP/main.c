/*
 * main.c
 *
 *  Created on: Aug 31, 2024
 *      Author: Islam Nagi
 */

#include "../LIB/StdTypes.h"
#include "../LIB/errorStatuse.h"
#include "../MCAL/DIO_int.h"
#include"../HAL/LCD_int.h"
#include"../HAL/LCD_Config.h"

#include<util/delay.h>
int main()
{

	u8 letter1[] ={0x00, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04 ,0x00};
	u8 letter2[] ={0x00, 0x00,0x00,0x00,0x00, 0x15, 0x1f, 0x00};
	u8 letter3[] = {0x00, 0x01, 0x01, 0x05, 0x05, 0x05, 0x0f, 0x00};
	u8 letter4[] = {0x00, 0x00, 0x1f, 0x15, 0x17, 0x10, 0x10, 0x00};
	LCD_enuINIT();
	 LCD_enuCreateLetter(1,letter1);
	 LCD_enuCreateLetter(2,letter2);
	 LCD_enuCreateLetter(3,letter3);
	 LCD_enuCreateLetter(4,letter4);
	 LCD_enuSetCurser(16,1);
	 LCD_enuWriteFrmRI8toLFT();
	 LCD_enuDispChar(1);
	 LCD_enuDispChar(2);
	 LCD_enuDispChar(3);
	 LCD_enuDispChar(4);
	while(1)
	{



	}


return 0;
}
