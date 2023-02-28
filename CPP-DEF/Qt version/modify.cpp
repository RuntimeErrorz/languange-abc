#include "modify.h"
#include "ui_modify.h"
modify::modify(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modify)
{
    ui->setupUi(this);
}

modify::~modify()
{
    delete ui;
}


void modify::display(const employee &e)
{
    ui->label_6->setText("Eid: "+QString::fromStdString(e.eid));
    ui->label_10->setText("Name: "+QString::fromStdString(e.name));
    if(e.gender==employee::sex_t::M)
        ui->label_7->setText("Sex: Male");
    else
        ui->label_7->setText("Sex: Female");
    ui->label->setText("Dob: "+QString::fromStdString(std::to_string(e.dob.year) + "/" + std::to_string(e.dob.month) + "/" + std::to_string(e.dob.day)));
    ui->label_2->setText("Doe: "+QString::fromStdString(std::to_string(e.doe.year) + "/" + std::to_string(e.doe.month) + "/" + std::to_string(e.doe.day)));
    if (e.unit == 0) {
        ui->label_8->setText("Unit :HumanResources");
    }
    else if (e.unit == 1) {
        ui->label_8->setText("Unit :Accounting");
    }
    else if (e.unit == 2) {
        ui->label_8->setText("Unit :Sales");
    }
    else {
        ui->label_8->setText("Unit :Adminstration");
    }
    if (e.job->off == 0) {
        ui->label_8->setText("Title :Manager");
    }
    else if (e.job->off == 1) {
        ui->label_8->setText("Title :HRSpecialist");
    }
    else if (e.job->off == 2) {
        ui->label_8->setText("Title :TreasuryAttache");
    }
    else if (e.job->off == 3) {
        ui->label_8->setText("Title :SalesExecutive");
    }
    else {
        ui->label_8->setText("AdministrativeCommissioner");
    }
}

void modify::on_eid_2_editingFinished()
{
    //ui->
}

void modify::on_dateEdit_userDateChanged(const QDate &date)
{

}

void modify::on_confirm_2_clicked()
{
    //s->
}
