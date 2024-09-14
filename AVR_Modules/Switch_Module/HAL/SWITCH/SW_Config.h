/*
 * SW_Config.h
 *
 *  Created on: Aug 28, 2024
 *      Author: Islam Nagi
 */

#ifndef SW_CONFIG_H_
#define SW_CONFIG_H_

#include"../../LIB/errorStatuse.h"
#include"../../LIB/StdTypes.h"

#define SW_u8SwNUMS        3
#define SW_u8SwPressed     0
#define SW_u8SwNPressed    1
typedef struct
{
  u8 SW_u8PortID;
  u8 SW_u8PinID;
  u8 SW_u8SWconnection;
}SW_t;


#endif /* SW_CONFIG_H_ */
