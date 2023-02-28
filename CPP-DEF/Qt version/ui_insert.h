/********************************************************************************
** Form generated from reading UI file 'insert.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERT_H
#define UI_INSERT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_insert
{
public:
    QFormLayout *formLayout;
    QFormLayout *formLayout_2;
    QLabel *eid;
    QLabel *gender;
    QComboBox *gender_2;
    QLabel *department;
    QComboBox *department_2;
    QLabel *postion;
    QComboBox *position_2;
    QLineEdit *eid_2;
    QLabel *name;
    QPushButton *confirm_2;
    QLabel *dob;
    QLabel *doe;
    QDateEdit *dateEdit;
    QLineEdit *name_2;
    QDateEdit *dateEdit_2;

    void setupUi(QDialog *insert)
    {
        if (insert->objectName().isEmpty())
            insert->setObjectName(QString::fromUtf8("insert"));
        insert->resize(694, 561);
        formLayout = new QFormLayout(insert);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        eid = new QLabel(insert);
        eid->setObjectName(QString::fromUtf8("eid"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(eid->sizePolicy().hasHeightForWidth());
        eid->setSizePolicy(sizePolicy);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, eid);

        gender = new QLabel(insert);
        gender->setObjectName(QString::fromUtf8("gender"));
        sizePolicy.setHeightForWidth(gender->sizePolicy().hasHeightForWidth());
        gender->setSizePolicy(sizePolicy);

        formLayout_2->setWidget(4, QFormLayout::LabelRole, gender);

        gender_2 = new QComboBox(insert);
        gender_2->addItem(QString());
        gender_2->addItem(QString());
        gender_2->setObjectName(QString::fromUtf8("gender_2"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, gender_2);

        department = new QLabel(insert);
        department->setObjectName(QString::fromUtf8("department"));
        sizePolicy.setHeightForWidth(department->sizePolicy().hasHeightForWidth());
        department->setSizePolicy(sizePolicy);

        formLayout_2->setWidget(5, QFormLayout::LabelRole, department);

        department_2 = new QComboBox(insert);
        department_2->addItem(QString());
        department_2->addItem(QString());
        department_2->addItem(QString());
        department_2->addItem(QString());
        department_2->setObjectName(QString::fromUtf8("department_2"));

        formLayout_2->setWidget(5, QFormLayout::FieldRole, department_2);

        postion = new QLabel(insert);
        postion->setObjectName(QString::fromUtf8("postion"));
        sizePolicy.setHeightForWidth(postion->sizePolicy().hasHeightForWidth());
        postion->setSizePolicy(sizePolicy);

        formLayout_2->setWidget(6, QFormLayout::LabelRole, postion);

        position_2 = new QComboBox(insert);
        position_2->addItem(QString());
        position_2->addItem(QString());
        position_2->addItem(QString());
        position_2->addItem(QString());
        position_2->addItem(QString());
        position_2->setObjectName(QString::fromUtf8("position_2"));

        formLayout_2->setWidget(6, QFormLayout::FieldRole, position_2);

        eid_2 = new QLineEdit(insert);
        eid_2->setObjectName(QString::fromUtf8("eid_2"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(eid_2->sizePolicy().hasHeightForWidth());
        eid_2->setSizePolicy(sizePolicy1);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, eid_2);

        name = new QLabel(insert);
        name->setObjectName(QString::fromUtf8("name"));
        sizePolicy.setHeightForWidth(name->sizePolicy().hasHeightForWidth());
        name->setSizePolicy(sizePolicy);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, name);

        confirm_2 = new QPushButton(insert);
        confirm_2->setObjectName(QString::fromUtf8("confirm_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(confirm_2->sizePolicy().hasHeightForWidth());
        confirm_2->setSizePolicy(sizePolicy2);

        formLayout_2->setWidget(7, QFormLayout::SpanningRole, confirm_2);

        dob = new QLabel(insert);
        dob->setObjectName(QString::fromUtf8("dob"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, dob);

        doe = new QLabel(insert);
        doe->setObjectName(QString::fromUtf8("doe"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, doe);

        dateEdit = new QDateEdit(insert);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, dateEdit);

        name_2 = new QLineEdit(insert);
        name_2->setObjectName(QString::fromUtf8("name_2"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, name_2);

        dateEdit_2 = new QDateEdit(insert);
        dateEdit_2->setObjectName(QString::fromUtf8("dateEdit_2"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, dateEdit_2);


        formLayout->setLayout(0, QFormLayout::SpanningRole, formLayout_2);


        retranslateUi(insert);

        QMetaObject::connectSlotsByName(insert);
    } // setupUi

    void retranslateUi(QDialog *insert)
    {
        insert->setWindowTitle(QCoreApplication::translate("insert", "Dialog", nullptr));
        eid->setText(QCoreApplication::translate("insert", "eid", nullptr));
        gender->setText(QCoreApplication::translate("insert", "gender", nullptr));
        gender_2->setItemText(0, QCoreApplication::translate("insert", "Male", nullptr));
        gender_2->setItemText(1, QCoreApplication::translate("insert", "Female", nullptr));

        department->setText(QCoreApplication::translate("insert", "department", nullptr));
        department_2->setItemText(0, QCoreApplication::translate("insert", "HumanResources", nullptr));
        department_2->setItemText(1, QCoreApplication::translate("insert", "Accounting", nullptr));
        department_2->setItemText(2, QCoreApplication::translate("insert", "Sales", nullptr));
        department_2->setItemText(3, QCoreApplication::translate("insert", "Administration", nullptr));

        postion->setText(QCoreApplication::translate("insert", "position", nullptr));
        position_2->setItemText(0, QCoreApplication::translate("insert", "Manager", nullptr));
        position_2->setItemText(1, QCoreApplication::translate("insert", "HRSpecialist", nullptr));
        position_2->setItemText(2, QCoreApplication::translate("insert", "TreasuryAttache", nullptr));
        position_2->setItemText(3, QCoreApplication::translate("insert", "SalesExecutive", nullptr));
        position_2->setItemText(4, QCoreApplication::translate("insert", "AdministrativeCommissioner", nullptr));

        name->setText(QCoreApplication::translate("insert", "name", nullptr));
        confirm_2->setText(QCoreApplication::translate("insert", "confirm", nullptr));
        dob->setText(QCoreApplication::translate("insert", "dob", nullptr));
        doe->setText(QCoreApplication::translate("insert", "doe", nullptr));
    } // retranslateUi

};

namespace Ui {
    class insert: public Ui_insert {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERT_H
