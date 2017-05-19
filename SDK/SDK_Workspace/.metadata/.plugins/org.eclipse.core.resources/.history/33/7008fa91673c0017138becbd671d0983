/*
 * defines.h
 *
 *  Created on: 16.06.2015.
 *      Author: student
 */

#ifndef DEFINES_H_
#define DEFINES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "platform.h"
#include "xintc.h"
#include "xparameters.h"
#include "xio.h"
#include "xil_io.h"
#include "xil_exception.h"
#include "xbasic_types.h"
#include "fsl.h"

#define VGA_PERIPH_MEM_mWriteMemory(Address, Data) \
 	Xil_Out32(Address, (Xuint32)(Data))
#define VGA_PERIPH_MEM_mReadMemory(Address) \
 	Xil_In32(Address)

#define GRAPHICS_MEM_OFF 0x2000000
#define TEXT_MEM_OFF 0x1000000

#define INVADER_INIT_ROW 1
#define INIT_ROWS 2
#define INIT_COLS 9
#define INIT_NUM INIT_ROWS*INIT_COLS

#define SHIP_Y 14
#define MIN_SHIP_X 1
#define MAX_SHIP_X 78

#define MAX_PROJECTILES_Y 15
#define MAX_PROJECTILES_X 80

#define LEFT 0
#define RIGHT 1
#define DOWN 0

#define LEFT_JOY 23
#define MIDDLE_JOY 27
#define RIGHT_JOY 29
#define DOWN_JOY 30

#define INVADER_SPEED 40
#define PROJECTILE_SPEED 12
#define SHOOT_SPEED 25

#define INIT_LIVES 3

#define PUT_TO_FSL(address, value) \
	do{ \
		putfsl(address, 0); \
		putfsl(value, 0); \
	}while(0)





#endif /* DEFINES_H_ */
