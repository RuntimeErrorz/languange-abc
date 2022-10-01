#define _CRT_SECURE_NO_WARNINGS
#include "chess.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

extern bool player;
extern qiZi_T board[MAX_ROW][MAX_COL];
extern node_PT record_start; //棋谱链表表头
extern node_PT record_now; //棋谱链表尾部结点


//正向遍历用于输出
//逆向遍历用于悔棋

void createLinkList(void)
{
	record_start = (node_PT)malloc(sizeof(node_T));
	if (record_start == NULL)
	{
		printf("棋谱记录创建失败\n");
		system("pause");
		return;
	}
	//头结点不存数据
	record_start->next = NULL; //标识链表尾端
	record_start->prev = NULL; //标识链表头部
	//(*pStart)->piece = 'a'; //标识链表头结点
	record_now = record_start;
}


void recordMove(int now_x, int now_y, int move_x, int move_y) //在尾部创建一个新结点来记录移动
{
	record_now->next = (node_PT)malloc(sizeof(node_T));
	if (record_now->next == NULL)
	{
		printf("棋谱记录结点创建失败\n");
		system("pause");
		return;
	}
	record_now->next->next = NULL; //标识新的尾部
	record_now->next->prev = record_now;
	record_now = record_now->next; //更新当前结点指针
	record_now->player = player;
	record_now->now_x = now_x;
	record_now->now_y = now_y;
	record_now->move_x = move_x;
	record_now->move_y = move_y;
	record_now->piece = board[now_y][now_x].type;
	record_now->taking = board[move_y][move_x].type;
	return;
}


//这个函数有点没必要
void deleteRecord(void) //在尾部删除一个结点，用于悔棋和释放内存
{
	if (record_now == NULL)
		return;
	if (record_now->prev == NULL)
	{
		free(record_now);
		record_now = NULL;
		return;
	}
	record_now = record_now->prev;
	free(record_now->next);
	record_now->next = NULL;
}

void loadLinkList(void)
{
	FILE* fp;
	fp = fopen("record_internal_1.txt", "r");
	if (fp == NULL)
	{
		system("cls");
		printf("                                                   未找到棋谱记录\n");
		printf("\n                                                    棋谱加载失败\n");
		printf("\n\n\n                                                      请输入任意键继续：");
		system("pause");
		return;
	}
	int input_temp;
	while (fscanf_s(fp, "%d", &input_temp)!=EOF)
	{
		record_now->next = (node_PT)malloc(sizeof(node_T));
		if (record_now->next == NULL)
		{
			printf("                                                     棋谱记录结点创建失败\n");
			printf("                                                          请输入任意键继续：");
			system("pause");
			return;
		}

		record_now->next->next = NULL; //标识新的尾部
		record_now->next->prev = record_now;
		record_now = record_now->next; //更新当前结点指针
		record_now->player = input_temp;
		fscanf_s(fp, "%d%d%d%d", &(record_now->now_x), &(record_now->now_y), &(record_now->move_x), &(record_now->move_y));
		/*fscanf_s(fp, "%c %c\n", &(record_now->piece), &(record_now->taking));*/
		record_now->piece = fgetc(fp);
		record_now->taking = fgetc(fp);
	}
	fclose(fp);
	return;
}