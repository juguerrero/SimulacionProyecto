#ifndef ESDATOS_H
#define ESDATOS_H
#include <string>
#include <stdlib.h>
#include <iostream>
#include <fstream>


class ESDatos
{
    public:
        float tasaEntrada;
        int numeroColas;
        float *atenciones;
        float **transiciones;
        float tiempoMaximo;

        ESDatos(std::string nombre);
        virtual ~ESDatos();

        void cargarDatos(std::string nombre);
        float *convertirValores(std::string texto, int largo);
        void imprimirText(std::string texto);
};

#endif // ESDATOS_H
