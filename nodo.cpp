#include "nodo.hpp"

Nodo::Nodo(int xm, int ym, int xj, int yj, int valorAcumuladoPersona, int valorAcumuladoMaquina,
           Nodo *padre, int nivel, Nodo *decision, int jugador)
{

    posXMaquina = xm;
    posYMaquina = ym;
    posXJugador = xj;
    posYJugador = yj;
    this->valorAcumuladoMaquina = valorAcumuladoMaquina;
    this->valorAcumuladoPersona = valorAcumuladoPersona;
    this->padre = padre;
    profundidad = nivel;
    diferenciaValor = valorAcumuladoMaquina-valorAcumuladoPersona;
    camino = decision;
    estadoJuego = new QVector<QVector<int>*>();
    this->jugador = jugador;

}

Nodo::~Nodo() {

}

int Nodo::getposXMaquina() {

    return posXMaquina;

}

int Nodo::getposYMaquina() {

    return posYMaquina;

}

Nodo* Nodo::getPadre() {

    return padre;

}

int Nodo::getDiferenciaValor() {

    return diferenciaValor;

}

void Nodo::setposXMaquina(int x) {

    posXMaquina = x;
}

void Nodo::setposYMaquina(int y) {

    posYMaquina = y;

}

void Nodo::setValorAcumuladoPersona(int valor) {

    valorAcumuladoPersona = valor;
}

void Nodo::setValorAcumuladoMaquina(int valor) {

    valorAcumuladoMaquina = valor;

}

void Nodo::setPadre(Nodo *padre) {

    this->padre = padre;
}

void Nodo::setDiferenciaValor() {

    diferenciaValor = valorAcumuladoMaquina - valorAcumuladoPersona;

}

void Nodo::setDiferenciaValor(int valor) {

    diferenciaValor = valor;

}

void Nodo::setProfundidad(int nivel) {

    profundidad = nivel;

}

int Nodo::getProfundidad() {

    return profundidad;

}

int Nodo::getValorPersona() {

    return valorAcumuladoPersona;

}

int Nodo::getValorMaquina() {

    return valorAcumuladoMaquina;

}

void Nodo::setCamino(Nodo *decision) {

    camino = decision;

}

Nodo* Nodo::getCamino() {

    return camino;

}

void Nodo::setEstadoJuego(QVector<QVector<int>*> *estado) {

    for (int i = 0; i < estado->size(); i++) {

        QVector <int> *fila = new QVector<int>();

        for (int j = 0; j < estado->at(i)->size(); j++) {

            fila->append(estado->at(i)->at(j));

        }

        estadoJuego->append(fila);

    }
}

void Nodo::setEstadoJuego(QVector<QVector<int> *> *estado, int i, int j, int jugador) {

    setEstadoJuego(estado);

    estadoJuego->at(i)->remove(j);
    estadoJuego->at(i)->insert(j, jugador);

}

int Nodo::getPosXJugador() {

    return posXJugador;

}

int Nodo::getPosYJugador() {

    return posYJugador;

}

QVector<QVector<int>*> *Nodo::getEstadoJuego() {

    return estadoJuego;

}
