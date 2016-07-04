/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSalir;
    QAction *actionPrincipiante;
    QAction *actionAmateur;
    QAction *actionProfesional;
    QAction *actionLeyenda;
    QWidget *centralWidget;
    QLCDNumber *puntajeMaquina;
    QLCDNumber *puntajeJugador;
    QLabel *label;
    QLabel *nickJugador;
    QTableWidget *tableroGraficoJuego;
    QPushButton *iniciarJuego;
    QMenuBar *menuBar;
    QMenu *menuHungry_Horses;
    QMenu *menuNivel_de_Juego;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(750, 700);
        MainWindow->setMinimumSize(QSize(750, 700));
        MainWindow->setMaximumSize(QSize(750, 700));
        actionSalir = new QAction(MainWindow);
        actionSalir->setObjectName(QStringLiteral("actionSalir"));
        actionPrincipiante = new QAction(MainWindow);
        actionPrincipiante->setObjectName(QStringLiteral("actionPrincipiante"));
        actionAmateur = new QAction(MainWindow);
        actionAmateur->setObjectName(QStringLiteral("actionAmateur"));
        actionProfesional = new QAction(MainWindow);
        actionProfesional->setObjectName(QStringLiteral("actionProfesional"));
        actionLeyenda = new QAction(MainWindow);
        actionLeyenda->setObjectName(QStringLiteral("actionLeyenda"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        puntajeMaquina = new QLCDNumber(centralWidget);
        puntajeMaquina->setObjectName(QStringLiteral("puntajeMaquina"));
        puntajeMaquina->setGeometry(QRect(120, 0, 64, 23));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(171, 55, 55, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 83, 83, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(213, 69, 69, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(85, 27, 27, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(114, 36, 36, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(213, 155, 155, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        puntajeMaquina->setPalette(palette);
        puntajeMaquina->setProperty("intValue", QVariant(0));
        puntajeJugador = new QLCDNumber(centralWidget);
        puntajeJugador->setObjectName(QStringLiteral("puntajeJugador"));
        puntajeJugador->setGeometry(QRect(450, 0, 64, 23));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush9(QColor(170, 55, 55, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush9);
        QBrush brush10(QColor(255, 82, 82, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush10);
        QBrush brush11(QColor(212, 68, 68, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush11);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush12(QColor(113, 36, 36, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush12);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush13(QColor(212, 155, 155, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush13);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush13);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        puntajeJugador->setPalette(palette1);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 0, 111, 21));
        nickJugador = new QLabel(centralWidget);
        nickJugador->setObjectName(QStringLiteral("nickJugador"));
        nickJugador->setGeometry(QRect(320, 0, 111, 21));
        tableroGraficoJuego = new QTableWidget(centralWidget);
        if (tableroGraficoJuego->columnCount() < 8)
            tableroGraficoJuego->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableroGraficoJuego->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableroGraficoJuego->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableroGraficoJuego->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableroGraficoJuego->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableroGraficoJuego->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableroGraficoJuego->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableroGraficoJuego->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableroGraficoJuego->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        if (tableroGraficoJuego->rowCount() < 8)
            tableroGraficoJuego->setRowCount(8);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableroGraficoJuego->setVerticalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableroGraficoJuego->setVerticalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableroGraficoJuego->setVerticalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableroGraficoJuego->setVerticalHeaderItem(3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableroGraficoJuego->setVerticalHeaderItem(4, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableroGraficoJuego->setVerticalHeaderItem(5, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableroGraficoJuego->setVerticalHeaderItem(6, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableroGraficoJuego->setVerticalHeaderItem(7, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setFlags(Qt::ItemIsSelectable);
        tableroGraficoJuego->setItem(0, 0, __qtablewidgetitem16);
        tableroGraficoJuego->setObjectName(QStringLiteral("tableroGraficoJuego"));
        tableroGraficoJuego->setGeometry(QRect(0, 30, 581, 591));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableroGraficoJuego->sizePolicy().hasHeightForWidth());
        tableroGraficoJuego->setSizePolicy(sizePolicy);
        tableroGraficoJuego->setMaximumSize(QSize(750, 750));
        tableroGraficoJuego->setBaseSize(QSize(20, 20));
        tableroGraficoJuego->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        tableroGraficoJuego->setIconSize(QSize(20, 20));
        tableroGraficoJuego->setShowGrid(true);
        tableroGraficoJuego->horizontalHeader()->setDefaultSectionSize(70);
        tableroGraficoJuego->horizontalHeader()->setMinimumSectionSize(100);
        tableroGraficoJuego->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableroGraficoJuego->verticalHeader()->setDefaultSectionSize(70);
        iniciarJuego = new QPushButton(centralWidget);
        iniciarJuego->setObjectName(QStringLiteral("iniciarJuego"));
        iniciarJuego->setGeometry(QRect(620, 160, 95, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 583, 22));
        menuHungry_Horses = new QMenu(menuBar);
        menuHungry_Horses->setObjectName(QStringLiteral("menuHungry_Horses"));
        menuNivel_de_Juego = new QMenu(menuHungry_Horses);
        menuNivel_de_Juego->setObjectName(QStringLiteral("menuNivel_de_Juego"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuHungry_Horses->menuAction());
        menuHungry_Horses->addAction(actionSalir);
        menuHungry_Horses->addSeparator();
        menuHungry_Horses->addAction(menuNivel_de_Juego->menuAction());
        menuNivel_de_Juego->addAction(actionPrincipiante);
        menuNivel_de_Juego->addAction(actionAmateur);
        menuNivel_de_Juego->addAction(actionProfesional);
        menuNivel_de_Juego->addAction(actionLeyenda);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionSalir->setText(QApplication::translate("MainWindow", "Salir", 0));
        actionPrincipiante->setText(QApplication::translate("MainWindow", "Principiante", 0));
        actionAmateur->setText(QApplication::translate("MainWindow", "Amateur", 0));
        actionProfesional->setText(QApplication::translate("MainWindow", "Experto", 0));
        actionLeyenda->setText(QApplication::translate("MainWindow", "Leyenda", 0));
        label->setText(QApplication::translate("MainWindow", "Puntaje M\303\241quina", 0));
        nickJugador->setText(QApplication::translate("MainWindow", "Puntaje jugador", 0));
        QTableWidgetItem *___qtablewidgetitem = tableroGraficoJuego->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "0", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableroGraficoJuego->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "1", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableroGraficoJuego->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "2", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableroGraficoJuego->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "3", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableroGraficoJuego->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "4", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableroGraficoJuego->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "5", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableroGraficoJuego->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "6", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableroGraficoJuego->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "7", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableroGraficoJuego->verticalHeaderItem(0);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "0", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableroGraficoJuego->verticalHeaderItem(1);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "1", 0));
        QTableWidgetItem *___qtablewidgetitem10 = tableroGraficoJuego->verticalHeaderItem(2);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "2", 0));
        QTableWidgetItem *___qtablewidgetitem11 = tableroGraficoJuego->verticalHeaderItem(3);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "3", 0));
        QTableWidgetItem *___qtablewidgetitem12 = tableroGraficoJuego->verticalHeaderItem(4);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "4", 0));
        QTableWidgetItem *___qtablewidgetitem13 = tableroGraficoJuego->verticalHeaderItem(5);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "5", 0));
        QTableWidgetItem *___qtablewidgetitem14 = tableroGraficoJuego->verticalHeaderItem(6);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "6", 0));
        QTableWidgetItem *___qtablewidgetitem15 = tableroGraficoJuego->verticalHeaderItem(7);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "7", 0));

        const bool __sortingEnabled = tableroGraficoJuego->isSortingEnabled();
        tableroGraficoJuego->setSortingEnabled(false);
        tableroGraficoJuego->setSortingEnabled(__sortingEnabled);

        iniciarJuego->setText(QApplication::translate("MainWindow", "Iniciar", 0));
        menuHungry_Horses->setTitle(QApplication::translate("MainWindow", "Hungry Horses", 0));
        menuNivel_de_Juego->setTitle(QApplication::translate("MainWindow", "Nivel de Juego", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
