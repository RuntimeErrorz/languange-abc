#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib> //用于创建文件
#include "DoubleLinkList.h"
#include "employee.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QLineEdit>
#include "mainone.h"
#include <QHeaderView>
#include "modify.h"
#include <QMessageBox>
#define private public
class staff;
extern int flag;
extern staff*s;
class modify;
class staff {
    friend class textbox;
    friend class insert;
private:
    job_t jobs[5];
    DoubleLinkList<employee> List;

public:
    staff() {}
    ~staff() {}
    void modify1(std::string temp,employee temp1)
    {
        for(auto i = List.begin(); i != List.end(); i++) {
            if((*i).eid == temp)
                *i=temp1;
        }
        QMessageBox::question(NULL, " ", "Successfully Changed",QMessageBox::Ok);
    }
    employee* find(std::string temp)
    {
        for(auto i = List.begin(); i != List.end(); i++) {
            if((*i).eid == temp)
                return &(i.pointer->data);
        }
        return nullptr;
    }
    void modify_salary(int i,int salary) {
        job_t *p;
        p = &jobs[i - 4]; //根据你原来实现调的
        p->salary = salary;
    }
    template<typename iterator, typename filter> int statistics(iterator first, iterator last, filter fn)
    {
        int cnt = 0;
        for(iterator i = first; i != last; i++)
            if(fn(*i))
                cnt++;
        return cnt;
    }
    void statistics_staff(int accordance) {
        QTableWidget* tableWidget = new QTableWidget(5, 2);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setVisible(false);

        switch(accordance)
        {
        case 0:
            tableWidget->setWindowTitle("Statics");
            tableWidget->setItem(0, 0, new QTableWidgetItem("Male"));
            tableWidget->setItem(1, 0, new QTableWidgetItem("Female"));
            tableWidget->setItem(0, 1, new QTableWidgetItem(QString::number(statistics(List.begin(), List.end(), [](employee a)->bool{
                                                                                if(a.gender == employee::sex_t::M)
                                                                                return true;
                                                                                return false;} ))));
            tableWidget->setItem(1, 1, new QTableWidgetItem(QString::number(statistics(List.begin(), List.end(), [](employee a)->bool{
                                                                                if(a.gender == employee::sex_t::F)
                                                                                return true;
                                                                                return false;} ))));
            for(int i =4;i>1;i--)
                tableWidget->removeRow(i);
            for (int i=0;i<2;i++)
            {
                for (int j=0;j<2;j++)
                {
                    tableWidget->item(i,j)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                }
            }
            tableWidget->resize(500,50*2);
            tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
            tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
            tableWidget->setFixedSize(tableWidget->width(),tableWidget->height());
            tableWidget->show();
            break;
        case 1:
            tableWidget->setWindowTitle("Statics");
            tableWidget->setItem(0, 0, new QTableWidgetItem("HumanResources"));
            tableWidget->setItem(1, 0, new QTableWidgetItem("Accounting"));
            tableWidget->setItem(2, 0, new QTableWidgetItem("Sales:"));
            tableWidget->setItem(3, 0, new QTableWidgetItem("Administration"));
            tableWidget->setItem(0, 1, new QTableWidgetItem(QString::number(statistics(List.begin(), List.end(), [](employee a)->bool{
                                                                                if(a.unit == employee::office_t::HumanResources)
                                                                                return true;
                                                                                return false;} ))));
            tableWidget->setItem(1, 1, new QTableWidgetItem(QString::number(statistics(List.begin(), List.end(), [](employee a)->bool{
                                                                                if(a.unit == employee::office_t::Accounting)
                                                                                return true;
                                                                                return false;} ))));
            tableWidget->setItem(2, 1, new QTableWidgetItem(QString::number(statistics(List.begin(), List.end(), [](employee a)->bool{
                                                                                if(a.unit == employee::office_t::Sales)
                                                                                return true;
                                                                                return false;} ))));
            tableWidget->setItem(3, 1, new QTableWidgetItem(QString::number(statistics(List.begin(), List.end(), [](employee a)->bool{
                                                                                if(a.unit == employee::office_t::Administration)
                                                                                return true;
                                                                                return false;} ))));
            for(int i =4;i>3;i--)
                tableWidget->removeRow(i);
            for (int i=0;i<4;i++)
            {
                for (int j=0;j<2;j++)
                {
                    tableWidget->item(i,j)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                }
            }
            tableWidget->resize(500,4*50);
            tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
            tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
            tableWidget->setFixedSize(tableWidget->width(),tableWidget->height());
            tableWidget->show();
            break;
        case 2:
            tableWidget->setWindowTitle("Statics");
            tableWidget->resize(1300, 1080);
            tableWidget->setItem(0, 0, new QTableWidgetItem("Manager"));
            tableWidget->setItem(1, 0, new QTableWidgetItem("HRSpecialist"));
            tableWidget->setItem(2, 0, new QTableWidgetItem("TreasuryAttache"));
            tableWidget->setItem(3, 0, new QTableWidgetItem("SalesExecutive"));
            tableWidget->setItem(4, 0, new QTableWidgetItem("AdministrativeCommissioner"));
            tableWidget->setItem(0, 1, new QTableWidgetItem(QString::number(statistics(List.begin(), List.end(), [](employee a)->bool{
                                                                                if((a.job)->off == job_t::Manager)
                                                                                return true;
                                                                                return false;} ))));
            tableWidget->setItem(1, 1, new QTableWidgetItem(QString::number(statistics(List.begin(), List.end(), [](employee a)->bool{
                                                                                if((a.job)->off == job_t::HRSpecialist)
                                                                                return true;
                                                                                return false;} ))));
            tableWidget->setItem(2, 1, new QTableWidgetItem(QString::number(statistics(List.begin(), List.end(), [](employee a)->bool{
                                                                                if((a.job)->off == job_t::TreasuryAttache)
                                                                                return true;
                                                                                return false;} ))));
            tableWidget->setItem(3, 1, new QTableWidgetItem(QString::number(statistics(List.begin(), List.end(), [](employee a)->bool{
                                                                                if((a.job)->off == job_t::SalesExecutive)
                                                                                return true;
                                                                                return false;} ))));
            tableWidget->setItem(4, 1, new QTableWidgetItem(QString::number(statistics(List.begin(), List.end(), [](employee a)->bool{
                                                                                if((a.job)->off == job_t::SalesExecutive)
                                                                                return true;
                                                                                return false;} ))));
            for (int i=0;i<5;i++)
            {
                for (int j=0;j<2;j++)
                {
                    tableWidget->item(i,j)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                }
            }
            tableWidget->resize(700,5*50);
            tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
            tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
            tableWidget->setFixedSize(tableWidget->width(),tableWidget->height());
            tableWidget->show();
            break;
        default:
            break;
        }

    }
    inline void load(std::string file_name, std::string file_name2 = "demo_job.txt") {
        std::fstream file;
        file.open(file_name2);
        if (!file) {
            QMessageBox::critical(NULL, "Error", "Job and salary file does not exist", QMessageBox::Ok);
            exit(EXIT_FAILURE);
        }
        file.get();
        if(file.eof())
        {
            QMessageBox::critical(NULL, "Error", "Job and salary file is empty", QMessageBox::Ok);
            exit(EXIT_FAILURE);
        }
        file.close();
        file.clear();
        file.open(file_name2);
        job_t::work_t work_temp;
        employee temp;
        while (!file.eof()) {
            try {
                file >> work_temp;
                jobs[(int)work_temp].off = work_temp;
                file >> jobs[(int)work_temp].salary;
            } catch (int) {
                QMessageBox::critical(NULL, "Error", "Error of job-salary", QMessageBox::Ok);
                exit(EXIT_FAILURE);
            }
        }
        file.close();
        file.clear();

        //载入员工信息
        file.open(file_name);
        if (!file) {
            QMessageBox::critical(NULL, "Error", "Employee file does not exist", QMessageBox::Ok);
            exit(EXIT_FAILURE);
        }
        file.get();
        if(file.eof())
        {
            QMessageBox::critical(NULL, "Error", "Employee file is empty", QMessageBox::Ok);
            exit(EXIT_FAILURE);
        }
        file.close();
        file.clear();
        file.open(file_name);
        int cnt=0;
        while (!file.eof()) {
            try {
                file >> temp.eid >> temp.name >> temp.gender;
                file >> temp.dob >> temp.doe >> temp.unit;
                file >> work_temp;
                temp.job = &jobs[(int)work_temp];
                int flag1=0;
                if(cnt==0)
                    List.push_with_order(temp, [](const employee& a, const employee& b)->bool { return a.eid <= b.eid; });
                else
                {
                    for(auto i = s->List.begin();i!=s->List.end();++i)
                    {
                        if((*i).eid==temp.eid)
                        {
                            flag1++;
                            break;
                        }
                    }
                    if(!flag1)
                        List.push_with_order(temp, [](const employee& a, const employee& b)->bool { return a.eid <= b.eid; });
                    else
                    {
                        QMessageBox::critical(NULL, "Error", "Repeated Eid", QMessageBox::Ok);
                        exit(EXIT_FAILURE);
                    }
                }
            } catch (int) {
                QMessageBox::critical(NULL, "Error", "Error of employee-file", QMessageBox::Ok);
                exit(EXIT_FAILURE);
            }
            cnt++;
        }
        file.close();
        file.clear();
    }

