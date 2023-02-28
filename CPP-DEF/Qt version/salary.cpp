#include "salary.h"
#include "ui_salary.h"

salary::salary(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::salary)
{
    ui->setupUi(this);
}

salary::~salary()
{
    delete ui;
}

void salary::on_pushButton_2_clicked()
{
    flag=4;
    textbox * a = new textbox(this);
    a->setWindowTitle("Change Salary");
    a->show();
}

void salary::on_pushButton_clicked()
{
    flag=5;
    textbox * a = new textbox(this);
    a->setWindowTitle("Change Salary");
    a->show();
}

void salary::on_pushButton_5_clicked()
{
    flag=6;
    textbox * a = new textbox(this);
    a->setWindowTitle("Change Salary");
    a->show();
}

void salary::on_pushButton_4_clicked()
{
    flag=7;
    textbox * a = new textbox(this);
    a->setWindowTitle("Change Salary");
    a->show();
}

void salary::on_pushButton_3_clicked()
{
    flag=8;
    textbox * a = new textbox(this);
    a->setWindowTitle("Change Salary");
    a->show();
}
