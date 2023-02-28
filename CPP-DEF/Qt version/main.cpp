#include <QApplication>
#include "mainone.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    s->load("save_employee.txt","save_job.txt");
    mainone *w=new mainone;
    w->setWindowTitle("Human Resources Manage System");
    w->show();
    w->exec();
    s->save("save_employee.txt","save_job.txt");
    return 0;
}
