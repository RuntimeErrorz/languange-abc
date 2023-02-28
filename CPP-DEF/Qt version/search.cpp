#include "search.h"
#include "ui_search.h"
search::search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::search)
{
    ui->setupUi(this);
}

search::~search()
{
    delete ui;
}

void search::on_eid_clicked()
{
    flag = 3;
    textbox * a = new textbox(this);
    a->setWindowTitle("Search By Eid");
    a->show();
}

void search::on_name_clicked()
{
    flag = 9;
    textbox * a = new textbox(this);
    a->setWindowTitle("Search By Name");
    a->show();

}

void search::on_unit_clicked()
{
    unit* u = new unit(this);
    u->setWindowTitle("Search By Unit");
    u->show();
}

void search::on_title_clicked()
{
    title* t = new title (this);
    t->setWindowTitle("Search By Title");
    t->show();
}

void search::on_salary_clicked()
{
    searchsalary* t = new searchsalary(this);
    t->setWindowTitle("Search By Salary");
    t->show();
}
