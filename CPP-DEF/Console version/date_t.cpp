#include <fstream>
#include <iostream>
#include <iomanip>
#include <ctime>
#include "date_t.h"

int date_t::days_in_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool date_t::is_leap_year() {
    if(year % 4 != 0)
        return false;
    else if(year % 100 != 0)
        return true;
    else if(year % 400 == 0)
        return false;
    return true;
}

bool date_t::error_date() {
    if((month == 2 && is_leap_year()) && (day < 1 || day > 29))
        return true;
    if(month < 1 || month > 12)
        return true;
    if(day < 1 || day > days_in_month[month])
        return true;
    return false; //年份不判，欢迎千年老妖入职
}

bool date_t::later_than_now() {
    time_t now = time(0);
    tm *now_struct = localtime(&now);
    if(year > (now_struct->tm_year + 1900))
        return true;
    else if(year == (now_struct->tm_year + 1900) && month > (now_struct->tm_mon + 1))
        return true;
    else if(year == (now_struct->tm_year + 1900) && month == (now_struct->tm_mon + 1) && day > now_struct->tm_mday)
        return true;
    return false;
}

date_t& date_t::operator=(date_t& a) {
    year = a.year;
    month = a.month;
    day = a.day;
    return *this;
}

void date_t::print() {
    std::cout << std::right << std::setw(4) << year << "/";
    std::cout << std::right << std::setfill('0') << std::setw(2) << month << "/";
    std::cout << std::right << std::setfill('0') << std::setw(2) << day;
    std::cout << std::setfill(' ');
}

std::ostream& operator<<(std::ostream& o, date_t& a) {
    o << std::right << std::setw(4) << a.year << "/";
    o << std::right << std::setfill('0') << std::setw(2) << a.month << "/";
    o << std::right << std::setfill('0')  << std::setw(2)<< a.day;
    o << std::setfill(' ');
    return o;
}

std::istream& operator>>(std::istream& i, date_t& a) {
    i >> a.year >> a.month >> a.day;
    return i;
}