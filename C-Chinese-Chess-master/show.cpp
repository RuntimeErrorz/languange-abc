#include "chess.h"
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <stdbool.h>

extern qiZi_T board[MAX_ROW][MAX_COL];
extern bool player;
extern bool threat_flag;

int map[19][18] =
{
{'a',0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},//0
{'z',1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//1
{'b',0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},//2
{'z',1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//3
{'c',0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},//4
{'z',1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//5
{'d',0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},//6
{'z',1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//7
{'e',0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},//8
{'z',2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},//9
{'f',0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},//10
{'z',1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//11
{'g',0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},//12
{'z',1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//13
{'h',0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},//14
{'z',1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//15
{'i',0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},//16
{'z',1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//17
{'j',0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0}//18
};

void color(int x) //改变字体颜色
{
	if (x >= 0 && x <= 15)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void show(int warning_type)
{
	int i, j;
	system("cls");
	printf("\n");
	color(12);
	switch (warning_type)
	{
	    case 0: printf("\n"); break;
	    case 1: printf("                                        您输入的坐标不在棋盘范围内,请重新输入\n"); break;
	    case 2: printf("                                            您这子儿捏起来没动啊，麻烦再想想\n"); break;
	    case 3: printf("                                              您仔细看看，这儿有子吗？\n"); break;
    	case 4: printf("                                              您别动对手的子儿，再想想吧\n"); break;
    	case 5: printf("                                                您不能吃自己的子儿啊\n"); break;
    	case 6: printf("                                               您确定这子有这种走法？\n"); break;
		case 7: printf("                                              将帅碰面，请重新思考走法\n"); break;
	}
	color(7);
	for (i = 18; i >= 0; i--)
	{
		if (i == 9)
		{
			printf("                                         ║     楚  河          汉  界    ║\n");
			continue;
		}
		else if (i == 3 || i == 17)
		{
			printf("                                         ║   │   │   │ ╲ │ ╱ │   │   │   ║\n");
			continue;
		}
		else if (i == 1 || i == 15)
		{
			printf("                                         ║   │   │   │ ╱ │ ╲ │   │   │   ║\n");
			continue;
		}
		printf("                                      ");
		for (j = 0; j <= 17; j++)
		{
			if (map[i][j] == 0 && board[i / 2][(j - 1) / 2].type != 'k')
			{
				if (board[i / 2][(j - 1) / 2].player == true)
					color(12);
				else
					color(10);
			    switch (board[i / 2][(j - 1) / 2].type)
				{
					case 'b':printf("兵"); break;
					case 'p':printf("炮"); break;
					case 'c':printf("车"); break;
					case 'm':printf("马"); break;
					case 'j':printf("将"); break;
					case 's':printf("士"); break;
					case 'x':printf("象"); break;
				}
				color(7);
			}
			else if (map[i][j] == 0 && board[i / 2][(j - 1) / 2].type == 'k')
			{
				if (i == 0 && j == 1) printf("╚ ");
				else if (i == 0 && j == 17) printf("╝");
				else if (i == 18 && j == 1) printf("╔ ");
				else if (i == 18 && j == 17) printf("╗");
				else if ((i != 0 && i != 18) && j == 1)
				{
					if (i == 8 || i == 10)
						printf("╠ ");
					else
						printf("╟ ");
				}
				else if ((i != 0 && i != 18) && j == 17)
				{
					if (i == 8 || i == 10)
						printf("╣ ");
					else
						printf("╢ ");
				}
				else if (i == 2 && j == 9 || i == 16 && j == 9) printf("╳ ");
				else if (i == 0 && j != 1) printf("╧ ");
				else if (i == 18 && j != 1) printf("╤ ");
				else if (i == 8 || i == 10) printf("═ ");
				else printf("┼ ");
			}
			else if (map[i][j] == 1)
			{
				if (i == 0 || i == 18) printf("═ ");
				else if (j == 1) printf("║");
				else if (j == 17) printf(" ║");
				else if (j == 1 || j == 3 || j == 5 || j == 7 || j == 9 || j == 11 || j == 13 || j == 15)
				{
					if (i != 0 && i != 18)
					printf(" │");
				}
				else if (i == 2 || i == 4 || i == 6 || i == 12 || i == 14 || i == 16)
				{
					if (j != 1 && j != 17) printf("──");
				}
				else if (i == 8 || i == 10) printf("══");
				else printf("  ");
			}
			else
			{
				switch (map[i][j])
				{
				case 'a':
					printf("0  "); break;
				case 'b':
					printf("1  "); break;
				case 'c':
					printf("2  "); break;
				case 'd':
					printf("3  "); break;
				case 'e':
					printf("4  "); break;
				case 'f':
					printf("5  "); break;
				case 'g':
					printf("6  "); break;
				case 'h':
					printf("7  "); break;
				case 'i':
					printf("8  "); break;
				case 'j':
					printf("9  "); break;
				case 'z':
					printf("   "); break;
				}
			}
		}
		if (i == 14)
			printf("                  t——投降 ");
		else if (i == 12)
			printf("                  s——存档");
		else if (i == 10)
			printf("                  h——悔棋");
		else if (i == 8)
			printf("                  c——棋谱");
		else if (i == 6)
			printf("                  q——退出");

		printf("\n");
	}
	printf("\n                                         0   1   2   3   4   5   6   7   8\n");
}

void show_player(void)
{
	if (player)
	{
		if (threat_flag)
		{
			color(6);
			printf("                                                   将军   ");
			color(12);
			printf("红方轮次\n");
		}
		else
		{
			color(12);
			printf("                                                     红方轮次\n");
		}
		color(7);
		printf("\n                                             请用空格或英文逗号分隔坐标\n");
	}
	else
	{
		if (threat_flag)
		{
			color(6);
			printf("                                                  将军   ");
			color(10);
			printf("绿方轮次\n");
		}
		else
		{
			color(10);
			printf("                                                     绿方轮次\n");
		}
		color(7);
		printf("\n                                             请用空格或英文逗号分隔坐标\n");
	}
}