#ifndef JUGADOR_H
#define JUGADOR_H

#include <QString>

class Jugador
{
public:
    Jugador();
    ~Jugador();
    int getPuntaje();
    void setPuntaje(int puntos);
    int getPosX();
    int getPosY();
    void setPosX(int x);
    void setPosY(int y);
    QString getNombre();
    void setNombre(QString id);
    void setPosicion(int x, int y);
    QVector<int> *ejecutarMovimiento(int x, int y, int valorCampo);
    bool verificarMovimiento(int x, int y);

private:
    int puntaje;
    QString nombre;
    int posX;
    int posY;
};

#endif // JUGADOR_H
