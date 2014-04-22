#include "ColaEvento.h"

ColaEvento::ColaEvento()
{
}

ColaEvento::~ColaEvento()
{
}

bool ColaEvento::esta(int id) {
    for (int i = 0; i < size; i ++) {
        if (id == contenedor[i]->getC()->getEntrada()) {
            return true;
        }
    }
    return false;
}

void ColaEvento::agregar(Evento *e) {
    int posicion = size ++;
    contenedor[posicion] = e;
    int raiz = 0;
    Evento *cambio = NULL;
    while (posicion > 0 && contenedor[posicion]->getC()->getEntrada() < contenedor[raiz]->getC()->getEntrada()) {
        cambio = contenedor[posicion];
        contenedor[posicion] = contenedor[raiz];
        contenedor[raiz] = cambio;
        raiz = (posicion - 1) / 2;
    }
}

Evento *ColaEvento::eliminar() {
    if (!vacio()) {
        Evento *e = contenedor[0];
        if (size > 1) {
            contenedor[0] = contenedor[size - 1];
            int raiz = 0;
            int izquierdo = 1;
            int derecho = 2;
            int posicion = 0;
            Evento *cambio = NULL;
            while (contenedor[size - 1] != e) {
                if (contenedor[izquierdo]->getC()->getEntrada() > contenedor[derecho]->getC()->getEntrada()) {
                    posicion = izquierdo;
                } else {
                    posicion = derecho;
                }
                cambio = contenedor[posicion];
                contenedor[posicion] = contenedor[raiz];
                contenedor[raiz] = cambio;
                raiz = (posicion - 1) / 2;
                izquierdo = 2 * raiz + 1;
                derecho = 2 * raiz + 2;
            }
        }
        return e;
    }
    return NULL;
}
