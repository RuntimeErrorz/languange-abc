#include <iostream>
#include <stdlib.h>
#include "staff.h"


int main() {
    staff sta;
    std::string input_temp;
    int temp;
    bool error_input_flag = false;
    sta.load("save_employee.txt", "save_job.txt");
    std::cout << "\033c";
    std::cout << "\t---------Welcome to our personnel management system---------" << std::endl << std::endl << std::endl;
    std::cout << "\t      Developed by BaoRongJia, ZengDeYu and TanKaiYuan" << std::endl << std::endl;
    std::cout << "\t               Press \"Enter\" to continue" << std::endl;
    std::cout << "                                 ";
    std::getline(std::cin, input_temp);
    std::cout << "\033c";
    
    while(1)
    {
        std::cout << "\t----------------Main Manu----------------" << std::endl << std::endl;
        std::cout << "\t1. View all infomation." << std::endl;
        std::cout << "\t2. Import new employee information" << std::endl;
        std::cout << "\t3. Remove employee information" << std::endl;
        std::cout << "\t4. Search by keyword" << std::endl;
        std::cout << "\t5. Modify existing information" << std::endl;
        std::cout << "\t6. View statistics" << std::endl;
        std::cout << "\t7. Save current state" << std::endl;
        std::cout << "\t8. Save and quit" << std::endl;
        std::cout << "\t9. Quit without save" << std::endl;
        if(error_input_flag == true)
        {
            std::cout << "\t         Pardon? ";
            error_input_flag = false;
        }
        else
            std::cout << "\t             ";
        std::getline(std::cin, input_temp);
        std::cout << "\033c";

        if(input_temp == "1")
        {
            sta.show();
            std::cout << "\t   Press \"Enter\" to continue" << std::endl;
            std::cout << "\t                 ";
            std::getline(std::cin, input_temp);
            std::cout << "\033c";
        }
        else if(input_temp == "2")
        {
            while(1)
            {
                std::cout << "\t--------------Importing Type--------------" << std::endl << std::endl;
                std::cout << "\t1. Import by key in." << std::endl;
                std::cout << "\t2. Import from file." << std::endl;
                std::cout << "\t3. Return to the previous menu." << std::endl;
                if(error_input_flag == true)
                {
                    std::cout << "\t              Pardon? ";
                    error_input_flag = false;
                }
                else
                    std::cout << "\t                 ";
                std::getline(std::cin, input_temp);
                if(input_temp == "1")
                {
                    sta.insert_from_keyboard();
                    std::cout << "\033c";
                    continue;
                }
                else if(input_temp == "2")
                {
                    sta.insert_from_file();
                    std::cout << "\033c";
                    continue;
                }
                else if(input_temp == "3")
                {
                    std::cout << "\033c";
                    break;
                }
                else
                {
                    error_input_flag = true;
                    std::cout << "\033c";
                }
            }
        }
        else if(input_temp == "3")
        {
            while(1)
            {
                std::cout << "\t--------------Deleting Type--------------" << std::endl << std::endl;
                std::cout << "\t1. Deleting individually." << std::endl;
                std::cout << "\t2. Deleting multiply." << std::endl;
                std::cout << "\t3. Return to the previous menu." << std::endl;
                if(error_input_flag == true)
                {
                    std::cout << "\t              Pardon? ";
                    error_input_flag = false;
                }
                else
                    std::cout << "\t                 ";
                std::getline(std::cin, input_temp);
                if(input_temp == "1")
                {
                    std::cout << "\033c";
                    sta.remove_with_eid(0);
                    std::cout << "\033c";
                    continue;
                }
                else if(input_temp == "2")
                {
                    std::cout << "\033c";
                    sta.remove_with_eid(1);
                    std::cout << "\033c";
                    continue;
                }
                else if(input_temp == "3")
                {
                    std::cout << "\033c";
                    break;
                }
                else
                {
                    error_input_flag = true;
                    std::cout << "\033c";
                }
            }
        }
        else if(input_temp == "4")
        {
            std::cout << "\033c";
            sta.search();
            std::cout << "\033c";
        }
        else if(input_temp == "5")
        {
            while(1)
            {
                std::cout << "\t--------------Modifying Type--------------" << std::endl << std::endl;
                std::cout << "\t1. Modify employee." << std::endl;
                std::cout << "\t2. Modify salary." << std::endl;
                std::cout << "\t3. Return to the previous menu." << std::endl;
                if(error_input_flag == true)
                {
                    std::cout << "\t              Pardon? ";
                    error_input_flag = false;
                }
                else
                    std::cout << "\t                 ";
                std::getline(std::cin, input_temp);
                if(input_temp == "1")
                {
                    std::cout << "\033c";
                    sta.modify_employee();
                    std::cout << "\033c";
                    continue;
                }
                else if(input_temp == "2")
                {
                    std::cout << "\033c";
                    sta.modify_salary();
                    std::cout << "\033c";
                    continue;
                }
                else if(input_temp == "3")
                {
                    std::cout << "\033c";
                    break;
                }
                else
                    error_input_flag = true;
            }
        }
        else if(input_temp == "6")
        {
            std::cout << "\033c";
            sta.statistics_staff();
            std::cout << "\033c";
        }
        else if(input_temp == "7")
        {
            std::cout << "\033c";
            std::cout << "\t                    Saving......" << std::endl << std::endl;
            sta.save("save_employee.txt", "save_job.txt");
            std::cout << "\t                      Finished." << std::endl;
            std::cout << "\t                press \"Enter\" to continue" << std::endl;
            std::cout << "\t                           ";
            std::getline(std::cin, input_temp);
            std::cout << "\033c";
        }
        else if(input_temp == "8")
        {
            sta.save("save_employee.txt", "save_job.txt");
            break;
        }
        else if(input_temp == "9")
            break;
        else
            error_input_flag = true;
    }
    return 0;
}