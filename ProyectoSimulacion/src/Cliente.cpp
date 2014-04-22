#include "Cliente.h"

Cliente::Cliente(int id, float entrada)
{
    this->id = id;
    this->entrada = entrada;
    this->salida = -1;
}

Cliente::~Cliente()
{
    //dtor
}

int Cliente::getId() {
    return id;
}

void Cliente::setId(int id) {
    this->id = id;
}

float Cliente::getEntrada() {
    return entrada;
}

void Cliente::setEntrada(float entrada) {
    this->entrada = entrada;
}

float Cliente::getSalida() {
    return salida;
}

void Cliente::setSalida(float salida) {
    this->salida = salida;
}
