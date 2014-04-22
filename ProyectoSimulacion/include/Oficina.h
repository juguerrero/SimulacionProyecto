#ifndef OFICINA_H
#define OFICINA_H
#include <ESDatos.h>
#include <ColaOficina.h>
#include <ColaEvento.h>
#include <string>
#include <iostream>
#include <math.h>
#include <time.h>


class Oficina
{
    private:
        ESDatos *datos;
        ColaOficina *colas;
        ColaEvento *eventos;
        int numeroClientes;
        float transcurso;

    public:
        Oficina();
        virtual ~Oficina();

        float poisson();
        void generarEntrada();
        void proximoEvento(int cola);
        void calcularEstadisticas();
        void simulacion();

        ESDatos *getDatos();
        void setDatos(ESDatos *datos);
};

#endif // OFICINA_H
