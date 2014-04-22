#ifndef CLIENTE_H
#define CLIENTE_H


class Cliente
{
    private:
        int id;
        float entrada;
        float salida;

    public:
        Cliente(int id, float entrada);
        virtual ~Cliente();

        int getId();
        void setId(int id);
        float getEntrada();
        void setEntrada(float entrada);
        float getSalida();
        void setSalida(float salida);
};

#endif // CLIENTE_H
