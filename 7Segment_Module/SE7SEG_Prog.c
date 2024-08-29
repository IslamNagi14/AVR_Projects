/*
 * SE7SEG_Prog.c
 *
 *  Created on: Aug 26, 2024
 *      Author: Islam Nagi
 */

#include"StdTypes.h"
#include"errorStatuse.h"
#include"SE7SEG_Private.h"
#include"SE7SEG_Config.h"
#include"DIO_int.h"
ES_t SE7SEG_enuINIT(SE7SEG_t *Copy_AStr_SE7SEG)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_AStr_SE7SEG)
	{
		for(u8 Local_u8Striterate = 0;Local_u8Striterate<SE7SEG_u8NUMBER;Local_u8Striterate++)
		{
			for(u8 Local_u8Piniterate = 0;Local_u8Piniterate<SE7Pin_NUMBER;Local_u8Piniterate++)
			{
				DIO_enuSetPINDir(Copy_AStr_SE7SEG[Local_u8Striterate].SE7SEG_A[Local_u8Piniterate].SE7SEG_u8PortID,Copy_AStr_SE7SEG[Local_u8Striterate].SE7SEG_A[Local_u8Piniterate].SE7SEG_u8PinID,DIO_OUTPUT);
				if(Copy_AStr_SE7SEG[Local_u8Striterate].SE7SEG_u8Connection == SE7SEG_Ccath)
					Local_enuErrorState = DIO_enuSetPINVAL(Copy_AStr_SE7SEG[Local_u8Striterate].SE7SEG_A[Local_u8Piniterate].SE7SEG_u8PortID,Copy_AStr_SE7SEG[Local_u8Striterate].SE7SEG_A[Local_u8Piniterate].SE7SEG_u8PinID,DIO_LOW);
				else if(Copy_AStr_SE7SEG[Local_u8Striterate].SE7SEG_u8Connection == SE7SEG_CAnod)
					Local_enuErrorState = DIO_enuSetPINVAL(Copy_AStr_SE7SEG[Local_u8Striterate].SE7SEG_A[Local_u8Piniterate].SE7SEG_u8PortID,Copy_AStr_SE7SEG[Local_u8Striterate].SE7SEG_A[Local_u8Piniterate].SE7SEG_u8PinID,DIO_HIGH);
				else
					Local_enuErrorState = ES_Out_Of_Range;

			}

		}

	}
	else
	{
		Local_enuErrorState = ES_NULLPOINTER;
	}

	return  Local_enuErrorState;

}
ES_t SE7SEG_enuSetSE7SegVal(SE7SEG_t *Copy_SE7SEG,u8 Copy_u8ValSE7)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_SE7SEG)
	{
		u8 Local_u8Piniterate = 0;
		for(Local_u8Piniterate = 0;Local_u8Piniterate<SE7Pin_NUMBER;Local_u8Piniterate++)
		{
			if(Copy_SE7SEG->SE7SEG_u8Connection == SE7SEG_Ccath)
			{

				Local_enuErrorState = DIO_enuSetPINVAL(Copy_SE7SEG->SE7SEG_A[Local_u8Piniterate].SE7SEG_u8PortID,Copy_SE7SEG->SE7SEG_A[Local_u8Piniterate].SE7SEG_u8PinID,((SE7SEG_u8NUMs[Copy_u8ValSE7]>>Local_u8Piniterate)&1));
			}
			else if(Copy_SE7SEG->SE7SEG_u8Connection == SE7SEG_CAnod)
			{
				Local_enuErrorState = DIO_enuSetPINVAL(Copy_SE7SEG->SE7SEG_A[Local_u8Piniterate].SE7SEG_u8PortID,Copy_SE7SEG->SE7SEG_A[Local_u8Piniterate].SE7SEG_u8PinID,!((SE7SEG_u8NUMs[Copy_u8ValSE7]>>Local_u8Piniterate)&1));
			}
			else
				Local_enuErrorState = ES_Out_Of_Range;
		}
	}
	else
	{
		Local_enuErrorState = ES_NULLPOINTER;
	}

	return  Local_enuErrorState;
}



