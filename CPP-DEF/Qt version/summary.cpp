#include "summary.h"
#include "ui_summary.h"
#include "mainone.h"
summary::summary(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::summary)
{
    ui->setupUi(this);
}

summary::~summary()
{
    delete ui;
}

void summary::on_gender_clicked()
{
    s->statistics_staff(0);
}

void summary::on_unit_clicked()
{
    s->statistics_staff(1);
}

void summary::on_title_clicked()
{
    s->statistics_staff(2);
}
