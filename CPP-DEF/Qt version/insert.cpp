#include "insert.h"
#include "ui_insert.h"

insert::insert(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::insert)
{
    ui->setupUi(this);
    e = new employee{"@default","@default",employee::sex_t::M,{2000,0,0},{2000,0,0},employee::office_t::HumanResources,&s->jobs[0]};
}

insert::~insert()
{
    delete ui;
    delete e;
}


void insert::on_gender_2_currentIndexChanged(int index)
{
    switch(ui->gender_2->currentIndex())
    {
    case 0 : e->gender=employee::sex_t::M; break;
    case 1 : e->gender=employee::sex_t::F; break;
    }
}

void insert::on_name_2_editingFinished()
{
    e->name=ui->name_2->text().toStdString();

}

void insert::on_eid_2_editingFinished()
{
    e->eid=ui->eid_2->text().toStdString();
}

void insert::on_department_2_currentIndexChanged(int index)
{
    switch(ui->department_2->currentIndex())
    {
    case 0 : e->unit=employee::office_t::HumanResources; break;
    case 1 : e->unit=employee::office_t::Accounting; break;
    case 2 : e->unit=employee::office_t::Sales; break;
    case 3 : e->unit=employee::office_t::Administration; break;
    }
}

void insert::on_position_2_currentIndexChanged(int index)
{
    e->job = &s->jobs[ui->position_2->currentIndex()];
}

void insert::on_confirm_2_clicked()
{
    if(flag==11)
    {
        flag=20;
        if(s->insert_from_keyboard(*e))
            s->remove_with_eid(q.toStdString());
        this->close();
    }
    else
        if(e->dob.year+e->dob.month*0.1+e->dob.day*0.01>e->doe.year+e->doe.month*0.1+e->doe.day*0.01)
            QMessageBox::warning(NULL, "Error", "dob > doe", QMessageBox::Ok);
        else
        {
            s->insert_from_keyboard(*e);
            this->close();
        }
}

void insert::on_dateEdit_2_userDateChanged(const QDate &date)
{
    QDate d = ui->dateEdit_2->date();
    e->dob.day=d.day();
    e->dob.year=d.year();
    e->dob.month=d.month();
}

void insert::on_dateEdit_userDateChanged(const QDate &date)
{
    QDate d = ui->dateEdit->date();
    e->doe.day=d.day();
    e->doe.year=d.year();
    e->doe.month=d.month();
}

void insert::display(const employee *e)
{
    ui->eid->setText("Eid: "+QString::fromStdString(e->eid));
    ui->name->setText("Name: "+QString::fromStdString(e->name));
    if(e->gender==employee::sex_t::M)
        ui->gender->setText("Sex: Male");
    else
        ui->gender->setText("Sex: Female");
    ui->dob->setText("Dob: "+QString::fromStdString(std::to_string(e->dob.year) + "/" + std::to_string(e->dob.month) + "/" + std::to_string(e->dob.day)));
    ui->doe->setText("Doe: "+QString::fromStdString(std::to_string(e->doe.year) + "/" + std::to_string(e->doe.month) + "/" + std::to_string(e->doe.day)));
    if (e->unit == 0) {
        ui->department->setText("Unit: HumanResources");
    }
    else if (e->unit == 1) {
        ui->department->setText("Unit: Accounting");
    }
    else if (e->unit == 2) {
        ui->department->setText("Unit: Sales");
    }
    else {
        ui->department->setText("Unit: Adminstration");
    }
    if (e->job->off == 0) {
        ui->postion->setText("Title: Manager");
    }
    else if (e->job->off == 1) {
        ui->postion->setText("Title: HRSpecialist");
    }
    else if (e->job->off == 2) {
        ui->postion->setText("Title: TreasuryAttache");
    }
    else if (e->job->off == 3) {
        ui->postion->setText("Title: SalesExecutive");
    }
    else {
        ui->department->setText("Title: AdministrativeCommissioner");
    }
}
