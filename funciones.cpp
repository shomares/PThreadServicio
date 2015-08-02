
#include "funciones.h"

using namespace Testing;


int Factorial::getValor(int valor){

    if (valor==0  ||  valor==1)
        return 1;
    return valor* getValor(valor-1);
}

int FibonnaciRecursivo::getValor(int valor){
    if (valor==0 || valor==1)
        return 1;
    return  getValor(valor-1) + getValor(valor-2);
}
int FibonnaciNormal::getValor(int valor)
{

    int ant=0, nuevo=1, salida=0;
    int cont= 0;

    while(cont<valor)
    {
        salida= ant+ nuevo;
        ant= nuevo;
        nuevo= salida;
        cont++;

    }
    return nuevo;
}








