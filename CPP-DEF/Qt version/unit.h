#ifndef UNIT_H
#define UNIT_H

#include <QDialog>
#include "mainone.h"
namespace Ui {
class unit;
}

class unit : public QDialog
{
    Q_OBJECT

public:
    explicit unit(QWidget *parent = nullptr);
    ~unit();

private slots:
    void on_HumanResources_clicked();

    void on_Accounting_clicked();

    void on_Sales_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::unit *ui;
};

#endif // UNIT_H
