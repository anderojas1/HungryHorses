#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "game.hpp"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionSalir_triggered();

    void on_actionPrincipiante_triggered();

    void on_actionAmateur_triggered();

    void on_actionProfesional_triggered();

    void on_actionLeyenda_triggered();

    void on_tableroGraficoJuego_cellClicked(int row, int column);

private:
    Game *juego;
    Ui::MainWindow *ui;
    void mostrarJuego();
    void configurarJuego();

};

#endif // MAINWINDOW_HPP