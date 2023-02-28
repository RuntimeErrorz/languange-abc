#ifndef ADD_H
#define ADD_H
#include <QDialog>
#include "staff.h"
#include "mainone.h"
#include "textbox.h"
#include "insert.h"
namespace Ui {
class add;
}

class add : public QDialog
{
    Q_OBJECT

public:
    explicit add(QWidget *parent = nullptr);

    ~add();

private slots:

    void on_Key_clicked();

    void on_File_clicked();

private:
    Ui::add *ui;
};

#endif // ADD_H
