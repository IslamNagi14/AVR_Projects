/*
 * DIO_Prog.c
 *
 *  Created on: Sep 17, 2024
 *      Author: Islam Nagi
 */

#ifndef DIO_PROG_C_
#define DIO_PROG_C_

#include"../../LIB/StdTypes.h"
#include"../../LIB/errorStatuse.h"
#include"DIO_config.h"
#include"DIO_prive.h"
ES_t DIO_enuINIT(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	/*DIRECTION INITIALIZATION*/
	DDRA = CONC(PA_PIN0_DIR,PA_PIN1_DIR,PA_PIN2_DIR,PA_PIN3_DIR,PA_PIN4_DIR,PA_PIN5_DIR,PA_PIN6_DIR,PA_PIN7_DIR);
	DDRB = CONC(PB_PIN0_DIR,PB_PIN1_DIR,PB_PIN2_DIR,PB_PIN3_DIR,PB_PIN4_DIR,PB_PIN5_DIR,PB_PIN6_DIR,PB_PIN7_DIR);
	DDRC = CONC(PC_PIN0_DIR,PC_PIN1_DIR,PC_PIN2_DIR,PC_PIN3_DIR,PC_PIN4_DIR,PC_PIN5_DIR,PC_PIN6_DIR,PC_PIN7_DIR);
	DDRD = CONC(PD_PIN0_DIR,PD_PIN1_DIR,PD_PIN2_DIR,PD_PIN3_DIR,PD_PIN4_DIR,PD_PIN5_DIR,PD_PIN6_DIR,PD_PIN7_DIR);
	/*VALUE INITIALIZATION*/
	PORTA = CONC(PA_PIN0_VAL,PA_PIN1_VAL,PA_PIN2_VAL,PA_PIN3_VAL,PA_PIN4_VAL,PA_PIN5_VAL,PA_PIN6_VAL,PA_PIN7_VAL);
	PORTB = CONC(PB_PIN0_VAL,PB_PIN1_VAL,PB_PIN2_VAL,PB_PIN3_VAL,PB_PIN4_VAL,PB_PIN5_VAL,PB_PIN6_VAL,PB_PIN7_VAL);
	PORTC = CONC(PC_PIN0_VAL,PC_PIN1_VAL,PC_PIN2_VAL,PC_PIN3_VAL,PC_PIN4_VAL,PC_PIN5_VAL,PC_PIN6_VAL,PC_PIN7_VAL);
	PORTD = CONC(PD_PIN0_VAL,PD_PIN1_VAL,PD_PIN2_VAL,PD_PIN3_VAL,PD_PIN4_VAL,PD_PIN5_VAL,PD_PIN6_VAL,PD_PIN7_VAL);
	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}
