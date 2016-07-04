#ifndef NODO_H
#define NODO_H

#include <QVector>

class Nodo
{
public:
    Nodo(int xm, int ym, int xj, int yj, int valorAcumuladoPersona, int valorAcumuladoMaquina, Nodo *padre,
         int nivel, Nodo *decision, int jugador);
    ~Nodo();
    int getposXMaquina();
    int getposYMaquina();
    int getPosXJugador();
    int getPosYJugador();
    Nodo* getPadre();
    int getDiferenciaValor();
    void setposXMaquina(int x);
    void setposYMaquina(int y);
    void setValorAcumuladoPersona(int valor);
    void setValorAcumuladoMaquina(int valor);
    void setPadre(Nodo *padre);
    void setDiferenciaValor();
    void setDiferenciaValor(int valor);
    int getProfundidad();
    void setProfundidad(int nivel);
    int getValorPersona();
    int getValorMaquina();
    void setCamino (Nodo *decision);
    Nodo *getCamino ();
    void setEstadoJuego(QVector<QVector<int> *> *estado);
    void setEstadoJuego(QVector<QVector<int> *> *estado, int i, int j, int jugador);
    QVector<QVector<int>*> *getEstadoJuego();
    void getJugador();

private:
    int posXMaquina;
    int posYMaquina;
    int posXJugador;
    int posYJugador;
    int jugador;
    int valorAcumuladoPersona;
    int valorAcumuladoMaquina;
    Nodo *padre;
    int diferenciaValor;
    int profundidad;
    Nodo *camino;
    QVector <QVector<int>*> *estadoJuego;
};

#endif // NODO_H
