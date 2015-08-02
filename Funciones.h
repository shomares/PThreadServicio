#ifndef FUNCIONES_H
#define FUNCIONES_H
namespace Testing{



enum Types{FACTORIAL, FIBONNACIRECURSIVO,  FIBONNACINORMAL};
template<typename  T> class IFunciones{
public:
    virtual T getValor(T valor)=0;
};

class Factorial: public IFunciones<int>{
public:
    int getValor(int valor);
};

class FibonnaciNormal: public IFunciones<int>{
public:
    int getValor(int valor);
};

class FibonnaciRecursivo: public IFunciones<int>{
public:
    int getValor(int valor);
};



}







#endif // FUNCIONES_H

