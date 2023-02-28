#ifndef SEARCH_H
#define SEARCH_H

#include <QDialog>
#include "textbox.h"
#include "mainone.h"
#include "unit.h"
#include "title.h"
#include "searchsalary.h"
namespace Ui {
class search;
}

class search : public QDialog
{
    Q_OBJECT

public:
    explicit search(QWidget *parent = nullptr);
    ~search();

private slots:
    void on_eid_clicked();

    void on_name_clicked();

    void on_unit_clicked();

    void on_title_clicked();

    void on_salary_clicked();

private:
    Ui::search *ui;
};

#endif // SEARCH_H
