/*
 * SI_draw.c
 *
 *  Created on: 16.06.2015.
 *      Author: Standzi, Marko, Dva geja (Urosko i Milan GAY)
 */

#include "SI_draw.h"

void draw_square(Xuint32 BaseAddress, Xuint8 x_crdnt, Xuint8 y_crdnt)
{
	int j, k;
	k = x_crdnt;

	for (j = 0 + 32*y_crdnt; j < 32 + 32*y_crdnt; j++)
	{
		PUT_TO_FSL((j*(640/8) + k-2), 0x00A0A000);
		PUT_TO_FSL((j*(640/8) + k-1), 0x0A0A0A0A);
		PUT_TO_FSL((j*(640/8) + k+0), 0xA0A0A0A0);
		PUT_TO_FSL((j*(640/8) + k+1), 0x0A0A0A0A);
		PUT_TO_FSL((j*(640/8) + k+2), 0x00A0A000);
	}
}

void draw_invaderX(Xuint32 BaseAddress, Xuint8 x_crdnt, Xuint8 y_crdnt, Xuint8 type)
{
	int i, j, k;
	k = x_crdnt;

	if(type == 1)
	{
		for (j = 16 + 32*y_crdnt; j < 32 + 32*y_crdnt; j++)
		{
			i = j*(640/8) + k;
			if (j >= (16 + 32*y_crdnt) && j < (18 + 32*y_crdnt)) {
				PUT_TO_FSL(i-1,0x00000110);//VGA1_PERIPH_MEM_mWriteMemory((i-1), 0x00000110);
				//VGA1_PERIPH_MEM_mWriteMemory((i+0), 0x00000000);
				PUT_TO_FSL(i+1,0x01100000);//VGA1_PERIPH_MEM_mWriteMemory((i+1), 0x01100000);
			}
			else if (j >= (18 + 32*y_crdnt) && j < (20 + 32*y_crdnt)) {
				PUT_TO_FSL(i-1,0x00000001); //VGA1_PERIPH_MEM_mWriteMemory((i-1), 0x00000001);
				PUT_TO_FSL((i+0), 0x10000001);//PUT_TO_FSL((i+0), 0x10000001);
				PUT_TO_FSL((i+1), 0x10000000);//PUT_TO_FSL((i+1), 0x10000000);
			}
			else if (j >= (20 + 32*y_crdnt) && j < (22 + 32*y_crdnt)) {
				PUT_TO_FSL((i-1), 0x00000111);//VGA1_PERIPH_MEM_mWriteMemory((i-1), 0x00000111);
				PUT_TO_FSL((i+0), 0x11111111);
				PUT_TO_FSL((i+1), 0x11100000);
			}
			else if (j >= (22 + 32*y_crdnt) && j < (24 + 32*y_crdnt)) {
				PUT_TO_FSL((i-1), 0x00011112);
				PUT_TO_FSL((i+0), 0x21111112);
				PUT_TO_FSL((i+1), 0x21111000);
			}
			else if (j >= (24 + 32*y_crdnt) && j < (26 + 32*y_crdnt)) {
				PUT_TO_FSL((i-1), 0x11111111);
				PUT_TO_FSL((i+0), 0x11111111);
				PUT_TO_FSL((i+1), 0x11111111);
			}
			else if (j >= (26 + 32*y_crdnt) && j < (28 + 32*y_crdnt)) {
				PUT_TO_FSL((i-1), 0x11001111);
				PUT_TO_FSL((i+0), 0x11111111);
				PUT_TO_FSL((i+1), 0x11110011);
			}
			else if (j >= (28 + 32*y_crdnt) && j < (30 + 32*y_crdnt)) {
				PUT_TO_FSL((i-1), 0x11001100);
				//PUT_TO_FSL((i+0), 0x00000000);
				PUT_TO_FSL((i+1), 0x00110011);
			}
			else {
				PUT_TO_FSL((i-1), 0x00000011);
				PUT_TO_FSL((i+0), 0x11000011);
				PUT_TO_FSL((i+1), 0x11000000);
			}
		}
	}
	else
	{
		for (j = 16 + 32*y_crdnt; j < 32 + 32*y_crdnt; j++)
		{
			i = j*(640/8) + k;
			if (j >= (16 + 32*y_crdnt) && j < (18 + 32*y_crdnt)) {
				PUT_TO_FSL((i-1), 0x00000110);
				//PUT_TO_FSL((i+0), 0x00000000);
				PUT_TO_FSL((i+1), 0x01100000);
			}
			else if (j >= (18 + 32*y_crdnt) && j < (20 + 32*y_crdnt)) {
				PUT_TO_FSL((i-1), 0x11000001);
				PUT_TO_FSL((i+0), 0x10000001);
				PUT_TO_FSL((i+1), 0x10000011);
			}
			else if (j >= (20 + 32*y_crdnt) && j < (22 + 32*y_crdnt)) {
				PUT_TO_FSL((i-1), 0x11001111);
				PUT_TO_FSL((i+0), 0x11111111);
				PUT_TO_FSL((i+1), 0x11110011);
			}
			else if (j >= (22 + 32*y_crdnt) && j < (24 + 32*y_crdnt)) {
				PUT_TO_FSL((i-1), 0x11111112);
				PUT_TO_FSL((i+0), 0x21111112);
				PUT_TO_FSL((i+1), 0x21111111);
			}
			else if (j >= (24 + 32*y_crdnt) && j < (26 + 32*y_crdnt)) {
				PUT_TO_FSL((i-1), 0x11111111);
				PUT_TO_FSL((i+0), 0x11111111);
				PUT_TO_FSL((i+1), 0x11111111);
			}
			else if (j >= (26 + 32*y_crdnt) && j < (28 + 32*y_crdnt)) {
				PUT_TO_FSL((i-1), 0x00111111);
				PUT_TO_FSL((i+0), 0x11111111);
				PUT_TO_FSL((i+1), 0x11111100);
			}
			else if (j >= (28 + 32*y_crdnt) && j < (30 + 32*y_crdnt)) {
				PUT_TO_FSL((i-1), 0x00000110);
				//PUT_TO_FSL((i+0), 0x00000000);
				PUT_TO_FSL((i+1), 0x01100000);
			}
			else {
				PUT_TO_FSL((i-1), 0x00011000);
				//PUT_TO_FSL((i+0), 0x00000000);
				PUT_TO_FSL((i+1), 0x00011000);
			}
		}
	}
}