    void save(const char* file_name, std::string file_name2) {
        std::fstream file;

        //记录职位与工资信息
        file.open(file_name2);
        for(int i = 0; i < 4; i++)
            file << jobs[i] << std::endl;
        file << jobs[4];
        file.close();
        file.clear();

        //记录员工信息
        FILE* fp;
        fp = fopen(file_name, "w"); //创建文件
        fclose(fp);
        file.open(file_name);
        for (DoubleLinkList<employee>::iterator i = List.begin(); i != List.end(); ) {
            file << (*i);
            i++;
            if (i != List.end())
                file << std::endl;
        }
        file.close();
    }

    bool insert_from_keyboard(employee temp) {
        int flag1=0;
        for(auto i = s->List.begin();i!=s->List.end();++i)
        {
            if((*i).eid==temp.eid)
            {
                flag1++;
                break;
            }
        }
        if(!flag1)
        {
            List.push_with_order(temp, [](const employee& a, const employee& b)->bool { return a.eid <= b.eid; });
            if(flag!=20)
                QMessageBox::question(NULL, " ", "Inserted", QMessageBox::Ok);
            else
                QMessageBox::question(NULL, " ", "Changed", QMessageBox::Ok);
            return true;
        }

        else
        {
            QMessageBox::warning(NULL, "Error", "Repeated Eid", QMessageBox::Ok);
            return false;
        }

    }
    void insert_from_file(QString q) {
        std::fstream file;
        employee temp;
        int work_temp;
        file.open(q.toStdString());
        if (!file) {
            QMessageBox::critical(NULL, "Error", "Insertingfile does not exist", QMessageBox::Ok);
            return;
        }
        char ch =file.get();
        if(file.eof())
        {
            QMessageBox::critical(NULL, "Error", "Insertingfile is empty", QMessageBox::Ok);
            exit(EXIT_FAILURE);
        }
        while (!file.eof()) {
            try {
                file >> temp.eid >> temp.name >> temp.gender;
                file >> temp.dob >> temp.doe >> temp.unit;
                file >> work_temp;
                temp.job = &jobs[(int)work_temp];
                int flag1 = 0;
                for(auto i=s->List.begin();i!=s->List.end();++i)
                {
                    if((*i).eid==temp.eid)
                    {
                        ++flag1;
                        break;
                    }
                }
                if(!flag1)
                {
                    List.push_with_order(temp, [](const employee& a, const employee& b)->bool { return a.eid <= b.eid; });
                }
                else
                {
                    QMessageBox::warning(NULL, "Error", "Repeated Eid", QMessageBox::Ok);
                    return;
                }
            } catch (int) {
                QMessageBox::critical(NULL, "Error", "Error of employee-file", QMessageBox::Ok);
                exit(EXIT_FAILURE);
            }
        }
        file.close();
        QMessageBox::question(NULL, " ", "Inserted", QMessageBox::Ok);
    }

