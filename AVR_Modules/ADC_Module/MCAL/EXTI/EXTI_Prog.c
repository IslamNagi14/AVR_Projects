/*
 * EXTI_Prog.c
 *
 *  Created on: Sep 22, 2024
 *      Author: Islam Nagi
 */


#include"../../LIB/StdTypes.h"
#include"../../LIB/errorStatuse.h"
#include"EXTI_Config.h"
#include"EXTI_Prive.h"
#include"interrupt.h"

static volatile void (*EXTI_PvidGLOfun[INT_NUMBERS])(void*) = {NULL,NULL,NULL};
static volatile void *EXTI_PvidGLOPara[INT_NUMBERS] = {NULL,NULL,NULL};

ES_t EXTI_enuINIT(EXTI_t * Copy_PAryOFINT)
{
	ES_t Local_enuErrorState  = ES_NOK;

	if(Copy_PAryOFINT)
	{
		u8 Local_u8Iterator = 0;
		for(Local_u8Iterator = 0; INT_NUMBERS >Local_u8Iterator;Local_u8Iterator++)
		{
			if(Copy_PAryOFINT[Local_u8Iterator].State == ACTIVE)
			{
				switch(Local_u8Iterator)
				{
				case INT0:
					GICR|=(MASK_NUM<<GICR_INT0);
					switch(Copy_PAryOFINT[Local_u8Iterator].SenseLevel)
					{

					case LOWLEVEL:
						MCUCR&=~(MASK_NUM<<ISC00);
						MCUCR&=~(MASK_NUM<<ISC01);
						Local_enuErrorState  = ES_OK;break;
					case ANY_LOGIC_CHANGE:
						MCUCR|=(MASK_NUM<<ISC00);
						MCUCR&=~(MASK_NUM<<ISC01);
						Local_enuErrorState  = ES_OK;break;
					case FALLINGEDGE:
						MCUCR&=~(MASK_NUM<<ISC00);
						MCUCR|=(MASK_NUM<<ISC01);
						Local_enuErrorState  = ES_OK;break;
					case RISINGEDGE:
						MCUCR|=(MASK_NUM<<ISC00);
						MCUCR|=(MASK_NUM<<ISC01);
						Local_enuErrorState  = ES_OK;break;
					default:
						Local_enuErrorState  = ES_Out_Of_Range;break;

					}
					break;
					case INT1:
						GICR|=(MASK_NUM<<GICR_INT1);
						switch(Copy_PAryOFINT[Local_u8Iterator].SenseLevel)
						{

						case LOWLEVEL:
							MCUCR&=~(MASK_NUM<<ISC10);
							MCUCR&=~(MASK_NUM<<ISC11);
							Local_enuErrorState  = ES_OK;break;
						case ANY_LOGIC_CHANGE:
							MCUCR|=(MASK_NUM<<ISC10);
							MCUCR&=~(MASK_NUM<<ISC11);
							Local_enuErrorState  = ES_OK;break;
						case FALLINGEDGE:
							MCUCR&=~(MASK_NUM<<ISC10);
							MCUCR|=(MASK_NUM<<ISC11);
							Local_enuErrorState  = ES_OK;break;
						case RISINGEDGE:
							MCUCR|=(MASK_NUM<<ISC10);
							MCUCR|=(MASK_NUM<<ISC11);
							Local_enuErrorState  = ES_OK;break;
						default:
							Local_enuErrorState  = ES_Out_Of_Range;break;
						}
						break;
						case INT2:
							GICR|=(MASK_NUM<<GICR_INT2);
							switch(Copy_PAryOFINT[Local_u8Iterator].SenseLevel)
							{
							case FALLINGEDGE:
								MCUCSR&=~(MASK_NUM<<ISC2);
								Local_enuErrorState  = ES_OK;break;
							case RISINGEDGE:
								MCUCSR|=(MASK_NUM<<ISC2);
								Local_enuErrorState  = ES_OK;break;
							default:
								Local_enuErrorState  = ES_Out_Of_Range;break;
							}
							break;
							default:
								Local_enuErrorState  = ES_Out_Of_Range;break;

				}
			}
		}
	}
	else
	{
		Local_enuErrorState  = ES_NULLPOINTER;
	}

	return Local_enuErrorState ;
}
ES_t EXTI_enuSetSenseLevel(u8 Copy_u8INT_ID,u8 Copy_u8State)
{
	ES_t Local_enuErrorState  = ES_NOK;
	switch(Copy_u8INT_ID)
	{
	case INT0:
		GICR|=(MASK_NUM<<GICR_INT0);
		switch(Copy_u8State)
		{
		case LOWLEVEL:
			MCUCR&=~(MASK_NUM<<ISC00);
			MCUCR&=~(MASK_NUM<<ISC01);
			Local_enuErrorState  = ES_OK;break;
		case ANY_LOGIC_CHANGE:
			MCUCR|=(MASK_NUM<<ISC00);
			MCUCR&=~(MASK_NUM<<ISC01);
			Local_enuErrorState  = ES_OK;break;
		case FALLINGEDGE:
			MCUCR&=~(MASK_NUM<<ISC00);
			MCUCR|=(MASK_NUM<<ISC01);
			Local_enuErrorState  = ES_OK;break;
		case RISINGEDGE:
			MCUCR|=(MASK_NUM<<ISC00);
			MCUCR|=(MASK_NUM<<ISC01);
			Local_enuErrorState  = ES_OK;break;
		default:
			Local_enuErrorState  = ES_Out_Of_Range;break;
		}
		break;
		case INT1:
			GICR|=(MASK_NUM<<GICR_INT1);
			switch(Copy_u8State)
			{
			case LOWLEVEL:
				MCUCR&=~(MASK_NUM<<ISC10);
				MCUCR&=~(MASK_NUM<<ISC11);
				Local_enuErrorState  = ES_OK;break;

			case ANY_LOGIC_CHANGE:
				MCUCR|=(MASK_NUM<<ISC10);
				MCUCR&=~(MASK_NUM<<ISC11);
				Local_enuErrorState  = ES_OK;break;

			case FALLINGEDGE:
				MCUCR&=~(MASK_NUM<<ISC10);
				MCUCR|=(MASK_NUM<<ISC11);
				Local_enuErrorState  = ES_OK;break;

			case RISINGEDGE:
				MCUCR|=(MASK_NUM<<ISC10);
				MCUCR|=(MASK_NUM<<ISC11);
				Local_enuErrorState  = ES_OK;break;
			default:
				Local_enuErrorState  = ES_Out_Of_Range;break;
			}
			break;
			case INT2:
				GICR|=(MASK_NUM<<GICR_INT2);
				switch(Copy_u8State)
				{
				case FALLINGEDGE:
					MCUCSR&=~(MASK_NUM<<ISC2);Local_enuErrorState  = ES_OK;break;
				case RISINGEDGE:
					MCUCSR|=(MASK_NUM<<ISC2);Local_enuErrorState  = ES_OK;break;
				default:
					Local_enuErrorState  = ES_Out_Of_Range;break;
				}
				break;
				default:
					Local_enuErrorState  = ES_Out_Of_Range;break;

	}

	return Local_enuErrorState ;
}
ES_t EXTI_enuEnableEXINT(u8 Copy_u8INT_ID)
{
	ES_t Local_enuErrorState  = ES_NOK;
	switch(Copy_u8INT_ID)
	{
	case INT0:
		GICR|=(MASK_NUM<<GICR_INT0);Local_enuErrorState  = ES_OK;break;
	case INT1:
		GICR|=(MASK_NUM<<GICR_INT1);Local_enuErrorState  = ES_OK;break;
	case INT2:
		GICR|=(MASK_NUM<<GICR_INT2);Local_enuErrorState  = ES_OK;break;
	default:
		Local_enuErrorState  = ES_Out_Of_Range;break;
	}

	return Local_enuErrorState ;
}
ES_t EXTI_enuDisableEXINT(u8 Copy_u8INT_ID)
{
	ES_t Local_enuErrorState  = ES_NOK;

	switch(Copy_u8INT_ID)
	{
	case INT0:
		GICR&=~(MASK_NUM<<GICR_INT0);Local_enuErrorState  = ES_OK;break;
	case INT1:
		GICR&=~(MASK_NUM<<GICR_INT1);Local_enuErrorState  = ES_OK;break;
	case INT2:
		GICR&=~(MASK_NUM<<GICR_INT2);Local_enuErrorState  = ES_OK;break;
	default:
		Local_enuErrorState  = ES_Out_Of_Range;break;
	}

	return Local_enuErrorState ;
}

ES_t EXTI_enuCallBack(void * Copy_PvidFun,void * Copy_enuPvidPara,u8 Copy_u8INT_ID)
{
	ES_t Local_enuErrorState  = ES_NOK;

	if(Copy_PvidFun)
	{

		EXTI_PvidGLOfun[Copy_u8INT_ID] = Copy_PvidFun;
		EXTI_PvidGLOPara[Copy_u8INT_ID] = Copy_enuPvidPara;


	}
	else
	{
		Local_enuErrorState = ES_NULLPOINTER ;
	}

	return Local_enuErrorState ;
}

ISR(VECT_INT0)
{
	if(EXTI_PvidGLOfun[0])
	{
		EXTI_PvidGLOfun[0]((void*)EXTI_PvidGLOPara[0]);
	}
}

ISR(VECT_INT1)
{
	if(EXTI_PvidGLOfun[1])
	{
		EXTI_PvidGLOfun[1]((void*)EXTI_PvidGLOPara[1]);
	}
}
ISR(VECT_INT2)
{
	if(EXTI_PvidGLOfun[2])
	{
		EXTI_PvidGLOfun[2]((void*)EXTI_PvidGLOPara[2]);
	}
}
