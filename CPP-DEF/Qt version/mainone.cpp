#include "mainone.h"
#include "ui_mainone.h"
#include <QDialog>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QLineEdit>
int flag;
staff *s = new staff;
QString q;
mainone::mainone(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainone)
{
    ui->setupUi(this);
}

mainone::~mainone()
{
    delete ui;
}

void mainone::on_DisplayButton_clicked()
{
    if(s->printtoqt()==nullptr)
        QMessageBox::information(this,tr("Error"),tr("No data"),QMessageBox::Ok);
    else
        (s->printtoqt())->show();
}

void mainone::on_AddButton_clicked()
{
    flag=0;
    add* a =new add(this);
    a->setWindowTitle("Add");
    a->show();
}

void mainone::on_DeleteButton_clicked()
{
    flag=1;
    textbox* a = new textbox(this);
    a->setWindowTitle("Delete");
    a->setModal(true);
    a->show();
}

void mainone::on_SearchButton_clicked()
{
    search * m = new search(this);
    m->setWindowTitle("Search");
    m->show();
}

void mainone::on_ChangeButton_clicked()
{
    change* a = new change(this);
    a->setWindowTitle("Change");
    a->setModal(true);
    a->show();
}

void mainone::on_SumButton_clicked()
{
    summary* t = new summary(this);
    t->setWindowTitle("Summary");
    t->show();
}

void mainone::on_QuitButton_clicked()
{
    this->close();
}

