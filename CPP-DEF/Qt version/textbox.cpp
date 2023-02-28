#include "textbox.h"
#include "ui_deletebyeid.h"
#include <QString>
#include "insert.h"
#include <QMessageBox>
#include <QValidator>
textbox::textbox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::textbox)
{
    ui->setupUi(this);
    if(flag==4||flag==5||flag==6||flag==7||flag==8)
    {
        QValidator * validator = new QDoubleValidator(this);
        ui->deletebyuid->setValidator(validator);
    }
}

textbox::~textbox()
{
    delete ui;
}

void textbox::on_deletebyuid_editingFinished()
{
    extern int flag;
    QString b=ui->deletebyuid->text();
    q=b;
    if(flag==1)
    {
        ui->deletebyuid->blockSignals(true);
        s->remove_with_eid(b.toStdString());
        ui->deletebyuid->blockSignals(false);
    }
    else if(flag==0)
    {
        ui->deletebyuid->blockSignals(true);
        s->insert_from_file(b);
        ui->deletebyuid->blockSignals(false);
    }
    else if (flag==3)//search eid
    {
        ui->deletebyuid->blockSignals(true);
        if(s->modifyTable(s->printtoqt(),b.toStdString(),0)==nullptr)
        {
            QMessageBox::information(this,tr("Warning"),tr("Not found"),QMessageBox::Ok);
            ui->deletebyuid->blockSignals(false);
        }
        else
        {
            s->modifyTable(s->printtoqt(),b.toStdString(),0)->show();
        }
    }
    else if(flag==4||flag==5||flag==6||flag==7||flag==8)
        {
            ui->deletebyuid->blockSignals(true);
            s->modify_salary(flag,b.toInt());
            QMessageBox::question(NULL, " ", "Successfully Changed",QMessageBox::Ok);
            ui->deletebyuid->blockSignals(false);
            this->close();
        }
    else if(flag==9)//search name
    {
        ui->deletebyuid->blockSignals(true);
        if(s->modifyTable(s->printtoqt(),b.toStdString(),1)==nullptr)
        {
            QMessageBox::information(this,tr("Warning"),tr("Not found"),QMessageBox::Ok);
            ui->deletebyuid->blockSignals(false);
        }
        else
            s->modifyTable(s->printtoqt(),b.toStdString(),1)->show();
    }
    else if(flag==11)
    {
        insert* i =new insert(this);
        ui->deletebyuid->blockSignals(true);
        if(s->find(b.toStdString())==nullptr)
        {
            QMessageBox::information(this,tr("Warning"),tr("Not found"),QMessageBox::Ok);
            ui->deletebyuid->blockSignals(false);
        }
        else
        {
            i->display(s->find(b.toStdString()));
            i->setWindowTitle("Modify Employee");
            i->setModal("true");
            i->show();
            i->exec();
            i->close();
        }
        this->close();
    }
}
