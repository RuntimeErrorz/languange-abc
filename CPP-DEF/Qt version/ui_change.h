/********************************************************************************
** Form generated from reading UI file 'change.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGE_H
#define UI_CHANGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_change
{
public:
    QFormLayout *formLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *change)
    {
        if (change->objectName().isEmpty())
            change->setObjectName(QString::fromUtf8("change"));
        change->resize(341, 312);
        formLayout = new QFormLayout(change);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        pushButton = new QPushButton(change);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        formLayout->setWidget(0, QFormLayout::SpanningRole, pushButton);

        pushButton_2 = new QPushButton(change);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);

        formLayout->setWidget(1, QFormLayout::SpanningRole, pushButton_2);


        retranslateUi(change);

        QMetaObject::connectSlotsByName(change);
    } // setupUi

    void retranslateUi(QDialog *change)
    {
        change->setWindowTitle(QCoreApplication::translate("change", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("change", "employee", nullptr));
        pushButton_2->setText(QCoreApplication::translate("change", "salary", nullptr));
    } // retranslateUi

};

namespace Ui {
    class change: public Ui_change {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGE_H
