
/*
 * SI_main.c
 *
 *  Created on: 16.06.2015.
 *      Authors: Standzi, Marko, Dva geja (Urosko i Milan GAY)
 */

#include "SI_logic.h"
#include "SI_interrupt.h"
#include <stdlib.h>



void init_colors()
{
	/* Define colors */
	VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x10, 0x27104f);	//color 0
	VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x14, 0x90edac);	//color 1
	VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x18, 0xff0000);	//color 2
	VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x1C, 0xa0a0a0);	//color 3 siva
	VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x20, 0x00ffff);	//color 4
	VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x24, 0xff00ff);	//color 5
	VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x28, 0xffff00);	//color 6
	VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x2C, 0x000000);	//color 7
	VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x30, 0xffffff);	//color 8
	VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x34, 0xff1493);	//color 9
	VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x38, 0xff6666);	//color 10 A
	VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x3C, 0x556b2f);	//color 11 B
	VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x40, 0x191970);	//color 12 C
	VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x44, 0xb8860b);	//color 13 D
	VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x48, 0xffe4c4);	//color 14 E
	VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x4C, 0xd2691e);	//color 15 F
}

void init_variables(Xuint8* spaceship_dir, Xuint8* invader_dir, Xuint8* invader_dir_chng, Xuint8* row)
{
	int i, j;

	/* Init all arrays and variables */
	for(i = 0; i < INIT_ROWS + level - 1; i++)
	{
		invader_dir[i] = RIGHT;
		invader_dir_chng[i] = 1;
		row[i] = i + INVADER_INIT_ROW;

		flag_row[i] = 0;
	}

	spaceship_speed_cnt = 0;
	projectil_speed = 0;
	spaceship_flag = 0;
	projectil_flag = 0;
	invader_speed = 0;
	shoot_flag = 0;
	invader_shoot_flag = 0;
	counter = 0;
	invaders_num = INIT_NUM + INIT_COLS*(level-1);
	game_over = 0;
	move_faster = 0,
	seed = 0;
	input = 0;

	if(level - 1 == 0)
	{
		*spaceship_dir = 0;
		spaceship_x = 7;
		lives = INIT_LIVES;
	}

	for(i = 0; i < MAX_PROJECTILES_X; i++)
	{
		projectiles_of_ship_num[i] = 0;
		projectiles_of_invaders_num[i] = 0;

		for(j = 0; j < MAX_PROJECTILES_Y; j++)
		{
			projectiles_map[i][j] = 0;
			invaders_map[i][j] = 0;
		}
	}
}

