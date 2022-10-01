#include "chess.h"
#include <stdbool.h>

extern bool player;
extern locate_T list[2][12]; //棋子位置列表   0:黑，1:红    list[][0]固定是将

bool threat(void)
{
	player = !player; //先翻转以便使用isLegal函数
	for (int i = 1; i <= 11; i++)
	{
		if (list[player][i].type != 'k' && isLegal(list[player][i].x, list[player][i].y, list[!player][0].x, list[!player][0].y) == 0)
		{
			player = !player; //翻转回去
			return true;
		}
	}
	player = !player; //翻转回去
	return false;
}