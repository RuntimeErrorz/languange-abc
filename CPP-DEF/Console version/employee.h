#pragma once
#include <iostream>
#include <fstream>
#include "job_t.h"
#include "date_t.h"


class employee
{
    public:
        using unit_t = enum {
            HumanResources = 0,
            Accounting,
            Sales,
            Administration
        };
        using gender_t = enum {M = 0, F};

        static std::string unit_t_str[4];
        static std::string unit_t_str_short[4];
        static std::string gender_t_str[2];
    
    private:
        std::string eid; //员工号
        std::string name; //姓名
        gender_t gender; //性别，M为男，F为女
        date_t dob; //出生日期
        date_t doe; //入职日期
        unit_t unit; //部门
        job_t *job; //职位及年薪
    
    public:
        employee();
        employee(std::string _eid, std::string _name, gender_t _gender, date_t _dob, date_t _doe, unit_t _unit, job_t *_job);
        employee(std::string _eid);
        ~employee();

        
        employee& operator=(employee& a);

        void print(); //用于输出到屏幕

        

        friend std::ostream& operator<<(std::ostream& o, unit_t& a);
        friend std::istream& operator>>(std::istream& i, unit_t& a);
        friend std::ostream& operator<<(std::ostream& o, gender_t& a);
        friend std::istream& operator>>(std::istream& i, gender_t& a);
        friend std::ostream& operator<<(std::ostream& o, employee& a); //用于储存到文件中

        friend class staff;
};

employee::unit_t _int2unit_t(int a);
employee::gender_t _int2gender_t(int a);