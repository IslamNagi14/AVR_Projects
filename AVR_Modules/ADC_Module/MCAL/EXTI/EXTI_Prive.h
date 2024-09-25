/*
 * EXTI_Prive.h
 *
 *  Created on: Sep 22, 2024
 *      Author: Islam Nagi
 */

#ifndef EXTI_EXTI_PRIVE_H_
#define EXTI_EXTI_PRIVE_H_

#define SREG   		*((volatile u8*)0x5F)
#define GIFR   		*((volatile u8*)0x5A)
#define MCUCSR   	*((volatile u8*)0x54)
#define MCUCR   	*((volatile u8*)0x55)
#define GICR   		*((volatile u8*)0x5B)

#define INT0		0
#define INT1		1
#define INT2		2

#define GICR_INT0		6
#define GICR_INT1		7
#define GICR_INT2		5

#define ISC00			0
#define ISC01			1
#define ISC10			2
#define ISC11			3
#define ISC2			6
#define ACTIVE				10
#define DECTIVE				45
#define FALLINGEDGE			56
#define RISINGEDGE			12
#define LOWLEVEL			20
#define ANY_LOGIC_CHANGE	89

#endif /* EXTI_EXTI_PRIVE_H_ */
