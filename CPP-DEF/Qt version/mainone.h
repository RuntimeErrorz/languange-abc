#pragma once

#include <QDialog>
#include "staff.h"
#include "textbox.h"
#include "insert.h"
#include "add.h"
#include "summary.h"
#include "search.h"
#include "change.h"
class staff;
extern staff *s;
extern QString q;
extern int flag;
namespace Ui {
class mainone;
}

class mainone : public QDialog
{
    Q_OBJECT

public:
    explicit mainone(QWidget *parent = nullptr);
    ~mainone();
private slots:
    void on_DisplayButton_clicked();

    void on_AddButton_clicked();

    void on_DeleteButton_clicked();

    void on_SearchButton_clicked();

    void on_ChangeButton_clicked();

    void on_SumButton_clicked();

    void on_QuitButton_clicked();

private:
    Ui::mainone *ui;
};
