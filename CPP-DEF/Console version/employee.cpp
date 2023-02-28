#include <iostream>
#include <fstream>
#include <iomanip>
#include "job_t.h"
#include "date_t.h"
#include "employee.h"

std::string employee::unit_t_str[4] = {"HumanResources", "Accouting", "Sales", "Administration"};

std::string employee::unit_t_str_short[4] = {"HR", "ACCT", "Sal", "Admin"};

std::string employee::gender_t_str[2] = {"Male", "Female"};

employee::employee() {}


employee::employee(std::string _eid, std::string _name, gender_t _gender, date_t _dob, date_t _doe, unit_t _unit, job_t *_job)
    : eid(_eid), name(_name), gender(_gender), dob(_dob), doe(_doe), unit(_unit), job(_job) {}


employee::employee(std::string _eid) : eid(_eid) {}


employee::~employee() {}


employee& employee::operator=(employee& a) {
    eid = a.eid;
    name = a.name;
    gender = a.gender;
    dob = a.dob;
    doe = a.doe;
    unit = a.unit;
    job = a.job;
    return *this;
}


void employee::print() {
    std::cout << "  ┃";
    std::cout << std::left << std::setw(11) <<eid << "│";
    std::cout << std::left << std::setw(10) << name << "│";
    std::cout << (gender == M ? "  male  " : " female ") << "│";
    std::cout << dob << "│ " << doe << "  │";
    std::cout << unit << "│";
    std::cout << job->title << "│";
    std::cout << std::left << std::setw(10) << job->salary << "┃";
}


employee::unit_t _int2unit_t(int a) {
    if(a < 0 || a > 3)
        throw(1);
    return (employee::unit_t)a;
}


employee::gender_t _int2gender_t(int a)
{
    if(a != 0 && a != 1)
        throw(1);
    return (employee::gender_t)a;
}


std::ostream& operator<<(std::ostream& o, employee::unit_t& a) {
    o << std::left << std::setw(6) << employee::unit_t_str_short[(int)a];
    return o;
}


std::istream& operator>>(std::istream& i, employee::unit_t& a) {
    int temp;
    i >> temp;
    a = (employee::unit_t)temp;
    return i;
}


std::ostream& operator<<(std::ostream& o, employee::gender_t& a) {
    o << employee::gender_t_str[(int)a];
    return o;
}


std::istream& operator>>(std::istream& i, employee::gender_t& a) {
    int temp;
    i >> temp;
    a = (employee::gender_t)temp;
    return i;
}


std::ostream& operator<<(std::ostream& o, employee& a) {
    o << a.eid << " " << a.name << " ";
    o << (int)a.gender << " ";
    o << a.dob.year << " " << a.dob.month << " " << a.dob.day << " ";
    o << a.doe.year << " " << a.doe.month << " " << a.doe.day << " ";
    o << (int)a.unit << " ";
    o << (int)((a.job)->title);
    return o;
}