#include "title.h"
#include "ui_title.h"

title::title(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::title)
{
    ui->setupUi(this);
}

title::~title()
{
    delete ui;
}

void title::on_pushButton_2_clicked()//manager
{
    if(s->modifyTable(s->printtoqt(),job_t::work_t::Manager)==nullptr)
    {
         QMessageBox::information(this,tr("Warning"),tr("Not found"),QMessageBox::Ok);
    }
    else
        s->modifyTable(s->printtoqt(),job_t::work_t::Manager)->show();
}

void title::on_pushButton_clicked()//hr
{
    if(s->modifyTable(s->printtoqt(),job_t::work_t::HRSpecialist)==nullptr)
    {
         QMessageBox::information(this,tr("Warning"),tr("Not found"),QMessageBox::Ok);
    }
    else
        s->modifyTable(s->printtoqt(),job_t::work_t::HRSpecialist)->show();
}

void title::on_pushButton_5_clicked()
{
    if(s->modifyTable(s->printtoqt(),job_t::work_t::TreasuryAttache)==nullptr)
    {
         QMessageBox::information(this,tr("Warning"),tr("Not found"),QMessageBox::Ok);

    }
    else
        s->modifyTable(s->printtoqt(),job_t::work_t::TreasuryAttache)->show();
}

void title::on_pushButton_4_clicked()
{
    if(s->modifyTable(s->printtoqt(),job_t::work_t::SalesExecutive)==nullptr)
    {
         QMessageBox::information(this,tr("Warning"),tr("Not found"),QMessageBox::Ok);
    }
    else
        s->modifyTable(s->printtoqt(),job_t::work_t::SalesExecutive)->show();
}

void title::on_pushButton_3_clicked()
{
    if(s->modifyTable(s->printtoqt(),job_t::work_t::AdministrativeCommissioner)==nullptr)
    {
         QMessageBox::information(this,tr("Warning"),tr("Not found"),QMessageBox::Ok);
    }
    else
        s->modifyTable(s->printtoqt(),job_t::work_t::AdministrativeCommissioner)->show();
}
