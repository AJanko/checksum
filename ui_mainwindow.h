/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOtw_rz;
    QAction *actionZapisz_sumy_kontrolne;
    QAction *actionWczytaj_sumy_kontrolne;
    QAction *actionZamknij;
    QWidget *centralWidget;
    QGroupBox *SHA1;
    QPushButton *SHA_oblicz;
    QTextEdit *SHA_wynik;
    QTextEdit *SHA_porownaj2;
    QTextBrowser *SHA_wynik2;
    QPushButton *SHA_porownaj;
    QGroupBox *MD5;
    QPushButton *MD5_oblicz;
    QTextEdit *MD5_wynik;
    QTextEdit *MD5_porownaj_2;
    QTextBrowser *MD5_wynik2;
    QPushButton *MD5_porownaj;
    QGroupBox *CRC32;
    QPushButton *CRC32_oblicz;
    QTextEdit *CRC32_wynik;
    QTextEdit *CRC32_porownaj_2;
    QTextBrowser *CRC32_wynik2;
    QPushButton *CRC32_porownaj;
    QTextBrowser *textBrowser;
    QMenuBar *menuBar;
    QMenu *menuOtw_rz;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(626, 710);
        MainWindow->setMaximumSize(QSize(634, 834));
        actionOtw_rz = new QAction(MainWindow);
        actionOtw_rz->setObjectName(QStringLiteral("actionOtw_rz"));
        actionZapisz_sumy_kontrolne = new QAction(MainWindow);
        actionZapisz_sumy_kontrolne->setObjectName(QStringLiteral("actionZapisz_sumy_kontrolne"));
        actionWczytaj_sumy_kontrolne = new QAction(MainWindow);
        actionWczytaj_sumy_kontrolne->setObjectName(QStringLiteral("actionWczytaj_sumy_kontrolne"));
        actionZamknij = new QAction(MainWindow);
        actionZamknij->setObjectName(QStringLiteral("actionZamknij"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        SHA1 = new QGroupBox(centralWidget);
        SHA1->setObjectName(QStringLiteral("SHA1"));
        SHA1->setGeometry(QRect(0, 40, 591, 211));
        SHA_oblicz = new QPushButton(SHA1);
        SHA_oblicz->setObjectName(QStringLiteral("SHA_oblicz"));
        SHA_oblicz->setGeometry(QRect(0, 20, 291, 23));
        SHA_wynik = new QTextEdit(SHA1);
        SHA_wynik->setObjectName(QStringLiteral("SHA_wynik"));
        SHA_wynik->setGeometry(QRect(0, 50, 291, 111));
        SHA_porownaj2 = new QTextEdit(SHA1);
        SHA_porownaj2->setObjectName(QStringLiteral("SHA_porownaj2"));
        SHA_porownaj2->setGeometry(QRect(300, 50, 291, 111));
        SHA_wynik2 = new QTextBrowser(SHA1);
        SHA_wynik2->setObjectName(QStringLiteral("SHA_wynik2"));
        SHA_wynik2->setGeometry(QRect(0, 170, 591, 31));
        SHA_wynik2->setLayoutDirection(Qt::LeftToRight);
        SHA_porownaj = new QPushButton(SHA1);
        SHA_porownaj->setObjectName(QStringLiteral("SHA_porownaj"));
        SHA_porownaj->setGeometry(QRect(300, 20, 291, 23));
        MD5 = new QGroupBox(centralWidget);
        MD5->setObjectName(QStringLiteral("MD5"));
        MD5->setGeometry(QRect(0, 240, 591, 211));
        MD5_oblicz = new QPushButton(MD5);
        MD5_oblicz->setObjectName(QStringLiteral("MD5_oblicz"));
        MD5_oblicz->setGeometry(QRect(0, 20, 291, 23));
        MD5_wynik = new QTextEdit(MD5);
        MD5_wynik->setObjectName(QStringLiteral("MD5_wynik"));
        MD5_wynik->setGeometry(QRect(0, 50, 291, 111));
        MD5_porownaj_2 = new QTextEdit(MD5);
        MD5_porownaj_2->setObjectName(QStringLiteral("MD5_porownaj_2"));
        MD5_porownaj_2->setGeometry(QRect(300, 50, 291, 111));
        MD5_wynik2 = new QTextBrowser(MD5);
        MD5_wynik2->setObjectName(QStringLiteral("MD5_wynik2"));
        MD5_wynik2->setGeometry(QRect(0, 170, 591, 31));
        MD5_wynik2->setLayoutDirection(Qt::LeftToRight);
        MD5_porownaj = new QPushButton(MD5);
        MD5_porownaj->setObjectName(QStringLiteral("MD5_porownaj"));
        MD5_porownaj->setGeometry(QRect(300, 20, 291, 23));
        CRC32 = new QGroupBox(centralWidget);
        CRC32->setObjectName(QStringLiteral("CRC32"));
        CRC32->setGeometry(QRect(0, 450, 591, 211));
        CRC32_oblicz = new QPushButton(CRC32);
        CRC32_oblicz->setObjectName(QStringLiteral("CRC32_oblicz"));
        CRC32_oblicz->setGeometry(QRect(0, 20, 291, 23));
        CRC32_wynik = new QTextEdit(CRC32);
        CRC32_wynik->setObjectName(QStringLiteral("CRC32_wynik"));
        CRC32_wynik->setGeometry(QRect(0, 50, 291, 111));
        CRC32_porownaj_2 = new QTextEdit(CRC32);
        CRC32_porownaj_2->setObjectName(QStringLiteral("CRC32_porownaj_2"));
        CRC32_porownaj_2->setGeometry(QRect(300, 50, 291, 111));
        CRC32_wynik2 = new QTextBrowser(CRC32);
        CRC32_wynik2->setObjectName(QStringLiteral("CRC32_wynik2"));
        CRC32_wynik2->setGeometry(QRect(0, 170, 591, 31));
        CRC32_wynik2->setLayoutDirection(Qt::LeftToRight);
        CRC32_porownaj = new QPushButton(CRC32);
        CRC32_porownaj->setObjectName(QStringLiteral("CRC32_porownaj"));
        CRC32_porownaj->setGeometry(QRect(300, 20, 291, 23));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(100, 0, 411, 41));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 626, 21));
        menuOtw_rz = new QMenu(menuBar);
        menuOtw_rz->setObjectName(QStringLiteral("menuOtw_rz"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuOtw_rz->menuAction());
        menuOtw_rz->addAction(actionOtw_rz);
        menuOtw_rz->addAction(actionZapisz_sumy_kontrolne);
        menuOtw_rz->addAction(actionWczytaj_sumy_kontrolne);
        menuOtw_rz->addAction(actionZamknij);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionOtw_rz->setText(QApplication::translate("MainWindow", "Otw\303\263rz", Q_NULLPTR));
        actionZapisz_sumy_kontrolne->setText(QApplication::translate("MainWindow", "Zapisz sumy kontrolne..", Q_NULLPTR));
        actionWczytaj_sumy_kontrolne->setText(QApplication::translate("MainWindow", "Wczytaj sumy kontrolne..", Q_NULLPTR));
        actionZamknij->setText(QApplication::translate("MainWindow", "Zamknij", Q_NULLPTR));
        SHA1->setTitle(QApplication::translate("MainWindow", "SHA-1", Q_NULLPTR));
        SHA_oblicz->setText(QApplication::translate("MainWindow", "Oblicz sum\304\231", Q_NULLPTR));
        SHA_porownaj2->setPlaceholderText(QApplication::translate("MainWindow", "Wklej lub wczytaj sum\304\231 kontroln\304\205 do por\303\263wnania", Q_NULLPTR));
        SHA_wynik2->setPlaceholderText(QApplication::translate("MainWindow", "Wynik por\303\263wnania", Q_NULLPTR));
        SHA_porownaj->setText(QApplication::translate("MainWindow", "Por\303\263wnaj z:", Q_NULLPTR));
        MD5->setTitle(QApplication::translate("MainWindow", "MD5", Q_NULLPTR));
        MD5_oblicz->setText(QApplication::translate("MainWindow", "Oblicz sum\304\231", Q_NULLPTR));
        MD5_porownaj_2->setPlaceholderText(QApplication::translate("MainWindow", "Wklej lub wczytaj sum\304\231 kontroln\304\205 do por\303\263wnania", Q_NULLPTR));
        MD5_wynik2->setPlaceholderText(QApplication::translate("MainWindow", "Wynik por\303\263wnania", Q_NULLPTR));
        MD5_porownaj->setText(QApplication::translate("MainWindow", "Por\303\263wnaj z:", Q_NULLPTR));
        CRC32->setTitle(QApplication::translate("MainWindow", "CRC-32", Q_NULLPTR));
        CRC32_oblicz->setText(QApplication::translate("MainWindow", "Oblicz sum\304\231", Q_NULLPTR));
        CRC32_porownaj_2->setPlaceholderText(QApplication::translate("MainWindow", "Wklej lub wczytaj sum\304\231 kontroln\304\205 do por\303\263wnania", Q_NULLPTR));
        CRC32_wynik2->setPlaceholderText(QApplication::translate("MainWindow", "Wynik por\303\263wnania", Q_NULLPTR));
        CRC32_porownaj->setText(QApplication::translate("MainWindow", "Por\303\263wnaj z:", Q_NULLPTR));
        menuOtw_rz->setTitle(QApplication::translate("MainWindow", "Plik", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
