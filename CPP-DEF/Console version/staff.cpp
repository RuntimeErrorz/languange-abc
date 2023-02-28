#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib> //用于创建文件
#include <iomanip> //用于控制输出宽度
#include <climits> //用于处理查询时缺省的上限
#include "DoubleLinkList.h"
#include "employee.h"
#include "template_functions.h"
#include "staff.h"

staff::staff() {}

staff::~staff() {}

void staff::load(std::string file_name, std::string file_name2) {
    std::fstream file;
    int input_int;
    std::string input_str;
    employee temp;

    //载入职位与工资信息
    bool load_job_success[5] = {0};
    std::cout << "\033c";
    std::cout << "                                 Loading......" << std::endl << std::endl;
    for(int i = 0; i < 5; ++i) //这个顺序必须一致
        jobs[i].title = (job_t::title_t)i;
    file.open(file_name2);
    if(file)
    {
        while(!file.eof())
        {
            try
            {
                std::getline(file, input_str, ' '); //双确认，确保工资对应到正确的职位
                input_int = _str2int(input_str);
                if(input_int < 0 ||input_int > 4)
                    throw(1);
            }
            catch(int) { //跳过该行
                std::getline(file, input_str);
                continue;
            }
            try
            {
                std::getline(file, input_str);
                jobs[input_int].salary = _str2int(input_str);
                load_job_success[input_int] = true;
            }
            catch(int) {
                continue;
            }
        }
        file.close();
        file.clear();
    }  
    for(int i = 0; i < 5; ++i)
    {
        if(!load_job_success[i])
        {
            std::cout << "\033c";
            std::cout << "               # Warning # : Title-salary infomation of " << job_t::title_t_str[i] << " lost" << std::endl;
            std::cout << "                       Fix by key in or simply exit?" << std::endl;
            std::cout << "                 (Enter number to fix or Enter \"-1\" to exit)" << std::endl;
            std::cout << "                                       ";
            while(1)
            {
                std::getline(std::cin, input_str);
                try {
                    if(input_str == "-1")
                        exit(EXIT_FAILURE);
                    jobs[i].salary = _str2int(input_str);
                    break;
                }
                catch(int) {
                    std::cout << "                              Pardon? ";
                }
            }
            std::cout << std::endl;
        }
    }

    //载入员工信息
    file.open(file_name);
    if(!file)
    {
        std::cout << "                    # Waring # : Failed to find the save file" << std::endl;
        std::cout << "                  Continue without history data or simply exit?" << std::endl;
        std::cout << "                (press \"Enter\" to continue or Enter \"-1\" to exit)" << std::endl;
        std::cout << "                                       ";
        std::getline(std::cin, input_str);
        if(input_str == "-1")
            exit(EXIT_FAILURE);
        return;
    }
    if(_insert_from_file(file)) //出现问题则停留，否则不停留
    {
        std::cout << std::endl;
        std::cout << "                 Press \"Enter\" to continue" << std::endl;
        std::getline(std::cin, input_str);
    }
    file.close();
}

void staff::save(const char *file_name, const char *file_name2) {
    std::fstream file;
    FILE *fp;

    //记录员工信息
    fp = fopen(file_name, "w"); //创建文件
    fclose(fp);
    file.open(file_name);
    for(DoubleLinkList<employee>::iterator i = List.begin(); i != List.end(); )
    {
        file << (*i);
        i++;
        if(i != List.end())
    file << std::endl;
    }
    file.close();
    file.clear();
    
    //记录职位与工资信息
    fp = fopen(file_name2, "w"); //创建文件
    fclose(fp);
    file.open(file_name2);
    for(int i = 0; i < 4; ++i)
        file << jobs[i] << std::endl;
    file << jobs[4]; //最后不用再换行
    file.close();
    file.clear();
}