void draw_invader_2(Xuint32 BaseAddress, Xuint8 x_crdnt, Xuint8 y_crdnt)
{
	int i, j, k;
	k = x_crdnt;

	for (j = 16 + 32*y_crdnt; j < 32 + 32*y_crdnt; j++)
	{
		i = j*(640/8) + k;
		if (j >= (16 + 32*y_crdnt) && j < (18 + 32*y_crdnt)) {
			PUT_TO_FSL((i-1), 0x00000110);
			//PUT_TO_FSL((i+0), 0x00000000);
			PUT_TO_FSL((i+1), 0x01100000);
		}
		else if (j >= (18 + 32*y_crdnt) && j < (20 + 32*y_crdnt)) {
			PUT_TO_FSL((i-1), 0x11000001);
			PUT_TO_FSL((i+0), 0x10000001);
			PUT_TO_FSL((i+1), 0x10000011);
		}
		else if (j >= (20 + 32*y_crdnt) && j < (22 + 32*y_crdnt)) {
			PUT_TO_FSL((i-1), 0x11001111);
			PUT_TO_FSL((i+0), 0x11111111);
			PUT_TO_FSL((i+1), 0x11110011);
		}
		else if (j >= (22 + 32*y_crdnt) && j < (24 + 32*y_crdnt)) {
			PUT_TO_FSL((i-1), 0x11111112);
			PUT_TO_FSL((i+0), 0x21111112);
			PUT_TO_FSL((i+1), 0x21111111);
		}
		else if (j >= (24 + 32*y_crdnt) && j < (26 + 32*y_crdnt)) {
			PUT_TO_FSL((i-1), 0x11111111);
			PUT_TO_FSL((i+0), 0x11111111);
			PUT_TO_FSL((i+1), 0x11111111);
		}
		else if (j >= (26 + 32*y_crdnt) && j < (28 + 32*y_crdnt)) {
			PUT_TO_FSL((i-1), 0x00111111);
			PUT_TO_FSL((i+0), 0x11111111);
			PUT_TO_FSL((i+1), 0x11111100);
		}
		else if (j >= (28 + 32*y_crdnt) && j < (30 + 32*y_crdnt)) {
			PUT_TO_FSL((i-1), 0x00000110);
			//PUT_TO_FSL((i+0), 0x00000000);
			PUT_TO_FSL((i+1), 0x01100000);
		}
		else {
			PUT_TO_FSL((i-1), 0x00011000);
			//PUT_TO_FSL((i+0), 0x00000000);
			PUT_TO_FSL((i+1), 0x00011000);
		}
	}
}

