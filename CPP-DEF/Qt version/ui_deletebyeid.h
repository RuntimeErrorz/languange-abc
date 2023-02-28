/********************************************************************************
** Form generated from reading UI file 'deletebyeid.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEBYEID_H
#define UI_DELETEBYEID_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_DeleteByEid
{
public:
    QFormLayout *formLayout;
    QLineEdit *deletebyuid;

    void setupUi(QDialog *DeleteByEid)
    {
        if (DeleteByEid->objectName().isEmpty())
            DeleteByEid->setObjectName(QString::fromUtf8("DeleteByEid"));
        DeleteByEid->resize(705, 43);
        formLayout = new QFormLayout(DeleteByEid);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        deletebyuid = new QLineEdit(DeleteByEid);
        deletebyuid->setObjectName(QString::fromUtf8("deletebyuid"));

        formLayout->setWidget(0, QFormLayout::SpanningRole, deletebyuid);


        retranslateUi(DeleteByEid);

        QMetaObject::connectSlotsByName(DeleteByEid);
    } // setupUi

    void retranslateUi(QDialog *DeleteByEid)
    {
        DeleteByEid->setWindowTitle(QCoreApplication::translate("DeleteByEid", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class textbox: public Ui_DeleteByEid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEBYEID_H
