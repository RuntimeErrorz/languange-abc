#pragma once
#ifndef __RECORD_H___
#define __RECORD_H___
void createLinkList(void); //参数都成全局变量了
void recordMove(int now_x, int now_y, int move_x, int move_y); //创建一个新结点来记录移动
void deleteRecord(void); //在尾部删除一个结点，用于悔棋
void loadLinkList(void); //读档时重新挂上链表
#endif