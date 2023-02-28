#pragma once

#include <QDialog>
#include <QMessageBox>
#include "mainone.h"
namespace Ui {
class textbox;
}

class textbox : public QDialog
{
    Q_OBJECT
    friend class search;
public:
    explicit textbox(QWidget *parent = nullptr);
    ~textbox();

private slots:

    void on_deletebyuid_editingFinished();

private:
    Ui::textbox *ui;
};