void init_draw(Xuint8* row)
{
	int i, j;

	//if(level - 1 == 0)
		draw_ship(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, spaceship_x, SHIP_Y);

	for(i = 0; i < INIT_ROWS + level - 1; i++)
	{
		for(j = 0; j < MAX_PROJECTILES_X; j++)
		{
			if(invaders_map[j][row[i]])
			{
				draw_invader(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, j, row[i], invaders_map[j][row[i]]);
			}
		}
	}
}
void draw_ball(int x, int y, int x_prev, int y_prev)
{
	PUT_TO_FSL(((y_prev-6)*80 + x_prev), 0x11111111);
	PUT_TO_FSL(((y_prev-5)*80 + x_prev), 0x11111111);
	PUT_TO_FSL(((y_prev-4)*80 + x_prev), 0x11111111);
	PUT_TO_FSL(((y_prev-3)*80 + x_prev), 0x11111111);
	PUT_TO_FSL(((y_prev-2)*80 + x_prev), 0x11111111);
	PUT_TO_FSL(((y_prev-1)*80 + x_prev), 0x11111111);
	PUT_TO_FSL((y_prev*80 + x_prev), 0x11111111);
	PUT_TO_FSL(((y_prev+1)*80 + x_prev), 0x11111111);
	PUT_TO_FSL(((y_prev+2)*80 + x_prev), 0x11111111);
	PUT_TO_FSL(((y_prev+3)*80 + x_prev), 0x11111111);
	PUT_TO_FSL(((y_prev+4)*80 + x_prev), 0x11111111);
	PUT_TO_FSL(((y_prev+5)*80 + x_prev), 0x11111111);
	PUT_TO_FSL(((y_prev+6)*80 + x_prev), 0x11111111);

	PUT_TO_FSL(((y_prev-6)*80 + x_prev+1), 0x11111111);
	PUT_TO_FSL(((y_prev-5)*80 + x_prev+1), 0x11111111);
	PUT_TO_FSL(((y_prev-4)*80 + x_prev+1), 0x11111111);
	PUT_TO_FSL(((y_prev-3)*80 + x_prev+1), 0x11111111);
	PUT_TO_FSL(((y_prev-2)*80 + x_prev+1), 0x11111111);
	PUT_TO_FSL(((y_prev-1)*80 + x_prev+1), 0x11111111);
	PUT_TO_FSL((y_prev*80 + x_prev+1), 0x11111111);
	PUT_TO_FSL(((y_prev+1)*80 + x_prev+1), 0x11111111);
	PUT_TO_FSL(((y_prev+2)*80 + x_prev+1), 0x11111111);
	PUT_TO_FSL(((y_prev+3)*80 + x_prev+1), 0x11111111);
	PUT_TO_FSL(((y_prev+4)*80 + x_prev+1), 0x11111111);
	PUT_TO_FSL(((y_prev+5)*80 + x_prev+1), 0x11111111);
	PUT_TO_FSL(((y_prev+6)*80 + x_prev+1), 0x11111111);

	PUT_TO_FSL(((y-6)*80 + x), 0x11113333);
	PUT_TO_FSL(((y-5)*80 + x), 0x11333333);
	PUT_TO_FSL(((y-4)*80 + x), 0x13333333);
	PUT_TO_FSL(((y-3)*80 + x), 0x33333333);
	PUT_TO_FSL(((y-2)*80 + x), 0x33333333);
	PUT_TO_FSL(((y-1)*80 + x), 0x33333333);
	PUT_TO_FSL((y*80 + x), 0x33333333);
	PUT_TO_FSL(((y+1)*80 + x), 0x33333333);
	PUT_TO_FSL(((y+2)*80 + x), 0x33333333);
	PUT_TO_FSL(((y+3)*80 + x), 0x33333333);
	PUT_TO_FSL(((y+4)*80 + x), 0x13333333);
	PUT_TO_FSL(((y+5)*80 + x), 0x11333333);
	PUT_TO_FSL(((y+6)*80 + x), 0x11113333);

	PUT_TO_FSL(((y-6)*80 + x+1), 0x33331111);
	PUT_TO_FSL(((y-5)*80 + x+1), 0x33333311);
	PUT_TO_FSL(((y-4)*80 + x+1), 0x33333331);
	PUT_TO_FSL(((y-3)*80 + x+1), 0x33333333);
	PUT_TO_FSL(((y-2)*80 + x+1), 0x33333333);
	PUT_TO_FSL(((y-1)*80 + x+1), 0x33333333);
	PUT_TO_FSL((y*80 + x+1), 0x33333333);
	PUT_TO_FSL(((y+1)*80 + x+1), 0x33333333);
	PUT_TO_FSL(((y+2)*80 + x+1), 0x33333333);
	PUT_TO_FSL(((y+3)*80 + x+1), 0x33333333);
	PUT_TO_FSL(((y+4)*80 + x+1), 0x33333331);
	PUT_TO_FSL(((y+5)*80 + x+1), 0x33333311);
	PUT_TO_FSL(((y+6)*80 + x+1), 0x33331111);
}
void draw_left_leg(int index)
{

	int pom,i,j;
	for(i=440;i<445;i++)
	{
		int m=0;
		for(j=34;j<40;j++)
		{
			pom=(i+m)*80+j;
			m+=index;
			PUT_TO_FSL(pom, 0xbbbbbbbb);
		}
	}
}
void erase_left_leg(int index)
{
	int pom,i,j;
	for(i=440;i<445;i++)
	{
		int m=0;
		for(j=34;j<40;j++)
		{
			pom=(i+m)*80+j;
			m+=index;
			PUT_TO_FSL(pom, 0x11111111);
		}
	}
}
void draw_right_leg(int index)
{
	int pom,i,j;
	for(i=440;i<445;i++)
	{
		int m=index*5;
		for(j=44;j<=49;j++)
		{
			pom=(i+m)*80+j;
			m-=index;
			PUT_TO_FSL(pom, 0xbbbbbbbb);
		}
	}
}
void erase_right_leg(int index)
{
	int pom,i,j;
		for(i=440;i<445;i++)
		{
			int m=index*5;
			for(j=44;j<=49;j++)
			{
				pom=(i+m)*80+j;
				m-=index;
				PUT_TO_FSL(pom, 0x11111111);
			}
		}
}
void move_left_leg()
{
	draw_left_leg(3);
	draw_left_leg(3);
	erase_left_leg(3);
	draw_left_leg(2);
	draw_left_leg(2);
	erase_left_leg(2);
	draw_left_leg(1);
	draw_left_leg(1);
	erase_left_leg(1);
	draw_left_leg(0);
	draw_left_leg(0);
	erase_left_leg(0);
	draw_left_leg(-1);
	draw_left_leg(-1);
	erase_left_leg(-1);
	draw_left_leg(-2);
	draw_left_leg(-2);
	erase_left_leg(-2);
	draw_left_leg(-3);
	draw_left_leg(-3);
	erase_left_leg(-3);
	draw_left_leg(-2);
	draw_left_leg(-2);
	erase_left_leg(-2);
	draw_left_leg(-1);
	draw_left_leg(-1);
	erase_left_leg(-1);
	draw_left_leg(0);
	draw_left_leg(0);
	erase_left_leg(0);
	draw_left_leg(1);
	draw_left_leg(1);
	erase_left_leg(1);
	draw_left_leg(2);
	draw_left_leg(2);
	erase_left_leg(2);
	draw_left_leg(3);
	draw_left_leg(3);
}
void move_right_leg()
{
	draw_right_leg(3);
	draw_right_leg(3);
	erase_right_leg(3);
	draw_right_leg(2);
	draw_right_leg(2);
	erase_right_leg(2);
	draw_right_leg(1);
	draw_right_leg(1);
	erase_right_leg(1);
	draw_right_leg(0);
	draw_right_leg(0);
	erase_right_leg(0);
	draw_right_leg(-1);
	draw_right_leg(-1);
	erase_right_leg(-1);
	draw_right_leg(-2);
	draw_right_leg(-2);
	erase_right_leg(-2);
	draw_right_leg(-3);
	draw_right_leg(-3);
	erase_right_leg(-3);
	draw_right_leg(-2);
	draw_right_leg(-2);
	erase_right_leg(-2);
	draw_right_leg(-1);
	draw_right_leg(-1);
	erase_right_leg(-1);
	draw_right_leg(0);
	draw_right_leg(0);
	erase_right_leg(0);
	draw_right_leg(1);
	draw_right_leg(1);
	erase_right_leg(1);
	draw_right_leg(2);
	draw_right_leg(2);
	erase_right_leg(2);
	draw_right_leg(3);
	draw_right_leg(3);
}
void draw_background()
{
	int i,j,pom;
	for(i=0;i<410;i++)
		{
			for(j=30;j<=54;j++)
			{
				if(i<=10)
				{
					pom = i*80 + j;
					PUT_TO_FSL(pom, 0x44444444);
				}
			}
			pom = i*80 + 29;
			PUT_TO_FSL(pom, 0x44444444);
			pom = i*80 + 54;
			PUT_TO_FSL(pom, 0x44444444);



		}
		int pom1=30;
		int pom2=29;
		int pom4=53;
		int pom3=54;
		while(i<440)
		{
				pom=i*80+pom1;
				PUT_TO_FSL(pom, 0x41111111);
				pom=i*80+pom2;
				PUT_TO_FSL(pom, 0x14444444);
				pom=i*80+pom4;
				PUT_TO_FSL(pom, 0x11111114);
				pom=i*80+pom3;
				PUT_TO_FSL(pom, 0x44444441);
				i++;

				pom=i*80+pom1;
				PUT_TO_FSL(pom, 0x44111111);
				pom=i*80+pom2;
				PUT_TO_FSL(pom, 0x11444444);
				pom=i*80+pom4;
				PUT_TO_FSL(pom, 0x11111144);
				pom=i*80+pom3;
				PUT_TO_FSL(pom, 0x44444411);
				i++;

				pom=i*80+pom1;
				PUT_TO_FSL(pom, 0x44411111);
				pom=i*80+pom2;
				PUT_TO_FSL(pom, 0x11144444);
				pom=i*80+pom4;
				PUT_TO_FSL(pom, 0x11111444);
				pom=i*80+pom3;
				PUT_TO_FSL(pom, 0x44444111);
				i++;

				pom=i*80+pom1;
				PUT_TO_FSL(pom, 0x44441111);
				pom=i*80+pom2;
				PUT_TO_FSL(pom, 0x11114444);
				pom=i*80+pom4;
				PUT_TO_FSL(pom, 0x11114444);
				pom=i*80+pom3;
				PUT_TO_FSL(pom, 0x44441111);
				i++;

				pom=i*80+pom1;
				PUT_TO_FSL(pom, 0x44444111);
				pom=i*80+pom2;
				PUT_TO_FSL(pom, 0x11111444);
				pom=i*80+pom4;
				PUT_TO_FSL(pom, 0x11144444);
				pom=i*80+pom3;
				PUT_TO_FSL(pom, 0x44411111);
				i++;

				pom=i*80+pom1;
				PUT_TO_FSL(pom, 0x44444411);
				pom=i*80+pom2;
				PUT_TO_FSL(pom, 0x11111144);
				pom=i*80+pom4;
				PUT_TO_FSL(pom, 0x11444444);
				pom=i*80+pom3;
				PUT_TO_FSL(pom, 0x44111111);
				i++;


				pom=i*80+pom1;
				PUT_TO_FSL(pom, 0x44444441);
				pom=i*80+pom2;
				PUT_TO_FSL(pom, 0x11111114);
				pom=i*80+pom4;
				PUT_TO_FSL(pom, 0x14444444);
				pom=i*80+pom3;
				PUT_TO_FSL(pom, 0x41111111);
				i++;

				pom=i*80+pom1;
				PUT_TO_FSL(pom, 0x44444444);
				pom=i*80+pom2;
				PUT_TO_FSL(pom, 0x11111111);
				pom=i*80+pom4;
				PUT_TO_FSL(pom, 0x44444444);
				pom=i*80+pom3;
				PUT_TO_FSL(pom, 0x11111111);
				i++;

				pom1++;
				pom2++;
				pom3--;
				pom4--;

		}

}


