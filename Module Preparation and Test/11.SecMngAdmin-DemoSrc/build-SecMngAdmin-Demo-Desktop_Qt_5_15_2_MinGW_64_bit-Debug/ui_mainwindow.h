/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <welcomewg.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *orclSetAction;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QToolBox *toolBox;
    QWidget *serverSet_page;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QToolButton *serverSet;
    QToolButton *netMng;
    QToolButton *businessMng;
    QToolButton *dealMng;
    QSpacerItem *horizontalSpacer_2;
    QWidget *peopleMng_page;
    QWidget *devicemng_page;
    QStackedWidget *stackedWidget;
    WelcomeWg *welcome;
    QWidget *serverArgSet;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *dbHostName;
    QLabel *label_2;
    QLineEdit *dbUser;
    QLabel *label_3;
    QLineEdit *dbName;
    QLineEdit *dbPasswd;
    QLineEdit *dbPort;
    QPushButton *dbArgSave;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_14;
    QLineEdit *serverIP;
    QLabel *label_13;
    QLineEdit *serverPort;
    QLabel *label_12;
    QLineEdit *maxNetNum;
    QPushButton *serverArgSave;
    QSpacerItem *horizontalSpacer_8;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QLabel *label_17;
    QLabel *label_15;
    QLineEdit *netStatus;
    QLineEdit *netNumber;
    QLabel *label_16;
    QLineEdit *netName;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *netInfoSave;
    QSpacerItem *horizontalSpacer_10;
    QWidget *netMng_page;
    QVBoxLayout *verticalLayout_4;
    QTableWidget *tableWidget;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *createNet;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *modifyNet;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *deleteNet;
    QSpacerItem *horizontalSpacer_12;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_6;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_17;
    QLabel *label_7;
    QDateTimeEdit *dateStart;
    QLabel *label_8;
    QDateTimeEdit *dateEnd;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *vagueSearch;
    QSpacerItem *horizontalSpacer_14;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_2;
    QLabel *label_10;
    QLineEdit *netID;
    QPushButton *exactSearch;
    QLineEdit *netInfo;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_15;
    QSpacerItem *horizontalSpacer_16;
    QSpacerItem *horizontalSpacer_18;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(716, 520);
        orclSetAction = new QAction(MainWindow);
        orclSetAction->setObjectName(QString::fromUtf8("orclSetAction"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        toolBox = new QToolBox(centralWidget);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setMinimumSize(QSize(150, 0));
        toolBox->setMaximumSize(QSize(150, 16777215));
        serverSet_page = new QWidget();
        serverSet_page->setObjectName(QString::fromUtf8("serverSet_page"));
        serverSet_page->setGeometry(QRect(0, 0, 150, 379));
        horizontalLayout_2 = new QHBoxLayout(serverSet_page);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        widget = new QWidget(serverSet_page);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        serverSet = new QToolButton(widget);
        serverSet->setObjectName(QString::fromUtf8("serverSet"));
        serverSet->setMaximumSize(QSize(115, 85));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/set.ico"), QSize(), QIcon::Normal, QIcon::Off);
        serverSet->setIcon(icon);
        serverSet->setIconSize(QSize(32, 32));
        serverSet->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        serverSet->setAutoRaise(true);

        verticalLayout_2->addWidget(serverSet);

        netMng = new QToolButton(widget);
        netMng->setObjectName(QString::fromUtf8("netMng"));
        netMng->setMaximumSize(QSize(115, 85));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/user.ico"), QSize(), QIcon::Normal, QIcon::Off);
        netMng->setIcon(icon1);
        netMng->setIconSize(QSize(32, 32));
        netMng->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        netMng->setAutoRaise(true);

        verticalLayout_2->addWidget(netMng);

        businessMng = new QToolButton(widget);
        businessMng->setObjectName(QString::fromUtf8("businessMng"));
        businessMng->setMaximumSize(QSize(115, 85));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/req.ico"), QSize(), QIcon::Normal, QIcon::Off);
        businessMng->setIcon(icon2);
        businessMng->setIconSize(QSize(32, 32));
        businessMng->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        businessMng->setAutoRaise(true);

        verticalLayout_2->addWidget(businessMng);

        dealMng = new QToolButton(widget);
        dealMng->setObjectName(QString::fromUtf8("dealMng"));
        dealMng->setMaximumSize(QSize(115, 85));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/re.ico"), QSize(), QIcon::Normal, QIcon::Off);
        dealMng->setIcon(icon3);
        dealMng->setIconSize(QSize(32, 32));
        dealMng->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        dealMng->setAutoRaise(true);

        verticalLayout_2->addWidget(dealMng);


        horizontalLayout_2->addWidget(widget);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        toolBox->addItem(serverSet_page, QString::fromUtf8("  SecMngServer\351\205\215\347\275\256\347\256\241\347\220\206"));
        peopleMng_page = new QWidget();
        peopleMng_page->setObjectName(QString::fromUtf8("peopleMng_page"));
        peopleMng_page->setGeometry(QRect(0, 0, 150, 379));
        toolBox->addItem(peopleMng_page, QString::fromUtf8("       \344\272\272\345\221\230\347\256\241\347\220\206"));
        devicemng_page = new QWidget();
        devicemng_page->setObjectName(QString::fromUtf8("devicemng_page"));
        devicemng_page->setGeometry(QRect(0, 0, 150, 379));
        toolBox->addItem(devicemng_page, QString::fromUtf8("       \350\256\276\345\244\207\347\256\241\347\220\206"));

        horizontalLayout->addWidget(toolBox);

        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        welcome = new WelcomeWg();
        welcome->setObjectName(QString::fromUtf8("welcome"));
        stackedWidget->addWidget(welcome);
        serverArgSet = new QWidget();
        serverArgSet->setObjectName(QString::fromUtf8("serverArgSet"));
        verticalLayout = new QVBoxLayout(serverArgSet);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(serverArgSet);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(24);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        groupBox = new QGroupBox(serverArgSet);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 2, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 4, 1, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 5, 1, 1, 1);

        dbHostName = new QLineEdit(groupBox);
        dbHostName->setObjectName(QString::fromUtf8("dbHostName"));

        gridLayout->addWidget(dbHostName, 0, 2, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        dbUser = new QLineEdit(groupBox);
        dbUser->setObjectName(QString::fromUtf8("dbUser"));

        gridLayout->addWidget(dbUser, 4, 2, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 1, 1, 1);

        dbName = new QLineEdit(groupBox);
        dbName->setObjectName(QString::fromUtf8("dbName"));

        gridLayout->addWidget(dbName, 1, 2, 1, 1);

        dbPasswd = new QLineEdit(groupBox);
        dbPasswd->setObjectName(QString::fromUtf8("dbPasswd"));

        gridLayout->addWidget(dbPasswd, 5, 2, 1, 1);

        dbPort = new QLineEdit(groupBox);
        dbPort->setObjectName(QString::fromUtf8("dbPort"));

        gridLayout->addWidget(dbPort, 2, 2, 1, 1);

        dbArgSave = new QPushButton(groupBox);
        dbArgSave->setObjectName(QString::fromUtf8("dbArgSave"));

        gridLayout->addWidget(dbArgSave, 5, 3, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 5, 4, 1, 1);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(serverArgSet);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalSpacer_7 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_7, 0, 0, 1, 1);

        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_3->addWidget(label_14, 0, 1, 1, 1);

        serverIP = new QLineEdit(groupBox_2);
        serverIP->setObjectName(QString::fromUtf8("serverIP"));

        gridLayout_3->addWidget(serverIP, 0, 2, 1, 1);

        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_3->addWidget(label_13, 1, 1, 1, 1);

        serverPort = new QLineEdit(groupBox_2);
        serverPort->setObjectName(QString::fromUtf8("serverPort"));

        gridLayout_3->addWidget(serverPort, 1, 2, 1, 1);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_3->addWidget(label_12, 2, 1, 1, 1);

        maxNetNum = new QLineEdit(groupBox_2);
        maxNetNum->setObjectName(QString::fromUtf8("maxNetNum"));

        gridLayout_3->addWidget(maxNetNum, 2, 2, 1, 1);

        serverArgSave = new QPushButton(groupBox_2);
        serverArgSave->setObjectName(QString::fromUtf8("serverArgSave"));

        gridLayout_3->addWidget(serverArgSave, 2, 3, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_8, 2, 4, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(serverArgSet);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_17 = new QLabel(groupBox_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_4->addWidget(label_17, 1, 1, 1, 1);

        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_4->addWidget(label_15, 0, 1, 1, 1);

        netStatus = new QLineEdit(groupBox_3);
        netStatus->setObjectName(QString::fromUtf8("netStatus"));

        gridLayout_4->addWidget(netStatus, 2, 2, 1, 1);

        netNumber = new QLineEdit(groupBox_3);
        netNumber->setObjectName(QString::fromUtf8("netNumber"));

        gridLayout_4->addWidget(netNumber, 1, 2, 1, 1);

        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_4->addWidget(label_16, 2, 1, 1, 1);

        netName = new QLineEdit(groupBox_3);
        netName->setObjectName(QString::fromUtf8("netName"));

        gridLayout_4->addWidget(netName, 0, 2, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_9, 1, 0, 1, 1);

        netInfoSave = new QPushButton(groupBox_3);
        netInfoSave->setObjectName(QString::fromUtf8("netInfoSave"));

        gridLayout_4->addWidget(netInfoSave, 2, 3, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_10, 2, 4, 1, 1);


        verticalLayout->addWidget(groupBox_3);

        stackedWidget->addWidget(serverArgSet);
        netMng_page = new QWidget();
        netMng_page->setObjectName(QString::fromUtf8("netMng_page"));
        verticalLayout_4 = new QVBoxLayout(netMng_page);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        tableWidget = new QTableWidget(netMng_page);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout_4->addWidget(tableWidget);

        groupBox_4 = new QGroupBox(netMng_page);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_4);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        createNet = new QPushButton(groupBox_4);
        createNet->setObjectName(QString::fromUtf8("createNet"));

        horizontalLayout_4->addWidget(createNet);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        modifyNet = new QPushButton(groupBox_4);
        modifyNet->setObjectName(QString::fromUtf8("modifyNet"));

        horizontalLayout_4->addWidget(modifyNet);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_11);

        deleteNet = new QPushButton(groupBox_4);
        deleteNet->setObjectName(QString::fromUtf8("deleteNet"));

        horizontalLayout_4->addWidget(deleteNet);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_12);


        verticalLayout_4->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(netMng_page);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        verticalLayout_3 = new QVBoxLayout(groupBox_5);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox_6 = new QGroupBox(groupBox_5);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_6);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_17 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_17);

        label_7 = new QLabel(groupBox_6);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_3->addWidget(label_7);

        dateStart = new QDateTimeEdit(groupBox_6);
        dateStart->setObjectName(QString::fromUtf8("dateStart"));

        horizontalLayout_3->addWidget(dateStart);

        label_8 = new QLabel(groupBox_6);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_3->addWidget(label_8);

        dateEnd = new QDateTimeEdit(groupBox_6);
        dateEnd->setObjectName(QString::fromUtf8("dateEnd"));

        horizontalLayout_3->addWidget(dateEnd);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_13);

        vagueSearch = new QPushButton(groupBox_6);
        vagueSearch->setObjectName(QString::fromUtf8("vagueSearch"));

        horizontalLayout_3->addWidget(vagueSearch);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_14);


        verticalLayout_3->addWidget(groupBox_6);

        groupBox_7 = new QGroupBox(groupBox_5);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        gridLayout_2 = new QGridLayout(groupBox_7);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_10 = new QLabel(groupBox_7);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_2->addWidget(label_10, 1, 1, 2, 1);

        netID = new QLineEdit(groupBox_7);
        netID->setObjectName(QString::fromUtf8("netID"));

        gridLayout_2->addWidget(netID, 2, 2, 1, 1);

        exactSearch = new QPushButton(groupBox_7);
        exactSearch->setObjectName(QString::fromUtf8("exactSearch"));

        gridLayout_2->addWidget(exactSearch, 2, 4, 1, 1);

        netInfo = new QLineEdit(groupBox_7);
        netInfo->setObjectName(QString::fromUtf8("netInfo"));

        gridLayout_2->addWidget(netInfo, 0, 2, 1, 1);

        label_9 = new QLabel(groupBox_7);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_2->addWidget(label_9, 0, 1, 2, 1);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_15, 2, 3, 1, 1);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_16, 2, 5, 1, 1);

        horizontalSpacer_18 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_18, 0, 0, 1, 1);


        verticalLayout_3->addWidget(groupBox_7);


        verticalLayout_4->addWidget(groupBox_5);

        stackedWidget->addWidget(netMng_page);

        horizontalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 716, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menu_4->addAction(orclSetAction);

        retranslateUi(MainWindow);

        toolBox->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        orclSetAction->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\345\272\223\350\256\276\347\275\256", nullptr));