void draw_invaderY(Xuint32 BaseAddress, Xuint8 x_crdnt, Xuint8 y_crdnt, Xuint8 type)
{
	int i, j, k;
	k = x_crdnt;

	if(type == 1)
	{
		for (j = 16 + 32*y_crdnt; j < 32 + 32*y_crdnt; j++)
		{
			i = j*(640/8) + k;
			if (j >= (16 + 32*y_crdnt) && j < (18 + 32*y_crdnt)) {
				PUT_TO_FSL(i-1,0x00000000);
				PUT_TO_FSL(i+0,0x11111111);
				PUT_TO_FSL(i+1,0x00000000);
			}
			else if (j >= (18 + 32*y_crdnt) && j < (20 + 32*y_crdnt)) {
				PUT_TO_FSL(i-1,0x00000011);
				PUT_TO_FSL((i+0), 0x11111111);
				PUT_TO_FSL((i+1), 0x11000000);
			}
			else if (j >= (20 + 32*y_crdnt) && j < (22 + 32*y_crdnt)) {
				PUT_TO_FSL((i-1), 0x00001111);
				PUT_TO_FSL((i+0), 0x11111111);
				PUT_TO_FSL((i+1), 0x11110000);
			}
			else if (j >= (22 + 32*y_crdnt) && j < (24 + 32*y_crdnt)) {
				PUT_TO_FSL((i-1), 0x00111100);
				PUT_TO_FSL((i+0), 0x11111111);
				PUT_TO_FSL((i+1), 0x00111100);
			}
			else if (j >= (24 + 32*y_crdnt) && j < (26 + 32*y_crdnt)) {
				PUT_TO_FSL((i-1), 0x11111111);
				PUT_TO_FSL((i+0), 0x11111111);
				PUT_TO_FSL((i+1), 0x11111111);
			}
			else if (j >= (26 + 32*y_crdnt) && j < (28 + 32*y_crdnt)) {
				PUT_TO_FSL((i-1), 0x11111111);
				PUT_TO_FSL((i+0), 0x11100111);
				PUT_TO_FSL((i+1), 0x11111111);
			}
			else if (j >= (28 + 32*y_crdnt) && j < (30 + 32*y_crdnt)) {
				PUT_TO_FSL((i-1), 0x00000011);
				PUT_TO_FSL((i+0), 0x00111100);
				PUT_TO_FSL((i+1), 0x11000000);
			}
			else {
				PUT_TO_FSL((i-1), 0x00011111);
				PUT_TO_FSL((i+0), 0x10000001);
				PUT_TO_FSL((i+1), 0x11111000);
			}
		}
	}
	else
	{
		for (j = 16 + 32*y_crdnt; j < 32 + 32*y_crdnt; j++)
		{
			i = j*(640/8) + k;
			if (j >= (16 + 32*y_crdnt) && j < (18 + 32*y_crdnt)) {
				PUT_TO_FSL(i-1,0x02200000);
				PUT_TO_FSL(i+0,0x11111111);
				PUT_TO_FSL(i+1,0x00000220);
			}
			else if (j >= (18 + 32*y_crdnt) && j < (20 + 32*y_crdnt)) {
				PUT_TO_FSL(i-1,0x00220011);
				PUT_TO_FSL((i+0), 0x11111111);
				PUT_TO_FSL((i+1), 0x11002200);
			}
			else if (j >= (20 + 32*y_crdnt) && j < (22 + 32*y_crdnt)) {
				PUT_TO_FSL((i-1), 0x00001111);
				PUT_TO_FSL((i+0), 0x11111111);
				PUT_TO_FSL((i+1), 0x11110000);
			}
			else if (j >= (22 + 32*y_crdnt) && j < (24 + 32*y_crdnt)) {
				PUT_TO_FSL((i-1), 0x00111121);
				PUT_TO_FSL((i+0), 0x11111111);
				PUT_TO_FSL((i+1), 0x12111100);
			}
			else if (j >= (24 + 32*y_crdnt) && j < (26 + 32*y_crdnt)) {
				PUT_TO_FSL((i-1), 0x11111122);
				PUT_TO_FSL((i+0), 0x11111111);
				PUT_TO_FSL((i+1), 0x22111111);
			}
			else if (j >= (26 + 32*y_crdnt) && j < (28 + 32*y_crdnt)) {
				PUT_TO_FSL((i-1), 0x11111111);
				PUT_TO_FSL((i+0), 0x11000011);
				PUT_TO_FSL((i+1), 0x11111111);
			}
			else if (j >= (28 + 32*y_crdnt) && j < (30 + 32*y_crdnt)) {
				PUT_TO_FSL((i-1), 0x00000011);
				PUT_TO_FSL((i+0), 0x00111100);
				PUT_TO_FSL((i+1), 0x11000000);
			}
			else {
				PUT_TO_FSL((i-1), 0x00011111);
				PUT_TO_FSL((i+0), 0x10000001);
				PUT_TO_FSL((i+1), 0x11111000);
			}
		}
	}
}

