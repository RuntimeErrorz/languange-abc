#include "insertkeyboard.h"
#include "mydialog.h"
job_t job_Mng, job_HR, job_Tsy, job_Sal, job_Adm;
employee e={"","",employee::sex_t::M,{0,0,0},{0,0,0},employee::office_t::HumanResources,&job_Mng};


insertfromkeyboard::insertfromkeyboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::insertfromkeyboard)
{
    ui->setupUi(this);
}

insertfromkeyboard::~insertfromkeyboard()
{
    delete ui;
}

void insertfromkeyboard::on_eid_editingFinished()
{
    e.eid=ui->eid->text().toStdString();
}

void insertfromkeyboard::on_gender_currentIndexChanged(int index)
{
    switch(ui->gender->currentIndex())
    {
        case 0 : e.gender=employee::sex_t::M; break;
        case 1 : e.gender=employee::sex_t::F; break;
    }
}

void insertfromkeyboard::on_department_currentIndexChanged(int index)
{
    switch(ui->department->currentIndex())
    {
        case 0 : e.unit=employee::office_t::HumanResources; break;
        case 1 : e.unit=employee::office_t::Accounting; break;
        case 2 : e.unit=employee::office_t::Sales; break;
        case 3 : e.unit=employee::office_t::Administration; break;
    }
}

void insertfromkeyboard::on_position_currentIndexChanged(int index)
{
    switch(ui->position->currentIndex())
    {
        case 0 : e.job = &job_Mng; break;
        case 1 : e.job= &job_HR; break;
        case 2 : e.job= &job_Tsy; break;
        case 3 : e.job= &job_Sal; break;
        case 4 : e.job= &job_Adm; break;
    }
}

void insertfromkeyboard::on_name_editingFinished()
{
     e.name=ui->name->text().toStdString();
}

void insertfromkeyboard::on_confirm_clicked()
{
    s->insert_from_keyboard(e);
    this->close();
}
