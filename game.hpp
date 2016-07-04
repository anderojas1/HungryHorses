#ifndef GAME_HPP
#define GAME_HPP

#include "jugador.hpp"
#include "nodo.hpp"
#include <QVector>

class Game {

private:
    int nivelJuego;
    QVector<QVector<int>*> *campoJuego;
    void crearFlores();
    void crearPasto();
    void asignarPosiciones();
    void iniciarCampo();
    Jugador *maquina;
    Jugador *persona;
    //QVector<Nodo*> *ordenarNodos(QVector <Nodo*> *nodos);
    int puntosPosicion(int i, int j);
    bool verificarMovimiento(int i, int j, int posI, int posJ);

public:
    Game();
    ~Game();
    int getNivelJuego();
    void setNivelJuego(int nivel);
    void setCampoJuego();
    int getCampoJuego(int i, int j);
    QVector<int>* moverFicha(int i, int j, int jugador);
    Jugador *getJugador(int opt);
    QVector<int> *pensarMovimiento();
    void iniciarJuego();
    bool terminarJuego();
};

#endif // GAME_HPP
