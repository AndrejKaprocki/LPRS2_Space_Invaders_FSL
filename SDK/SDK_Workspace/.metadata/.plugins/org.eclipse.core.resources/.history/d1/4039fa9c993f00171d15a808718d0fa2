/*
 * SI_globals.c
 *
 *  Created on: 16.06.2015.
 *      Author: student
 */

#include "SI_globals.h"

/* init variables for interrupts */
XIntc Intc;

Xuint8	spaceship_speed = 8,
		spaceship_speed_cnt = 0,
		spaceship_x = 0,
		projectil_speed = 0,
		spaceship_flag = 0,
		projectil_flag = 0,
		invader_speed = 0,
		shoot_flag = 0,
		invader_shoot_flag = 0,
		counter = 0,
		move_faster = 0,
		level = 0,
		print_level = 0,
		invaders_num = INIT_NUM,
		game_over = 0,
		lives = INIT_LIVES,
		seed = 0,
		input = 0;

Xuint8 flag_row[INIT_ROWS];
/****************************/

/* main variables/maps */
Xuint8 invaders_map[MAX_PROJECTILES_X][MAX_PROJECTILES_Y];
Xuint8 invaders_num;

Xuint8 projectiles_of_ship_num[MAX_PROJECTILES_X];	//Number of projectiles in column
Xuint8 projectiles_of_invaders_num[MAX_PROJECTILES_X];
Xuint8 projectiles_map[MAX_PROJECTILES_X][MAX_PROJECTILES_Y];
/****************************/

Xuint32 cursor_position = 0;
