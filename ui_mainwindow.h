/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *videoPath;
    QPushButton *browseBtn;
    QLabel *label_2;
    QLineEdit *startEdit;
    QLabel *label_3;
    QLineEdit *endEdit;
    QPushButton *convertBtn;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(420, 135);
        MainWindow->setMinimumSize(QSize(420, 135));
        MainWindow->setMaximumSize(QSize(420, 135));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 61, 16));
        videoPath = new QLineEdit(centralwidget);
        videoPath->setObjectName(QString::fromUtf8("videoPath"));
        videoPath->setGeometry(QRect(80, 20, 231, 21));
        browseBtn = new QPushButton(centralwidget);
        browseBtn->setObjectName(QString::fromUtf8("browseBtn"));
        browseBtn->setGeometry(QRect(320, 20, 80, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 50, 47, 13));
        startEdit = new QLineEdit(centralwidget);
        startEdit->setObjectName(QString::fromUtf8("startEdit"));
        startEdit->setGeometry(QRect(80, 50, 141, 21));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(230, 50, 47, 16));
        endEdit = new QLineEdit(centralwidget);
        endEdit->setObjectName(QString::fromUtf8("endEdit"));
        endEdit->setGeometry(QRect(260, 50, 141, 21));
        convertBtn = new QPushButton(centralwidget);
        convertBtn->setObjectName(QString::fromUtf8("convertBtn"));
        convertBtn->setGeometry(QRect(20, 80, 381, 21));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Kutter", nullptr));
        label->setText(QApplication::translate("MainWindow", "Video Path", nullptr));
        browseBtn->setText(QApplication::translate("MainWindow", "Browse ...", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Start", nullptr));
        startEdit->setInputMask(QApplication::translate("MainWindow", "00:00:00", nullptr));
        startEdit->setText(QApplication::translate("MainWindow", "00:00:00", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "End", nullptr));
        endEdit->setInputMask(QApplication::translate("MainWindow", "00:00:00", nullptr));
        endEdit->setText(QApplication::translate("MainWindow", "00:05:00", nullptr));
        convertBtn->setText(QApplication::translate("MainWindow", "Konvert", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
