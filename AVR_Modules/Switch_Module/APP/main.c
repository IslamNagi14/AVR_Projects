/*
 * main.c
 *
 *  Created on: Aug 28, 2024
 *      Author: Islam Nagi
 */

#include"../LIB/errorStatuse.h"
#include"../LIB/StdTypes.h"

#include"../HAL/SWITCH/SW_Config.h"
#include"../HAL/SWITCH/SW_int.h"
#include"../HAL/LED/LED_config.h"
#include"../HAL/LED/LED_int.h"
#include"../MCAL/DIO_int.h"


#include<util/delay.h>
extern SW_t Switches[SW_u8SwNUMS] ;
extern LED_t LEDsARR[LED_NUMBER] ;

int main()
{

	SW_t SWitCH_0 = {DIO_u8PORTD,DIO_u8PIN0,DIO_PULLUP};

	LED_t LED_0   = {DIO_u8PORTA,DIO_u8PIN3,LED_u8SOURCE,LED_u8OFF};

	DIO_enuInit();
	SW_enuINIT(Switches);
	LED_enuINIT(LEDsARR);
	SW_enuSETUP(&Switches[0],SWitCH_0);

	LED_enuSETUP(&LEDsARR[0],LED_0);


	u8 PressedKey_0 = SW_u8SwNPressed;

	while(1)
	{

		SW_enuGetState(&Switches[0],&PressedKey_0);
		switch(PressedKey_0)
		{
		case SW_u8SwPressed:
			LED_enuSetState(&LEDsARR[0],LED_u8OFF);break;
		case SW_u8SwNPressed:
			LED_enuSetState(&LEDsARR[0],LED_u8ON);break;
		}




	}


	return 0;
}

