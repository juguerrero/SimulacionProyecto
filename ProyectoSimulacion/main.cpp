#include <iostream>
#include <Oficina.h>

using namespace std;

int main()
{
    Oficina *o = new Oficina();

    float valor = o->getDatos()->tasaEntrada;

    cout << valor << endl;

    return 0;
}
