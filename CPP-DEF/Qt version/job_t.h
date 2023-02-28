#pragma once
#include <iostream>
#include <fstream>

class job_t
{
    public:
        using work_t = enum{
            Manager,
            HRSpecialist,
            TreasuryAttache,
            SalesExecutive,
            AdministrativeCommissioner
        };

    public:
        work_t off;
        long salary;

    public:
        job_t() {}
        job_t(work_t _off, long _salary) : off(_off), salary(_salary) {}
        ~job_t() {}

        inline friend std::ostream& operator<<(std::ostream& o, work_t& work);
        inline friend std::istream& operator>>(std::istream& i, work_t& work);
        inline friend std::ostream& operator<<(std::ostream& o, job_t& job); //用于向文件中写入信息
        inline friend std::istream& operator>>(std::istream& i, job_t& job);
};

inline std::ostream& operator<<(std::ostream& o, job_t::work_t& work) {
    switch(work)
    {
        case job_t::Manager: o << "Manager"; break;
        case job_t::HRSpecialist: o << "HRSpecialist"; break;
        case job_t::TreasuryAttache: o << "TreasuryAttache"; break;
        case job_t::SalesExecutive: o << "SalesExecutive"; break;
        case job_t::AdministrativeCommissioner: o << "AdministrativeCommissioner"; break;
    }
    return o;
}

inline std::istream& operator>>(std::istream& i, job_t::work_t& work) {
    int temp;
    i >> temp;
    work = (job_t::work_t)temp;
    return i;
}

inline std::ostream& operator<<(std::ostream& o, job_t& job) {
    o << (int)(job.off) << " " << job.salary;
    return o;
}


inline std::istream& operator>>(std::istream& i, job_t& job) {
    i >> job.off;
    i >> job.salary;
    return i;
}
