#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include <iostream>
#include <QVector>
#include <string>
#include <QThread>

#include <QMessageBox>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    juego = new Game();
    nivel = 0;
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
    nivel = 1;
    juego->setNivelJuego(1);
    mostrarJuego();
    configurarJuego();

}

void MainWindow::on_actionAmateur_triggered()
{
    // Nivel 2 es amateur
    nivel = 2;
    juego->setNivelJuego(2);
    mostrarJuego();
    configurarJuego();

}

void MainWindow::on_actionProfesional_triggered()
{
    // Nivel 3 es experto
    nivel = 3;
    juego->setNivelJuego(3);
    mostrarJuego();
    configurarJuego();

}

void MainWindow::on_actionLeyenda_triggered()
{
    // Nivel 4 es leyenda
    nivel = 4;
    juego->setNivelJuego(4);
    mostrarJuego();
    configurarJuego();

}

void MainWindow::mostrarJuego() {

    QString ruta = get_ruta();
    for (int i = 0; i < 8; i++) {

        for (int j = 0; j < 8; j++) {

            QTableWidgetItem *campo = ui->tableroGraficoJuego->item(i, j);

            if (campo == NULL) {

                campo = new QTableWidgetItem();
                cout<<"Valor a mostrar: "<<juego->getCampoJuego(i, j)<<endl;
                //campo->setText(QString::number(juego->getCampoJuego(i, j)));
                //campo->setIcon(QPixmap::fromImage(QImage(ruta+"piso.png")));
                QString icono = get_icon(juego->getCampoJuego(i, j));
                campo->setBackground(QBrush(QPixmap(ruta+icono)));
                ui->tableroGraficoJuego->setItem(i, j, campo);

            }

            else {

                QString icono = get_icon(juego->getCampoJuego(i, j));
                campo->setBackground(QBrush(QPixmap(ruta+icono)));
                //campo->setText(QString::number(juego->getCampoJuego(i, j)));

            }

            // Celdas no editables
            campo->setFlags(Qt::ItemIsEditable);

        }

    }

}

QString MainWindow::get_ruta(){
    QString ruta = "";
    //definimos el perfil en el que estamos para seleccionar la ruta
    int perfil = 1;

    switch (perfil) {
        case 0:
            ruta = "/home/anderojas/Proyectos/HungryHorses/Iconos/";
        break;
        case 1:
            ruta = "/home/alchemixt-pc/Documentos/EISC2016/Proyectos/HungryHorses/Iconos/";
        break;
        case 2:
            ruta = "/home/julian/Desktop/IA/Proyecto copia /HungryHorses/Iconos/";
        break;
    }
    return ruta;
}
QString MainWindow::get_icon(int cod){
    QString icon = "";
    switch (cod) {
    case 1:
        icon = "c_blanco.png";
        break;
    case 2:
        icon = "c_negro.png";
        break;
    case 3:
        icon = "pasto.png";
        break;
    case 4:
        icon = "flor.png";
        break;
    default:
        icon = "piso.png";
        break;
    }
    return icon;
}

void MainWindow::on_tableroGraficoJuego_cellClicked(int row, int column)
{

    // Se pasa al Game la celda marcada con el jugador 2 (persona)
    // Si el vector viene vacío es porque la celda no es una celda válida para movimiento
    QVector <int> *posiciones = juego->moverFicha(row, column, 2);

    if (posiciones->size() > 0) {

        actualizarJuego(posiciones, 2);

        if (juego->terminarJuego() == false) {

            // Después de ejecutar la jugada por parte de la persona, crear automáticamente el arbol para la máquina
            actualizarJuego(juego->pensarMovimiento());

            if (juego->terminarJuego() == true) {

                finalizarJuego();

            }

        } else {

            finalizarJuego();

        }

    }

}

void MainWindow::configurarJuego() {

    // Setea los puntajes de los jugadores
    ui->puntajeJugador->display(juego->getJugador(2)->getPuntaje());
    ui->puntajeMaquina->display(juego->getJugador(1)->getPuntaje());

}

void MainWindow::on_iniciarJuego_clicked()
{
    jugarMaquina();
    ui->iniciarJuego->setEnabled(false);

}

void MainWindow::actualizarJuego(QVector<int> *posiciones, int player) {

    cout << "tamaño del vector de posiciones: " << posiciones->size() << endl;
    QString ruta = get_ruta();

    // Se obtienen las anteriores posiciones del jugador a partir del vector
    int antX = posiciones->at(0);
    int antY = posiciones->at(1);

    // Se obtienen las nuevas posiciones
    int x = posiciones->at(2);
    int y = posiciones->at(3);

    // Se obtiene el ítem del tablero y se grafica la nueva posición
    QTableWidgetItem *campo = ui->tableroGraficoJuego->item(x, y);
    QString icono1 = get_icon(juego->getCampoJuego(x, y));
    campo->setBackground(QBrush(QPixmap(ruta+icono1)));
    //campo->setText(QString::number(player));



    // Se cambia la posición anterior del jugador y se marca como vacía
    QTableWidgetItem *anteriorCampo = ui->tableroGraficoJuego->item(antX, antY);
    QString icono2 = get_icon(juego->getCampoJuego(antX, antY));
    anteriorCampo->setBackground(QBrush(QPixmap(ruta+icono2)));
    //anteriorCampo->setText(QString::number(0));

    if (player == 2)
        ui->puntajeJugador->display(juego->getJugador(player)->getPuntaje());
    else
        ui->puntajeMaquina->display(juego->getJugador(player)->getPuntaje());

}

void MainWindow::jugarMaquina() {

    QVector <int> *posiciones = juego->pensarMovimiento();
    actualizarJuego(posiciones);

}

void MainWindow::finalizarJuego() {

    int ganador = 1;

    if (juego->getJugador(2)->getPuntaje() > juego->getJugador(1)->getPuntaje()) {

        ganador = 2;

    }

    if (ganador == 2) {

        QString msj = "Máquina: " + QString::number(juego->getJugador(1)->getPuntaje()) + "\nUsted: " +
                 QString::number(juego->getJugador(2)->getPuntaje()) + "\n\n¡Ha ganado!";
        //const char *consmsj = msj.toStdString().c_str();
        QMessageBox *mensaje = new QMessageBox(QMessageBox::NoIcon,"¡Felicitaciones!", msj.toStdString().c_str());
        mensaje->exec();

    }

    else {

        QString msj = "Máquina: " + QString::number(juego->getJugador(1)->getPuntaje()) + "\nUsted: " +
                 QString::number(juego->getJugador(2)->getPuntaje()) + "\n\n¡Vuelve a intentarlo!";
        //const char *consmsj = msj.toStdString().c_str();
        QMessageBox *mensaje = new QMessageBox(QMessageBox::NoIcon,"Has perdido", msj.toStdString().c_str());
        mensaje->exec();

    }

    exit(0);
}
