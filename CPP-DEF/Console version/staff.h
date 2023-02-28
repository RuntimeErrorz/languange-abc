#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib> //用于创建文件
#include "DoubleLinkList.h"
#include "employee.h"
#include "template_functions.h"



class staff
{
    private:
        job_t jobs[5]; //换成数组，用类似dict的方式控制
        DoubleLinkList<employee> List;

    public:
        staff();
        ~staff();

        void load(std::string file_name, std::string file_name2);
        void save(const char *file_name, const char *file_name2);
        void insert_from_keyboard();
        void insert_from_file();
        void remove_with_eid(int mode);
        void modify_employee();
        void modify_salary();
        void show();
        void search();
        void statistics_staff();

    private:
        void _modify_employee(employee& a);
        bool _insert_from_file(std::fstream& s); //考虑到load和insert_from_file都用到了这部分，单独拿出来方便复用，返回值标识文件中信息有无错误
        job_t::title_t _int2title_t(int a);
        int _str2int(std::string s);

        template<typename info_type, typename fn_t> bool _search(info_type info, fn_t fn) { //减少search的代码量
            DoubleLinkList<employee>::iterator ite, ite_begin = List.begin(), ite_end = List.end();
            bool success_flag = false;
            while(true)
            {
                ite = find(ite_begin, ite_end, fn);
                if(ite == List.end())
                    break;
                if(!success_flag)
                {
                    std::cout << "  ┏━━━━━━━━━━━┳━━━━━━━━━━┳━━━━━━━━┳━━━━━━━━━━┳━━━━━━━━━━━━━┳━━━━━━┳━━━━━━━┳━━━━━━━━━━┓" << std::endl;
                    std::cout << "  ┃    Eid    ┃   Name   ┃ Gender ┃  Birth   ┃Employee Time┃ Unit ┃ Title ┃  Salary  ┃" << std::endl;
                    std::cout << "  ┣━━━━━━━━━━━╇━━━━━━━━━━╇━━━━━━━━╇━━━━━━━━━━╇━━━━━━━━━━━━━╇━━━━━━╇━━━━━━━╇━━━━━━━━━━┫" << std::endl;
                    success_flag = true;
                }
                (*ite).print();
                std::cout << std::endl;
                ite_begin = ite + 1;
            }
            return success_flag;
        }
};