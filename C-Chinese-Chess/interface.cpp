#define _CRT_SECURE_NO_WARNINGS
#include "chess.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

//返回值说明：0.重新生成棋盘，1.从文件中载入
int show_UI()
{
	char temp_s[11];
	temp_s[10] = '\n';
	int deal = 0;
	char ch;
	int shift = 0;
	while (deal == 0)
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n");
		printf("                                                        中国象棋\n\n\n\n");
		printf("                                                     1.新 的 游 戏\n");
		printf("                                                     2.载 入 存 档\n");
		printf("                                                     3.查 看 帮 助\n");
		printf("                                                     4.历 史 回 顾\n");
		printf("                                                     5.退 出 游 戏\n");
		printf("                                                            ");
		fgets(temp_s, 10, stdin); //安全的输入
		shift = 0;
		sscanf_s(temp_s + (shift++), "%c", &ch);
		if (ch < '1' || ch>'5')
			continue;
		else
			deal = ch - '0';
		sscanf_s(temp_s + (shift++), "%c", &ch); //输入不正确时重新显示，保证不会崩溃
		if (ch != '\n' && ch != '\0')
		{
			deal = 0;
			continue;
		} //安全输入到此为止
		if (deal == 1)
			return 0;
		else if (deal == 2)
			return 1;
		else if (deal == 3)
		{
			while (deal != 0)
			{
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\n");
				printf("                                                          帮助\n\n\n");
				printf("                                                     0.返回上级目录\n");
				printf("                                                     1.游戏操则\n");
				printf("                                                     2.游戏操作\n");
				printf("                                                     3.版权说明\n");
				printf("                                                     4.制作人名单\n");
				printf("                                                            ");
				fgets(temp_s, 10, stdin); //安全的输入
				shift = 0;
				sscanf_s(temp_s + (shift++), "%c", &ch);
				if (ch < '0' || ch>'4')
					continue;
				else
					deal = ch - '0';
				sscanf_s(temp_s + (shift++), "%c", &ch); //输入不正确时重新显示，保证不会崩溃
				if (ch != '\n' && ch != '\0')
				{
					deal = 0;
					continue;
				}
				switch (deal)
				{
					case 0:
						break;
					case 1:
						system("cls");
						printf("\n                                                         游戏规则\n");
						printf("\n\n");
						printf(" 胜负:\n");
						printf("\n  将死——另一方走一步棋之后试图吃掉一方的帅（将），但该方的帅（将）却不能躲避");
						printf("\n  困毙——轮到一方行棋，但按规定，己方无棋可走；");
						printf("\n  认输——由于子力悬殊，继续抵抗毫无意义的主动认输；\n\n");
						printf("\n 走子:\n");
						printf("\n     帅（将）：帅（将）是棋中的首脑，是双方竭力争夺的目标。它只能在九宫之内活动，可上可下，可左可右，每次走动只能按\n  竖线或横线走动一格。帅与将不能在同一直线上直接对面。\n");
						printf("\n     仕（士）：仕（士）是将（帅）的贴身保镖，它也只能在九宫内走动。它的行棋路径只有九宫内的四条斜线。\n");
						printf("\n     相（象）：相（象）的主要作用是防守，保护自己的帅（将）。它的走法是每次循对角线走两格，俗称“象飞田”。相（象）\n  的活动范围限于河界以内的本方阵地，不能过河，且如果它走的田字中央有一个棋子，就不能走，俗称“塞象眼”。\n");
						printf("\n     车：车在象棋中威力最大，无论横线、竖线均可行走，只要无子阻拦，步数不受限制。因此，一车可以控制十七个点，故有\n  “一车十子寒”之称。\n");
						printf("\n     炮：炮在不吃子的时候，移动与车完全相同。当吃子时，己方和对方的棋子中间必须间隔1个棋子（无论对方或己方棋子），\n  炮是象棋中唯一可以越子的棋种。\n");
						printf("\n     马：马走动的方法是一直一斜，即先横着或直着走一格，然后再斜着走一个对角线，俗称“马走日”。马一次可走的选择点\n  可以达到四周的八个点，故有“八面威风”之说。如果在要去的方向有别的棋子挡住，马就无法走过去，俗称“蹩马腿”。\n");
						printf("\n     兵（卒）：兵（卒）在未过河前，只能向前一步步走，过河以后，除不能后退外，允许左右移动，但也只能一次一步，即使\n  这样，兵（卒）的威力也大大增强，故有“过河的卒子顶半个车”之说。");
						printf("\n\n                                                  请输入0回到上级目录：");
						scanf_s("%d", &deal);
						deal = 1;
						break;
					case 2:
						system("cls");
						printf("\n                                                         游戏操作\n");
						printf("\n\n\n\n\n");
						printf("          参照棋盘旁的坐标根据提示来操作棋子。\n");
						printf("\n          键入\"t\"来投降\n");
						printf("\n          键入\"h\"悔一步棋\n");
						printf("\n          键入\"s\"来存档\n");
						printf("\n          键入\"c\"来查看本局棋谱\n");
						printf("\n          键入\"q\"来退出\n");
						printf("\n\n\n\n\n\n\n\n                                                  请输入0回到上级目录：");
						scanf_s("%d", &deal);
						deal = 1;
						break;
					case 3:
						system("cls");
						printf("\n                                                         版权说明\n");
						printf("\n\n\n");
						printf("                                        本作品遵循知识共享许可协议(CC)4.0协议。\n");
						printf("  您可以自由地使用本程序：\n\n");
						printf("    惟须遵守下列条件：\n\n");
						printf("  ·相同形式共享 — 您可以自由复制、散布、展示及演出本作品; 若您改变、转变或更改本作品，仅在遵守与本作品相同的许可条款下，您才能散布由本作品产生的派生作品。\n");
						printf("\n  ·署名 — 您（用户）可以复制、发行、展览、表演、放映、广播或通过信息网络传播本作品。您必须按照作者或者许可人指定的方式对作品进行署名。\n");
						printf("\n  ·非商业性使用 — 您可以自由复制、散布、展示及演出本作品;您不得为商业目的而使用本作品。\n");
						printf("\n  ·没有附加限制 — 您不得使用法律术语或者技术措施从而限制其他人做许可协议允许的事情。\n");
						printf("\n\n  声明：\n");
						printf("    您不必因为公共领域的作品要素而遵守许可协议，或者您的使用被可适用的例外或限制所允许。\n");
						printf("    不提供担保。许可协议可能不会给与您意图使用的所必须的所有许可。例如，其他权利比如形象权、隐私权或人格权可能限制\n  您如何使用作品。\n");
						printf("                                                  请输入0回到上级目录：");
						scanf_s("%d", &deal);
						deal = 1;
						break;
					case 4:
						system("cls");
						printf("\n                                            制作人名单（按姓氏拼音首字母排序）\n");
						printf("\n\n\n\n\n\n");
						printf("                                                       包镕嘉\n\n");
						printf("                                                       陈驿\n\n");
						printf("                                                       陆虹羽\n\n");
						printf("                                                       谭凯元\n\n");
						printf("                                                       曾德御\n\n");
						printf("\n\n\n                                                 请输入0回到上级目录：");
						scanf_s("%d", &deal);
						deal = 1;
						break;
				}
			}
		}
		else if (deal == 4)
		{
			while (deal != 0)
			{
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\n                                                        历史回顾\n\n\n");
				printf("                                                    0.返回上级目录\n");
				printf("                                                    1.上局棋谱\n");
				printf("                                                    2.最长对局排行榜\n");
				printf("                                                           ");
				fgets(temp_s, 10, stdin); //安全的输入
				shift = 0;
				sscanf_s(temp_s + (shift++), "%c", &ch);
				if (ch < '0' || ch>'2')
					continue;
				else
					deal = ch - '0';
				sscanf_s(temp_s + (shift++), "%c", &ch); //输入不正确时重新显示，保证不会崩溃
				if (ch != '\n' && ch != '\0')
				{
					deal = 0;
					continue;
				}
				if (deal == 1)
				{
					system("cls");
					FILE* fp;
					fp = fopen("record_1.txt", "r");
					if (fp == NULL)
					{
						printf("\n\n\n\n\n\n\n\n\n\n\n                                                     未找到相关文件\n");
						deal = 1;
					}
					else
					{
						char record_line[101];
						record_line[100] = '\0';
						int i = 1;
						bool printf_flag = true;
						while (fgets(record_line, 100, fp) != NULL)
						{
							if(printf_flag)
								printf("\n\n                                                      上局棋谱\n\n\n");
							printf("                                            第%d手  %s\n", i++, record_line);
							printf_flag = false;
						}
						if (printf_flag)
							printf("\n\n\n\n\n\n\n\n\n\n\n                                                      棋谱中无记录！\n");
						fclose(fp);
					}
					printf("\n\n\n\n\n                                                   ");
					system("pause");
					deal = 1;
				}

				else if (deal == 2) //排行榜
				{
					FILE* fp;
					fp = fopen("ranking_list.txt", "r");
					if (fp == NULL)
					{
						system("cls");
						printf("\n\n\n\n\n\n\n\n\n\n\n                                                     排行榜纪录丢失\n");
						printf("\n\n\n\n\n                                                   ");
						system("pause");
						deal = 1;
						continue;
					}
					int step_temp;
					system("cls");
					printf("\n\n                                                    最长对弈排行榜\n\n\n\n\n\n");
					int i;
					for (i = 0; fscanf(fp, "%d", &step_temp) != EOF; i++)
					{
						struct tm info;
						fscanf(fp, "%d %d %d %d %d %d", &info.tm_year, &info.tm_mon, &info.tm_mday, &info.tm_hour, &info.tm_min, &info.tm_sec);
						printf("        %2d.  共%4d  手  ", i+1, step_temp);
						printf("%d 年 %2d 月 %2d 日  %2d : %.2d : %.2d\n", info.tm_year, info.tm_mon, info.tm_mday, info.tm_hour, info.tm_min, info.tm_sec);
					}
					while (i < 10)
					{
						printf("        %2d.\n", (i++)+1);
					}
					printf("\n\n\n\n\n                                                 请输入0回到上级目录：");
					scanf_s("%d", &deal);
					deal = 1;
					fclose(fp);
				}
			}
		}
		else if (deal == 5) //退出
			exit(EXIT_SUCCESS);
	}
}