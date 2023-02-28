#include "chess.h"
#include <stdio.h>
//这是一个绝对安全的输入函数，无论如何都不会崩溃，可厉害了
//码了好久终于码出来了，开心qaq

/**********************
* 返回值说明：        *
* 0.正常输入          *
* 1.投降              *
* 2.悔棋              *
* 3.存档              *
* 4.棋谱              *
* 5.退出              *
***********************/
int myInput(int* p_now_x, int* p_now_y, int* p_move_x, int* p_move_y)
{
	int temp; //叠加int
	char input_temp[21], ch; //缓冲数组和处理的单个字符变量
	input_temp[20] = '\n'; //封尾保证后面不会无限循环
	bool flag = false; //标识有无错误
	int num = 0; //只是为了把两端代码压成一段，0为now，1为move
	while (1)
	{
		if (flag)
		{
			temp = 0;
			printf("                       您的输入有问题，请输入坐标，第一个数字应在0—8范围内，第二个应在0—9范围内\n");
			if (num == 0) //偷懒ing
				printf("                                             请输入您要移动的点的坐标：");
			else
				printf("                                             请输入目标点的坐标：");
		}
		else
		{
			if (num == 0)
				printf("                                             请输入您要移动的点的坐标：");
			else
				printf("                                             请输入目标点的坐标：");
		}
		fgets(input_temp, 20, stdin); //读入至缓冲字符串
		int shift = 0;
		sscanf_s(input_temp + (shift++), "%c", &ch);

		if (ch == 't') //投降特判
		{
			sscanf_s(input_temp + (shift++), "%c", &ch);
			if (ch == '\n')
				return 1;
			else
			{
				flag = true;
				continue;
			}
		}
		else if (ch == 'h') //悔棋特判
		{
			sscanf_s(input_temp + (shift++), "%c", &ch);
			if (ch == '\n')
				return 2;
			else
			{
				flag = true;
				continue;
			}
		}
		else if (ch == 's') //存档特判
		{
			sscanf_s(input_temp + (shift++), "%c", &ch);
			if (ch == '\n')
				return 3;
			else
			{
				flag = false;
				continue;
			}
		}
		else if (ch == 'c') //棋谱特判
		{
			sscanf_s(input_temp + (shift++), "%c", &ch);
			if (ch == '\n')
				return 4;
			else
			{
				flag = false;
				continue;
			}
		}
		else if (ch == 'q') //退出特判
		{
			sscanf_s(input_temp + (shift++), "%c", &ch);
			if (ch == '\n')
				return 5;
			else
			{
				flag = false;
				continue;
			}
		}

		if (ch < '0' || ch>'9')
		{
			flag = true;
			continue;
		}
		temp = 0;
		flag = false;
		while (ch != ' ' && ch != '\n' && ch != ',')
		{
			if (ch >= '0' && ch <= '9')
				temp = temp * 10 + ch - '0';
			else
			{
				flag = true;
				break;
			}
			sscanf_s(input_temp + (shift++), "%c", &ch);
		}
		if (ch == '\n')
			flag = true;
		if (flag)
			continue;
		if (num == 0) //再次偷懒。。。
			*p_now_x = temp;
		else
			*p_move_x = temp;
		temp = 0;
		while ((ch == ' ' || ch == ',') && ch != '\n')
			sscanf_s(input_temp + (shift++), "%c", &ch);
		while (ch != ' ' && ch != '\n')
		{
			if (ch >= '0' && ch <= '9')
				temp = temp * 10 + ch - '0';
			else
			{
				flag = true;
				break;
			}
			sscanf_s(input_temp + (shift++), "%c", &ch);
		}
		if (flag)
			continue;
		if (num == 0) //能偷懒的关键
		{
			*p_now_y = temp;
			temp = 0;
			num++;
		}
		else
		{
			*p_move_y = temp;
			break;
		}
	}
	return 0; //正常结束
}