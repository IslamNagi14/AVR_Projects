/*
 * main.c
 *
 *  Created on: Sep 2, 2024
 *      Author: Islam Nagi
 */

#include"../LIB/errorStatuse.h"
#include"../LIB/StdTypes.h"

#include"../MCAL/DIO/DIO_int.h"

#include"../MCAL/EXTI/EXTI_Config.h"
#include"../MCAL/EXTI/EXTI_Int.h"
#include"../MCAL/GIE/GIE_int.h"
void tog(void);
extern EXTI_t EXTI_AstrEXTConfig[3] ;
int main()
{
	DIO_enuSetPINDir(DIO_u8PORTD,DIO_u8PIN2,DIO_INPUT);
	DIO_enuSetPINVAL(DIO_u8PORTD,DIO_u8PIN2,DIO_PULLUP);
	DIO_enuSetPINDir(DIO_u8PORTA,DIO_u8PIN1,DIO_OUTPUT);
	DIO_enuSetPINVAL(DIO_u8PORTA,DIO_u8PIN1,DIO_HIGH);
	EXTI_enuCallBackF(tog,0);
	EXTI_enuInit(EXTI_AstrEXTConfig);
	GIE_enuEnable();
	while(1);
}

void tog(void)
{
	//*(u8*)p = 10;
	DIO_enuToggelPIN(DIO_u8PORTA,DIO_u8PIN1);
}
