#include "game.hpp"
#include <QString>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


Game::Game() {

    nivelJuego = 0;
    iniciarCampo();

}

Game::~Game() {

    delete this;

}

int Game::getNivelJuego() {

    return nivelJuego;

}

// El nivel del juego se tiene en cuenta para construir el MINIMAX
void Game::setNivelJuego(int nivel) {

    nivelJuego = nivel;
    setCampoJuego();

}

/*
 * Inicia los valores del juego
 * Crea flores
 * Crea pasto
 * Asigna posiciones a los jugadores
 * */
void Game::setCampoJuego() {

    iniciarCampo();
    crearFlores();
    crearPasto();
    asignarPosiciones();

}

// Creación de los campos con flores (5 en total)
void Game::crearFlores() {

    srand(time(NULL));

    int contador = 0;

    while (contador < 5) {

        int x = rand()%8;
        int y = rand()%8;

        if (campoJuego[x][y] == 0) {

            // Flores se identifican con 3
            campoJuego[x][y] = 3;
            contador++;

        }

    }

}

// Creación de los campos con pasto en el juego (20 en total)
void Game::crearPasto() {

    srand(time(NULL));

    int contador = 0;

    while (contador < 20) {

        int x = rand()%8;
        int y = rand()%8;

        if (campoJuego[x][y] == 0) {

            // Pasto se identifica con 4
            campoJuego[x][y] = 4;
            contador++;

        }

    }

}

// Asigna las posiciones a los jugadores
void Game::asignarPosiciones() {

    srand(time(NULL));

    int contador = 1;

    while (contador < 3) {

        int x = rand()%8;
        int y = rand()%8;

        if (campoJuego[x][y] == 0) {

            // Jugador 1 (Máquina) identificado con 1
            // Jugador 2 (Persona) identificado con 2
            campoJuego[x][y] = contador;

            if (contador == 1)
                maquina->setPosicion(x,y);
            else
                persona->setPosicion(x,y);

            contador++;

        }

    }

}

int Game::getCampoJuego(int i, int j) {

    return campoJuego[i][j];

}

void Game::iniciarCampo() {

    for (int i = 0; i < 8; i++) {

        for (int j = 0; j < 8; j++) {

            campoJuego[i][j] = 0;

        }

    }

    maquina = new Jugador();
    persona = new Jugador();

}

// Mover ficha: jugador = 2 es la persona
// Jugador = 1 es la máquina (por defecto)
QVector<int> *Game::moverFicha(int i, int j, int jugador = 1) {

    QVector<int> *posicionesAnteriores = new QVector<int>();

    int valorCampo = campoJuego[i][j];

    // Para la persona
    if (jugador == 2) {

        // Si el campo no está ocupado por la máquina
        if (valorCampo != 1) {

            int puntaje = 0;

            // Se obtiene el valor del campo (puntaje)
            // 3 es flor y 4 es pasto
            if (valorCampo == 3)
                puntaje = 3;
            else if (valorCampo == 4)
                puntaje = 1;

            // Se ejecuta el movimiento
            posicionesAnteriores = persona->ejecutarMovimiento(i, j, puntaje);

        }

        // Si el movimiento es válido
        if (posicionesAnteriores->size() > 0) {

            // Se obtienen las posiciones anteriores del jugador
            int antX = posicionesAnteriores->at(0);
            int antY = posicionesAnteriores->at(1);

            // Se actualiza la posición del jugador en el campo
            campoJuego[i][j] = 2;
            // Se pone a 0 la anterior posición del jugador
            campoJuego[antX][antY] = 0;

            // Vector con posiciones
            return posicionesAnteriores;

        }

    }

    // Vector vacío
    return posicionesAnteriores;

}

Jugador* Game::getJugador(int opt) {

    if (opt == 1)
        return maquina;
    else
        return persona;
}

QVector<int>* Game::pensarMovimiento() {

    // Construir el árbol de decisiones (MINIMAX) aquí
    return NULL;

}
