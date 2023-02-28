/********************************************************************************
** Form generated from reading UI file 'searchsalary.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHSALARY_H
#define UI_SEARCHSALARY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_searchsalary
{
public:
    QFormLayout *formLayout_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;

    void setupUi(QDialog *searchsalary)
    {
        if (searchsalary->objectName().isEmpty())
            searchsalary->setObjectName(QString::fromUtf8("searchsalary"));
        searchsalary->resize(483, 145);
        formLayout_2 = new QFormLayout(searchsalary);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit = new QLineEdit(searchsalary);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        label = new QLabel(searchsalary);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_2 = new QLineEdit(searchsalary);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout->addWidget(lineEdit_2);


        formLayout_2->setLayout(0, QFormLayout::SpanningRole, horizontalLayout);

        pushButton = new QPushButton(searchsalary);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, pushButton);


        retranslateUi(searchsalary);

        QMetaObject::connectSlotsByName(searchsalary);
    } // setupUi

    void retranslateUi(QDialog *searchsalary)
    {
        searchsalary->setWindowTitle(QCoreApplication::translate("searchsalary", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("searchsalary", "---", nullptr));
        pushButton->setText(QCoreApplication::translate("searchsalary", "confirm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class searchsalary: public Ui_searchsalary {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHSALARY_H
