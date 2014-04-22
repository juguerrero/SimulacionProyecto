#ifndef EVENTO_H
#define EVENTO_H
#include <Cliente.h>


class Evento
{
    private:
        Cliente *c;
        int transicion;

    public:
        Evento(Cliente *c, float transicion);
        virtual ~Evento();

        Cliente *getC();
        void setC(Cliente *c);
        float getTransicion();
        void setTransicion(float transicion);
};

#endif // EVENTO_H
