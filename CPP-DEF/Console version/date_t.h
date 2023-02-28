#pragma once
#include <fstream>
#include <iostream>

struct date_t
{
    int year;
    int month;
    int day;
    static int days_in_month[13]; //每月日期，多留一位用的时候方便

    bool is_leap_year(); //判断闰年
    bool error_date(); //判断日期是否是公历日期
    bool later_than_now(); //判断是否日期晚于现在

    date_t& operator=(date_t& a);

    friend std::ostream& operator<<(std::ostream& o, date_t& a);
    friend std::istream& operator>>(std::istream& i, date_t& a);

    void print();
};