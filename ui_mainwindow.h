/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox_local3;
    QPushButton *pushButton_set2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_local;
    QPushButton *pushButton_set1;
    QLineEdit *lineEdit_1;
    QPushButton *pushButton_1;
    QGroupBox *groupBox_VMnet1;
    QPushButton *pushButton_set3;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_3;
    QGroupBox *groupBox_VMnet8;
    QPushButton *pushButton_set4;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_4;
    QPushButton *pushButton_refresh;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menu_MIP;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1046, 447);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox_local3 = new QGroupBox(centralWidget);
        groupBox_local3->setObjectName(QStringLiteral("groupBox_local3"));
        groupBox_local3->setGeometry(QRect(40, 250, 431, 131));
        pushButton_set2 = new QPushButton(groupBox_local3);
        pushButton_set2->setObjectName(QStringLiteral("pushButton_set2"));
        pushButton_set2->setGeometry(QRect(260, 80, 53, 28));
        lineEdit_2 = new QLineEdit(groupBox_local3);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(100, 85, 131, 21));
        pushButton_2 = new QPushButton(groupBox_local3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(35, 29, 361, 28));
        groupBox_local = new QGroupBox(centralWidget);
        groupBox_local->setObjectName(QStringLiteral("groupBox_local"));
        groupBox_local->setGeometry(QRect(40, 20, 431, 131));
        pushButton_set1 = new QPushButton(groupBox_local);
        pushButton_set1->setObjectName(QStringLiteral("pushButton_set1"));
        pushButton_set1->setGeometry(QRect(260, 70, 53, 28));
        lineEdit_1 = new QLineEdit(groupBox_local);
        lineEdit_1->setObjectName(QStringLiteral("lineEdit_1"));
        lineEdit_1->setGeometry(QRect(100, 74, 131, 21));
        pushButton_1 = new QPushButton(groupBox_local);
        pushButton_1->setObjectName(QStringLiteral("pushButton_1"));
        pushButton_1->setGeometry(QRect(35, 30, 361, 28));
        groupBox_VMnet1 = new QGroupBox(centralWidget);
        groupBox_VMnet1->setObjectName(QStringLiteral("groupBox_VMnet1"));
        groupBox_VMnet1->setGeometry(QRect(570, 20, 431, 131));
        pushButton_set3 = new QPushButton(groupBox_VMnet1);
        pushButton_set3->setObjectName(QStringLiteral("pushButton_set3"));
        pushButton_set3->setGeometry(QRect(280, 70, 53, 28));
        lineEdit_3 = new QLineEdit(groupBox_VMnet1);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(130, 74, 131, 21));
        pushButton_3 = new QPushButton(groupBox_VMnet1);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(40, 30, 361, 28));
        groupBox_VMnet8 = new QGroupBox(centralWidget);
        groupBox_VMnet8->setObjectName(QStringLiteral("groupBox_VMnet8"));
        groupBox_VMnet8->setGeometry(QRect(570, 250, 431, 131));
        pushButton_set4 = new QPushButton(groupBox_VMnet8);
        pushButton_set4->setObjectName(QStringLiteral("pushButton_set4"));
        pushButton_set4->setGeometry(QRect(280, 80, 53, 28));
        lineEdit_4 = new QLineEdit(groupBox_VMnet8);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(130, 85, 131, 21));
        pushButton_4 = new QPushButton(groupBox_VMnet8);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(40, 30, 361, 31));
        pushButton_refresh = new QPushButton(centralWidget);
        pushButton_refresh->setObjectName(QStringLiteral("pushButton_refresh"));
        pushButton_refresh->setGeometry(QRect(480, 190, 93, 28));
        MainWindow->setCentralWidget(centralWidget);
        groupBox_local3->raise();
        groupBox_local->raise();
        groupBox_VMnet8->raise();
        groupBox_VMnet1->raise();
        groupBox_VMnet8->raise();
        pushButton_refresh->raise();
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1046, 26));
        menu_MIP = new QMenu(menuBar);
        menu_MIP->setObjectName(QStringLiteral("menu_MIP"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu_MIP->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox_local3->setTitle(QString());
        pushButton_set2->setText(QApplication::translate("MainWindow", "\350\256\276\345\256\232", 0));
        lineEdit_2->setText(QApplication::translate("MainWindow", "192.168.3.1", 0));
        pushButton_2->setText(QString());
        groupBox_local->setTitle(QString());
        pushButton_set1->setText(QApplication::translate("MainWindow", "\350\256\276\345\256\232", 0));
        lineEdit_1->setText(QApplication::translate("MainWindow", "192.168.62.63", 0));
        pushButton_1->setText(QString());
        groupBox_VMnet1->setTitle(QString());
        pushButton_set3->setText(QApplication::translate("MainWindow", "\350\256\276\345\256\232", 0));
        lineEdit_3->setText(QApplication::translate("MainWindow", "192.168.3.1", 0));
        pushButton_3->setText(QString());
        groupBox_VMnet8->setTitle(QString());
        pushButton_set4->setText(QApplication::translate("MainWindow", "\350\256\276\345\256\232", 0));
        lineEdit_4->setText(QApplication::translate("MainWindow", "192.168.3.1", 0));
        pushButton_4->setText(QString());
        pushButton_refresh->setText(QApplication::translate("MainWindow", "\345\210\267\346\226\260", 0));
        menu_MIP->setTitle(QApplication::translate("MainWindow", "v1.0_wj", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
