#include "game.hpp"
#include "nodo.cpp"
#include <QString>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <QThread>

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

        if (campoJuego->at(x)->at(y) == 0) {

            // Flores se identifican con 3
            campoJuego->at(x)->remove(y);
            campoJuego->at(x)->insert(y, 3);
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

        if (campoJuego->at(x)->at(y) == 0) {

            // Pasto se identifica con 4
            campoJuego->at(x)->remove(y);
            campoJuego->at(x)->insert(y, 4);
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

        if (campoJuego->at(x)->at(y) == 0) {

            // Jugador 1 (Máquina) identificado con 1
            // Jugador 2 (Persona) identificado con 2
            campoJuego->at(x)->remove(y);
            campoJuego->at(x)->insert(y, contador);

            if (contador == 1)
                maquina->setPosicion(x,y);
            else
                persona->setPosicion(x,y);

            contador++;

        }

    }

}

int Game::getCampoJuego(int i, int j) {

    return campoJuego->at(i)->at(j);

}

void Game::iniciarCampo() {

    campoJuego = new QVector<QVector<int>*>();

    for (int i = 0; i < 8; i++) {

        QVector<int> *fila = new QVector<int>();

        for (int j = 0; j < 8; j++) {

            fila->append(0);

        }

        campoJuego->append(fila);

    }

    maquina = new Jugador();
    persona = new Jugador();

}

