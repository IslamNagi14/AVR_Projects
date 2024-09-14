/*
 * SW_Prog.c
 *
 *  Created on: Aug 28, 2024
 *      Author: Islam Nagi
 */

#include"../../LIB/errorStatuse.h"
#include"../../LIB/StdTypes.h"
#include"../../MCAL/DIO_int.h"
#include"SW_Config.h"
#include"SW_Private.h"
ES_t SW_enuINIT(SW_t * Copy_enuSWITCHs)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_enuSWITCHs)
	{
		u8 iterator = 0;
		for(iterator = 0;iterator <= SW_u8SwNUMS;iterator++)
		{
		Local_enuErrorState = DIO_enuSetPINDir(Copy_enuSWITCHs[iterator].SW_u8PortID,Copy_enuSWITCHs[iterator].SW_u8PinID,DIO_INPUT);
		Local_enuErrorState = DIO_enuSetPINVAL(Copy_enuSWITCHs[iterator].SW_u8PortID,Copy_enuSWITCHs[iterator].SW_u8PinID,Copy_enuSWITCHs[iterator].SW_u8SWconnection);
		}

	}
	else
	{
		Local_enuErrorState = ES_NULLPOINTER;
	}



	return Local_enuErrorState;

}
ES_t SW_enuSETUP(SW_t  *Copy_StrSWITCH,SW_t Copy_StrINFO)
{
	ES_t Local_enuErrorState = ES_NOK;

		if(Copy_StrSWITCH)
		{
			if(Copy_StrSWITCH->SW_u8PortID <= DIO_u8PORTD &&
			   Copy_StrINFO.SW_u8PortID <= DIO_u8PORTD &&
			   Copy_StrSWITCH->SW_u8PinID <= DIO_u8PIN7 &&
			   Copy_StrINFO.SW_u8PinID<= DIO_u8PIN7 &&
			   (Copy_StrINFO.SW_u8SWconnection == DIO_PULLUP || Copy_StrINFO.SW_u8SWconnection == DIO_FLOAT))
			{
				Local_enuErrorState = DIO_enuSetPINDir(Copy_StrINFO.SW_u8PortID,Copy_StrINFO.SW_u8PinID,DIO_INPUT);

			Copy_StrSWITCH->SW_u8PortID = Copy_StrINFO.SW_u8PortID;
			Copy_StrSWITCH->SW_u8PinID = Copy_StrINFO.SW_u8PinID;
			Copy_StrSWITCH->SW_u8SWconnection = Copy_StrINFO.SW_u8SWconnection;

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
ES_t SW_enuGetState(SW_t  *Copy_StrSWITCH,u8 *Copy_u8SWVal)
{
	ES_t Local_enuErrorState = ES_NOK;

			if(Copy_StrSWITCH)
			{
				Local_enuErrorState = DIO_enuGetPINVAL(Copy_StrSWITCH->SW_u8PortID,Copy_StrSWITCH->SW_u8PinID,Copy_u8SWVal);
				if(Copy_StrSWITCH->SW_u8SWconnection == DIO_FLOAT)
					*Copy_u8SWVal = ! *Copy_u8SWVal;


			}
			else
			{
				Local_enuErrorState = ES_NULLPOINTER;
			}



			return Local_enuErrorState;
}
