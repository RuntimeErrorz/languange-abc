#include <iostream>
#include <fstream>
#include <iomanip>
#include "job_t.h"

std::string job_t::title_t_str[5] = {"Manager", "HRSpecialist", "TreasuryAttache", "SalesExecutive", "Administrative"};

std::string job_t::title_t_str_short[5] = {"Mng", "HR", "FD", "Sal", "EO"};

job_t::job_t() {}


job_t::job_t(title_t _title, long _salary) : title(_title), salary(_salary) {}


job_t::~job_t() {}


std::ostream& operator<<(std::ostream& o, job_t::title_t& title) {
    o << std::left << std::setw(7) << job_t::title_t_str_short[(int)title];
    return o;
}


std::istream& operator>>(std::istream& i, job_t::title_t& title) {
    int temp;
    i >> temp;
    title = (job_t::title_t)temp;
    return i;
}


std::ostream& operator<<(std::ostream& o, job_t& job) {
    o << (int)(job.title) << " " << job.salary;
    return o;
}


std::istream& operator>>(std::istream& i, job_t& job) {
    i >> job.title;
    i >> job.salary;
    return i;
}