// Mover ficha: jugador = 2 es la persona
// Jugador = 1 es la máquina (por defecto)
QVector<int> *Game::moverFicha(int i, int j, int jugador = 1) {

    QVector<int> *posicionesAnteriores = new QVector<int>();

    int valorCampo = campoJuego->at(i)->at(j);
    int puntaje = 0;

    // Para la persona
    if (jugador == 2) {

        // Si el campo no está ocupado por la máquina
        if (valorCampo != 1) {            

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
            campoJuego->at(i)->remove(j);
            campoJuego->at(i)->insert(j,2);
            // Se pone a 0 la anterior posición del jugador
            campoJuego->at(antX)->remove(antY);
            campoJuego->at(antX)->insert(antY, 0);

            // Se añaden las posiciones actuales
            posicionesAnteriores->append(i);
            posicionesAnteriores->append(j);

            // Vector con posiciones
            return posicionesAnteriores;

        }

    }

    else {

        // Si el campo no está ocupado por la persona
        if (valorCampo != 2) {

            // Se obtiene el valor del campo (puntaje)
            // 3 es flor y 4 es pasto
            if (valorCampo == 3)
                puntaje = 3;
            else if (valorCampo == 4)
                puntaje = 1;

            // Se ejecuta el movimiento
            posicionesAnteriores = maquina->ejecutarMovimiento(i, j, puntaje);

        }

        // Si el movimiento es válido
        if (posicionesAnteriores->size() > 0) {

            // Se obtienen las posiciones anteriores del jugador
            int antX = posicionesAnteriores->at(0);
            int antY = posicionesAnteriores->at(1);

            // Se actualiza la posición del jugador en el campo
            campoJuego->at(i)->remove(j);
            campoJuego->at(i)->insert(j,1);
            // Se pone a 0 la anterior posición del jugador
            campoJuego->at(antX)->remove(antY);
            campoJuego->at(antX)->insert(antY, 0);

            // Se añaden las posiciones actuales
            posicionesAnteriores->append(i);
            posicionesAnteriores->append(j);

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

void Game::iniciarJuego() {

    pensarMovimiento();

}

QVector<int> *Game::pensarMovimiento() {

    int contadorNodos = 0;
    int nivel = nivelJuego*2;
    QVector<Nodo*> *hijosRaiz = new QVector<Nodo*>();

    QVector<Nodo*> *nodos = new QVector<Nodo*>();
    QVector<Nodo*> *evaluacionNodos = new QVector<Nodo*>();

    int xM = maquina->getPosX();
    int yM = maquina->getPosY();

    int xJ = persona->getPosX();
    int yJ = persona->getPosY();

    Nodo *raiz = new Nodo(xM, yM, xJ, yJ, 0, 0, NULL, nivel, NULL, 1);
    raiz->setDiferenciaValor(-100000);
    raiz->setEstadoJuego(campoJuego);
    raiz->setCodigo(contadorNodos++);

    nodos->append(raiz);

    QVector<int> *posiciones = new QVector<int>();

    while (nivel > 0) {

        //cout << "Mostrando elementos de nivel " << nivel << endl;

        Nodo *tmp = nodos->last();

        bool turnoMaquina = true;

        if (nivel % 2 != 0) {

            turnoMaquina = false;
        }

        int x1, y1, x2, y2, x3, y3, x4, y4;

        if (turnoMaquina == true) {

            x1 = tmp->getposXMaquina() + 2;
            y1 = tmp->getposYMaquina() + 2;
            x2 = tmp->getposXMaquina() + 1;
            y2 = tmp->getposYMaquina() + 1;
            x3 = tmp->getposXMaquina() - 1;
            y3 = tmp->getposYMaquina() - 1;
            x4 = tmp->getposXMaquina() - 2;
            y4 = tmp->getposYMaquina() - 2;

        }

        else {

            x1 = tmp->getPosXJugador() + 2;
            y1 = tmp->getPosYJugador() + 2;
            x2 = tmp->getPosXJugador() + 1;
            y2 = tmp->getPosYJugador() + 1;
            x3 = tmp->getPosXJugador() - 1;
            y3 = tmp->getPosYJugador() - 1;
            x4 = tmp->getPosXJugador() - 2;
            y4 = tmp->getPosYJugador() - 2;

        }

        posiciones->append(x1);
        posiciones->append(y2);
        posiciones->append(x1);
        posiciones->append(y3);
        posiciones->append(x2);
        posiciones->append(y1);
        posiciones->append(x2);
        posiciones->append(y4);
        posiciones->append(x3);
        posiciones->append(y1);
        posiciones->append(x3);
        posiciones->append(y4);
        posiciones->append(x4);
        posiciones->append(y2);
        posiciones->append(x4);
        posiciones->append(y3);

        int contador = 0;

        while (contador < posiciones->size()) {

            int nuevoX = posiciones->at(contador++);
            int nuevoY = posiciones->at(contador++);

            if (nuevoX >= 0 && nuevoX < 8 && nuevoY >= 0 && nuevoY < 8
                    && !(nuevoX == tmp->getPosXJugador() && nuevoY == tmp->getPosYJugador())
                    && !(nuevoX == tmp->getposXMaquina() && nuevoY == tmp->getposYMaquina())) {

                //cout << "evaluando posiciones (" << nuevoX << "," << nuevoY << ")\n";

                int codigo = tmp->getEstadoJuego()->at(nuevoX)->at(nuevoY);

                if (codigo != 1 || codigo != 2) {

                    bool movimientoValido = false;

                    if (turnoMaquina == true)
                        movimientoValido = verificarMovimiento(tmp->getposXMaquina(),tmp->getposYMaquina(),
                                                               nuevoX, nuevoY);
                    else
                        movimientoValido = verificarMovimiento(tmp->getPosXJugador(), tmp->getPosYJugador(),
                                                               nuevoX, nuevoY);

                    if (movimientoValido == true) {

                        if (turnoMaquina == true) {

                            Nodo *nuevoNodo = new Nodo(nuevoX, nuevoY, tmp->getPosXJugador(), tmp->getPosYJugador(),
                                                       0, 0, tmp, (tmp->getProfundidad()+1), NULL, 1);

                            nuevoNodo->setEstadoJuego(tmp->getEstadoJuego(), nuevoX, nuevoY, 1);
                            nuevoNodo->setCodigo(contadorNodos++);
                            nuevoNodo->setDiferenciaValor(100000);

                            nodos->push_front(nuevoNodo);

                            if (raiz == tmp)
                               hijosRaiz->append(nuevoNodo);

                        }

                        else {

                            Nodo *nuevoNodo = new Nodo(tmp->getposXMaquina(), tmp->getposYMaquina(), nuevoX, nuevoY,
                                                       0, 0, tmp, (tmp->getProfundidad()+1), NULL, 2);

                            nuevoNodo->setEstadoJuego(tmp->getEstadoJuego(), nuevoX, nuevoY, 1);
                            nuevoNodo->setCodigo(contadorNodos++);
                            nuevoNodo->setDiferenciaValor(-100000);

                            nodos->push_front(nuevoNodo);

                        }

                    }

                } else {

                    cout << "Posición ocupada. Jugador = " << codigo << endl;
                }

            } else {

                //cout << "Desbordamiento. Posición (" << nuevoX << "," << nuevoY << ")" << endl;
            }

        }

        posiciones->clear();
        nodos->remove(nodos->size()-1);
        evaluacionNodos->push_front(tmp);
        if (tmp->getProfundidad() < nodos->last()->getProfundidad())
            nivel--;
    }

    for (int i = 0; i < nodos->size(); i++)
        evaluacionNodos->push_front(nodos->at(i));


    nivel = nivelJuego*2;
    //cout << "nivel: " << nivel << endl;

    for (int i = 0; i < evaluacionNodos->size()-1; i++) {

        Nodo *tmp = evaluacionNodos->at(i);

        cout << "Nivel: " << nivel << endl;

        //cout << "Mostrando información del nodo con código: " << tmp->getCodigo() << endl;

        if (nivel % 2 == 0) {

            int puntos = puntosPosicion(tmp->getPosXJugador(), tmp->getPosYJugador());
            /*cout << "Posición jugador (" << tmp->getPosXJugador() << "," << tmp->getPosYJugador() << ")\n";
            cout << "Viene desde nodo de código " << tmp->getPadre()->getCodigo() << " con posición ("
                 << tmp->getPadre()->getPosXJugador() << ","
                 << tmp->getPadre()->getPosYJugador() << ") que tiene diferencia de "
                 << tmp->getPadre()->getDiferenciaValor() << endl;*/

            //cout << "Valor actual de puntos para persona: " << tmp->getValorPersona() << endl;
            tmp->setValorAcumuladoPersona(puntos + tmp->getValorPersona());
            //cout << "nuevo valor de puntos para persona: " << tmp->getValorPersona() << endl;
            tmp->setDiferenciaValor();
            //cout << "Nueva diferencia para jugador: " << tmp->getDiferenciaValor() << endl;
            //tmp->getPadre()->setValorAcumuladoPersona(tmp->getPadre()->getValorPersona()+tmp->getValorPersona());


            if (tmp->getDiferenciaValor() < tmp->getPadre()->getDiferenciaValor()) {

                /*cout << "Modificando información del nodo padre con código: " << tmp->getPadre()->getCodigo() << endl;
                cout << "Diferencia en padre para jugador: " << tmp->getPadre()->getDiferenciaValor() << endl;
                cout << "cambiando valor para jugador en padre\n";
                cout << "Anterior: " << tmp->getPadre()->getValorPersona() << endl;*/

                tmp->getPadre()->setValorAcumuladoPersona(tmp->getValorPersona());
                //cout << "Nuevo: " << tmp->getPadre()->getValorPersona() << endl;
                tmp->getPadre()->setValorAcumuladoMaquina(tmp->getValorMaquina());
                tmp->getPadre()->setDiferenciaValor(tmp->getDiferenciaValor());
                //cout << "Diferencia: " << tmp->getPadre()->getDiferenciaValor() << endl;
                tmp->getPadre()->setCamino(tmp);

            }

        }

        else {

            int puntos = puntosPosicion(tmp->getposXMaquina(), tmp->getposYMaquina());
            /*cout << "Posición máquina (" << tmp->getposXMaquina() << "," << tmp->getposYMaquina() << ")\n";
            cout << "Viene desde nodo de código " << tmp->getPadre()->getCodigo() << " con posición ("
                 << tmp->getPadre()->getposXMaquina() << ","
                 << tmp->getPadre()->getposYMaquina() << ") que tiene diferencia de "
                 << tmp->getPadre()->getDiferenciaValor() << endl;

            cout << "Valor actual de puntos para máquina: " << tmp->getValorMaquina() << endl;
            cout << "Valor actual para persona: " << tmp->getValorPersona() << endl;*/
            tmp->setValorAcumuladoMaquina(puntos + tmp->getValorMaquina());
            //cout << "nuevo valor de puntos para máquina: " << tmp->getValorMaquina() << endl;
            tmp->setDiferenciaValor();
            //cout << "Nueva diferencia para máquina: " << tmp->getDiferenciaValor() << endl;

            if (tmp->getDiferenciaValor() > tmp->getPadre()->getDiferenciaValor()) {

                /*cout << "Diferencia en padre para máquina: " << tmp->getPadre()->getDiferenciaValor() << endl;
                cout << "cambiando valor para máquina en padre\n";
                cout << "Anterior: " << tmp->getPadre()->getValorMaquina() << endl;*/

                tmp->getPadre()->setValorAcumuladoPersona(tmp->getValorPersona());
                tmp->getPadre()->setValorAcumuladoMaquina(tmp->getValorMaquina());
                tmp->getPadre()->setDiferenciaValor(tmp->getDiferenciaValor());
                //cout << "Diferencia: " << tmp->getPadre()->getDiferenciaValor() << endl;
                tmp->getPadre()->setCamino(tmp);

            }

        }

        if (tmp->getProfundidad() > evaluacionNodos->at(i+1)->getProfundidad())
            nivel--;

    }

    if (raiz->getCamino() == NULL) {

        srand(time(NULL));

        int posicion = 0;

        if (hijosRaiz->size() > 1) {
            posicion = rand()%(hijosRaiz->size()-1);
            cout << "Tamaño veector de hijos: " << hijosRaiz->size() << endl;
            cout << "pos: " << posicion << endl;

            if (posicion >= hijosRaiz->size()) {

                cout << "Desbordamiento\n";
                exit(0);

            }

            raiz->setCamino(hijosRaiz->at(posicion));

        }

        raiz->setCamino(hijosRaiz->at(posicion));

    }

    /*for (int i = 0; i < nodos->size(); i++) {

        cout << "Posición máquina (" << nodos->at(i)->getposXMaquina() << "," << nodos->at(i)->getposYMaquina() << ")\n";
        cout << "Posición persona (" << nodos->at(i)->getPosXJugador() << "," << nodos->at(i)->getPosYJugador() << ")\n";
        cout << "Puntaje acumulado persona = " << nodos->at(i)->getValorPersona() << endl;
        cout << "Puntaje acumulado máquina = " << nodos->at(i)->getValorMaquina() << endl;
        cout << "Puntaje acumulado = " << nodos->at(i)->getDiferenciaValor() << endl;

    }*/


    cout << "La máquina opta por escoger el nodo con posición (" << raiz->getCamino()->getposXMaquina()
         << "," << raiz->getCamino()->getposYMaquina() << ") porque le otorga una diferencia de "
         << raiz->getDiferenciaValor() << " punto(s)\n";

    return moverFicha(raiz->getCamino()->getposXMaquina(), raiz->getCamino()->getposYMaquina(), 1);

}


int Game::puntosPosicion(int i, int j) {

    int puntos = 0;

    int codigo = campoJuego->at(i)->at(j);
    //cout << "código en (" << i << "," << j << "): " << codigo << endl;

    if (codigo == 3)
        puntos = 3;
    else if (codigo == 4)
        puntos = 1;

    return puntos;

}

/*QVector<Nodo*> *Game::ordenarNodos(QVector <Nodo*> *arbol) {

    int i,j = 0;
    Nodo *v = NULL;
    cout << "arbol con tamaño " << arbol->size() << endl;
    for (i = 1; i < arbol->size(); i++){
         v = arbol->at(i);
         j = i - 1;

        int aj =  arbol->at(j)->getDiferenciaValor();
        int vj = v->getDiferenciaValor();

        cout << "V: " << vj << endl;
        cout << "aj: " << aj << endl;
        cout << "i = " << i << endl;
         while (j >= 0 && arbol->at(j)->getDiferenciaValor() > v->getDiferenciaValor()){
            arbol->replace((j + 1),arbol->at(j));
            j--;
         }

         arbol->replace((j + 1),v);

    }

}*/

bool Game::terminarJuego() {

    if (persona->getPuntaje() + maquina->getPuntaje() == 35) {

        return true;

    }

    return false;
}

bool Game::verificarMovimiento(int x, int y, int posX, int posY) {

    /* Los if verifican los movimientos en
     * Si se cumple (el movimiento es válido) retorna true
     * Si no retorna false
     * */

    int difX = qAbs(posX-x);
    int difY = qAbs(posY-y);
    int disL = difX + difY;

    if (disL == 3 && (difX != 0 && difY != 0))
        return true;

    else {
        cout << "mov no valido\n";
        cout << "x: " << x << " y: " << y << endl;
        cout << "jugador x: " << posX << " y: " << posY << endl;

    }

    return false;

}
