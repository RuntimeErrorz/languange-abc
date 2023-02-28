#ifndef SALARY_H
#define SALARY_H

#include <QDialog>
#include "mainone.h"
namespace Ui {
class salary;
}

class salary : public QDialog
{
    Q_OBJECT

public:
    explicit salary(QWidget *parent = nullptr);
    ~salary();

private slots:


    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::salary *ui;
};

#endif // SALARY_H
