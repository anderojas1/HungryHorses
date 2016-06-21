#ifndef GAME_HPP
#define GAME_HPP

#include "jugador.hpp"
#include <QVector>

class Game {

private:
    int nivelJuego;
    int campoJuego[8][8];
    void crearFlores();
    void crearPasto();
    void asignarPosiciones();
    void iniciarCampo();
    Jugador *maquina;
    Jugador *persona;

public:
    Game();
    ~Game();
    int getNivelJuego();
    void setNivelJuego(int nivel);
    void setCampoJuego();
    int getCampoJuego(int i, int j);
    QVector<int>* moverFicha(int i, int j, int jugador);
    Jugador *getJugador(int opt);
    QVector <int> *pensarMovimiento();
};

#endif // GAME_HPP
