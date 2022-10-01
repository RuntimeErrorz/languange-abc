#pragma once
#ifndef __ISLEGAL_H___
#define __ISLEGAL_H___
int isLegal(const int now_x, const int now_y, const int move_x, const int move_y);
bool meet(const int now_x, const int now_y, const int move_x, const int move_y); //true表示会导致对将
#endif