void clear_text_screen(Xuint32 BaseAddress)
{
   	int i;

    for (i = 0; i < 4800; i++)
    {
        VGA_PERIPH_MEM_mWriteMemory(BaseAddress + TEXT_MEM_OFF + i*4, 0x20);
    }
}

void print_string(Xuint32 BaseAddress, char string_s[], int lenght)
{
    int i;

    for (i = 0; i < lenght; i++)
    {
        VGA_PERIPH_MEM_mWriteMemory(BaseAddress + TEXT_MEM_OFF + cursor_position + i*4, (string_s[i]-0x40));
    }
}

void set_cursor(Xuint32 new_value)
{
    cursor_position = new_value;
}

int num_len(int num)
{
	int len = 0;

	if(num == 0)
	{
		len++;
	}
	else
	{
		while(num > 0)
		{
			num /= 10;
			len++;
		}
	}

	return len;
}

void num_to_str(char *s, unsigned long bin, unsigned char n)
{
    s += n;
    *s = '\0';

    while (n--)
    {
        --s;
    	*s = (bin % 10) + '0';
        bin /= 10;
    }
}

/*int ball_next_y(ball_y,ball_angle)
{
	if(ball_angle>=0 && ball_angle<90)
	{
		return ball_y-tan(ball_angle*3.81/360);
	}

	if(ball_angle>=90 && ball_angle<180)
	{
		return 1;
	}

	if(ball_angle>=180 && ball_angle<270)
	{
		return 1;
	}

	if(ball_angle>=270 && ball_angle<360)
	{
		return 1;
	}
}*/

