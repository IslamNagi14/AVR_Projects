/*
 * SEG_Config.h
 *
 *  Created on: Aug 26, 2024
 *      Author: Islam Nagi
 */

#ifndef SE7SEG_CONFIG_H_
#define SE7SEG_CONFIG_H_

#include"StdTypes.h"
#include"errorStatuse.h"
#define SE7SEG_u8NUMBER  	 2
#define SE7Pin_u8NUMBER  	 7
#define SE7SEG_u8Ccath     	 1
#define SE7SEG_u8CAnod       0

#define SE7SEG_u8TurnOn     1
#define SE7SEG_u8TurnOff    0
typedef struct
{
	struct
	{
		u8 SE7SEG_u8PortID; //A,B,C,D
		u8 SE7SEG_u8PinID;//01234567
	}SE7SEG_A[SE7Pin_u8NUMBER];
	u8 SE7SEG_u8Connection;//anode_cathod

}SE7SEG_t;

typedef struct
{
	u8 SE7SEG_u8PortID; //A,B,C,D
	u8 SE7SEG_u8PinID;//01234567
}SETUP_t;



#endif /* 7SEG_CONFIG_H_ */
