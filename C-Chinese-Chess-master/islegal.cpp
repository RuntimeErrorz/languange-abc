#include "chess.h"
#include <stdio.h>

extern qiZi_T board[MAX_ROW][MAX_COL];
extern locate_T list[2][12];
extern bool player;

/*******************
* 返回值说明       *
* 0.合法           *
* 1.坐标越界       *
* 2.没有移动       *
* 3.选定坐标无棋子 *
* 4.非己方棋子     *
* 5.目标点有己方子 *
* 6.移动非法       *
********************/

int isLegal(const int now_x, const int now_y, const int move_x, const int move_y)
{
	if (now_x < 0 || now_x>8 || now_y < 0 || now_y>9
		|| move_x < 0 || move_x>8 || move_y < 0 || move_y>9)
		return 1;
	if (move_x == now_x && move_y == now_y)
		return 2;
	if (board[now_y][now_x].type == 'k')
		return 3;
	if (board[now_y][now_x].player != player)
		return 4;
	if (board[move_y][move_x].player == player && board[move_y][move_x].type != 'k')
		return 5;


	if (board[now_y][now_x].type == 'b') //兵
	{
		if (player) //红方
		{
			if (now_y <= 4) //过河前
			{
				if (move_x != now_x || move_y != now_y + 1)
					return 6;
			}
			else //过河后
			{
				bool flag = true;
				if (move_x == now_x && move_y == now_y + 1)
					flag = false;
				else if (move_x == now_x + 1 && move_y == now_y)
					flag = false;
				else if (move_x == now_x - 1 && move_y == now_y)
					flag = false;
				if (flag) //若非向上，向左或向右走，则为非法
					return 6;
			}
		}
		else //黑方
		{
			if (now_y >= 5) //过河前
			{
				if (move_x != now_x || move_y != now_y - 1)
					return 6;
			}
			else //过河后
			{
				bool flag = true;
				if (move_x == now_x && move_y == now_y - 1)
					flag = false;
				else if (move_x == now_x + 1 && move_y == now_y)
					flag = false;
				else if (move_x == now_x - 1 && move_y == now_y)
					flag = false;
				if (flag) //若非向下，向左或向右走，则为非法
					return 6;
			}
		}
		return 0;
	}


	else if (board[now_y][now_x].type == 'p') //炮
	{
		int interval = 0; //两点间间隔的子数
		//判断两点间间隔的子数
		if (now_x == move_x && now_y < move_y) //往上动
		{
			for (int i = now_y + 1; i != move_y; i++)
				if (board[i][now_x].type != 'k')
					interval++;
		}
		else if (now_x == move_x && now_y > move_y) //往下动
		{
			for (int i = now_y - 1; i != move_y; i--)
				if (board[i][now_x].type != 'k')
					interval++;
		}
		else if (now_y == move_y && now_x < move_x) //往右动
		{
			for (int i = now_x + 1; i != move_x; i++)
				if (board[now_y][i].type != 'k')
					interval++;
		}
		else if (now_y == move_y && now_x > move_x) //往左动
		{
			for (int i = now_x - 1; i != move_x; i--)
				if (board[now_y][i].type != 'k')
					interval++;
		}
		else //若不是直着走的，则显然是非法移动
			return 6;

		if (interval == 0) //若两点间无子，则为合法走
			return 0;
		else if (interval > 1) //若两点间有一个以上的子，则为非法移动
			return 6;
		else if (board[move_y][move_x].type != 'k') //合法吃子
			return 0;
		else //无子可吃则不可跳，移动非法
			return 6;
	}


	else if (board[now_y][now_x].type == 'c') //车
	{
		if (now_x == move_x && now_y < move_y) //向上走
		{
			for (int i = now_y + 1; i != move_y; i++)
				if (board[i][now_x].type != 'k') //中间有子阻挡时移动非法，下同
					return 6;
		}
		else if (now_x == move_x && now_y > move_y) //往下走
		{
			for (int i = now_y - 1; i != move_y; i--)
				if (board[i][now_x].type != 'k')
					return 6;
		}
		else if (now_y == move_y && now_x < move_x) //往右走
		{
			for (int i = now_x + 1; i != move_x; i++)
				if (board[now_y][i].type != 'k')
					return 6;
		}
		else if (now_y == move_y && now_x > move_x) //往左走
		{
			for (int i = now_x - 1; i != move_x; i--)
				if (board[now_y][i].type != 'k')
					return 6;
		}
		else //不是直着走则显然移动非法
			return 6;
		return 0; //直走且前面未弹出，则无阻挡，移动合法
	}


	else if (board[now_y][now_x].type == 'm') //马
	{ //写法比较巧妙，可能可读性较差
	    int dif_x = now_x > move_x ? now_x - move_x : move_x - now_x;
		int dif_y = now_y > move_y ? now_y - move_y : move_y - now_y;
		if (dif_x == 2 && dif_y == 1) //横着跳（横二竖一的四个点）
		{
			if (board[now_y][(now_x + move_x) / 2].type != 'k') //别马腿了
				return 6;
		}
		else if (dif_x == 1 && dif_y == 2) //竖着跳（横一竖二的四个点）
		{
			if (board[(now_y + move_y) / 2][now_x].type != 'k') //别马脚了
				return 6;
		}
		else //不走“日”字则为非法移动
			return 6;
		return 0; //走了“日”字，且没被别马腿，合法移动
	}

	else if (board[now_y][now_x].type == 'x') //象
	{
	    if (player == true && move_y > 4) //红方象不能过河
		    return 6;
	    else if (player == false && move_y < 5) //黑方象不能过河
		    return 6;
		else
		{
			int dif_x = now_x > move_x ? now_x - move_x : move_x - now_x;
			int dif_y = now_y > move_y ? now_y - move_y : move_y - now_y;
			if (dif_x != 2 || dif_y != 2) //若不走田则移动非法
				return 6;
			else if (board[(now_y + move_y) / 2][(now_x + move_x) / 2].type != 'k') //别象腿
				return 6;
			return 0;
		}
    }

	else if (board[now_y][now_x].type == 's') //士
	{
		if (player)//红方
		{
			if (move_x < 3 || move_x > 5 || move_y > 2) return 6;//出宫
			else if (now_x == move_x || now_y == move_y) return 6;//非斜走
			else if (now_x - move_x > 1 || now_x - move_x < -1 || now_y - move_y>1 || now_y - move_y < -1) return 6;//移动大于一格
			else return 0;
		}
		else //黑方
		{
			if (move_x < 3 || move_x > 5 || move_y < 7) return 6;//出宫
			else if (now_x == move_x || now_y == move_y) return 6;//非斜走
			else if (now_x - move_x > 1 || now_x - move_x < -1 || now_y - move_y>1 || now_y - move_y < -1) return 6;//移动大于一格
			else return 0;
		}
     }
     
    
	else if (board[now_y][now_x].type == 'j')//将
	{
		if (player) //红方
		{
			if (move_x < 3 || move_x > 5 || move_y > 2) return 6;//出宫
			else if (now_x != move_x && now_y != move_y) return 6;//斜走
			else if (now_x - move_x > 1 || now_x - move_x < -1 || now_y - move_y>1 || now_y - move_y < -1) return 6;//移动大于一格
			if (move_x != list[0][0].x) return 0;//对将
			int between = 0; //两将之间间隔的子数
			for (int i = list[1][0].y + 1; i < list[0][0].y; i++)
				if (board[i][now_x].type != 'k')
					between++;
			if (between == 0) return 6;
			else return 0;
		}
		else //黑方
		{
			if (move_x < 3 || move_x > 5 || move_y < 7) return 6;//出宫
			else if (now_x != move_x && now_y != move_y) return 6;//斜走
			else if (now_x - move_x > 1 || now_x - move_x < -1 || now_y - move_y>1 || now_y - move_y < -1) return 6;//移动大于一格
			if (move_x != list[1][0].x) return 0;//对将
			int between = 0; //两将之间间隔的子数
			for (int i = list[1][0].y + 1; i < list[0][0].y; i++)
				if (board[i][now_x].type != 'k')
					between++;
			if (between == 0) return 6;
			else return 0;
		}
	}
}

bool meet(int now_x, int now_y, int move_x, int move_y) //true表示会导致对将
{
	if (board[now_y][now_x].type == 'j')
		return false;
	if (list[0][0].x != list[1][0].x) //将不在一列则肯定不会碰面
		return false;
	if (now_x != list[0][0].x) //要动的子本来就不在这一列则动了也不会导致碰面
		return false;
	//若到这一步还没返回，则此时三个子肯定在一列
	if (move_x == list[0][0].x || move_x == list[1][0].x) //最后吃将特判
		return false;
	int between = 0; //两将之间间隔的子数
	for (int i = list[1][0].y + 1; i < list[0][0].y; i++)
		if (board[i][now_x].type != 'k')
			between++;
	if (between == 1 && move_x != now_x) //只有当两将之间只隔了一个子，且该子正要移到别的列时才会导致对将
		return true;
	else
		return false;
}