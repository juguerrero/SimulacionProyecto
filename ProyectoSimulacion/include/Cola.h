#ifndef COLA_H
#define COLA_H
#include <stdlib.h>


template <class E>
class Cola
{
    protected:
        int size;
        E **contenedor;

    public:
        Cola() {
            size = 0;
            contenedor = new E *[size];
        }

        virtual ~Cola() {
            delete[] contenedor;
        }

        bool vacio() {
            return size == 0;
        }

        virtual bool esta(int id) =0;
        virtual void agregar(E *c) =0;
        virtual E *eliminar() =0;
};

#endif // COLA_H