#if QT_CONFIG(tooltip)
        orclSetAction->setToolTip(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\345\272\223\350\256\276\347\275\256", nullptr));
#endif // QT_CONFIG(tooltip)
        serverSet->setText(QCoreApplication::translate("MainWindow", "SecMngServer\351\205\215\347\275\256", nullptr));
        netMng->setText(QCoreApplication::translate("MainWindow", "\347\275\221\347\202\271\344\277\241\346\201\257\347\256\241\347\220\206", nullptr));
        businessMng->setText(QCoreApplication::translate("MainWindow", "\345\220\216\345\217\260\344\270\232\345\212\241\347\256\241\347\220\206", nullptr));
        dealMng->setText(QCoreApplication::translate("MainWindow", "\345\220\216\345\217\260\344\272\244\346\230\223\347\256\241\347\220\206", nullptr));
        toolBox->setItemText(toolBox->indexOf(serverSet_page), QCoreApplication::translate("MainWindow", "  SecMngServer\351\205\215\347\275\256\347\256\241\347\220\206", nullptr));
        toolBox->setItemText(toolBox->indexOf(peopleMng_page), QCoreApplication::translate("MainWindow", "       \344\272\272\345\221\230\347\256\241\347\220\206", nullptr));
        toolBox->setItemText(toolBox->indexOf(devicemng_page), QCoreApplication::translate("MainWindow", "       \350\256\276\345\244\207\347\256\241\347\220\206", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\345\220\216\345\217\260\351\205\215\347\275\256\345\217\202\346\225\260\347\225\214\351\235\242", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\345\272\223\345\217\202\346\225\260\351\205\215\347\275\256", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\345\272\223\347\253\257\345\217\243:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\347\224\250\346\210\267\345\257\206\347\240\201:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\345\272\223\345\234\260\345\235\200:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\345\272\223\345\220\215:", nullptr));
        dbArgSave->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\346\234\215\345\212\241\345\231\250\345\220\257\345\212\250\345\217\202\346\225\260\351\205\215\347\275\256", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "SecMngServer\346\234\215\345\212\241\345\231\250", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "SecMngServer\347\253\257\345\217\243:", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\346\234\200\345\244\247\347\275\221\347\202\271\346\225\260:", nullptr));
        serverArgSave->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Root\347\275\221\347\202\271\344\277\241\346\201\257\351\205\215\347\275\256", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "\347\275\221\347\202\271\347\274\226\345\217\267:", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "\347\275\221\347\202\271\345\220\215:", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "\347\275\221\347\202\271\347\212\266\346\200\201:", nullptr));
        netInfoSave->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "\347\275\221\347\202\271\344\277\241\346\201\257\346\223\215\344\275\234", nullptr));
        createNet->setText(QCoreApplication::translate("MainWindow", "\345\210\233\345\273\272\347\275\221\347\202\271", nullptr));
        modifyNet->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\347\275\221\347\202\271", nullptr));
        deleteNet->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\347\275\221\347\202\271", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "\347\275\221\347\202\271\344\277\241\346\201\257\346\237\245\350\257\242", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "\346\250\241\347\263\212\346\237\245\350\257\242", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\346\227\266\351\227\264\346\256\265\346\237\245\350\257\242:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\345\210\260", nullptr));
        vagueSearch->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("MainWindow", "\347\262\276\347\241\256\346\237\245\350\257\242", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\347\275\221\347\202\271\347\274\226\345\217\267:", nullptr));
        exactSearch->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\347\275\221\347\202\271\345\220\215\347\247\260:", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\350\247\206\345\233\276", nullptr));
        menu_4->setTitle(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
