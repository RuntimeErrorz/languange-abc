#define _CRT_SECURE_NO_WARNINGS
#include "chess.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

extern bool player;
extern bool threat_flag;
extern qiZi_T board[MAX_ROW][MAX_COL];
extern locate_T list[2][12];
extern node_PT record_start; //棋谱头
extern node_PT record_now; //用尾插法记录新的移动，该变量跟踪链表尾部
extern int step;

void specialDeal(int type) //返回ture表示进行了特殊操作，false表示没有
{
	if (type == 1)
	{
		if (player) //红方投降
		{
			for (int i = 0; i <= 2; i++)
				for (int j = 3; j <= 5; j++)
					if (board[i][j].type == 'j')
						board[i][j].type = 'k';
		}
		else //绿方投降
		{
			for (int i = 7; i <= 9; i++)
				for (int j = 3; j <= 5; j++)
					if (board[i][j].type == 'j')
						board[i][j].type = 'k';
		}
		return;
	}
	else if (type == 2) //悔棋
	{
		if (record_now->prev == NULL || record_now->prev->prev == NULL) //短路运算，其实是安全的
		{
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n                                                  您还没走过棋呢\n");
			printf("\n\n\n                                               ");
			system("pause");
			return;
		}
		board[(record_now->move_y)][(record_now->move_x)].player = player;
		board[(record_now->move_y)][(record_now->move_x)].type = record_now->taking;
		board[(record_now->now_y)][(record_now->now_x)].player = !player;
		board[(record_now->now_y)][(record_now->now_x)].type = record_now->piece;
		if (record_now->taking != 'k' && record_now->taking != 'x' && record_now->taking != 's') //回溯list
		{
			for (int i = 0; i <= 11; i++)
			{
				if (list[player][i].x == record_now->move_x && list[player][i].y == record_now->move_y&&list[player][i].type=='k')
				{
					list[player][i].type = record_now->taking;
					break;
				}
			}
		}
		for (int i = 0; i <= 11; i++)
		{
			if (list[!player][i].x == record_now->move_x && list[!player][i].y == record_now->move_y && list[!player][i].type == record_now->piece)
			{
				list[!player][i].x = record_now->now_x;
				list[!player][i].y = record_now->now_y;
				break;
			}
		}
		deleteRecord(); //回溯一步
		board[record_now->move_y][record_now->move_x].player = !player; //
		board[record_now->move_y][record_now->move_x].type = record_now->taking;
		board[record_now->now_y][record_now->now_x].player = player; //
		board[record_now->now_y][record_now->now_x].type = record_now->piece;
		if (record_now->taking != 'k' && record_now->taking != 'x' && record_now->taking != 's') //回溯list
		{
			for (int i = 0; i <= 11; i++)
			{
				if (list[!player][i].x == record_now->move_x && list[!player][i].y == record_now->move_y && list[!player][i].type == 'k')
				{
					list[!player][i].type = record_now->taking;
					break;
				}
			}
		}
		for (int i = 0; i <= 11; i++)
		{
			if (list[player][i].x == record_now->move_x && list[player][i].y == record_now->move_y && list[player][i].type == record_now->piece)
			{
				list[player][i].x = record_now->now_x;
				list[player][i].y = record_now->now_y;
				break;
			}
		}
		deleteRecord(); //再回溯一步
		step -= 2; //去掉两步
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n                                                成功悔棋，下次请三思而后动\n");
		printf("\n\n\n                                                    ");
		system("pause");
		return;
	}
	else if (type == 3) //简单粗暴的覆写式存档
	{
		FILE* fp;
		fp = fopen(SAVE_FILE, "w"); //文本文件
		if (fp == NULL)
		{
			system("cls");
			printf("\n\n\n\n\n                                                       因系统问题，无法存档\n");
			printf("\n\n\n\n                                                         ");
			system("pause");
			return;
		}
		fprintf_s(fp, "%d %d %d\n", player,threat_flag,step); //载入各种杂项
		for (int i = 0; i <= 9; i++)
		{
			for (int j = 0; j <= 8; j++)
				fprintf_s(fp, "%d %c", board[i][j].player, board[i][j].type);
			fprintf_s(fp, "\n");
		}
		fclose(fp);
		//
		fp = fopen("record_1.txt", "w");
		if (fp == NULL)
		{
			system("cls");
			printf("\n\n\n\n\n                                                       因系统问题，无法存档\n");
			printf("\n\n\n\n                                                         ");
			system("pause");
			return;
		}
		node_PT temp = record_start->next;
		while (temp != NULL)
		{
			if (temp->player)
				fprintf(fp, "红 ");
			else
				fprintf(fp, "黑 ");
			switch (temp->piece)
			{
				case 'b':fprintf(fp, "兵"); break;
				case 'p':fprintf(fp, "炮"); break;
				case 'c':fprintf(fp, "车"); break;
				case 'm':fprintf(fp, "马"); break;
				case 'x':fprintf(fp, "象"); break;
				case 's':fprintf(fp, "士"); break;
				case 'j':fprintf(fp, "将"); break;
			}
			fprintf(fp, "(%d,%d) -> (%d,%d)", temp->now_x, temp->now_y, temp->move_x, temp->move_y);
			if (temp->taking != 'k')
			{
				fprintf(fp, " 提");
				switch (temp->taking)
				{
					case 'b':fprintf(fp, "兵"); break;
					case 'p':fprintf(fp, "炮"); break;
					case 'c':fprintf(fp, "车"); break;
					case 'm':fprintf(fp, "马"); break;
					case 'x':fprintf(fp, "象"); break;
					case 's':fprintf(fp, "士"); break;
					case 'j':fprintf(fp, "将"); break;
				}
			}
			fprintf(fp, "\n");
			temp = temp->next;
		}
		fclose(fp);
		//
		fp = fopen("save_list.txt", "w"); //list的存档
		if (fp == NULL)
		{
			system("cls");
			printf("\n\n\n\n\n                                                       因系统问题，无法存档\n");
			printf("\n\n\n\n                                                         ");
			system("pause");
			return;
		}
		for (int i = 0; i <= 11; i++)
			fprintf(fp,"%c%d %d", list[0][i].type, list[0][i].x, list[0][i].y);
		for (int i = 0; i <= 11; i++)
			fprintf(fp,"%c%d %d", list[1][i].type, list[1][i].x, list[1][i].y);
		fclose(fp);
		//
		fp = fopen("record_internal_1.txt", "w"); //用于读取的内部记录
		if (fp == NULL)
		{
			system("cls");
			printf("\n\n\n\n\n                                                       因系统问题，无法存档\n");
			printf("\n\n\n\n                                                         ");
			system("pause");
			return;
		}
		temp = record_start->next;
		while (temp != NULL)
		{
			fprintf(fp, "%d", temp->player);
			fprintf(fp, " %d %d %d %d", temp->now_x, temp->now_y, temp->move_x, temp->move_y);
			fprintf(fp, "%c%c", temp->piece, temp->taking);
			fprintf(fp, "\n");
			temp = temp->next;
		}
		fclose(fp);
		//
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n");
		printf("                                                          已保存\n");
		printf("\n\n\n");
		printf("                                                    ");
		system("pause");
		return;
	}
	else if (type == 4) //棋局中查看棋谱
	{
		system("cls");
		node_PT temp = record_start->next;
		bool printf_flag = false;
		int i = 1;
		while (temp != NULL)
		{
			if (printf_flag == false) //第一行特殊处理
				printf("\n\n\n");
			printf_flag = true;
			printf("                                           第 %d 手   ",i++);
			if (temp->player)
				printf("红 ");
			else
				printf("黑 ");
			switch (temp->piece)
			{
				case 'b':printf("兵"); break;
				case 'p':printf("炮"); break;
				case 'c':printf("车"); break;
				case 'm':printf("马"); break;
				case 'x':printf("象"); break;
				case 's':printf("士"); break;
				case 'j':printf("将"); break;
			}
			printf("(%d,%d) -> (%d,%d)", temp->now_x, temp->now_y, temp->move_x, temp->move_y);
			if (temp->taking != 'k')
			{
				printf(" 提");
				switch (temp->piece)
				{
					case 'b':printf("兵"); break;
					case 'p':printf("炮"); break;
					case 'c':printf("车"); break;
					case 'm':printf("马"); break;
					case 'x':printf("象"); break;
					case 's':printf("士"); break;
					case 'j':printf("将"); break;
				}
			}
			printf("\n");
			temp = temp->next;
		}
		printf("\n\n\n");
		if (printf_flag == false)
			printf("\n\n\n\n\n\n\n\n\n                                                  当前棋局还未走过棋\n\n\n\n");
		printf("                                                 ");
		system("pause");
		return;
	}
	else if (type == 5) //安全退出
	{
		while (record_now != NULL) //释放内存
			deleteRecord();
		printf("\n                                                  已经完成内存释放\n");
		printf("\n                                                ");
		system("pause");
		exit(EXIT_SUCCESS);
	}
}