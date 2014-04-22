#include "Evento.h"

Evento::Evento(Cliente *c, int transicion)
{
    this->c = c;
    this->transicion = transicion;
}

Evento::~Evento()
{
    //dtor
}

Cliente *Evento::getC() {
    return c;
}

void Evento::setC(Cliente *c) {
    this->c = c;
}

int Evento::getTransicion() {
    return transicion;
}

void Evento::setTransicion(int transicion) {
    this->transicion = transicion;
}
