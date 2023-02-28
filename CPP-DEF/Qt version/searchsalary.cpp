#include "searchsalary.h"
#include "ui_searchsalary.h"
#include <QValidator>
QString b,c;
searchsalary::searchsalary(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchsalary)
{
    ui->setupUi(this);
    QValidator * validator = new QDoubleValidator(this);
    ui->lineEdit->setValidator(validator);
    ui->lineEdit_2->setValidator(validator);
}

searchsalary::~searchsalary()
{
    delete ui;
}

void searchsalary::on_lineEdit_editingFinished()
{
    b=ui->lineEdit->text();
}

void searchsalary::on_lineEdit_2_editingFinished()
{
    c=ui->lineEdit_2->text();
}

void searchsalary::on_pushButton_clicked()
{
    if(s->modifyTable(s->printtoqt(),b.toDouble(0),c.toDouble())==nullptr)
    {
        QMessageBox::information(this,tr("Warning"),tr("Not found"),QMessageBox::Ok);
    }
    else
        s->modifyTable(s->printtoqt(),b.toDouble(),c.toDouble())->show();
    this->close();
}