void draw_invader(Xuint32 BaseAddress, Xuint8 x_crdnt, Xuint8 y_crdnt, Xuint8 type)
{
	if(level%2 == 0)
		draw_invaderY(BaseAddress, x_crdnt, y_crdnt, type);
	else
		draw_invaderX(BaseAddress, x_crdnt, y_crdnt, type);
}

void draw_ship(Xuint32 BaseAddress, Xuint8 x_crdnt, Xuint8 y_crdnt)
{
	int i, j, k;
	k = x_crdnt;

	if(lives > INIT_LIVES-1)
	{
		for (j = 2 + 32*y_crdnt; j < 28 + 32*y_crdnt; j++)
		{
			i = j*(640/8) + k;
			if (j >= (2 + 32*y_crdnt) && j < (6 + 32*y_crdnt)) {
				//PUT_TO_FSL((i-1), 0x00000000);
				PUT_TO_FSL((i+0), 0x22200222);
				//PUT_TO_FSL((i+1), 0x00000000);
			}
			else if (j >= (6 + 32*y_crdnt) && j < (12 + 32*y_crdnt)) {
				//PUT_TO_FSL((i-1), 0x01111110);
				PUT_TO_FSL((i+0), 0x24200242);
				//PUT_TO_FSL((i+1), 0x00000000);
			}
			else if (j >= (12 + 32*y_crdnt) && j < (16 + 32*y_crdnt)) {
				PUT_TO_FSL((i-1), 0x22222222);
				PUT_TO_FSL((i+0), 0x33333333);
				PUT_TO_FSL((i+1), 0x22222222);
			}
			else {
				PUT_TO_FSL((i-1), 0x22333333);
				PUT_TO_FSL((i+0), 0x88833888);
				PUT_TO_FSL((i+1), 0x33333322);
			}
		}
	}
	else if(lives == INIT_LIVES-1)
	{
		for (j = 2 + 32*y_crdnt; j < 28 + 32*y_crdnt; j++)
		{
			i = j*(640/8) + k;
			if (j >= (2 + 32*y_crdnt) && j < (6 + 32*y_crdnt)) {
				//PUT_TO_FSL((i-1), 0x00000000);
				PUT_TO_FSL((i+0), 0xaaa00aaa);
				//PUT_TO_FSL((i+1), 0x00000000);
			}
			else if (j >= (6 + 32*y_crdnt) && j < (12 + 32*y_crdnt)) {
				//PUT_TO_FSL((i-1), 0x01111110);
				PUT_TO_FSL((i+0), 0xA4A00A4A);
				//PUT_TO_FSL((i+1), 0x00000000);
			}
			else if (j >= (12 + 32*y_crdnt) && j < (16 + 32*y_crdnt)) {
				PUT_TO_FSL((i-1), 0x00AAAAAA);
				PUT_TO_FSL((i+0), 0x33333333);
				PUT_TO_FSL((i+1), 0xAAAAAA00);
			}
			else {
				PUT_TO_FSL((i-1), 0xAA333333);
				PUT_TO_FSL((i+0), 0x88833888);
				PUT_TO_FSL((i+1), 0x333333AA);
			}
		}
	}
	else
	{
		for (j = 2 + 32*y_crdnt; j < 28 + 32*y_crdnt; j++)
		{
			i = j*(640/8) + k;
			if (j >= (2 + 32*y_crdnt) && j < (6 + 32*y_crdnt)) {
				//PUT_TO_FSL((i-1), 0x00000000);
				PUT_TO_FSL((i+0), 0x00000000);
				//PUT_TO_FSL((i+1), 0x00000000);
			}
			else if (j >= (6 + 32*y_crdnt) && j < (12 + 32*y_crdnt)) {
				//PUT_TO_FSL((i-1), 0x01111110);
				PUT_TO_FSL((i+0), 0x04000040);
				//PUT_TO_FSL((i+1), 0x00000000);
			}
			else if (j >= (12 + 32*y_crdnt) && j < (16 + 32*y_crdnt)) {
				PUT_TO_FSL((i-1), 0x00000000);
				PUT_TO_FSL((i+0), 0x33333333);
				PUT_TO_FSL((i+1), 0x00000000);
			}
			else {
				PUT_TO_FSL((i-1), 0x00333333);
				PUT_TO_FSL((i+0), 0x88844888);
				PUT_TO_FSL((i+1), 0x33333300);
			}
		}
	}
}