void staff::insert_from_keyboard() {
    employee temp;
    std::string input_str;
    int input_int;
    auto input_date_t = [this](int &target, std::string msg)->bool { //用lambda来节约一点代码量
        std::string str;
        std::cout << msg;
        while(1)
        {
            std::getline(std::cin, str);
            if(str == "-1")
                return false;
            try {
                target = _str2int(str);
            }
            catch(int) {
                std::cout << "       Pardon? ";
                continue;
            }
            return true;
        }
    };
    std::cout << "\033c";
    std::cout << "                    Inserting..." << std::endl;
    std::cout << "        Enter \"-1\" at any time to go back" << std::endl << std::endl;
    std::cout << "   Eid: ";
    while(1)
    {
        std::getline(std::cin, input_str);
        if(input_str == "-1")
            return;
        if(input_str.empty())
        {
            std::cout << "       Pardon? ";
            continue;
        }
        if(find(List.begin(), List.end(), [input_str](employee a)->bool{ return (a.eid == input_str);}) != List.end())
        {
            std::cout << "       Eid already exist. Pardon? ";
            continue;
        }
        temp.eid = input_str;
        break;
    }
    std::cout << "   Name: ";
    while(1)
    {
        std::getline(std::cin, input_str);
        if(input_str.empty())
        {
            std::cout << "       Pardon? ";
            continue;
        }
        if(input_str == "-1")
            return;
        temp.name = input_str;
        break;
    }
    std::cout << "   Gender(M for male, F for female): "; //TODO
    while(1)
    {
        std::getline(std::cin, input_str);
        if(input_str == "-1")
            return;
        else if(input_str == "M" || input_str == "F")
        {
            temp.gender = employee::gender_t(input_str == "M" ? 0 : 1);
            break;
        }
        else if(input_str == "m" || input_str == "f")
        {
            temp.gender = employee::gender_t(input_str == "m" ? 0 : 1);
            break;
        }
        else
            std::cout << "       Pardon? ";
    }
    while(1)
    {
        std::cout << "   Day of birth: " << std::endl;
        if(!input_date_t(temp.dob.year, "     Year: "))
            return;
        if(!input_date_t(temp.dob.month, "     Month: "))
            return;
        if(!input_date_t(temp.dob.day, "     Day: "))
            return;
        if(temp.dob.error_date() || temp.dob.later_than_now()) //没出生就想挂进去？哼哼哼，绝对不行
        {
            std::cout << "     Error date. Please enter again." << std::endl;
            continue;
        }
        else
            break;
    }
    while(1)
    {
        std::cout << "   Day of employee: " << std::endl;
        if(!input_date_t(temp.doe.year, "     Year: "))
            return;
        if(!input_date_t(temp.doe.month, "     Month: "))
            return;
        if(!input_date_t(temp.doe.day, "     Day: "))
            return;
        if(temp.doe.error_date())
        {
            std::cout << "     Error date. Please enter again." << std::endl;
            continue;
        }
        else if(temp.doe.later_than_now())
        {
            std::cout << "     This date is later than now. Are you sure?" << std::endl;
            std::cout << "     (Press \"Enter\" to continue or Enter other to modify) ";
            std::getline(std::cin, input_str);
            if(input_str.empty())
                break;
            else
                continue;
        }
        else
            break;
    }
    std::cout << "   Unit: " << std::endl;
    std::cout << "     1.HumanResources      2.Accounting        3.Sales    4.Administration" << std::endl;
    std::cout << "    ? ";
    while(1)
    {
        std::getline(std::cin, input_str);
        if(input_str == "-1")
            return;
        try {
            input_int = _str2int(input_str);
            temp.unit = _int2unit_t(input_int - 1);
            break;
        }
        catch(int) {
            std::cout << "       Pardon? ";
            continue;
        }
    }
    std::cout << "   Work: " << std::endl;
    std::cout << "     1.Manager     2.HRSpecialist      3.TreasuryAttache" << std::endl;
    std::cout << "     4.SalesExecutive      5.AdministrativeCommissioner" << std::endl;
    std::cout << "    ? ";
    while(1)
    {
        std::getline(std::cin, input_str);
        if(input_str == "-1")
            return;
        try {
            input_int = _str2int(input_str);
            temp.job = &jobs[(int)_int2title_t(input_int - 1)];
            break;
        }
        catch(int) {
            std::cout << "       Pardon? ";
            continue;
        }
    }
    List.push_with_order(temp, [](const employee& a, const employee& b)->bool { return a.eid <= b.eid; } );
    std::cout << "\033c";
    show();
    std::cout << "                   Import success." << std::endl;
    std::cout << "              Press \"Enter\" to continue" << std::endl;
    std::getline(std::cin, input_str);
}

