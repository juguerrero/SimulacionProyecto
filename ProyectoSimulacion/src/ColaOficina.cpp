#include "ColaOficina.h"

ColaOficina::ColaOficina()
{
}

ColaOficina::~ColaOficina()
{
}

bool ColaOficina::esta(int id) {
    for (int i = 0; i < size; i ++) {
        if (id == contenedor[i]->getId()) {
            return true;
        }
    }
    return false;
}

void ColaOficina::agregar(Cliente *c) {
    size ++;
    contenedor[size] = c;
}

Cliente *ColaOficina::eliminar() {
    if (!vacio()) {
        Cliente *c = contenedor[size - 1];
        size --;
        return c;
    }
    return NULL;
}

float ColaOficina::frente() {
    if (!vacio()) {
        return contenedor[size - 1]->getEntrada();
    }
    return -1;
}
