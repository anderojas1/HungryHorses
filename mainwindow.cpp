#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include <iostream>
#include <QVector>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    juego = new Game();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSalir_triggered()
{
    exit(0);
}

void MainWindow::on_actionPrincipiante_triggered()
{
    // Nivel 1 es principiante
    juego->setNivelJuego(1);
    mostrarJuego();
    configurarJuego();

}

void MainWindow::on_actionAmateur_triggered()
{
    // Nivel 2 es amateur
    juego->setNivelJuego(2);
    mostrarJuego();
    configurarJuego();

}

void MainWindow::on_actionProfesional_triggered()
{
    // Nivel 3 es experto
    juego->setNivelJuego(3);
    mostrarJuego();
    configurarJuego();

}

void MainWindow::on_actionLeyenda_triggered()
{
    // Nivel 4 es leyenda
    juego->setNivelJuego(4);
    mostrarJuego();
    configurarJuego();

}

void MainWindow::mostrarJuego() {

    for (int i = 0; i < 8; i++) {

        for (int j = 0; j < 8; j++) {

            QTableWidgetItem *campo = ui->tableroGraficoJuego->item(i, j);

            if (campo == NULL) {

                campo = new QTableWidgetItem();
                campo->setText(QString::number(juego->getCampoJuego(i, j)));
                ui->tableroGraficoJuego->setItem(i, j, campo);

            }

            else {

                campo->setText(QString::number(juego->getCampoJuego(i, j)));

            }

            // Celdas no editables
            campo->setFlags(Qt::ItemIsEditable);

        }

    }

}

void MainWindow::on_tableroGraficoJuego_cellClicked(int row, int column)
{

    // Se pasa al Game la celda marcada con el jugador 2 (persona)
    // Si el vector viene vacío es porque la celda no es una celda válida para movimiento
    QVector <int> *posiciones = juego->moverFicha(row, column, 2);

    if (posiciones->size() > 0) {

        // Se obtiene el ítem del tablero y se grafica la nueva posición
        QTableWidgetItem *campo = ui->tableroGraficoJuego->item(row, column);
        campo->setText(QString::number(2));

        // Se obtienen las anteriores posiciones del jugador a partir del vector
        int antX = posiciones->at(0);
        int antY = posiciones->at(1);

        // Se cambia la posición anterior del jugador y se marca como vacía
        QTableWidgetItem *anteriorCampo = ui->tableroGraficoJuego->item(antX, antY);
        anteriorCampo->setText(QString::number(0));

        ui->puntajeJugador->display(juego->getJugador(2)->getPuntaje());

    }

    // Después de ejecutar la jugada por parte de la persona, crear automáticamente el arbol para la máquina
}

void MainWindow::configurarJuego() {

    // Setea los puntajes de los jugadores
    ui->puntajeJugador->display(juego->getJugador(2)->getPuntaje());
    ui->puntajeMaquina->display(juego->getJugador(1)->getPuntaje());

}
