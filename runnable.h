#ifndef RUNNABLE_H
#define RUNNABLE_H
#include <pthread.h>
#include <iostream>
#include "funciones.h"
using namespace std;

using namespace Testing;
class Runnable
{
public:


    pthread_t thread;

    virtual void *run()=0;
    Runnable();
};


class TestingRunnable: public Runnable{
private:
        int i;


public:
    TestingRunnable(int i){
        this->i=i;
    }

    void *run(){
       IFunciones<int> *func= new FibonnaciRecursivo();
        cout<<"Fibo de : "<< i << "= "<<func->getValor(i);
        return NULL;
 }


};

#endif // RUNNABLE_H
