/*
 * main.c
 *
 *  Created on: Aug 25, 2024
 *      Author: Islam Nagi
 */
#include"LED_config.h"
#include"DIO_int.h"
#include"StdTypes.h"
#include"LED_int.h"
#include"errorStatuse.h"
#include<util/delay.h>
extern LED_t LEDsARR[LED_NUMBER];

int main()
{

	/*for(u8 iterate = 0;iterate<LED_NUMBER,)
	DIO_enuSetPINDir(LEDsARR[0].LED_u8PortID,LEDsARR[0].LED_u8PinID,DIO_OUTPUT);*/

	LED_enuINIT(LEDsARR);

	while(1)
	{

		/*LED_enuINIT(LEDsARR);
				_delay_ms(500);*/

		LED_enuSetState(&LEDsARR[1],LED_u8ON);
		_delay_ms(1000);

		LED_enuSetState(&LEDsARR[1],LED_u8OFF);
				_delay_ms(100);

/*
		LED_enuSetState(&LEDsARR[0],LED_u8LOW);
		LED_enuSetState(&LEDsARR[2],LED_u8LOW);
		_delay_ms(500);
		LED_enuSetState(&LEDsARR[0],LED_u8HIGH);
		LED_enuSetState(&LEDsARR[2],LED_u8HIGH);
		_delay_ms(500);*/

	}
return 0;
}
