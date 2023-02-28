#ifndef MODIFY_H
#define MODIFY_H

#include <QDialog>
#include "mainone.h"
namespace Ui {
class modify;
}

class modify : public QDialog
{
    Q_OBJECT

private:
    Ui::modify *ui;

public:
    explicit modify(QWidget *parent = nullptr);

    ~modify();

    void display(const employee& a);
private slots:
    void on_eid_2_editingFinished();

    void on_dateEdit_userDateChanged(const QDate &date);

    void on_confirm_2_clicked();

};

#endif // MODIFY_H
