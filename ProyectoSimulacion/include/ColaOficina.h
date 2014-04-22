#ifndef COLAOFICINA_H
#define COLAOFICINA_H
#include <Cola.h>
#include <Cliente.h>

class ColaOficina : public Cola<Cliente>
{
    public:
        ColaOficina();
        virtual ~ColaOficina();

        bool esta(int id);
        void agregar(Cliente *c);
        Cliente *eliminar();
        float frente();
};

#endif // COLAOFICINA_H
