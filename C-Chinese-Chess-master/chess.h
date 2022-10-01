#pragma once
#ifndef __CHESS_H___
#define __CHESS_H___
#include "islegal.h"
#include "initialize.h"
#include "show.h"
#include "myInput.h"
#include "interface.h"
#include "winJudge.h"
#include "specialDeal.h"
#include "record.h"
#include "threat.h"
#include <stdbool.h>

#define MAX_ROW 10
#define MAX_COL 9
#define SAVE_FILE "save.txt"

typedef struct qiZi_T
{
	bool player; //0：黑 1：红
	char type; //b：兵 p：炮 c：车 m：马 x：象 s：士 j：帅 k：空
}qiZi_T, * qiZi_PT;

typedef struct locate_T
{
	int x;
	int y;
	char type;
}locate_T;

typedef struct node_T //
{
	int player;
	int now_x;
	int now_y;
	int move_x;
	int move_y;
	char taking; //吃的子
	char piece; //动的子
	node_T* next;
	node_T* prev;
}node_T, * node_PT;

typedef struct
{
	int step;
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
}record_T,*recod_PT;
#endif