void staff::insert_from_file() {
    std::string input_str;
    std::fstream file;
    employee temp;
    int title_temp;
    int line_cnt = 0;
    int success_cnt = 0;

    std::cout << "\033c";
    std::cout << "                    Inserting..." << std::endl;
    std::cout << "           Enter \"-1\" at any time to go back" << std::endl << std::endl;
    std::cout << "   File name: ";
    std::getline(std::cin, input_str);
    if(input_str == "-1")
        return;
    while(input_str.empty())
    {
        std::cout << "       Pardon? ";
        std::getline(std::cin, input_str);
        if(input_str == "-1")
            return;
    }
    file.open(input_str);
    if(!file)
    {
        std::cout << "   # ERROR # : It seems that this file is not exist." << std::endl;
        std::cout << "              Press \"Enter\" to continue" << std::endl;
        std::cout << "                           ";
        std::getline(std::cin, input_str);
        return;
    }
    _insert_from_file(file);
    file.close();
    std::cout << "              Press \"Enter\" to continue" << std::endl;
    std::cout << "                           ";
    std::getline(std::cin, input_str);
}

void staff::remove_with_eid(int mode) {
    std::string input_str;
    std::cout << "\033c";
    std::cout << "                       Deleting..." << std::endl << std::endl;
    if(List.begin() == List.end())
    {
        std::cout << "                 There is no data left." << std::endl;
        std::cout << "              Press \"Enter\" to continue" << std::endl;
        std::cout << "                            ";
        std::getline(std::cin, input_str);
        return;
    }
    if(mode == 1)
        std::cout << "   Please input the eid of target employee, enter \"-1\" to stop and go back" << std::endl << std::endl;
    do
    {
        if(List.begin() == List.end())
        {
            std::cout << "    There is no data left." << std::endl;
            break;
        }
        if(mode == 1)        
            std::cout << "   Eid: ";
        else
            std::cout << "   Eid(enter \"-1\" to go back): ";
        std::getline(std::cin, input_str);
        if(input_str == "-1")
            return;
        while(input_str.empty())
        {
            std::cout << "       Pardon? ";
            std::getline(std::cin, input_str);
            if(input_str == "-1")
                return;
        }
        if(find(List.begin(), List.end(), [input_str](employee a)->bool{ return (a.eid == input_str);}) == List.end())
            std::cout << "   There's not such a employee." << std::endl;
        else
        {
            employee temp_employee(input_str);
            List.remove_with_condition([](employee& a, employee& b)->bool{ return (a.eid == b.eid); }, temp_employee); //TODO，这样实现好不优雅。。。
        }
    } while(mode);
    std::cout << std::endl << "                 Deleting finish." << std::endl << std::endl;
    std::cout << "              Press \"Enter\" to continue" << std::endl;
    std::cout << "                             ";
    std::getline(std::cin, input_str);
}

