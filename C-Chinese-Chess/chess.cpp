#include "chess.h"
//公共变量

bool player; //记录当前棋手 true为红，false为黑
qiZi_T board[MAX_ROW][MAX_COL]; //棋盘
locate_T list[2][12]; //棋子位置列表   0:黑，1:红    list[][0]固定是将 其余的11个子都是攻击子
node_PT record_start; //棋谱链表表头
node_PT record_now; //链表尾部结点
bool threat_flag; //判断有无被将军
int step; //记录本局有多少手