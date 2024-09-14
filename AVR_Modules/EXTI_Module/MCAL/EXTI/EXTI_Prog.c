/*
 * EXTI_Prog.c
 *
 *  Created on: Sep 2, 2024
 *      Author: Islam Nagi
 */
#include"../../LIB/errorStatuse.h"
#include"../../LIB/StdTypes.h"
#include"EXTI_Config.h"
#include"EXTI_Priv.h"
#include"interrupt.h"

static volatile void(*EXTI_APFunINIT[3])(void) = {NULL,NULL,NULL};

ES_t EXTI_enuInit(EXTI_t * Copy_pstrEXTIConfig)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_pstrEXTIConfig)
	{
		u8 Local_u8Iretator = 0;
		for(Local_u8Iretator = 0;Local_u8Iretator<3;Local_u8Iretator++)
		{
			if(Copy_pstrEXTIConfig[Local_u8Iretator].EXTI_u8State == ACTIVE)
			{
				switch(Local_u8Iretator)
				{
				case 0:
					GICR|=(1<<6);
					MCUCR&=~(3<<0);
					switch(Copy_pstrEXTIConfig[Local_u8Iretator].EXTI_u8StenceLevel)
					{
					case FALLING_EDGE:
						MCUCR|=(1<<1);
						break;
					case RISING_EDGE:
						MCUCR|=(3<<0);
						break;
					case ANY_LOGICAL_CHANGE:
						MCUCR|=(1<<0);
						break;
					case LOW_LEVEL:
						break;
					default:
						Local_enuErrorState = ES_Out_Of_Range;
						break;
					}
					break;
					case 1:
						GICR|=(1<<7);
						MCUCR&=~(3<<2);
						switch(Copy_pstrEXTIConfig[Local_u8Iretator].EXTI_u8StenceLevel)
						{
						case FALLING_EDGE:
							MCUCR|=(1<<3);
							break;
						case RISING_EDGE:
							MCUCR|=(3<<2);
							break;
						case ANY_LOGICAL_CHANGE:
							MCUCR|=(1<<2);
							break;
						case LOW_LEVEL:
							break;
						default:
							Local_enuErrorState = ES_Out_Of_Range;
							break;
						}
						break;


						case 2:
							GICR|=(1<<5);
							MCUCSR&=~(1<<6);
							switch(Copy_pstrEXTIConfig[Local_u8Iretator].EXTI_u8StenceLevel)
							{
							case FALLING_EDGE:
								break;
							case RISING_EDGE:
								MCUCSR|=(1<<6);
								break;
							default:
								Local_enuErrorState = ES_Out_Of_Range;
								break;
							}

							break;
				}
			}

		}
	}
	else
	{
		Local_enuErrorState = ES_NULLPOINTER;
	}


	return Local_enuErrorState;
}
ES_t EXTI_enuSetSenceMode(u8 Copy_u8EXTI_ID, u8 Copy_u8SenceLevel)
{
	ES_t Local_enuErrorState = ES_NOK;

	switch(Copy_u8EXTI_ID)
	{
	case 0:
		MCUCR&=~(3<<0);
		switch(Copy_u8SenceLevel)
		{
		case FALLING_EDGE:
			MCUCR|=(1<<1);
			break;
		case RISING_EDGE:
			MCUCR|=(3<<0);
			break;
		case ANY_LOGICAL_CHANGE:
			MCUCR|=(1<<0);
			break;
		case LOW_LEVEL:
			break;
		default:
			Local_enuErrorState = ES_Out_Of_Range;
			break;
		}
		break;
	case 1:
		MCUCR&=~(3<<2);
		switch(Copy_u8SenceLevel)
		{
		case FALLING_EDGE:
			MCUCR|=(1<<3);
			break;
		case RISING_EDGE:
			MCUCR|=(3<<2);
			break;
		case ANY_LOGICAL_CHANGE:
			MCUCR|=(1<<2);
			break;
		case LOW_LEVEL:
			break;
		default:
			Local_enuErrorState = ES_Out_Of_Range;
			break;
		}
		break;
	case 2:
		MCUCSR&=~(1<<6);
		switch(Copy_u8SenceLevel)
		{
		case FALLING_EDGE:
			break;
		case RISING_EDGE:
			MCUCSR|=(1<<6);
			break;
		default:
			Local_enuErrorState = ES_Out_Of_Range;
			break;
		}
		break;
	}

return Local_enuErrorState;
}
ES_t EXTI_enuEnableINT(u8 Copy_u8EXTI_ID)
{
	ES_t Local_enuErrorState = ES_NOK;

	switch(Copy_u8EXTI_ID)
	{
	case 0:
		GICR|=(1<<6);
		break;
	case 1:
		GICR|=(1<<7);
		break;
	case 2:
		GICR|=(1<<5);
		break;
	default:
		Local_enuErrorState = ES_Out_Of_Range;
		break;
	}

return Local_enuErrorState;
}
ES_t EXTI_enuDisableINT(u8 Copy_u8EXTI_ID)
{
	ES_t Local_enuErrorState = ES_NOK;
	switch(Copy_u8EXTI_ID)
		{
		case 0:
			GICR&=~(1<<6);
			break;
		case 1:
			GICR&=~(1<<7);
			break;
		case 2:
			GICR&=~(1<<5);
			break;
		default:
			Local_enuErrorState = ES_Out_Of_Range;
			break;
		}
	return Local_enuErrorState;
}

ES_t EXTI_enuCallBackF(void(*Copy_PFunApp)(void),u8 Copy_u8EXTI_ID)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_PFunApp)
	{
		if(Copy_u8EXTI_ID<3)
			EXTI_APFunINIT[Copy_u8EXTI_ID] = Copy_PFunApp;
		else
			Local_enuErrorState = ES_Out_Of_Range;
	}
	else
	{
		Local_enuErrorState = ES_NULLPOINTER;
	}


	return Local_enuErrorState;
}
ISR(VECT_INT0)
{
	if(EXTI_APFunINIT[0])
	{
		EXTI_APFunINIT[0]();
	}
}

ISR(VECT_INT1)
{
	if(EXTI_APFunINIT[1])
		{
			EXTI_APFunINIT[1]();
		}
}

ISR(VECT_INT2)
{
	if(EXTI_APFunINIT[2])
		{
			EXTI_APFunINIT[2]();
		}
}