void staff::modify_employee() {
    std::string input_str;
    while(1)
    {
        std::cout << "\033c";
        std::cout << "                  Employee Modifying..." << std::endl;
        std::cout << "                Enter \"-1\" to go back." << std::endl << std::endl;
        if(List.begin() == List.end())
        {
            std::cout << "   There's no data to modify." << std::endl;
            break;
        }
        std::cout << "   Please enter the eid of target employee: ";
        std::getline(std::cin, input_str);
        if(input_str == "-1")
        {
            std::cout << "                    Modifying finish." << std::endl;
            std::cout << "              Press \"Enter\" to continue" << std::endl;
            std::getline(std::cin, input_str);
            return;
        }
        while(input_str.empty())
        {
            std::cout << "       Pardon? ";
            std::getline(std::cin, input_str);
            if(input_str == "-1")
            {
                std::cout << "                    Modifying finish." << std::endl;
                std::cout << "              Press \"Enter\" to continue" << std::endl;
                std::getline(std::cin, input_str);
                return;
            }
        }
        for(DoubleLinkList<employee>::iterator i = List.begin(); i != List.end(); i++)
        {
            if((*i).eid == input_str)
            {
                _modify_employee(*i);
                if((*i).eid != input_str) //特殊处理Eid发生变动的情况
                {
                    employee temp = (*i);
                    List.remove_with_condition([](employee& a, employee& b)->bool{ return (a.eid == b.eid); }, temp); //TODO，这样实现好不优雅。。。
                    List.push_with_order(temp, [](const employee& a, const employee& b)->bool { return a.eid <= b.eid; } );
                }
                break;
            }
        }
    }
}

void staff::modify_salary() {
    std::string input_str;
    job_t *p;

    std::cout << "\033c";
    std::cout << "                  Salary Modifying..." << std::endl;
    std::cout << "                Enter \"-1\" to go back." << std::endl << std::endl;
    std::cout << "   Job: " << std::endl;
    std::cout << "     1.Manager     2.HRSpecialist      3.TreasuryAttache" << std::endl;
    std::cout << "     4.SalesExecutive      5.AdministrativeCommissioner" << std::endl;
    std::cout << "    ? ";
    std::getline(std::cin, input_str);
    while(1)
    {
        if(input_str == "-1")
            return;
        try
        {
            p = &jobs[(int)_int2title_t(_str2int(input_str) - 1)];
            break;
        }
        catch(int) {
            std::cout << "       Pardon?";
            std::getline(std::cin, input_str);
            continue;
        }
    }
    std::cout << std::endl << "     Input new value if you want to change." << std::endl;
    std::cout << "         Or just simply press\"Enter\" if not." << std::endl;
    std::cout << "   salary: " << p->salary << " ? ";
    std::getline(std::cin, input_str);
    while(1)
    {
        if(input_str.empty())
            break;
        try {
            p->salary = _str2int(input_str);
            break;
        }
        catch(int) {
            std::cout << "       Pardon? ";
            std::cout << input_str << std::endl;
            std::getline(std::cin, input_str);
            continue;
        }
    }
    std::cout << std::endl << "           Modifying finish." << std::endl;
    std::cout << "         Press \"Enter\" to continue" << std::endl;
    std::getline(std::cin, input_str);
    return;
}

void staff::show() {
    std::cout << std::endl << "          Employee infomation is as follow." << std::endl << std::endl;
    std::cout << "  ┏━━━━━━━━━━━┳━━━━━━━━━━┳━━━━━━━━┳━━━━━━━━━━┳━━━━━━━━━━━━━┳━━━━━━┳━━━━━━━┳━━━━━━━━━━┓" << std::endl;
    std::cout << "  ┃    Eid    ┃   Name   ┃ Gender ┃  Birth   ┃Employee Time┃ Unit ┃ Title ┃  Salary  ┃" << std::endl;
    std::cout << "  ┣━━━━━━━━━━━╇━━━━━━━━━━╇━━━━━━━━╇━━━━━━━━━━╇━━━━━━━━━━━━━╇━━━━━━╇━━━━━━━╇━━━━━━━━━━┫" << std::endl;
    List.traverse([](employee& a) {a.print(); std::cout << std::endl;});
    std::cout << "  ┗━━━━━━━━━━━┷━━━━━━━━━━┷━━━━━━━━┷━━━━━━━━━━┷━━━━━━━━━━━━━┷━━━━━━┷━━━━━━━┷━━━━━━━━━━┛" << std::endl << std::endl;
}