ES_t DIO_enuSetPinDir(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8Direction)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8PortId <= DIO_PORTD && Copy_u8PinId<= DIO_PIN7)
	{
		switch(Copy_u8PortId)
		{
		case DIO_PORTA://SelectFromPortA
			switch(Copy_u8PinId)
			{
			case DIO_PIN0:
				DDRA &= ~(1<<DIO_PIN0);
				DDRA |=(Copy_u8Direction<<DIO_PIN0);break;
			case DIO_PIN1:
				DDRA &= ~(1<<DIO_PIN1);
				DDRA |=(Copy_u8Direction<<DIO_PIN1);break;
			case DIO_PIN2:
				DDRA &= ~(1<<DIO_PIN2);
				DDRA |=(Copy_u8Direction<<DIO_PIN2);break;
			case DIO_PIN3:
				DDRA &= ~(1<<DIO_PIN3);
				DDRA |=(Copy_u8Direction<<DIO_PIN3);break;
			case DIO_PIN4:
				DDRA &= ~(1<<DIO_PIN4);
				DDRA |=(Copy_u8Direction<<DIO_PIN4);break;
			case DIO_PIN5:
				DDRA &= ~(1<<DIO_PIN5);
				DDRA |=(Copy_u8Direction<<DIO_PIN5);break;
			case DIO_PIN6:
				DDRA &= ~(1<<DIO_PIN6);
				DDRA |=(Copy_u8Direction<<DIO_PIN6);break;
			case DIO_PIN7:
				DDRA &= ~(1<<DIO_PIN7);
				DDRA |=(Copy_u8Direction<<DIO_PIN7);break;

			}
			break;
			case DIO_PORTB://SelectFromPortB
				switch(Copy_u8PinId)
				{
				case DIO_PIN0:
					DDRB &= ~(1<<DIO_PIN0);
					DDRB |=(Copy_u8Direction<<DIO_PIN0);break;
				case DIO_PIN1:
					DDRB &= ~(1<<DIO_PIN1);
					DDRB |=(Copy_u8Direction<<DIO_PIN1);break;
				case DIO_PIN2:
					DDRB &= ~(1<<DIO_PIN2);
					DDRB |=(Copy_u8Direction<<DIO_PIN2);break;
				case DIO_PIN3:
					DDRB &= ~(1<<DIO_PIN3);
					DDRB |=(Copy_u8Direction<<DIO_PIN3);break;
				case DIO_PIN4:
					DDRB &= ~(1<<DIO_PIN4);
					DDRB |=(Copy_u8Direction<<DIO_PIN4);break;
				case DIO_PIN5:
					DDRB &= ~(1<<DIO_PIN5);
					DDRB |=(Copy_u8Direction<<DIO_PIN5);break;
				case DIO_PIN6:
					DDRB &= ~(1<<DIO_PIN6);
					DDRB |=(Copy_u8Direction<<DIO_PIN6);break;
				case DIO_PIN7:
					DDRB &= ~(1<<DIO_PIN7);
					DDRB |=(Copy_u8Direction<<DIO_PIN7);break;
				}
				break;
				case DIO_PORTC://SelectFromPortC
					switch(Copy_u8PinId)
					{
					case DIO_PIN0:
						DDRC &= ~(1<<DIO_PIN0);
						DDRC |=(Copy_u8Direction<<DIO_PIN0);break;
					case DIO_PIN1:
						DDRC &= ~(1<<DIO_PIN1);
						DDRC |=(Copy_u8Direction<<DIO_PIN1);break;
					case DIO_PIN2:
						DDRC &= ~(1<<DIO_PIN2);
						DDRC |=(Copy_u8Direction<<DIO_PIN2);break;
					case DIO_PIN3:
						DDRC &= ~(1<<DIO_PIN3);
						DDRC |=(Copy_u8Direction<<DIO_PIN3);break;
					case DIO_PIN4:
						DDRC &= ~(1<<DIO_PIN4);
						DDRC |=(Copy_u8Direction<<DIO_PIN4);break;
					case DIO_PIN5:
						DDRC &= ~(1<<DIO_PIN5);
						DDRC |=(Copy_u8Direction<<DIO_PIN5);break;
					case DIO_PIN6:
						DDRC &= ~(1<<DIO_PIN6);
						DDRC |=(Copy_u8Direction<<DIO_PIN6);break;
					case DIO_PIN7:
						DDRC &= ~(1<<DIO_PIN7);
						DDRC |=(Copy_u8Direction<<DIO_PIN7);break;
					}
					break;
					case DIO_PORTD://SelectFromPortD
						switch(Copy_u8PinId)
						{
						case DIO_PIN0:
							DDRD &= ~(1<<DIO_PIN0);
							DDRD |=(Copy_u8Direction<<DIO_PIN0);break;
						case DIO_PIN1:
							DDRD &= ~(1<<DIO_PIN1);
							DDRD |=(Copy_u8Direction<<DIO_PIN1);break;
						case DIO_PIN2:
							DDRD &= ~(1<<DIO_PIN2);
							DDRD |=(Copy_u8Direction<<DIO_PIN2);break;
						case DIO_PIN3:
							DDRD &= ~(1<<DIO_PIN3);
							DDRD |=(Copy_u8Direction<<DIO_PIN3);break;
						case DIO_PIN4:
							DDRD &= ~(1<<DIO_PIN4);
							DDRD |=(Copy_u8Direction<<DIO_PIN4);break;
						case DIO_PIN5:
							DDRD &= ~(1<<DIO_PIN5);
							DDRD |=(Copy_u8Direction<<DIO_PIN5);break;
						case DIO_PIN6:
							DDRD &= ~(1<<DIO_PIN6);
							DDRD |=(Copy_u8Direction<<DIO_PIN6);break;
						case DIO_PIN7:
							DDRD &= ~(1<<DIO_PIN7);
							DDRD |=(Copy_u8Direction<<DIO_PIN7);break;

						}
						break;

		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_Out_Of_Range;
	}



	return Local_enuErrorState;
}
ES_t DIO_enuSetPinVal(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8Value)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8PortId <= DIO_PORTD && Copy_u8PinId<= DIO_PIN7)
	{
		switch(Copy_u8PortId)
		{
		case DIO_PORTA://SelectFromPortA
			switch(Copy_u8PinId)
			{
			case DIO_PIN0:
				PORTA &= ~(1<<DIO_PIN0);
				PORTA |=(Copy_u8Value<<DIO_PIN0);break;
			case DIO_PIN1:
				PORTA &= ~(1<<DIO_PIN1);
				PORTA |=(Copy_u8Value<<DIO_PIN1);break;
			case DIO_PIN2:
				PORTA &= ~(1<<DIO_PIN2);
				PORTA |=(Copy_u8Value<<DIO_PIN2);break;
			case DIO_PIN3:
				PORTA &= ~(1<<DIO_PIN3);
				PORTA |=(Copy_u8Value<<DIO_PIN3);break;
			case DIO_PIN4:
				PORTA &= ~(1<<DIO_PIN4);
				PORTA |=(Copy_u8Value<<DIO_PIN4);break;
			case DIO_PIN5:
				PORTA &= ~(1<<DIO_PIN5);
				PORTA |=(Copy_u8Value<<DIO_PIN5);break;
			case DIO_PIN6:
				PORTA &= ~(1<<DIO_PIN6);
				PORTA |=(Copy_u8Value<<DIO_PIN6);break;
			case DIO_PIN7:
				PORTA &= ~(1<<DIO_PIN7);
				PORTA |=(Copy_u8Value<<DIO_PIN7);break;

			}
			break;
			case DIO_PORTB://SelectFromPortB
				switch(Copy_u8PinId)
				{
				case DIO_PIN0:
					PORTB &= ~(1<<DIO_PIN0);
					PORTB |=(Copy_u8Value<<DIO_PIN0);break;
				case DIO_PIN1:
					PORTB &= ~(1<<DIO_PIN1);
					PORTB |=(Copy_u8Value<<DIO_PIN1);break;
				case DIO_PIN2:
					PORTB &= ~(1<<DIO_PIN2);
					PORTB |=(Copy_u8Value<<DIO_PIN2);break;
				case DIO_PIN3:
					PORTB &= ~(1<<DIO_PIN3);
					PORTB |=(Copy_u8Value<<DIO_PIN3);break;
				case DIO_PIN4:
					PORTB &= ~(1<<DIO_PIN4);
					PORTB |=(Copy_u8Value<<DIO_PIN4);break;
				case DIO_PIN5:
					PORTB &= ~(1<<DIO_PIN5);
					PORTB |=(Copy_u8Value<<DIO_PIN5);break;
				case DIO_PIN6:
					PORTB &= ~(1<<DIO_PIN6);
					PORTB |=(Copy_u8Value<<DIO_PIN6);break;
				case DIO_PIN7:
					PORTB &= ~(1<<DIO_PIN7);
					PORTB |=(Copy_u8Value<<DIO_PIN7);break;
				}
				break;
				case DIO_PORTC://SelectFromPortC
					switch(Copy_u8PinId)
					{
					case DIO_PIN0:
						PORTC &= ~(1<<DIO_PIN0);
						PORTC |=(Copy_u8Value<<DIO_PIN0);break;
					case DIO_PIN1:
						PORTC &= ~(1<<DIO_PIN1);
						PORTC |=(Copy_u8Value<<DIO_PIN1);break;
					case DIO_PIN2:
						PORTC &= ~(1<<DIO_PIN2);
						PORTC |=(Copy_u8Value<<DIO_PIN2);break;
					case DIO_PIN3:
						PORTC &= ~(1<<DIO_PIN3);
						PORTC |=(Copy_u8Value<<DIO_PIN3);break;
					case DIO_PIN4:
						PORTC &= ~(1<<DIO_PIN4);
						PORTC |=(Copy_u8Value<<DIO_PIN4);break;
					case DIO_PIN5:
						PORTC &= ~(1<<DIO_PIN5);
						PORTC |=(Copy_u8Value<<DIO_PIN5);break;
					case DIO_PIN6:
						PORTC &= ~(1<<DIO_PIN6);
						PORTC |=(Copy_u8Value<<DIO_PIN6);break;
					case DIO_PIN7:
						PORTC &= ~(1<<DIO_PIN7);
						PORTC |=(Copy_u8Value<<DIO_PIN7);break;
					}
					break;
					case DIO_PORTD://SelectFromPortD
						switch(Copy_u8PinId)
						{
						case DIO_PIN0:
							PORTD &= ~(1<<DIO_PIN0);
							PORTD |=(Copy_u8Value<<DIO_PIN0);break;
						case DIO_PIN1:
							PORTD &= ~(1<<DIO_PIN1);
							PORTD |=(Copy_u8Value<<DIO_PIN1);break;
						case DIO_PIN2:
							PORTD &= ~(1<<DIO_PIN2);
							PORTD |=(Copy_u8Value<<DIO_PIN2);break;
						case DIO_PIN3:
							PORTD &= ~(1<<DIO_PIN3);
							PORTD |=(Copy_u8Value<<DIO_PIN3);break;
						case DIO_PIN4:
							PORTD &= ~(1<<DIO_PIN4);
							PORTD |=(Copy_u8Value<<DIO_PIN4);break;
						case DIO_PIN5:
							PORTD &= ~(1<<DIO_PIN5);
							PORTD |=(Copy_u8Value<<DIO_PIN5);break;
						case DIO_PIN6:
							PORTD &= ~(1<<DIO_PIN6);
							PORTD |=(Copy_u8Value<<DIO_PIN6);break;
						case DIO_PIN7:
							PORTD &= ~(1<<DIO_PIN7);
							PORTD |=(Copy_u8Value<<DIO_PIN7);break;

						}
						break;

		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_Out_Of_Range;
	}


	return Local_enuErrorState;
}
ES_t DIO_enuToggelPin(u8 Copy_u8PortId,u8 Copy_u8PinId)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_u8PortId <= DIO_PORTD && Copy_u8PinId<= DIO_PIN7)
	{
		switch(Copy_u8PortId)
		{
		case DIO_PORTA://SelectFromPortA
			switch(Copy_u8PinId)
			{
			case DIO_PIN0:

				PORTA ^=(1<<DIO_PIN0);break;
			case DIO_PIN1:

				PORTA ^=(1<<DIO_PIN1);break;
			case DIO_PIN2:

				PORTA ^=(1<<DIO_PIN2);break;
			case DIO_PIN3:

				PORTA ^=(1<<DIO_PIN3);break;
			case DIO_PIN4:

				PORTA ^=(1<<DIO_PIN4);break;
			case DIO_PIN5:

				PORTA ^=(1<<DIO_PIN5);break;
			case DIO_PIN6:

				PORTA ^=(1<<DIO_PIN6);break;
			case DIO_PIN7:

				PORTA ^=(1<<DIO_PIN7);break;

			}
			break;
			case DIO_PORTB://SelectFromPortB
				switch(Copy_u8PinId)
				{
				case DIO_PIN0:

					PORTB ^=(1<<DIO_PIN0);break;
				case DIO_PIN1:

					PORTB ^=(1<<DIO_PIN1);break;
				case DIO_PIN2:

					PORTB ^=(1<<DIO_PIN2);break;
				case DIO_PIN3:

					PORTB ^=(1<<DIO_PIN3);break;
				case DIO_PIN4:

					PORTB ^=(1<<DIO_PIN4);break;
				case DIO_PIN5:

					PORTB ^=(1<<DIO_PIN5);break;
				case DIO_PIN6:

					PORTB ^=(1<<DIO_PIN6);break;
				case DIO_PIN7:

					PORTB ^=(1<<DIO_PIN7);break;
				}
				break;
				case DIO_PORTC://SelectFromPortC
					switch(Copy_u8PinId)
					{
					case DIO_PIN0:

						PORTC ^=(1<<DIO_PIN0);break;
					case DIO_PIN1:

						PORTC ^=(1<<DIO_PIN1);break;
					case DIO_PIN2:

						PORTC ^=(1<<DIO_PIN2);break;
					case DIO_PIN3:

						PORTC ^=(1<<DIO_PIN3);break;
					case DIO_PIN4:

						PORTC ^=(1<<DIO_PIN4);break;
					case DIO_PIN5:

						PORTC ^=(1<<DIO_PIN5);break;
					case DIO_PIN6:

						PORTC ^=(1<<DIO_PIN6);break;
					case DIO_PIN7:

						PORTC ^=(1<<DIO_PIN7);break;
					}
					break;
					case DIO_PORTD://SelectFromPortD
						switch(Copy_u8PinId)
						{
						case DIO_PIN0:

							PORTD ^=(1<<DIO_PIN0);break;
						case DIO_PIN1:

							PORTD ^=(1<<DIO_PIN1);break;
						case DIO_PIN2:

							PORTD ^=(1<<DIO_PIN2);break;
						case DIO_PIN3:

							PORTD ^=(1<<DIO_PIN3);break;
						case DIO_PIN4:

							PORTD ^=(1<<DIO_PIN4);break;
						case DIO_PIN5:

							PORTD ^=(1<<DIO_PIN5);break;
						case DIO_PIN6:

							PORTD ^=(1<<DIO_PIN6);break;
						case DIO_PIN7:

							PORTD ^=(1<<DIO_PIN7);break;

						}
						break;

		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_Out_Of_Range;
	}


	return Local_enuErrorState;
}
ES_t DIO_enuGetPinVal(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 *Copy_u8Value)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8PortId <= DIO_PORTD && Copy_u8PinId<= DIO_PIN7)
	{
		switch(Copy_u8PortId)
		{
		case DIO_PORTA://SelectFromPortA
			switch(Copy_u8PinId)
			{
			case DIO_PIN0:

				*Copy_u8Value =((PINA>>DIO_PIN0)&1);break;
			case DIO_PIN1:

				*Copy_u8Value =((PINA>>DIO_PIN1)&1);break;
			case DIO_PIN2:

				*Copy_u8Value =((PINA>>DIO_PIN2)&1);break;
			case DIO_PIN3:

				*Copy_u8Value =((PINA>>DIO_PIN3)&1);break;
			case DIO_PIN4:

				*Copy_u8Value =((PINA>>DIO_PIN4)&1);break;
			case DIO_PIN5:

				*Copy_u8Value =((PINA>>DIO_PIN5)&1);break;
			case DIO_PIN6:

				*Copy_u8Value =((PINA>>DIO_PIN6)&1);break;
			case DIO_PIN7:

				*Copy_u8Value =((PINA>>DIO_PIN7)&1);break;

			}
			break;
			case DIO_PORTB://SelectFromPortB
				switch(Copy_u8PinId)
				{
				case DIO_PIN0:

					*Copy_u8Value =((PINB>>DIO_PIN0)&1);break;
				case DIO_PIN1:

					*Copy_u8Value =((PINB>>DIO_PIN1)&1);break;
				case DIO_PIN2:

					*Copy_u8Value =((PINB>>DIO_PIN2)&1);break;
				case DIO_PIN3:

					*Copy_u8Value =((PINB>>DIO_PIN3)&1);break;
				case DIO_PIN4:

					*Copy_u8Value =((PINB>>DIO_PIN4)&1);break;
				case DIO_PIN5:

					*Copy_u8Value =((PINB>>DIO_PIN5)&1);break;
				case DIO_PIN6:

					*Copy_u8Value =((PINB>>DIO_PIN6)&1);break;
				case DIO_PIN7:

					*Copy_u8Value =((PINB>>DIO_PIN7)&1);break;
				}
				break;
				case DIO_PORTC://SelectFromPortC
					switch(Copy_u8PinId)
					{
					case DIO_PIN0:

						*Copy_u8Value =((PINC>>DIO_PIN0)&1);break;
					case DIO_PIN1:

						*Copy_u8Value =((PINC>>DIO_PIN1)&1);break;
					case DIO_PIN2:

						*Copy_u8Value =((PINC>>DIO_PIN2)&1);break;
					case DIO_PIN3:

						*Copy_u8Value =((PINC>>DIO_PIN3)&1);break;
					case DIO_PIN4:

						*Copy_u8Value =((PINC>>DIO_PIN4)&1);break;
					case DIO_PIN5:

						*Copy_u8Value =((PINC>>DIO_PIN5)&1);break;
					case DIO_PIN6:

						*Copy_u8Value =((PINC>>DIO_PIN6)&1);break;
					case DIO_PIN7:

						*Copy_u8Value =((PINC>>DIO_PIN7)&1);break;
					}
					break;
					case DIO_PORTD://SelePINDomPortD
						switch(Copy_u8PinId)
						{
						case DIO_PIN0:

							*Copy_u8Value =((PIND>>DIO_PIN0)&1);break;
						case DIO_PIN1:

							*Copy_u8Value =((PIND>>DIO_PIN1)&1);break;
						case DIO_PIN2:

							*Copy_u8Value =((PIND>>DIO_PIN2)&1);break;
						case DIO_PIN3:

							*Copy_u8Value =((PIND>>DIO_PIN3)&1);break;
						case DIO_PIN4:

							*Copy_u8Value =((PIND>>DIO_PIN4)&1);break;
						case DIO_PIN5:

							*Copy_u8Value =((PIND>>DIO_PIN5)&1);break;
						case DIO_PIN6:

							*Copy_u8Value =((PIND>>DIO_PIN6)&1);break;
						case DIO_PIN7:

							*Copy_u8Value =((PIND>>DIO_PIN7)&1);break;
						}
						break;

		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_Out_Of_Range;
	}



	return Local_enuErrorState;
}

