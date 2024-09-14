/*
 * LED_prog.c
 *
 *  Created on: Aug 25, 2024
 *      Author: Islam Nagi
 */

#include"../../LIB/errorStatuse.h"
#include"../../LIB/StdTypes.h"
#include"../../MCAL/DIO_int.h"
#include "LED_config.h"
#include"LED_private.h"
ES_t LED_enuINIT(LED_t *Copy_AStr_LEDs)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_AStr_LEDs)
	{
		u8 Local_u8Irerator ;
		for(Local_u8Irerator = 0;Local_u8Irerator<LED_NUMBER;Local_u8Irerator++)
		{
			Local_enuErrorState = DIO_enuSetPINDir(Copy_AStr_LEDs[Local_u8Irerator].LED_u8PortID,Copy_AStr_LEDs[Local_u8Irerator].LED_u8PinID,DIO_OUTPUT);
			if(Copy_AStr_LEDs[Local_u8Irerator].LED_u8Connection == SINK)
			{
			Local_enuErrorState = DIO_enuSetPINVAL(Copy_AStr_LEDs[Local_u8Irerator].LED_u8PortID,Copy_AStr_LEDs[Local_u8Irerator].LED_u8PinID,!Copy_AStr_LEDs[Local_u8Irerator].LED_u8Val);
			}
			else if(Copy_AStr_LEDs[Local_u8Irerator].LED_u8Connection == SOURCE)
			{
				Local_enuErrorState = DIO_enuSetPINVAL(Copy_AStr_LEDs[Local_u8Irerator].LED_u8PortID,Copy_AStr_LEDs[Local_u8Irerator].LED_u8PinID,Copy_AStr_LEDs[Local_u8Irerator].LED_u8Val);
			}
			else
			{
				Local_enuErrorState = ES_Out_Of_Range;
			}
		}
	}
	else
	{
		Local_enuErrorState = ES_NULLPOINTER;
	}
	return Local_enuErrorState;
}
ES_t LED_enuSetState(LED_t *Copy_A_LED,u8 Copy_u8Led_SVal)
{
	ES_t Local_enuErrorState = ES_NOK;
		if(Copy_A_LED)
		{
			if(Copy_A_LED->LED_u8Connection == SINK)
				{
					Local_enuErrorState = DIO_enuSetPINVAL(Copy_A_LED->LED_u8PortID,Copy_A_LED->LED_u8PinID,!Copy_u8Led_SVal);
				}
				else if(Copy_A_LED->LED_u8Connection == SOURCE)
				{
					Local_enuErrorState = DIO_enuSetPINVAL(Copy_A_LED->LED_u8PortID,Copy_A_LED->LED_u8PinID,Copy_u8Led_SVal);
				}
				else
				{
					Local_enuErrorState = ES_Out_Of_Range;
				}

		}
		else
		{
			Local_enuErrorState = ES_NULLPOINTER;
		}

	return Local_enuErrorState;
}


ES_t LED_enuSETUP(LED_t *Copy_StrLED,LED_t Copy_StrINFO)
{
	ES_t Local_enuErrorState = ES_NOK;

			if(Copy_StrLED)
			{
				if(Copy_StrLED->LED_u8PortID <= DIO_u8PORTD &&
				   Copy_StrINFO.LED_u8PortID <= DIO_u8PORTD &&
				   Copy_StrLED->LED_u8PinID <= DIO_u8PIN7 &&
				   Copy_StrINFO.LED_u8PinID<= DIO_u8PIN7 &&
				   (Copy_StrINFO.LED_u8Connection == SINK || Copy_StrINFO.LED_u8Connection == SOURCE))
				{
					Local_enuErrorState = DIO_enuSetPINDir(Copy_StrINFO.LED_u8PortID,Copy_StrINFO.LED_u8PinID,DIO_OUTPUT);
				Copy_StrLED->LED_u8PortID = Copy_StrINFO.LED_u8PortID;
				Copy_StrLED->LED_u8PinID = Copy_StrINFO.LED_u8PinID;
				Copy_StrLED->LED_u8Connection = Copy_StrINFO.LED_u8Connection;
				Local_enuErrorState = DIO_enuSetPINVAL(Copy_StrINFO.LED_u8PortID,Copy_StrINFO.LED_u8PinID,Copy_StrINFO.LED_u8Val);

				}
				else
				{
					Local_enuErrorState = ES_Out_Of_Range;
				}

			}
			else
			{
				Local_enuErrorState = ES_NULLPOINTER;
			}



			return Local_enuErrorState;
}







/*ES_t LED_enuGetState(LED_t *Copy_A_LED,u8 *Copy_u8Led_State)
{
	ES_t Local_enuErrorState = ES_NOK;
		if(Copy_A_LED)
		{

				Local_enuErrorState = DIO_enuGetPINVAL(Copy_A_LED->LED_u8PortID,Copy_A_LED->LED_u8PinID,Copy_u8Led_State);

		}
		else
		{
			Local_enuErrorState = ES_NULLPOINTER;
		}
		return Local_enuErrorState;
}
*/