void draw_projectile(Xuint32 BaseAddress, Xuint8 x_crdnt, Xuint8 y_crdnt)
{
	int j, k;
	k = x_crdnt;
	int boja=0x00400400;

	for (j = 4 + 32*y_crdnt; j < 16 + 32*y_crdnt; j++)
	{

		PUT_TO_FSL((j*(640/8) + k), boja);
	}
}

void draw_invader_projectile(Xuint32 BaseAddress, Xuint8 x_crdnt, Xuint8 y_crdnt)
{
	int j, k;
	k = x_crdnt;

	for (j = 6 + 32*y_crdnt; j < 14 + 32*y_crdnt; j++)
	{
		if (j >= (7 + 32*y_crdnt) && j < (9 + 32*y_crdnt))
			PUT_TO_FSL((j*(640/8) + k), 0x02222220);
		else
			PUT_TO_FSL((j*(640/8) + k), 0x00022000);
	}
}

void erase_projectile(Xuint32 BaseAddress, Xuint8 x_crdnt, Xuint8 y_crdnt)
{
	int j, k;
	k = x_crdnt;

	for (j = 2 + 32*y_crdnt; j < 30 + 32*y_crdnt; j++)
	{
		PUT_TO_FSL((j*(640/8) + k), 0x00000000);
	}
}

void erase_square(Xuint32 BaseAddress, Xuint8 x_crdnt, Xuint8 y_crdnt)
{
	int j, k;
	k = x_crdnt;

	for (j = 0 + 32*y_crdnt; j < 32 + 32*y_crdnt; j++)
	{
		PUT_TO_FSL((j*(640/8) + k-2), 0x00000000);
		PUT_TO_FSL((j*(640/8) + k-1), 0x00000000);
		PUT_TO_FSL((j*(640/8) + k+0), 0x00000000);
		PUT_TO_FSL((j*(640/8) + k+1), 0x00000000);
		PUT_TO_FSL((j*(640/8) + k+2), 0x00000000);
	}
}

void clear_graphics_screen(Xuint32 BaseAddress)
{
	int i;
	for (i = 0; i < 9600*4; i++){
	    PUT_TO_FSL(i, 0x00000000);
	}
}

void draw_X(Xuint32 BaseAddress, Xuint8 x_crdnt, Xuint8 y_crdnt)
{
	int j, k;
	k = x_crdnt;

	for (j = 0 + 32*y_crdnt; j < 32 + 32*y_crdnt; j++)
	{
		PUT_TO_FSL((j*(640/8) + k-2), 0x00000000);
		PUT_TO_FSL((j*(640/8) + k-1), 0x0AA00AA0);
		PUT_TO_FSL((j*(640/8) + k+0), 0x00AAA000);
		PUT_TO_FSL((j*(640/8) + k+1), 0x0AA00AA0);
		PUT_TO_FSL((j*(640/8) + k+2), 0x00000000);
	}
}

void erase_X(Xuint32 BaseAddress, Xuint8 x_crdnt, Xuint8 y_crdnt)
{
	int j, k;
	k = x_crdnt;

	for (j = 0 + 32*y_crdnt; j < 32 + 32*y_crdnt; j++)
	{
		PUT_TO_FSL((j*(640/8) + k-2), 0x00000000);
		PUT_TO_FSL((j*(640/8) + k-1), 0x00000000);
		PUT_TO_FSL((j*(640/8) + k+0), 0x00000000);
		PUT_TO_FSL((j*(640/8) + k+1), 0x00000000);
		PUT_TO_FSL((j*(640/8) + k+2), 0x00000000);
	}
}

