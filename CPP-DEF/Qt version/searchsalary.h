#ifndef SEARCHSALARY_H
#define SEARCHSALARY_H

#include <QDialog>
#include "mainone.h"
namespace Ui {
class searchsalary;
}

class searchsalary : public QDialog
{
    Q_OBJECT

public:
    explicit searchsalary(QWidget *parent = nullptr);
    ~searchsalary();

private slots:
    void on_lineEdit_editingFinished();

    void on_lineEdit_2_editingFinished();

    void on_pushButton_clicked();

private:
    Ui::searchsalary *ui;
};

#endif // SEARCHSALARY_H
