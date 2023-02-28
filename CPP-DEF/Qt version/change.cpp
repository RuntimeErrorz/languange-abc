#include "change.h"
#include "ui_change.h"
change::change(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::change)
{
    ui->setupUi(this);
}

change::~change()
{
    delete ui;
}

void change::on_pushButton_clicked()
{
    flag=11;
    textbox * d = new textbox(this);
    d->setWindowTitle("modify employee");
    d->show();
}

void change::on_pushButton_2_clicked()
{
    salary* t= new salary(this);
    t->setWindowTitle("modify salary");
    t->show();
}