ES_t DIO_enuSetPortDir(u8 Copy_u8PortId,u8 Copy_u8Direction)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8PortId<= DIO_PORTD)
	{
		switch(Copy_u8PortId)
		{
		case DIO_PORTA:
			DDRA = Copy_u8Direction;
			break;
		case DIO_PORTB:
			DDRB = Copy_u8Direction;
					break;
		case DIO_PORTC:
			DDRC = Copy_u8Direction;
					break;
		case DIO_PORTD:
			DDRC = Copy_u8Direction;
					break;
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_Out_Of_Range;
	}

	return Local_enuErrorState;
}
ES_t DIO_enuSetPortVal(u8 Copy_u8PortId,u8 Copy_u8Value)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_u8PortId<= DIO_PORTD)
	{
		switch(Copy_u8PortId)
		{
		case DIO_PORTA:
			PORTA = Copy_u8Value;
			break;
		case DIO_PORTB:
			PORTB = Copy_u8Value;
			break;
		case DIO_PORTC:
			PORTC = Copy_u8Value;
			break;
		case DIO_PORTD:
			PORTD = Copy_u8Value;
			break;
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_Out_Of_Range;
		}



	return Local_enuErrorState;
}
ES_t DIO_enuGetPortVal(u8 Copy_u8PortId,u8 *Copy_u8Value)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8PortId<= DIO_PORTD)
		{
			switch(Copy_u8PortId)
			{
			case DIO_PORTA:
				*Copy_u8Value = PINA;
				break;
			case DIO_PORTB:
				*Copy_u8Value = PINB;
				break;
			case DIO_PORTC:
				*Copy_u8Value = PINC;
				break;
			case DIO_PORTD:
				*Copy_u8Value = PIND;
				break;
			}
			Local_enuErrorState = ES_OK;
		}
		else
		{
			Local_enuErrorState = ES_Out_Of_Range;
			}


	return Local_enuErrorState;
}
ES_t DIO_enuToggelPort(u8 Copy_u8PortId)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_u8PortId<= DIO_PORTD)
		{
			switch(Copy_u8PortId)
			{
			case DIO_PORTA:
				PORTA = ~PORTA;
				break;
			case DIO_PORTB:
				PORTB = ~PORTB;
				break;
			case DIO_PORTC:
				PORTC = ~PORTC;
				break;
			case DIO_PORTD:
				PORTD = ~PORTD;
				break;
			}
			Local_enuErrorState = ES_OK;
		}
		else
		{
			Local_enuErrorState = ES_Out_Of_Range;
			}



	return Local_enuErrorState;
}


#endif /* DIO_PROG_C_ */
