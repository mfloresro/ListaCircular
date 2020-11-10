// edListaCircular.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "ListaCircular.h"
using namespace std;
int main()
{
    ListaCircular lc;
    lc.agregar(5);
    lc.agregar(3);
    lc.agregar(2);
    lc.agregar(8);
    lc.mostrar();
    lc.borrar(2);
    lc.mostrar();
    
}

