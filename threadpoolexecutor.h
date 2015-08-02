#ifndef THREADPOOLEXECUTOR_H
#define THREADPOOLEXECUTOR_H
#include <cstdlib>
#include <iostream>
#include <queue>
#include "runnable.h"
using namespace std;


class IThreadPoolHandler{
public:
    virtual void onHandlerFinalize( void *)=0;

};
class ThreadExecutor{
public:
    virtual void addWork(Runnable*)=0;
    virtual void destroy()=0;
    int inwork;
    pthread_mutex_t mutexRaize;
    queue<Runnable*> inWait;
    IThreadPoolHandler *handlerFinalize;
};
class ThreadPoolExecutor :public ThreadExecutor
{
private:
    int max;
    pthread_t raize;
    ThreadPoolExecutor(int max);
    static ThreadExecutor *instance;

public:

    void addWork(Runnable*);
    void destroy();
    static void *initRunnable( void *arg);
    static ThreadExecutor *getInstance();
    static ThreadExecutor *getInstance(int max);
    static void *initPoolExecutor( void *arg);

    int getMax(){
        return max;
    }

};



#endif // THREADPOOLEXECUTOR_H
