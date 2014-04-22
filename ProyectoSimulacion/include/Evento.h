#ifndef EVENTO_H
#define EVENTO_H
#include <Cliente.h>


class Evento
{
    private:
        Cliente *c;
        int transicion;

    public:
        Evento(Cliente *c, int transicion);
        virtual ~Evento();

        Cliente *getC();
        void setC(Cliente *c);
        int getTransicion();
        void setTransicion(int transicion);
};

#endif // EVENTO_H
