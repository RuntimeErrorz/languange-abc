#ifndef TITLE_H
#define TITLE_H

#include <QDialog>
#include "mainone.h"
namespace Ui {
class title;
}

class title : public QDialog
{
    Q_OBJECT

public:
    explicit title(QWidget *parent = nullptr);
    ~title();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::title *ui;
};

#endif // TITLE_H
