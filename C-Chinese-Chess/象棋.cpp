#define _CRT_SECURE_NO_WARNINGS //防止fopen报错
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "chess.h"

extern bool player;
extern qiZi_T board[MAX_ROW][MAX_COL];
extern locate_T list[2][12];
extern node_PT record_start; //棋谱链表表头
extern node_PT record_now; //棋谱链表尾部结点
extern bool threat_flag;
extern int step;
int load_type = -1; //载入类型，0为重新生成，1为从存档中读取
int now_x, now_y, move_x, move_y; //要移动棋子的位置和目标点的位置
int illegal_type = 0; //非法移动类型
int special_deal_type; //投降或悔棋等

int main()
{
	while (load_type < 0) //处理读取失败时的情景
	{
		load_type = show_UI(); //显示UI界面

		/*char pass; //换用安全读入后无需再吃掉换行符
		scanf_s("%c", &pass);*/

		if (load_type == 0)
			initialize(); //初始化
		else if (load_type == 1)
			load_type = load(); //从文件读入
	}
	createLinkList();
	if (load_type == 1) // 若是从文件中读取，还需要重新挂载链表
		loadLinkList();

	while (1)
	{
		show(illegal_type); /*显示棋局*/
		if (win()) //判断胜负
			break;
		threat_flag = threat();
		show_player();
		special_deal_type = myInput(&now_x, &now_y, &move_x, &move_y); //用户操作阶段

		if (special_deal_type != 0) //如果需要进行特殊操作
		{
			specialDeal(special_deal_type);
			continue; //如果进行了特殊操作，则直接进入下一轮循环
		}
		if ((illegal_type = isLegal(now_x, now_y, move_x, move_y)) != 0) /*判断是否为合法移动*/
			continue; //直接跳过后续环节，要求重新移动
		else if (meet(now_x, now_y, move_x, move_y))
		{
			illegal_type = 7;
			continue;
		}
		else
		{
			recordMove(now_x, now_y, move_x, move_y);
			if (board[now_y][now_x].type != 'x' && board[now_y][now_x].type != 's') //更新己方的棋子位置
			{
				for (int i = 0; i <= 11; i++)
				{
					if (list[player][i].x == now_x && list[player][i].y == now_y &&list[player][i].type==board[now_y][now_x].type)
					{
						list[player][i].x = move_x;
						list[player][i].y = move_y;
						break;
					}
				}
			}
			if (board[move_y][move_x].type != 'x' && board[move_y][move_x].type != 's' && board[move_y][move_x].type != 'k') //更新对方的棋子位置
			{
				for (int i = 0; i <= 11; i++)
				{
					if (list[!player][i].x == move_x && list[!player][i].y == move_y)
					{
						list[!player][i].type = 'k';
						break;
					}
				}
			}
			board[move_y][move_x] = board[now_y][now_x];  /*更新棋盘和棋子等*/
			board[now_y][now_x].type = 'k';
			player = !player; //若合法，则下一轮换为对手下棋
			step++; //记录这一手棋
		}

	}
	printf("\n                                                ");
	system("pause");
	return 0;
}