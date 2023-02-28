#pragma once
#include <fstream>
#include <iostream>

struct date_t
{
    int year;
    int month;
    int day;

    date_t& operator=(date_t& a) {
        year = a.year;
        month = a.month;
        day = a.day;
        return *this;
    }

    inline friend std::ostream& operator<<(std::ostream& o, date_t& a);
    inline friend std::istream& operator>>(std::istream& i, date_t& a);

    void print() {
        std::cout << year << "/" << month << "/" << day;
    }
};

inline std::ostream& operator<<(std::ostream& o, date_t& a) {
    o << a.year << "/" << a.month << "/" << a.day;
    return o;
}

inline std::istream& operator>>(std::istream& i, date_t& a) {
    i >> a.year >> a.month >> a.day;
    return i;
}
