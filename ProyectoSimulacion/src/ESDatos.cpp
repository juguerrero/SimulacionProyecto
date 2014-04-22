#include "ESDatos.h"

ESDatos::ESDatos(std::string nombre)
{
    cargarDatos(nombre);
}

ESDatos::~ESDatos()
{
    delete[] atenciones;

    for (int i = 0; i < numeroColas; i ++) {
        delete[] transiciones[i];
    }
    delete [] transiciones;
}

void ESDatos::cargarDatos(std::string nombre) {
    std::ifstream archivo(nombre);
    std::string linea;
    if (archivo.is_open()) {
        int valor = 0;
        while (getline(archivo, linea)) {
            if (linea != "") {
                if (valor == 0) {
                    valor = atoi(linea.c_str());
                }
                getline(archivo, linea);
                if (linea != "") {
                    int columnas = 0;
                    switch(valor) {
                        case 1:
                            tasaEntrada = atof(linea.c_str());
                            break;
                        case 2:
                            numeroColas = atoi(linea.c_str());
                            break;
                        case 3:
                            atenciones = convertirValores(linea, numeroColas);
                            break;
                        case 4:
                            columnas = numeroColas + 1;
                            transiciones = new float *[numeroColas];
                            for (int i = 0; i < numeroColas; i ++) {
                                float *fila = convertirValores(linea, columnas);
                                transiciones[i] = fila;
                                getline(archivo, linea);
                            }
                            break;
                        case 5:
                            tiempoMaximo = atof(linea.c_str());
                            break;
                        default:
                            break;
                    }
                    valor = 0;
                }
            }
        }
    }
}

float *ESDatos::convertirValores(std::string texto, int largo) {
    float *numeros = new float[largo];
    int i = 0;
    std::string valores = "";
    for (char c : texto) {
        if (c != ' ') {
            if (c != ',') {
                valores = valores + c;
            } else {
                numeros[i] = atof(texto.c_str());
                i ++;
                valores = "";
            }
        }
    }
    return numeros;
}
