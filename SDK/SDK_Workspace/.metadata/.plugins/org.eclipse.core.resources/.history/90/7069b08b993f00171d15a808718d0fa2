/*
 * SI_init.c
 *
 *  Created on: 16.06.2015.
 *      Author: student
 */

#include "SI_interrupt.h"

void vga_interrupt_handler(void *BaseAddress)
{
	int i;

	input = VGA_PERIPH_MEM_mReadMemory(XPAR_MY_PERIPHERAL_0_BASEADDR);

	/* spaceship and projectiles signals */
	if(spaceship_speed_cnt >= (spaceship_speed))
	{
		spaceship_flag = 1;
		spaceship_speed_cnt = 0;
	}
	else
		spaceship_speed_cnt+=2;


	if(projectil_speed == PROJECTILE_SPEED)
	{
		projectil_flag = 1;
		projectil_speed = 0;
	}
	else
		projectil_speed+=1;
	/*************************************/

	/* signals for movement of rows of invaders */
	for(i = INIT_ROWS - 1 + level - 1; i >= 0; i--)
	{
		if(invader_speed == (INVADER_SPEED*(INIT_ROWS + level - 1 - i)) - (print_level-1)*3)
		{
			flag_row[i] = 1;
			if(i == 0)
				invader_speed = 0;
		}
	}

	invader_speed++;
	/*************************************/

	if(shoot_flag != 0)
	{
		shoot_flag--;
	}

	if(counter == (30 - (level+8)*2))
	{
		counter = 0;
		invader_shoot_flag = 1;
	}
	counter++;
}

void init_interrupt_controller()
{
	XStatus Status;

	XIo_Out32(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x54, 0x1E0); //init terminal counter on 524
	XIo_Out32(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x58, 1);		//enable timer

	//initialize interrupt controller
	Status = XIntc_Initialize (&Intc, XPAR_INTC_0_DEVICE_ID);
	if (Status != XST_SUCCESS)
		xil_printf ("\r\nInterrupt controller initialization failure");
	else
		xil_printf("\r\nInterrupt controller initialized");

	// Connect interrupt_handler
	Status = XIntc_Connect (&Intc, 0, (XInterruptHandler) vga_interrupt_handler, (void *)0);

	if (Status != XST_SUCCESS)
		xil_printf ("\r\nRegistering MY_TIMER Interrupt Failed");
	else
		xil_printf("\r\nMY_TIMER Interrupt registered");

	//Start the interrupt controller in real mode
	Status = XIntc_Start(&Intc, XIN_REAL_MODE);

	//Enable interrupt controller
	XIntc_Enable (&Intc, 0);
	microblaze_enable_interrupts();
}