void staff::search() {
    std::string input_str;
    int accordance;
    job_t::title_t info_title;
    employee::unit_t info_unit;
    int info_int1, info_int2;
    bool success_flag; //检查是否有找到
    DoubleLinkList<employee>::iterator ite, ite_begin, ite_end;

    while(1)
    {
        std::cout << "\033c";
        std::cout << "                      Searching..." << std::endl;
        std::cout << "                  Enter \"-1\" to go back"<< std::endl << std::endl;
        std::cout << "   Accordance: " << std::endl;
        std::cout << "     1.Eid      2.Name     3.Unit     4.Title    5.Salary" << std::endl;
        std::cout << "   ? ";
        success_flag = false;
        ite_begin = List.begin();
        ite_end = List.end();
        std::getline(std::cin, input_str);
        while(1)
        {
            if(input_str == "-1")
                return;
            try {
                accordance = _str2int(input_str);
                if(accordance < 1 || accordance > 5)
                    throw(1);
                break;
            }
            catch(int) {
                std::cout << "       Pardon? ";
                std::getline(std::cin, input_str);
            }
        }
        std::cout << std::endl;
        switch(accordance)
        {
            case 1:
                std::cout << "   Eid: ? ";
                std::getline(std::cin, input_str);
                while(input_str.empty())
                {
                    std::cout << "       Pardon? ";
                    std::getline(std::cin, input_str);
                }
                std::cout << "\033c";
                std::cout << "              Results are as follow (Eid: " << input_str << "):" << std::endl << std::endl;
                if(input_str == "*")
                {
                    show();
                    std::cout << "                  Press \"Enter\" to continue" << std::endl;
                    std::cout << "                          ";
                    std::getline(std::cin, input_str);
                    continue;
                }
                else
                    success_flag = _search(input_str, [input_str](employee a)->bool{ return (a.eid == input_str);});
                break;
            case 2:
                std::cout << "   Name: ? ";
                std::getline(std::cin, input_str);
                while(input_str.empty())
                {
                    std::cout << "       Pardon? ";
                    std::getline(std::cin, input_str);
                }
                std::cout << "\033c";
                std::cout << "              Results are as follow (Name: " << input_str << "):" << std::endl << std::endl;
                success_flag = _search(input_str, [input_str](employee a)->bool{ return (a.name == input_str);});
                break;
            case 3:
                std::cout << "   Unit:";
                std::cout << "     1.HumanResources      2.Accounting        3.Sales            4.Administration" << std::endl;
                std::cout << "    ? ";
                std::getline(std::cin, input_str);
                while(1)
                {
                    try {
                        info_unit = _int2unit_t(_str2int(input_str) - 1);
                        break;
                    }
                    catch(int) {
                        std::cout << "       Pardon? ";
                        std::getline(std::cin, input_str);
                    }
                }
                std::cout << "\033c";
                std::cout << "              Results are as follow (Unit: " << info_unit << "):"  << std::endl << std::endl;
                success_flag = _search(info_unit, [info_unit](employee a)->bool{ return (a.unit == info_unit);});
                break;
            case 4:
                std::cout << "   Title:" << std::endl;
                std::cout << "     1.Manager             2.HRSpecialist      3.TreasuryAttache" << std::endl;
                std::cout << "     4.SalesExecutive      5.AdministrativeCommissioner" << std::endl;
                std::cout << "    ? ";
                std::getline(std::cin, input_str);
                while(1)
                {
                    try {
                        info_title = _int2title_t(_str2int(input_str) - 1);
                        break;
                    }
                    catch(int) {
                        std::cout << "       Pardon? ";
                        std::getline(std::cin, input_str);
                    }
                }
                std::cout << "\033c";
                std::cout << "              Results are as follow (Title: " << info_title << "):" << std::endl << std::endl;
                success_flag = _search(info_title, [info_title](employee a)->bool{ return (a.job->title == info_title);});
                break;
            case 5:
                do
                {
                    std::cout << "   Range:" << std::endl;
                    std::cout << "     Minimum: ? "; //缺省时用0表示
                    std::getline(std::cin, input_str);
                    while(1)
                    {
                        if(input_str.empty())
                        {
                            info_int1 = 0;
                            break;
                        }
                        try {
                            info_int1 = _str2int(input_str);
                            break;
                        }
                        catch(int) {
                            std::cout << "       Pardon? ";
                            std::getline(std::cin, input_str);
                        }
                    }
                    std::cout << "     Maximum: ? ";
                    std::getline(std::cin, input_str);
                    while(1)
                    {
                        if(input_str.empty())
                        {
                            info_int2 = INT_MAX;
                            break;
                        }
                        try {
                            info_int2 = _str2int(input_str);
                            break;
                        }
                        catch(int) {
                            std::cout << "       Pardon? ";
                            std::getline(std::cin, input_str);
                        }
                    }
                    if(info_int1 > info_int2)
                    {
                        std::cout << "\033c";
                        std::cout << "    Minimum is greater than maximum: Pardon?" << std::endl;
                    }
                } while(info_int1 > info_int2);
                std::cout << "\033c";
                std::cout << "            Results are as follow (Salary: " << info_int1;
                if(info_int2 != INT_MAX)
                    std::cout  << " ~ " << info_int2 << "):" << std::endl << std::endl;
                else
                    std::cout << "+ ):" << std::endl << std::endl;
                while(true) //单一个没必要模板了
                {
                    ite = find(ite_begin, ite_end, [info_int1, info_int2](employee a)->bool {
                        if(info_int1 != -1 && (a.job)->salary < info_int1)
                            return false;
                        if(info_int2 != -1 && (a.job)->salary > info_int2)
                            return false;
                        return true;} );
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
                break;
        }
        if(success_flag)
            std::cout << "  ┗━━━━━━━━━━━┷━━━━━━━━━━┷━━━━━━━━┷━━━━━━━━━━┷━━━━━━━━━━━━━┷━━━━━━┷━━━━━━━┷━━━━━━━━━━┛" << std::endl << std::endl;
        else
            std::cout << "                    No matching employee." << std::endl;
        std::cout << "                  Press \"Enter\" to continue" << std::endl;
        std::cout << "                          ";
        std::getline(std::cin, input_str);
    }
}

void staff::statistics_staff() {
    int accordance;
    std::string input_str;

    while(1)
    {
        std::cout << "\033c";
        std::cout << "                       Statistics are being collected..." << std::endl;
        std::cout << "                            Enter \"-1\" to go back" << std::endl << std::endl;
        std::cout << "   Accordance: " << std::endl;
        std::cout << "     1.Gender   2.Unit     3.Title" << std::endl;
        std::cout << "   ? ";
        while(1)
        {
            std::getline(std::cin, input_str);
            if(input_str == "-1")
                return;
            try {
                accordance = _str2int(input_str);
                if(accordance < 1 || accordance > 3)
                    throw(1);
                break;
            }
            catch(int) {
                std::cout << "       Pardon? ";
            }
        }
        std::cout << "\033c";
        switch(accordance)
        {
            case 1:
                std::cout << "                Gender statistics are as follow:" << std::endl << std::endl;
                for(int i = 0; i < 2; ++i)
                {
                    std::cout << "      " << std::left << std::setw(10) << (employee::gender_t_str[i] + ':');
                    std::cout << statistics(List.begin(), List.end(), [i](employee a)->bool{
                        if(a.gender == (employee::gender_t)i)
                            return true;
                        return false;} );
                    std::cout << std::endl;
                }
                break;
            case 2:
                std::cout << "                 Unit statistics are as follow:" << std::endl << std::endl;
                for(int i = 0; i < 4; ++i)
                {
                    std::cout << "      " << std::left << std::setw(18) << (employee::unit_t_str[i] + ':');
                    std::cout << statistics(List.begin(), List.end(), [i](employee a)->bool{
                        if(a.unit == (employee::unit_t)(i))
                            return true;
                        return false;} );
                    std::cout << std::endl;
                }
                break;
            case 3:
                std::cout << "                Title statistics are as follow:" << std::endl << std::endl;
                for(int i = 0; i < 5; ++i)
                {
                    std::cout << "      " << std::left << std::setw(18) << (job_t::title_t_str[i] + ':');
                    std::cout << statistics(List.begin(), List.end(), [i](employee a)->bool{
                        if((a.job)->title  == (job_t::title_t)(i))
                            return true;
                        return false;} );
                    std::cout << std::endl;
                }
        }
        std::cout << "      ";
        for(int i = (accordance == 1 ? 12 : 20); i > 0; --i)
            std::cout << '-';
        std::cout << std::endl;
        std::cout << std::left << std::setw((accordance == 1 ? 16 : 24)) << "      Total:";
        std::cout << statistics(List.begin(), List.end(), [](employee a)->bool{ return true; } ) << std::endl << std::endl;
        std::cout << "                  Press \"Enter\" to continue" << std::endl;
        std::cout << "                                 ";
        std::getline(std::cin, input_str);
    }
}

void staff::_modify_employee(employee& a) {
    std::string input_str;
    std::cout << "\033c";
    std::cout << "      System will show this employee's information piece by piece." << std::endl;
    std::cout << "              If you want to change, nput new value." << std::endl;
    std::cout << "               If not, please simply press \"Enter\"." << std::endl << std::endl;

    std::cout << "   Eid: " << a.eid << " ? ";
    while(1)
    {
        std::getline(std::cin, input_str);
        if(input_str.empty())
            break;
        if(find(List.begin(), List.end(), [input_str](employee a)->bool{ return (a.eid == input_str);}) != List.end())
        {
            std::cout << "       Eid already exist. Pardon? ";
            continue;
        }
        a.eid = input_str;
        break;
    }

    std::cout << "   Name: " << a.name << " ? ";
    std::getline(std::cin, input_str);
    if(!(input_str.empty()))
        a.name = input_str;
    
    std::cout << "   Gender: " << a.gender << " ? ";
    while(1)
    {
        std::getline(std::cin, input_str);
        if(input_str.empty())
            break;
        if(input_str == "M" || input_str == "m")
        {
            a.gender = employee::gender_t::M;
            break;
        }
        else if(input_str == "F" || input_str == "f")
        {
            a.gender = employee::gender_t::F;
            break;
        }
        else
        {
            std::cout << "       Pardon? ";
            std::getline(std::cin, input_str);
        }
    }

    auto input_data_t = [this](int& target, std::string msg) {
        std::cout << msg << target << " ? ";
        std::string temp;
        std::getline(std::cin, temp);
        while(1)
        {
            if(temp.empty())
                return;
            try {
                target = _str2int(temp);
                return;
            }
            catch(int) {
                std::cout << "       Pardon? ";
                std::getline(std::cin, temp);
            }
        }
    };
    while(1)
    {
        std::cout << "   Date of birth: " << std::endl;
        input_data_t(a.dob.year, "     Year: ");
        input_data_t(a.dob.month, "     Month: ");
        input_data_t(a.dob.day, "     Day: ");
        if(a.dob.error_date() || a.dob.later_than_now())
            std::cout << "     Error date. Please enter again." << std::endl;
        else
            break;
    }
    while(1)
    {
        std::cout << "   Date of employee: " << std::endl;
        input_data_t(a.doe.year, "     Year: ");
        input_data_t(a.doe.month, "     Month: ");
        input_data_t(a.doe.day, "     Day: ");
        if(a.doe.error_date())
            std::cout << "     Error date. Please enter again." << std::endl;
        else if(a.doe.later_than_now())
        {
            std::cout << "     This date is later than now. Are you sure?" << std::endl;
            std::cout << "     (Press \"Enter\" to continue or Enter other to modify) ";
            std::getline(std::cin, input_str);
            if(input_str.empty())
                break;
            else
                continue;
        }
        else
            break; 
    }

    std::cout << "   Unit: " << a.unit << std::endl;
    std::cout << "     1.HumanResources      2.Accounting        3.Sales            4.Administration" << std::endl;
    std::cout << "    ? ";
    while(1)
    {
        std::getline(std::cin, input_str);
        if(input_str.empty())
            break;
        try {
            a.unit = _int2unit_t(_str2int(input_str) - 1);
            break;
        }
        catch(int) {
            std::cout << "       Pardon? ";
        }
    }
    
    std::cout << "   Job: " << (a.job)->title   << std::endl;
    std::cout << "     1.Manager             2.HRSpecialist      3.TreasuryAttache" << std::endl;
    std::cout << "     4.SalesExecutive      5.AdministrativeCommissioner" << std::endl;
    std::cout << "    ? ";
    while(1)
    {
        std::getline(std::cin, input_str);
        if(input_str.empty())
            break;
        try {
            a.job = &jobs[(int)_int2title_t(_str2int(input_str) - 1)];
            break;
        }
        catch(int) {
            std::cout << "       Pardon? ";
        }
    }
}

bool staff::_insert_from_file(std::fstream& file) {
    //文件流打开与关闭在外部完成
    std::string input_str;
    int line_cnt = 0, success_cnt = 0;
    employee temp;
    bool error_flag = false;
    while(!file.eof())
    {
        ++line_cnt;
        file >> temp.eid;
        if(find(List.begin(), List.end(), [temp](employee a)->bool{ return (a.eid == temp.eid);}) != List.end())
        {
            std::cout << "   # ERROR at line " << line_cnt <<" # : Eid already exist" << std::endl;
            std::getline(file, input_str);
            continue;
        }
        file >> temp.name;
        try{
            file >> input_str;
            temp.gender = _int2gender_t(_str2int(input_str));
            file >> input_str;
            temp.dob.year = _str2int(input_str);
            file >> input_str;
            temp.dob.month = _str2int(input_str);
            file >> input_str;
            temp.dob.day = _str2int(input_str);
            if(temp.dob.error_date() || temp.dob.later_than_now())
                throw(1.0);
            file >> input_str;
            temp.doe.year = _str2int(input_str);
            file >> input_str;
            temp.doe.month = _str2int(input_str);
            file >> input_str;
            temp.doe.day = _str2int(input_str);
            if(temp.doe.error_date())
                throw(1.0);
            file >> input_str;
            temp.unit = _int2unit_t(_str2int(input_str));
            file >> input_str;
            temp.job = &jobs[_int2title_t(_str2int(input_str))];
        }
        catch(int) {
            std::cout << "   # ERROR at line " << line_cnt <<" # : Data error" << std::endl;
            error_flag = true;
            std::getline(file, input_str);
            continue;
        }
        catch(double) {
            std::cout << "   # ERROR at line " << line_cnt <<" # : Time Information error" << std::endl;
            error_flag = true;
            std::getline(file, input_str);
            continue;
        }
        List.push_with_order(temp, [](const employee& a, const employee& b)->bool { return a.eid <= b.eid; } );
        ++success_cnt;
    }
    std::cout << std::endl << "  Successfully import " << success_cnt << " employees" << std::endl;
    return error_flag;
}

int staff::_str2int(std::string s) {
    int temp = 0, len = s.length();
    if(len == 0)
        throw(1);
    for(int i = 0; i < len; i++)
    {
        if(s[i] < '0' || s[i] > '9') //无法转化，抛出异常
            throw(1);
        temp *= 10;
        temp += s[i] - '0';
    }
    return temp;
}

job_t::title_t staff::_int2title_t(int a) {
    if(a < 0 || a > 4) //无法转换，抛出异常
        throw(1);
    return (job_t::title_t)a;
}