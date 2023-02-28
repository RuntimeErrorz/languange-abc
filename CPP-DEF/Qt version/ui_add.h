/********************************************************************************
** Form generated from reading UI file 'add.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_H
#define UI_ADD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_add
{
public:
    QFormLayout *formLayout_2;
    QPushButton *File;
    QPushButton *Key;

    void setupUi(QDialog *add)
    {
        if (add->objectName().isEmpty())
            add->setObjectName(QString::fromUtf8("add"));
        add->resize(377, 320);
        formLayout_2 = new QFormLayout(add);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        File = new QPushButton(add);
        File->setObjectName(QString::fromUtf8("File"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(File->sizePolicy().hasHeightForWidth());
        File->setSizePolicy(sizePolicy);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, File);

        Key = new QPushButton(add);
        Key->setObjectName(QString::fromUtf8("Key"));
        sizePolicy.setHeightForWidth(Key->sizePolicy().hasHeightForWidth());
        Key->setSizePolicy(sizePolicy);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, Key);


        retranslateUi(add);

        QMetaObject::connectSlotsByName(add);
    } // setupUi

    void retranslateUi(QDialog *add)
    {
        add->setWindowTitle(QCoreApplication::translate("add", "Dialog", nullptr));
        File->setText(QCoreApplication::translate("add", "From File", nullptr));
        Key->setText(QCoreApplication::translate("add", "From Keyboard", nullptr));
    } // retranslateUi

};

namespace Ui {
    class add: public Ui_add {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_H
