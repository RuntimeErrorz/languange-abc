#define _CRT_SECURE_NO_WARNINGS
#include "chess.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


extern bool player;
extern bool threat_flag;
extern qiZi_T board[MAX_ROW][MAX_COL];
extern locate_T list[2][12]; //0:黑，1:红    list[][0]固定是将
extern int step;

void initialize(void)
{
	player = true; //红方先手
	threat_flag = false; //一开始当然不可能将军
	step = 0;
	//初始化board
	for(int i=0;i<=9;i++)
		for (int j = 0; j <= 8; j++) //先把棋盘初始化为空
		{
			board[i][j].player = true;
			board[i][j].type = 'k';
		}
	for (int i = 0; i <=8; i+=2) //初始化兵
	{
		board[3][i].player = true; //红方兵
		board[3][i].type = 'b';
		board[6][i].player = false; //黑方兵
		board[6][i].type = 'b';
	}

	board[2][1].player = true; //红方炮
	board[2][1].type = 'p';
	board[2][7].player = true;
	board[2][7].type = 'p';
	board[7][1].player = false; //黑方炮
	board[7][1].type = 'p';
	board[7][7].player = false;
	board[7][7].type = 'p';

	board[0][0].player = true; //红方车
	board[0][0].type = 'c';
	board[0][8].player = true;
	board[0][8].type = 'c';
	board[9][0].player = false; //黑方车
	board[9][0].type = 'c';
	board[9][8].player = false;
	board[9][8].type = 'c';

	board[0][1].player = true; //红方马
	board[0][1].type = 'm';
	board[0][7].player = true;
	board[0][7].type = 'm';
	board[9][1].player = false; //黑方马
	board[9][1].type = 'm';
	board[9][7].player = false;
	board[9][7].type = 'm';

	board[0][2].player = true; //红方象
	board[0][2].type = 'x';
	board[0][6].player = true;
	board[0][6].type = 'x';
	board[9][2].player = false; //黑方象
	board[9][2].type = 'x';
	board[9][6].player = false;
	board[9][6].type = 'x';

	board[0][3].player = true; //红方士
	board[0][3].type = 's';
	board[0][5].player = true;
	board[0][5].type = 's';
	board[9][3].player = false; //黑方士
	board[9][3].type = 's';
	board[9][5].player = false;
	board[9][5].type = 's';

	board[0][4].player = true; //红方将
	board[0][4].type = 'j';
	board[9][4].player = false; //黑方将
	board[9][4].type = 'j';

	//初始化list
	list[0][0].type = 'j'; //将的位置
	list[0][0].x = 4;
	list[0][0].y = 9;
	list[1][0].type = 'j';
	list[1][0].x = 4;
	list[1][0].y = 0;
	for (int i = 1; i <= 5; i++) //兵的位置
	{
		list[0][i].type = 'b';
		list[0][i].x = (i - 1) * 2;
		list[0][i].y = 6;
		list[1][i].type = 'b';
		list[1][i].x = (i - 1) * 2;
		list[1][i].y = 3;
	}
	list[0][6].type = 'p'; //炮的位置
	list[0][6].x = 1;
	list[0][6].y = 7;
	list[0][7].type = 'p';
	list[0][7].x = 7;
	list[0][7].y = 7;
	list[1][6].type = 'p';
	list[1][6].x = 1;
	list[1][6].y = 2;
	list[1][7].type = 'p';
	list[1][7].x = 7;
	list[1][7].y = 2;
	list[0][8].type = 'c'; //车的位置
	list[0][8].x = 0;
	list[0][8].y = 9;
	list[0][9].type = 'c';
	list[0][9].x = 8;
	list[0][9].y = 9;
	list[1][8].type = 'c';
	list[1][8].x = 0;
	list[1][8].y = 0;
	list[1][9].type = 'c';
	list[1][9].x = 8;
	list[1][9].y = 0;
	list[0][10].type = 'm'; //马的位置
	list[0][10].x = 1;
	list[0][10].y = 9;
	list[0][11].type = 'm';
	list[0][11].x = 7;
	list[0][11].y = 9;
	list[1][10].type = 'm';
	list[1][10].x = 1;
	list[1][10].y = 0;
	list[1][11].type = 'm';
	list[1][11].x = 7;
	list[1][11].y = 0;
}

int load(void)
{
	FILE* fp = fopen(SAVE_FILE, "r");
	if (fp == NULL) //找不到文档时
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n");
		printf("                                                    没有进行中的对局\n\n\n\n\n");
		int temp;
		printf("                                                   ");
		system("pause");
		return -1;
	}
	int player_temp; //用int比较好读入
	char type_temp;
	fscanf_s(fp, "%d %d %d", &player, &threat_flag, &step);
	for (int i = 0; i <= 9; i++)
	{
		for (int j = 0; j <= 8; j++)
		{
			fscanf_s(fp,"%d %c", &player_temp, &type_temp);
			board[i][j].player = player_temp;
			board[i][j].type = type_temp;
		}
	}
	fclose(fp);
	fp = fopen("save_list.txt", "r"); //载入list
	if (fp == NULL)
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("                                                    存档文件损坏\n\n\n\n\n");
		int temp;
		printf("                                               请输入0以返回上级目录：");
		scanf_s("%d", &temp);
		return -1;
	}
	for (int i = 0; i <= 11; i++)
	{
		list[0][i].type = fgetc(fp);
		fscanf_s(fp, "%d%d", &list[0][i].x, &list[0][i].y);
	}
	for (int i = 0; i <= 11; i++)
	{
		list[1][i].type = fgetc(fp);
		fscanf_s(fp, "%d%d", &list[1][i].x, &list[1][i].y);
	}
	fclose(fp);
	return 1;
}
