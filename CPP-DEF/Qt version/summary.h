#ifndef SUMMARY_H
#define SUMMARY_H

#include <QDialog>

namespace Ui {
class summary;
}

class summary : public QDialog
{
    Q_OBJECT

public:
    explicit summary(QWidget *parent = nullptr);
    ~summary();

private slots:
    void on_gender_clicked();

    void on_unit_clicked();

    void on_title_clicked();

private:
    Ui::summary *ui;
};

#endif // SUMMARY_H