    void remove_with_eid(std::string temp) {
        employee temp_employee(temp);
        List.remove_with_condition([](employee& a, employee& b)->bool { return (a.eid == b.eid); }, temp_employee); //TODO，这样实现好不优雅。。。
    }


    QTableWidget* printtoqt() {
        QTableWidget* tableWidget = new QTableWidget(List.get_cnt(), 8);
        tableWidget->setWindowTitle("ShowAllStaffs");
        QStringList header;
        auto x=List.begin();
        if(x==nullptr)
        {
            return nullptr;
        }
        else
        {
            header << "eid" << "name" << "gender" << "dob" << "doe" << "unit" << "title" << "salary";
            tableWidget->setHorizontalHeaderLabels(header);
            tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
            for (int i = 0;i<List.get_cnt(); ++i) {
                for (int j = 0; j < 8; j++) {
                    switch (j) {
                    case 0: tableWidget->setItem(i, j, new QTableWidgetItem(QString::fromStdString((*x).eid))); break;
                    case 1: tableWidget->setItem(i, j, new QTableWidgetItem(QString::fromStdString((*x).name))); break;
                    case 2:
                    {
                        if ((*x).gender == 0) {
                            tableWidget->setItem(i, j, new QTableWidgetItem("Male"));
                        }
                        else tableWidget->setItem(i, j, new QTableWidgetItem("Female"));
                        break;
                    }
                    case 3:tableWidget->setItem(i, j, new QTableWidgetItem(QString::fromStdString(std::to_string((*x).dob.year) + "/" + std::to_string((*x).dob.month) + "/" + std::to_string((*x).dob.day)))); break;
                    case 4:tableWidget->setItem(i, j, new QTableWidgetItem(QString::fromStdString(std::to_string((*x).doe.year) + "/" + std::to_string((*x).doe.month) + "/" + std::to_string((*x).doe.day)))); break;
                    case 5: {
                        if ((*x).unit == 0) {
                            tableWidget->setItem(i, j, new QTableWidgetItem("HumanResources"));
                        }
                        else if ((*x).unit == 1) {
                            tableWidget->setItem(i, j, new QTableWidgetItem("Accounting"));
                        }
                        else if ((*x).unit == 2) {
                            tableWidget->setItem(i, j, new QTableWidgetItem("Sales"));
                        }
                        else {
                            tableWidget->setItem(i, j, new QTableWidgetItem("Adminstration"));
                        }
                        break;
                    }
                    case 6:
                    {
                        if ((*x).job->off == 0) {
                            tableWidget->setItem(i, j, new QTableWidgetItem("Manager"));
                        }
                        else if ((*x).job->off == 1) {
                            tableWidget->setItem(i, j, new QTableWidgetItem("HRSpecialist"));
                        }
                        else if ((*x).job->off == 2) {
                            tableWidget->setItem(i, j, new QTableWidgetItem("TreasuryAttache"));
                        }
                        else if ((*x).job->off == 3) {
                            tableWidget->setItem(i, j, new QTableWidgetItem("SalesExecutive"));
                        }
                        else {
                            tableWidget->setItem(i, j, new QTableWidgetItem("AdministrativeCommissioner"));
                        }
                        break;
                    }
                    default:
                    {
                        tableWidget->setItem(i, j, new QTableWidgetItem(QString::fromStdString(std::to_string((*x).job->salary))));
                    }
                    }
                }
                ++x;
            }
            for (int i=0;i<List.get_cnt();i++)
            {
                for (int j=0;j<8;j++)
                {
                    tableWidget->item(i,j)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                }
            }
            tableWidget->resize(1800,tableWidget->rowCount()<10?tableWidget->rowCount()*150:1000);
            tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
            tableWidget->horizontalHeader()->setSectionResizeMode(5, QHeaderView::ResizeToContents);
            tableWidget->horizontalHeader()->setSectionResizeMode(6, QHeaderView::ResizeToContents);
            tableWidget->horizontalHeader()->setStretchLastSection(true);
            tableWidget->setFixedSize(tableWidget->width(),tableWidget->height());
            return tableWidget;
        }
    }
    QTableWidget* modifyTable(QTableWidget* a,std::string temp,int accordance)
    {
        a->setWindowTitle("Search Result");
        if(temp=="*"&&accordance==0)
            return a;
        int j=0;
        switch (accordance) {
        case 0:for(auto i = List.begin();i!= List.end(); ++i)
            {
                if((*i).eid != temp)
                    a->removeRow(j--);
                ++j;
            }
            break;
        case 1:
            for(auto i = List.begin();i!= List.end(); ++i)
            {
                if((*i).name != temp)
                    a->removeRow(j--);
                ++j;
            }
            break;
        }
        if(j==0)
        {
            return nullptr;
        }
        a->setFixedSize(1700,a->rowCount()>10?500:a->rowCount()*150);
        return a;
    }
    QTableWidget* modifyTable(QTableWidget* a,job_t::work_t work)
    {
        a->setWindowTitle("Search Result");
        int j=0;
        for(auto i = List.begin();i!= List.end(); ++i)
        {
            if((*i).job->off != work )
                a->removeRow(j--);
            ++j;
        }
        if(j==0)
        {
            return nullptr;
        }
        a->setFixedSize(1700,a->rowCount()>10?500:a->rowCount()*150);
        return a;
    }
    QTableWidget* modifyTable(QTableWidget* a, employee::office_t off)
    {
        a->setWindowTitle("Search Result");
        int j=0;
        for(auto i = List.begin();i!= List.end(); ++i)
        {
            if((*i).unit != off )
            {
                a->removeRow(j--);
            }
            ++j;
        }
        if(j==0)
        {
            return nullptr;
        }
        a->setFixedSize(1700,a->rowCount()>10?500:a->rowCount()*150);
        return a;
    }
    QTableWidget* modifyTable(QTableWidget* a, double b,double c)
    {
        a->setWindowTitle("Search Result");
        int j=0;
        for(auto i = List.begin();i!= List.end(); ++i)
        {
            if((*i).job->salary<b||(*i).job->salary>c )
                a->removeRow(j--);
            ++j;
        }
        if(j==0)
        {
            return nullptr;
        }
        a->setFixedSize(1700,a->rowCount()>10?500:a->rowCount()*150);
        return a;
    }
private:

    int _str2int(std::string s) {
        int temp = 0, len = s.length();
        for (int i = 0; i < len; i++) {
            temp *= 10;
            temp += s[i] - '0';
        }
        return temp;
    }
};
