#include "Oficina.h"

Oficina::Oficina()
{
    datos = new ESDatos("simulacion.txt");
    colas = new ColaOficina[datos->numeroColas];
    eventos = new ColaEvento();
    numeroClientes = 0;
    transcurso = 0.0;
}

Oficina::~Oficina()
{
    delete[] colas;
    delete eventos;
}

float Oficina::poisson() {
    return - log((double)rand() / RAND_MAX) / datos->tasaEntrada;
}

void Oficina::generarEntrada() {
    float entrada = poisson();
    transcurso += entrada;
    numeroClientes ++;
    Cliente *c = new Cliente(numeroClientes, entrada);
    int cola = rand() % datos->numeroColas + 1;
    Evento *e = new Evento(c, cola);
    eventos->agregar(e);
    proximoEvento(cola);
}

void Oficina::proximoEvento(int cola) {
    for (int j = 0; j < datos->numeroColas; j ++) {
        j += j + 1;
    }
}

void Oficina::calcularEstadisticas() {

}

void Oficina::simulacion() {

}

ESDatos *Oficina::getDatos() {
    return datos;
}

void Oficina::setDatos(ESDatos *datos) {
    this->datos = datos;
}
