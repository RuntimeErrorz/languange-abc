#include "add.h"
#include "ui_add.h"
#include <QWidget>
#include <QLineEdit>

add::add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add)
{
    ui->setupUi(this);
}

add::~add()
{
    delete ui;
}

void add::on_Key_clicked()
{
    insert* e =new insert(this);
    e->setWindowTitle("Insert From KeyBoard");
    e->setModal(true);
    e->show();
}

void add::on_File_clicked()
{
    textbox* a = new textbox(this);
    a->setWindowTitle("Insert From File");
    a->setModal(true);
    a->show();
}
