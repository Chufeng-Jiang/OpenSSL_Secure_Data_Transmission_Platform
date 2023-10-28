/********************************************************************************
** Form generated from reading UI file 'dbinfoset.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBINFOSET_H
#define UI_DBINFOSET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DBInfoSet
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLineEdit *dbPort;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *dbHostName;
    QLineEdit *dbName;
    QLabel *label_3;
    QLineEdit *dbPasswd;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *dbUser;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *dbTest;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *dbConnect;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *cancle;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *DBInfoSet)
    {
        if (DBInfoSet->objectName().isEmpty())
            DBInfoSet->setObjectName(QString::fromUtf8("DBInfoSet"));
        DBInfoSet->resize(318, 228);
        verticalLayout = new QVBoxLayout(DBInfoSet);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(DBInfoSet);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        dbPort = new QLineEdit(groupBox);
        dbPort->setObjectName(QString::fromUtf8("dbPort"));

        gridLayout->addWidget(dbPort, 1, 2, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        dbHostName = new QLineEdit(groupBox);
        dbHostName->setObjectName(QString::fromUtf8("dbHostName"));

        gridLayout->addWidget(dbHostName, 0, 2, 1, 1);

        dbName = new QLineEdit(groupBox);
        dbName->setObjectName(QString::fromUtf8("dbName"));

        gridLayout->addWidget(dbName, 2, 2, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 1, 1, 1);

        dbPasswd = new QLineEdit(groupBox);
        dbPasswd->setObjectName(QString::fromUtf8("dbPasswd"));

        gridLayout->addWidget(dbPasswd, 4, 2, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 1, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 1, 1, 1);

        dbUser = new QLineEdit(groupBox);
        dbUser->setObjectName(QString::fromUtf8("dbUser"));

        gridLayout->addWidget(dbUser, 3, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 3, 1, 1);


        verticalLayout->addWidget(groupBox);

        widget = new QWidget(DBInfoSet);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        dbTest = new QPushButton(widget);
        dbTest->setObjectName(QString::fromUtf8("dbTest"));

        horizontalLayout->addWidget(dbTest);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        dbConnect = new QPushButton(widget);
        dbConnect->setObjectName(QString::fromUtf8("dbConnect"));

        horizontalLayout->addWidget(dbConnect);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        cancle = new QPushButton(widget);
        cancle->setObjectName(QString::fromUtf8("cancle"));

        horizontalLayout->addWidget(cancle);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout->addWidget(widget);

        QWidget::setTabOrder(dbHostName, dbPort);
        QWidget::setTabOrder(dbPort, dbName);
        QWidget::setTabOrder(dbName, dbUser);
        QWidget::setTabOrder(dbUser, dbPasswd);
        QWidget::setTabOrder(dbPasswd, dbTest);
        QWidget::setTabOrder(dbTest, dbConnect);
        QWidget::setTabOrder(dbConnect, cancle);

        retranslateUi(DBInfoSet);

        QMetaObject::connectSlotsByName(DBInfoSet);
    } // setupUi

    void retranslateUi(QDialog *DBInfoSet)
    {
        DBInfoSet->setWindowTitle(QCoreApplication::translate("DBInfoSet", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DBInfoSet", "\346\225\260\346\215\256\345\272\223\350\277\236\346\216\245\344\277\241\346\201\257", nullptr));
        label->setText(QCoreApplication::translate("DBInfoSet", "\346\225\260\346\215\256\345\272\223\345\234\260\345\235\200:", nullptr));
        label_2->setText(QCoreApplication::translate("DBInfoSet", "\346\225\260\346\215\256\345\272\223\347\253\257\345\217\243:", nullptr));
        label_3->setText(QCoreApplication::translate("DBInfoSet", "\346\225\260\346\215\256\345\272\223\345\220\215:", nullptr));
        label_4->setText(QCoreApplication::translate("DBInfoSet", "\347\224\250\346\210\267\345\220\215:", nullptr));
        label_5->setText(QCoreApplication::translate("DBInfoSet", "\345\257\206\347\240\201:", nullptr));
        dbTest->setText(QCoreApplication::translate("DBInfoSet", "\346\265\213\350\257\225", nullptr));
        dbConnect->setText(QCoreApplication::translate("DBInfoSet", "\347\241\256\345\256\232", nullptr));
        cancle->setText(QCoreApplication::translate("DBInfoSet", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DBInfoSet: public Ui_DBInfoSet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBINFOSET_H