ES_t SE7SEG_enuSetUPSE7Seg(SE7SEG_t *Copy_SE7SEG,SETUP_t * SegSetUP,u8 Copy_u8CONECTSE7)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_SE7SEG && SegSetUP)
	{
		u8 Local_u8iterator = 0;
		for(Local_u8iterator = 0;Local_u8iterator<SE7Pin_NUMBER;Local_u8iterator++)
		{
			DIO_enuSetPINDir(SegSetUP[Local_u8iterator].SE7SEG_u8PortID,SegSetUP[Local_u8iterator].SE7SEG_u8PinID,DIO_OUTPUT);
			Copy_SE7SEG->SE7SEG_A[Local_u8iterator].SE7SEG_u8PortID = SegSetUP[Local_u8iterator].SE7SEG_u8PortID;
			Copy_SE7SEG->SE7SEG_A[Local_u8iterator].SE7SEG_u8PinID = SegSetUP[Local_u8iterator].SE7SEG_u8PinID;
		}
		Copy_SE7SEG->SE7SEG_u8Connection = Copy_u8CONECTSE7;
	}
	else
	{
		Local_enuErrorState = ES_NULLPOINTER;
	}
	return  Local_enuErrorState;

}

ES_t SE7SEG_enuEnableSE7Seg(SE7SEG_t *Copy_SE7SEG,SETUP_t  Copy_pstr_EnPIN)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_SE7SEG)
	{
		if(Copy_pstr_EnPIN.SE7SEG_u8PortID<=DIO_u8PORTD && Copy_pstr_EnPIN.SE7SEG_u8PinID<=DIO_u8PIN7)
		{
			DIO_enuSetPINDir(Copy_pstr_EnPIN.SE7SEG_u8PortID,Copy_pstr_EnPIN.SE7SEG_u8PinID,DIO_OUTPUT);
			if(Copy_SE7SEG->SE7SEG_u8Connection == SE7SEG_CAnod)
			{
				Local_enuErrorState = DIO_enuSetPINVAL(Copy_pstr_EnPIN.SE7SEG_u8PortID,Copy_pstr_EnPIN.SE7SEG_u8PinID,DIO_HIGH);
			}
			else if(Copy_SE7SEG->SE7SEG_u8Connection == SE7SEG_Ccath)
			{
				Local_enuErrorState = DIO_enuSetPINVAL(Copy_pstr_EnPIN.SE7SEG_u8PortID,Copy_pstr_EnPIN.SE7SEG_u8PinID,DIO_LOW);
			}

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

ES_t SE7SEG_enuDisableSE7Seg(SE7SEG_t *Copy_SE7SEG,SETUP_t  Copy_pstr_EnPIN)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_SE7SEG)
	{
		if(Copy_pstr_EnPIN.SE7SEG_u8PortID<=DIO_u8PORTD && Copy_pstr_EnPIN.SE7SEG_u8PinID<=DIO_u8PIN7)
		{
			DIO_enuSetPINDir(Copy_pstr_EnPIN.SE7SEG_u8PortID,Copy_pstr_EnPIN.SE7SEG_u8PinID,DIO_OUTPUT);
			if(Copy_SE7SEG->SE7SEG_u8Connection == SE7SEG_CAnod)
			{
				Local_enuErrorState = DIO_enuSetPINVAL(Copy_pstr_EnPIN.SE7SEG_u8PortID,Copy_pstr_EnPIN.SE7SEG_u8PinID,DIO_LOW);
			}
			else if(Copy_SE7SEG->SE7SEG_u8Connection == SE7SEG_Ccath)
			{
				Local_enuErrorState = DIO_enuSetPINVAL(Copy_pstr_EnPIN.SE7SEG_u8PortID,Copy_pstr_EnPIN.SE7SEG_u8PinID,DIO_HIGH);
			}
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


ES_t SE7SEG_enuSetDOTSE7Seg(SE7SEG_t *Copy_SE7SEG,SETUP_t  Copy_pstr_EnPIN,u8 Copy_u8STATESE7)
{
	ES_t Local_enuErrorState = ES_NOK;

		if(Copy_SE7SEG)
		{
			if(Copy_pstr_EnPIN.SE7SEG_u8PortID<=DIO_u8PORTD && Copy_pstr_EnPIN.SE7SEG_u8PinID<=DIO_u8PIN7)
			{
				DIO_enuSetPINDir(Copy_pstr_EnPIN.SE7SEG_u8PortID,Copy_pstr_EnPIN.SE7SEG_u8PinID,DIO_OUTPUT);
				if(Copy_SE7SEG->SE7SEG_u8Connection == SE7SEG_CAnod)
				{
					if(Copy_u8STATESE7 == SE7SEG_TurnOn)
						Local_enuErrorState = DIO_enuSetPINVAL(Copy_pstr_EnPIN.SE7SEG_u8PortID,Copy_pstr_EnPIN.SE7SEG_u8PinID,DIO_LOW);
					else if(Copy_u8STATESE7 == SE7SEG_TurnOff)
						Local_enuErrorState = DIO_enuSetPINVAL(Copy_pstr_EnPIN.SE7SEG_u8PortID,Copy_pstr_EnPIN.SE7SEG_u8PinID,DIO_HIGH);
					else
						Local_enuErrorState = ES_Out_Of_Range;

				}
				else if(Copy_SE7SEG->SE7SEG_u8Connection == SE7SEG_Ccath)
				{
					if(Copy_u8STATESE7 == SE7SEG_TurnOn)
						Local_enuErrorState = DIO_enuSetPINVAL(Copy_pstr_EnPIN.SE7SEG_u8PortID,Copy_pstr_EnPIN.SE7SEG_u8PinID,DIO_HIGH);
					else if(Copy_u8STATESE7 == SE7SEG_TurnOff)
						Local_enuErrorState = DIO_enuSetPINVAL(Copy_pstr_EnPIN.SE7SEG_u8PortID,Copy_pstr_EnPIN.SE7SEG_u8PinID,DIO_LOW);
					else
						Local_enuErrorState = ES_Out_Of_Range;
				}

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


ES_t SE7SEG_enuClearSE7Seg(SE7SEG_t *Copy_SE7SEG)
{
	ES_t Local_enuErrorState = ES_NOK;

		if(Copy_SE7SEG)
		{

				for(u8 Local_u8Piniterate = 0;Local_u8Piniterate<SE7Pin_NUMBER;Local_u8Piniterate++)
				{
					DIO_enuSetPINDir(Copy_SE7SEG->SE7SEG_A[Local_u8Piniterate].SE7SEG_u8PortID,Copy_SE7SEG->SE7SEG_A[Local_u8Piniterate].SE7SEG_u8PinID,DIO_OUTPUT);
					if(Copy_SE7SEG->SE7SEG_u8Connection == SE7SEG_Ccath)
						Local_enuErrorState = DIO_enuSetPINVAL(Copy_SE7SEG->SE7SEG_A[Local_u8Piniterate].SE7SEG_u8PortID,Copy_SE7SEG->SE7SEG_A[Local_u8Piniterate].SE7SEG_u8PinID,DIO_LOW);
					else if(Copy_SE7SEG->SE7SEG_u8Connection == SE7SEG_CAnod)
						Local_enuErrorState = DIO_enuSetPINVAL(Copy_SE7SEG->SE7SEG_A[Local_u8Piniterate].SE7SEG_u8PortID,Copy_SE7SEG->SE7SEG_A[Local_u8Piniterate].SE7SEG_u8PinID,DIO_HIGH);
					else
						Local_enuErrorState = ES_Out_Of_Range;

				}



		}
		else
		{
			Local_enuErrorState = ES_NULLPOINTER;
		}

		return  Local_enuErrorState;



}


ES_t SE7SEG_enuSetPin(SE7SEG_t *Copy_SE7SEG,u8 Copy_u8PortSE7,u8 Copy_u8PinSE7,u8 Copy_u8STATESE7)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_SE7SEG)
	{

		if(Copy_SE7SEG->SE7SEG_u8Connection == SE7SEG_Ccath)
		{
			Local_enuErrorState = DIO_enuSetPINVAL(Copy_SE7SEG->SE7SEG_A[Copy_u8PinSE7].SE7SEG_u8PortID,Copy_SE7SEG->SE7SEG_A[Copy_u8PinSE7].SE7SEG_u8PinID,Copy_u8STATESE7);
		}
		else if(Copy_SE7SEG->SE7SEG_u8Connection == SE7SEG_CAnod)
		{
			if(Copy_u8STATESE7 == DIO_HIGH)
				Local_enuErrorState = DIO_enuSetPINVAL(Copy_SE7SEG->SE7SEG_A[Copy_u8PinSE7].SE7SEG_u8PortID,Copy_SE7SEG->SE7SEG_A[Copy_u8PinSE7].SE7SEG_u8PinID,DIO_LOW);
			else if(Copy_u8STATESE7 == DIO_LOW)
				Local_enuErrorState = DIO_enuSetPINVAL(Copy_SE7SEG->SE7SEG_A[Copy_u8PinSE7].SE7SEG_u8PortID,Copy_SE7SEG->SE7SEG_A[Copy_u8PinSE7].SE7SEG_u8PinID,DIO_HIGH);
			else
				Local_enuErrorState = ES_Out_Of_Range;
		}
		else
			Local_enuErrorState = ES_Out_Of_Range;

	}
	else
	{
		Local_enuErrorState = ES_NULLPOINTER;
	}

	return  Local_enuErrorState;

}



