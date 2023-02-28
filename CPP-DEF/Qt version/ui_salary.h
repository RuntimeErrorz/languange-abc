/********************************************************************************
** Form generated from reading UI file 'salary.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SALARY_H
#define UI_SALARY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_salary
{
public:
    QFormLayout *formLayout;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *salary)
    {
        if (salary->objectName().isEmpty())
            salary->setObjectName(QString::fromUtf8("salary"));
        salary->resize(498, 422);
        formLayout = new QFormLayout(salary);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        pushButton_5 = new QPushButton(salary);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);

        formLayout->setWidget(2, QFormLayout::SpanningRole, pushButton_5);

        pushButton_4 = new QPushButton(salary);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);

        formLayout->setWidget(3, QFormLayout::SpanningRole, pushButton_4);

        pushButton_3 = new QPushButton(salary);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);

        formLayout->setWidget(4, QFormLayout::SpanningRole, pushButton_3);

        pushButton = new QPushButton(salary);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        formLayout->setWidget(1, QFormLayout::SpanningRole, pushButton);

        pushButton_2 = new QPushButton(salary);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);

        formLayout->setWidget(0, QFormLayout::SpanningRole, pushButton_2);


        retranslateUi(salary);

        QMetaObject::connectSlotsByName(salary);
    } // setupUi

    void retranslateUi(QDialog *salary)
    {
        salary->setWindowTitle(QCoreApplication::translate("salary", "Dialog", nullptr));
        pushButton_5->setText(QCoreApplication::translate("salary", "TreasuryAttache", nullptr));
        pushButton_4->setText(QCoreApplication::translate("salary", "SalesExecutive", nullptr));
        pushButton_3->setText(QCoreApplication::translate("salary", "AdministrativeCommissioner", nullptr));
        pushButton->setText(QCoreApplication::translate("salary", "HRSpecialist", nullptr));
        pushButton_2->setText(QCoreApplication::translate("salary", "Manager", nullptr));
    } // retranslateUi

};

namespace Ui {
    class salary: public Ui_salary {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SALARY_H
