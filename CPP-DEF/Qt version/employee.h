#pragma once
#include <iostream>
#include <fstream>
#include "job_t.h"
#include "date_t.h"
class employee
{
    friend class insert;
    friend class modify;
    friend class DeleteByEid;
    public:
        using office_t = enum {
            HumanResources,
            Accounting,
            Sales,
            Administration
        };
        using sex_t = enum {M, F};
    
    private:
        std::string eid; //员工号
        std::string name; //姓名
        sex_t gender; //性别，M为男，F为女
        date_t dob; //出生日期
        date_t doe; //入职日期
        office_t unit; //部门
        job_t *job; //职位及年薪
    
    public:
        employee() {}
        employee(std::string _eid, std::string _name, sex_t _gender, date_t _dob, date_t _doe, office_t _unit, job_t *_job)
            : eid(_eid), name(_name), gender(_gender), dob(_dob), doe(_doe), unit(_unit), job(_job) {}
        employee(std::string _eid) : eid(_eid) {}
        ~employee() {}

        
        employee& operator=(employee& a) {
            eid = a.eid;
            name = a.name;
            gender = a.gender;
            dob = a.dob;
            doe = a.doe;
            unit = a.unit;
            job = a.job;
            return *this;
        }


        friend std::ostream& operator<<(std::ostream& o, office_t& a);
        friend std::istream& operator>>(std::istream& i, office_t& a);
        friend std::ostream& operator<<(std::ostream& o, sex_t& a);
        friend std::istream& operator>>(std::istream& i, sex_t& a);
        friend std::ostream& operator<<(std::ostream& o, employee& a); //用于储存到文件中

        friend class staff;
};


inline std::ostream& operator<<(std::ostream& o, employee::office_t& a) {
    switch(a)
    {
        case employee::HumanResources: o << "HumanResources"; break;
        case employee::Accounting: o << "Accounting"; break;
        case employee::Sales: o << "Sales"; break;
        case employee::Administration: o << "Administration"; break;
    }
    return o;
}

inline std::istream& operator>>(std::istream& i, employee::office_t& a) {
    int temp;
    i >> temp;
    a = (employee::office_t)temp;
    return i;
}

inline std::ostream& operator<<(std::ostream& o, employee::sex_t& a) {
    switch(a)
    {
        case employee::M: o << "Male"; break;
        case employee::F: o << "Female"; break;
    }
    return o;
}

inline std::istream& operator>>(std::istream& i, employee::sex_t& a) {
    int temp;
    i >> temp;
    a = (employee::sex_t)temp;
    return i;
}

inline std::ostream& operator<<(std::ostream& o, employee& a) {
    o << a.eid << " " << a.name << " ";
    o << (int)a.gender << " ";
    o << a.dob.year << " " << a.dob.month << " " << a.dob.day << " ";
    o << a.doe.year << " " << a.doe.month << " " << a.doe.day << " ";
    o << (int)a.unit << " ";
    o << (int)((a.job)->off);
    return o;
}
