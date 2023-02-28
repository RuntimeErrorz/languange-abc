#ifndef INSERT_H
#define INSERT_H

#include <QDialog>
#include "mainone.h"

class employee;

namespace Ui {
class insert;
}

class insert : public QDialog
{
    Q_OBJECT

public:
    explicit insert(QWidget *parent = nullptr);
    ~insert();
    void display(const employee *e);
private slots:
    void on_gender_2_currentIndexChanged(int index);

    void on_name_2_editingFinished();

    void on_eid_2_editingFinished();

    void on_department_2_currentIndexChanged(int index);

    void on_position_2_currentIndexChanged(int index);

    void on_confirm_2_clicked();

    void on_dateEdit_2_userDateChanged(const QDate &date);

    void on_dateEdit_userDateChanged(const QDate &date);

private:
    Ui::insert *ui;
    employee* e;
};

#endif // INSERT_H
