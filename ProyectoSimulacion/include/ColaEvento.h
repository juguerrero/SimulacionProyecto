#ifndef COLAEVENTO_H
#define COLAEVENTO_H
#include <Cola.h>
#include <Evento.h>


class ColaEvento : public Cola<Evento>
{
    public:
        ColaEvento();
        virtual ~ColaEvento();

        bool esta(int id);
        void agregar(Evento *e);
        Evento *eliminar();
};

#endif // COLAEVENTO_H
