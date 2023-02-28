#include "unit.h"
#include "ui_unit.h"

unit::unit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::unit)
{
    ui->setupUi(this);
}

unit::~unit()
{
    delete ui;
}

void unit::on_HumanResources_clicked()
{
    if(s->modifyTable(s->printtoqt(),employee::office_t::HumanResources)==nullptr)
    {
        QMessageBox::information(this,tr("error"),tr("Not found"),QMessageBox::Ok);
    }
    else
        s->modifyTable(s->printtoqt(),employee::office_t::HumanResources)->show();
}

void unit::on_Accounting_clicked()
{
    if(s->modifyTable(s->printtoqt(),employee::office_t::Accounting)==nullptr)
    {
         QMessageBox::information(this,tr("error"),tr("Not found"),QMessageBox::Ok);
    }
    else
        s->modifyTable(s->printtoqt(),employee::office_t::Accounting)->show();
}

void unit::on_Sales_clicked()
{
    if(s->modifyTable(s->printtoqt(),employee::office_t::Sales)==nullptr)
    {
         QMessageBox::information(this,tr("error"),tr("Not found"),QMessageBox::Ok);
    }
    else
        s->modifyTable(s->printtoqt(),employee::office_t::Sales)->show();
}

void unit::on_pushButton_4_clicked()
{
    if(s->modifyTable(s->printtoqt(),employee::office_t::Administration)==nullptr)
    {
         QMessageBox::information(this,tr("error"),tr("Not found"),QMessageBox::Ok);
    }
    else
        s->modifyTable(s->printtoqt(),employee::office_t::Administration)->show();
}
