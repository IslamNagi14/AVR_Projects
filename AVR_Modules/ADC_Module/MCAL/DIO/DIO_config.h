/*
 * DIO_config.h
 *
 *  Created on: Sep 17, 2024
 *      Author: Islam Nagi
 */

#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_

#include"../../LIB/StdTypes.h"
#include"../../LIB/errorStatuse.h"
#include"DIO_int.h"

/*         PORTA */
#define PA_PIN0_DIR				DIO_u8OUTPUT
#define PA_PIN1_DIR				DIO_u8OUTPUT
#define PA_PIN2_DIR				DIO_u8INPUT
#define PA_PIN3_DIR				DIO_u8OUTPUT
#define PA_PIN4_DIR				DIO_u8OUTPUT
#define PA_PIN5_DIR				DIO_u8OUTPUT
#define PA_PIN6_DIR				DIO_u8INPUT
#define PA_PIN7_DIR				DIO_u8INPUT

#define PA_PIN0_VAL				DIO_u8HIGH
#define PA_PIN1_VAL				DIO_u8HIGH
#define PA_PIN2_VAL				DIO_u8PULL_UP
#define PA_PIN3_VAL				DIO_u8HIGH
#define PA_PIN4_VAL				DIO_u8LOW
#define PA_PIN5_VAL				DIO_u8HIGH
#define PA_PIN6_VAL				DIO_u8FLOAT
#define PA_PIN7_VAL				DIO_u8PULL_UP

/*         PORTB */

#define PB_PIN0_DIR				DIO_u8OUTPUT
#define PB_PIN1_DIR				DIO_u8OUTPUT
#define PB_PIN2_DIR				DIO_u8OUTPUT
#define PB_PIN3_DIR				DIO_u8INPUT
#define PB_PIN4_DIR				DIO_u8OUTPUT
#define PB_PIN5_DIR				DIO_u8OUTPUT
#define PB_PIN6_DIR				DIO_u8INPUT
#define PB_PIN7_DIR				DIO_u8OUTPUT


#define PB_PIN0_VAL				DIO_u8HIGH
#define PB_PIN1_VAL				DIO_u8LOW
#define PB_PIN2_VAL				DIO_u8HIGH
#define PB_PIN3_VAL				DIO_u8FLOAT
#define PB_PIN4_VAL				DIO_u8HIGH
#define PB_PIN5_VAL				DIO_u8HIGH
#define PB_PIN6_VAL				DIO_u8PULL_UP
#define PB_PIN7_VAL				DIO_u8HIGH

/*         PORTC */

#define PC_PIN0_DIR				DIO_u8OUTPUT
#define PC_PIN1_DIR				DIO_u8OUTPUT
#define PC_PIN2_DIR				DIO_u8INPUT
#define PC_PIN3_DIR				DIO_u8OUTPUT
#define PC_PIN4_DIR				DIO_u8OUTPUT
#define PC_PIN5_DIR				DIO_u8INPUT
#define PC_PIN6_DIR				DIO_u8OUTPUT
#define PC_PIN7_DIR				DIO_u8OUTPUT

#define PC_PIN0_VAL				DIO_u8HIGH
#define PC_PIN1_VAL				DIO_u8HIGH
#define PC_PIN2_VAL				DIO_u8PULL_UP
#define PC_PIN3_VAL				DIO_u8HIGH
#define PC_PIN4_VAL				DIO_u8LOW
#define PC_PIN5_VAL				DIO_u8HIGH
#define PC_PIN6_VAL				DIO_u8PULL_UP
#define PC_PIN7_VAL				DIO_u8HIGH


/*         PORTD */

#define PD_PIN0_DIR				DIO_u8OUTPUT
#define PD_PIN1_DIR				DIO_u8OUTPUT
#define PD_PIN2_DIR				DIO_u8OUTPUT
#define PD_PIN3_DIR				DIO_u8INPUT
#define PD_PIN4_DIR				DIO_u8OUTPUT
#define PD_PIN5_DIR				DIO_u8OUTPUT
#define PD_PIN6_DIR				DIO_u8OUTPUT
#define PD_PIN7_DIR				DIO_u8OUTPUT

#define PD_PIN0_VAL				DIO_u8HIGH
#define PD_PIN1_VAL				DIO_u8LOW
#define PD_PIN2_VAL				DIO_u8HIGH
#define PD_PIN3_VAL				DIO_u8FLOAT
#define PD_PIN4_VAL				DIO_u8HIGH
#define PD_PIN5_VAL				DIO_u8LOW
#define PD_PIN6_VAL				DIO_u8HIGH
#define PD_PIN7_VAL				DIO_u8HIGH



#endif /* DIO_CONFIG_H_ */
