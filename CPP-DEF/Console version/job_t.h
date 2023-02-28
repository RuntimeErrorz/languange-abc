#pragma once
#include <iostream>
#include <fstream>

class job_t
{
    public:
        using title_t = enum{
            Manager = 0,
            HRSpecialist,
            TreasuryAttache,
            SalesExecutive,
            AdministrativeCommissioner
        };

        static std::string title_t_str[5];
        static std::string title_t_str_short[5];

    public:
        title_t title;
        long salary;

    public:
        job_t();
        job_t(title_t _title, long _salary);
        ~job_t();

        friend std::ostream& operator<<(std::ostream& o, title_t& title);
        friend std::istream& operator>>(std::istream& i, title_t& title);
        friend std::ostream& operator<<(std::ostream& o, job_t& job); //用于向文件中写入信息
        friend std::istream& operator>>(std::istream& i, job_t& job);
};