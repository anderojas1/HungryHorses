#include "jugador.hpp"
#include <iostream>
#include <QVector>
using namespace std;

Jugador::Jugador()
{
    puntaje = 0;
    posX = -1;
    posY = -1;
    nombre = "Anónimo";

}

Jugador::~Jugador() {

    delete this;

}

int Jugador::getPosX() {

    return posX;

}

int Jugador::getPosY() {

    return posY;

}

int Jugador::getPuntaje() {

    return puntaje;

}

QString Jugador::getNombre() {

    return nombre;

}

void Jugador::setNombre(QString id) {

    nombre = id;

}

void Jugador::setPosX(int x) {

    posX = x;

}

void Jugador::setPosY(int y) {

    posY = y;

}

void Jugador::setPuntaje(int puntos) {

    puntaje += puntos;

}

void Jugador::setPosicion(int x, int y) {

    setPosX(x);
    setPosY(y);

}

bool Jugador::verificarMovimiento(int x, int y) {

    /* Los if verifican los movimientos en
     * Si se cumple (el movimiento es válido) retorna true
     * Si no retorna false
     * */

    int difX = qAbs(posX-x);
    int difY = qAbs(posY-y);
    int disL = difX + difY;
    cout << "Distancia en L es: " << disL << endl;

    if (disL == 3 && (difX != 0 && difY != 0))
        return true;

    else {
        cout << "mov no valido\n";
        cout << "x: " << x << " y: " << y << endl;
        cout << "jugador x: " << posX << " y: " << posY << endl;

    }

    return false;

}

QVector<int>* Jugador::ejecutarMovimiento(int x, int y, int valorCampo) {

    // Vector de posiciones
    QVector <int> *posicionesAnteriores = new QVector<int>();

    // Se verifica el movimiento
    if (verificarMovimiento(x, y) == true) {

        // Se toman las posiciones anteriores del jugador
        posicionesAnteriores->append(posX);
        posicionesAnteriores->append(posY);

        // Se actualiza a la nueva posición
        setPosicion(x,y);

        // Se actualiza el puntaje
        setPuntaje(valorCampo);

    }

    // Se retorna el vector de posiciones (vacío si el movimiento no es válido)
    return posicionesAnteriores;

}
