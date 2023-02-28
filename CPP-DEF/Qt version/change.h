#ifndef CHANGE_H
#define CHANGE_H

#include <QDialog>
#include "salary.h"

namespace Ui {
class change;
}

class change : public QDialog
{
    Q_OBJECT

public:
    explicit change(QWidget *parent = nullptr);
    ~change();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::change *ui;
};

#endif // CHANGE_H
