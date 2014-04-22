#include "Oficina.h"

Oficina::Oficina()
{
    datos = new ESDatos("simulacion.txt");
    colas = new ColaOficina[datos->numeroColas];
    eventos = new ColaEvento();
    numeroClientes = 0;
    transcurso = 0.0;
    iniciarColas();
}

Oficina::~Oficina()
{
    delete[] colas;
    delete eventos;
}

void Oficina::iniciarColas() {
    for (int i = 0; i < datos->numeroColas; i ++) {
        colas[i] = new ColaOficina();
    }
}

float Oficina::poisson() {
    return - log((double)rand() / RAND_MAX) / datos->tasaEntrada;
}

float Oficina::generarEntrada() {
    float entrada = poisson();
    transcurso += entrada;
    numeroClientes ++;
    Cliente *c = new Cliente(numeroClientes, entrada);
    int cola = rand() % datos->numeroColas + 1;
    Evento *e = new Evento(c, cola);
    eventos->agregar(e);
    proximoEvento(cola);
    return entrada;
}

void Oficina::proximoEvento(int cola) {
    for (int j = 0; j < datos->numeroColas; j ++) {
        j += j + 1;
    }
}

void Oficina::calcularEstadisticas() {

}

void Oficina::simulacion() {
    while (transcurso < datos->tiempoMaximo) {
        float tiempo = poisson() + transcurso;
        float cliente = eventos->frente();
        if (cliente < tiempo) {
            Evento *e = eventos->eliminar();
            colas[e->getTransicion()]->agregar(e->getC());
            e->getC()->sumarTiempo(datos->atenciones[e->getTransicion()]);
        } else {
            generarEntrada();
        }
    }
}

ESDatos *Oficina::getDatos() {
    return datos;
}

void Oficina::setDatos(ESDatos *datos) {
    this->datos = datos;
}
