/*
 * EXTI_config.c
 *
 *  Created on: Sep 22, 2024
 *      Author: Islam Nagi
 */


#include"../../LIB/StdTypes.h"
#include"EXTI_int.h"
#include"EXTI_Config.h"

EXTI_t EXTI_AstrINTConfig[INT_NUMBERS] =
						  	  	  	  	  {
						  	  	  	  			  {EXTI_u8ACTIVE,EXTI_u8RISINGEDGE},
												  {EXTI_u8ACTIVE,EXTI_u8ANY_LOGIC_CHANGE},
												  {EXTI_u8ACTIVE,EXTI_u8FALLINGEDGE}
						  	  	  	  	  };