int main()
{
	/*************************/
	/* VARIABLES DECLARATION */
	/*************************/
	/*
	Xuint8 i, j, k1, k2, k3;
	Xuint8 spaceship_dir;
	Xuint8 invader_x;

	Xuint8* row;
	Xuint8* invader_dir;
	Xuint8* invader_dir_chng;

	int old_lives = 0, old_invaders_num = 0, old_level = -1;
	int score = 0, old_score = 0;
	char* str = NULL;

	init_platform();
	init_interrupt_controller();
	init_colors();

	clear_text_screen(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR);

	while(1)
	{
		clear_graphics_screen(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR);

		VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x04, 0b01);    //text mode

		set_cursor(8115);
		print_string(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, "PRESS KEY DOWN TO START", strlen("PRESS KEY DOWN TO START"));

		while(input != 30)	//wait for input from user
		{
			input = VGA_PERIPH_MEM_mReadMemory(XPAR_MY_PERIPHERAL_0_BASEADDR);
			seed++;
		}
		srand(seed);

		VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x04, 0b11);	//display and text mode
		set_cursor(666);
		clear_text_screen(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR);
		print_string(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, "SCORE", strlen("SCORE"));

		set_cursor(688);
		num_to_str(str, 0, num_len(0));
		print_string(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, str, strlen(str));

		set_cursor(710);
		print_string(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, "LIVES", strlen("LIVES"));

		set_cursor(732);
		num_to_str(str, lives, num_len(lives));
		print_string(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, str, strlen(str));

		set_cursor(751);
		print_string(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, "LEVEL", strlen("LEVEL"));

		game_over = 0;
		level = 0;
		print_level = 0;
		old_level = -1;
		score = 0;
		old_score = 0;
		j = 1;

		while(!game_over)
		{
			print_level++;

			if(level < 4)
			{
				level++;
			}

			old_score += score;

			row = (Xuint8*) malloc((INIT_ROWS+level-1)*sizeof(Xuint8));
			invader_dir = (Xuint8*) malloc((INIT_ROWS+level-1)*sizeof(Xuint8));
			invader_dir_chng = (Xuint8*) malloc((INIT_ROWS+level-1)*sizeof(Xuint8));

			init_variables(&spaceship_dir, invader_dir, invader_dir_chng, row);
			generate_init_invaders_positions();

			clear_graphics_screen(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR);

			if(level > 1)
			{
				for(k1 = 0; k1 < 230; k1++)
					for(k2 = 0; k2 < 230; k2++)
						for(k3 = 0; k3 < 20; k3++)
						{
							set_cursor(6543);
							print_string(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, "NEXT LEVEL", 10);
						}
				clear_text_screen(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR);
				set_cursor(666);
				clear_text_screen(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR);
				print_string(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, "SCORE", strlen("SCORE"));

				set_cursor(688);
				num_to_str(str, 0, num_len(0));
				print_string(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, str, strlen(str));

				set_cursor(710);
				print_string(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, "LIVES", strlen("LIVES"));

				set_cursor(732);
				num_to_str(str, lives, num_len(lives));
				print_string(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, str, strlen(str));

				set_cursor(751);
				print_string(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, "LEVEL", strlen("LEVEL"));

			}

			init_draw(row);

			while(!((invaders_num == 0) || (game_over == 1)))
			{
				switch(input)
				{
					case LEFT_JOY:
							spaceship_dir = LEFT;
							spaceship_speed = 4;
							break;

					case RIGHT_JOY:
							spaceship_dir = RIGHT;
							spaceship_speed = 4;
							break;

					case MIDDLE_JOY:
							if(shoot_flag == 0)
							{
								shoot_projectile_from_ship(spaceship_x);
								shoot_flag = SHOOT_SPEED;
							}
							break;
				}

				if(input != LEFT_JOY && input != RIGHT_JOY) //STISNUT NEKI JOY
				{
					spaceship_speed = 8;
				}


				if(spaceship_flag)	//time to move spaceship
				{
					move_spaceship(&spaceship_dir);
					spaceship_flag = 0;
				}

				if(projectil_flag)	//time to move projectiles
				{
					move_projectile_from_ship();
					move_projectile_from_invader();
					projectil_flag = 0;
				}

				if(invader_shoot_flag)
				{
					invader_x = rand()%80;
					shoot_projectile_from_invader(invader_x, row);
					invader_shoot_flag = 0;
				}

				for(i = 0; i < INIT_ROWS + level - 1; i++)
				{
					if(flag_row[i])	//time to move this row of invaders?
					{
						if(invader_dir_chng[i] == DOWN)	//time to move rows down?
						{
							invader_dir_chng[i]++;
							move_invaders_down(row, i);
						}
						else							//if not, move rows left/right
							move_invaders_row(row, invader_dir, invader_dir_chng, i);

						flag_row[i] = 0;
					}
				}

				if(old_invaders_num != invaders_num)
				{
					set_cursor(688);
					score = (INIT_NUM + INIT_COLS*(level-1) - invaders_num)*10;
					num_to_str(str, score + old_score, num_len(score + old_score));
					print_string(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, str, strlen(str));
					old_invaders_num = invaders_num;

					if(score + old_score > 500*j)
					{
						j++;
						lives++;
					}
				}

				if(old_lives != lives)
				{
					set_cursor(732);
					num_to_str(str, lives, num_len(lives));
					print_string(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, str, strlen(str));
					old_lives = lives;
				}

				if(old_level != print_level)
				{
					set_cursor(751 + 24);
					num_to_str(str, print_level, num_len(print_level));
					print_string(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, str, strlen(str));
					old_level = print_level;
				}
			}

			free(row);
			free(invader_dir);
			free(invader_dir_chng);
		}

		VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x04, 0b01);    //text mode
		clear_text_screen(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR);

		set_cursor(3660);
		print_string(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, "GAME OVER", 9);

		set_cursor(6543);
		print_string(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, "SCORE", 5);

		set_cursor(6543 + 24);
		num_to_str(str, score + old_score, num_len(score + old_score));
		print_string(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, str, num_len(score + old_score));

	}
	*/
	init_platform();
	init_interrupt_controller();
	init_colors();

	VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x04, 0b11);	//display and text mode
	int i,j,pom;
	clear_graphics_screen(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR);
	set_foreground_color(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, 0x000000);
	draw_background();
	set_background_color(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, 0x000000);
	//draw_block(20,45,21,41,26,40);
	//draw_block(40,15,41,11,16,40);
	//draw_block(285,44,300,47,285,51); //y x; a d b

	//print_string(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, "LEVEL", strlen("LEVEL"));
	//draw_minus_two();
	//draw_leg();
	draw_left_leg(2);
	draw_right_leg(2);
	draw_ball(200,50, 0,0);
	lives=1;
	int in_game=0;
	int ball_x, ball_y, ball_x_prev, ball_y_prev, move_ball=0;
	int ball_angle=350;
	//while(1)
		/*while(input != 30)	//wait for input from user
		{
			input = VGA_PERIPH_MEM_mReadMemory(XPAR_MY_PERIPHERAL_0_BASEADDR);
			seed++;
		}
		srand(seed);*/

		VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x04, 0b11);
		game_over = 0;

				while(!game_over)
				{
						input = VGA_PERIPH_MEM_mReadMemory(XPAR_MY_PERIPHERAL_0_BASEADDR);
						switch(input)
						{
							case LEFT_JOY:
									move_left_leg();
									break;

							case RIGHT_JOY:
									move_right_leg();
									break;
							case DOWN_JOY:
								if(lives > 0 && !in_game)
								{
									ball_x=20;
									ball_y=200;
									move_ball=1;
								}
								break;
						}

						if(projectil_flag && move_ball)
						{
							switch(ball_angle)
							{
								case 0:
									ball_x++;
									break;
								case 90:
									ball_y--;
									break;
								case 180:
									ball_x--;
									break;
								case 270:
									ball_y++;
									break;
							}
							if(ball_angle>0 && ball_angle<90)
							{
								ball_x++;
								ball_y=-tan(ball_angle)+ball_y;
							}
							if(ball_angle>90 && ball_angle<180)
							{
								ball_x--;
								ball_y=-tan((180-ball_angle))+ball_y;
							}
							if(ball_angle>180 && ball_angle<270)
							{
								ball_x--;
								ball_y=ball_y+tan((ball_angle-180));
							}
							if(ball_angle>270 && ball_angle<360)
							{
								ball_x++;
								ball_y=ball_y+tan((360-ball_angle));
							}
							draw_ball(ball_x,ball_y,ball_x_prev,ball_y_prev);

							ball_x_prev=ball_x;

							ball_y_prev=ball_y;
							projectil_flag = 0;
						}
				}
	return 0;
}

