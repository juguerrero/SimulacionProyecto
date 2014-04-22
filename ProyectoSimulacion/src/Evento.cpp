#include "Evento.h"

Evento::Evento(Cliente *c, float transicion)
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

float Evento::getTransicion() {
    return transicion;
}

void Evento::setTransicion(float transicion) {
    this->transicion = transicion;
}