void draw_red(Xuint32 BaseAddress, Xuint8 x_crdnt, Xuint8 y_crdnt, Xuint8 type)
{
	int i, j, k;
	k = x_crdnt;

	if(type == 1)
	{
		for (j = 16 + 32*y_crdnt; j < 32 + 32*y_crdnt; j++)
		{
			i = j*(640/8) + k;
			if (j >= (16 + 32*y_crdnt) && j < (18 + 32*y_crdnt)) {
				PUT_TO_FSL(i-1,0x00000220);
				PUT_TO_FSL(i+1,0x02200000);
			}
			else if (j >= (18 + 32*y_crdnt) && j < (20 + 32*y_crdnt)) {
				PUT_TO_FSL(i-1,0x00000002);
				PUT_TO_FSL((i+0), 0x20000002);
				PUT_TO_FSL((i+1), 0x20000000);
			}
			else if (j >= (20 + 32*y_crdnt) && j < (22 + 32*y_crdnt)) {
				PUT_TO_FSL((i-1), 0x00000222);
				PUT_TO_FSL((i+0), 0x22222222);
				PUT_TO_FSL((i+1), 0x22200000);
			}
			else if (j >= (22 + 32*y_crdnt) && j < (24 + 32*y_crdnt)) {
				PUT_TO_FSL((i-1), 0x00022222);
				PUT_TO_FSL((i+0), 0x22222222);
				PUT_TO_FSL((i+1), 0x22222000);
			}
			else if (j >= (24 + 32*y_crdnt) && j < (26 + 32*y_crdnt)) {
				PUT_TO_FSL((i-1), 0x22222222);
				PUT_TO_FSL((i+0), 0x22222222);
				PUT_TO_FSL((i+1), 0x22222222);
			}
			else if (j >= (26 + 32*y_crdnt) && j < (28 + 32*y_crdnt)) {
				PUT_TO_FSL((i-1), 0x22002222);
				PUT_TO_FSL((i+0), 0x22222222);
				PUT_TO_FSL((i+1), 0x22220022);
			}
			else if (j >= (28 + 32*y_crdnt) && j < (30 + 32*y_crdnt)) {
				PUT_TO_FSL((i-1), 0x22002200);
				PUT_TO_FSL((i+1), 0x00220022);
			}
			else {
				PUT_TO_FSL((i-1), 0x00000022);
				PUT_TO_FSL((i+0), 0x22000022);
				PUT_TO_FSL((i+1), 0x22000000);
			}
		}
	}
	else
	{
		for (j = 16 + 32*y_crdnt; j < 32 + 32*y_crdnt; j++)
		{
			i = j*(640/8) + k;
			if (j >= (16 + 32*y_crdnt) && j < (18 + 32*y_crdnt)) {
				PUT_TO_FSL((i-1), 0x00000220);
				PUT_TO_FSL((i+1), 0x02200000);
			}
			else if (j >= (18 + 32*y_crdnt) && j < (20 + 32*y_crdnt)) {
				PUT_TO_FSL((i-1), 0x22000002);
				PUT_TO_FSL((i+0), 0x20000002);
				PUT_TO_FSL((i+1), 0x20000022);
			}
			else if (j >= (20 + 32*y_crdnt) && j < (22 + 32*y_crdnt)) {
				PUT_TO_FSL((i-1), 0x22002222);
				PUT_TO_FSL((i+0), 0x22222222);
				PUT_TO_FSL((i+1), 0x22220022);
			}
			else if (j >= (22 + 32*y_crdnt) && j < (24 + 32*y_crdnt)) {
				PUT_TO_FSL((i-1), 0x22222222);
				PUT_TO_FSL((i+0), 0x22222222);
				PUT_TO_FSL((i+1), 0x22222222);
			}
			else if (j >= (24 + 32*y_crdnt) && j < (26 + 32*y_crdnt)) {
				PUT_TO_FSL((i-1), 0x22222222);
				PUT_TO_FSL((i+0), 0x22222222);
				PUT_TO_FSL((i+1), 0x22222222);
			}
			else if (j >= (26 + 32*y_crdnt) && j < (28 + 32*y_crdnt)) {
				PUT_TO_FSL((i-1), 0x00222222);
				PUT_TO_FSL((i+0), 0x22222222);
				PUT_TO_FSL((i+1), 0x22222200);
			}
			else if (j >= (28 + 32*y_crdnt) && j < (30 + 32*y_crdnt)) {
				PUT_TO_FSL((i-1), 0x00000220);
				//PUT_TO_FSL((i+0), 0x00000000);
				PUT_TO_FSL((i+1), 0x02200000);
			}
			else {
				PUT_TO_FSL((i-1), 0x00022000);
				//PUT_TO_FSL((i+0), 0x00000000);
				PUT_TO_FSL((i+1), 0x00022000);
			}
		}
	}
}
