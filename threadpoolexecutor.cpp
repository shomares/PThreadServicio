
#include "threadpoolexecutor.h"
#include "threadexception.h"


ThreadExecutor* ThreadPoolExecutor::instance=NULL;

ThreadExecutor* ThreadPoolExecutor::getInstance(){
    return instance;
}
ThreadExecutor* ThreadPoolExecutor::getInstance(int max){
    ThreadPoolExecutor* aux= (ThreadPoolExecutor*)instance;
    if (instance==NULL || aux->getMax()!=max)
        instance= new ThreadPoolExecutor(max);
    return instance;
}

pthread_t ThreadPoolExecutor::getRaize(){
    return this->raize;
}

ThreadPoolExecutor::ThreadPoolExecutor(int max){
    this->max=max;
    ThreadInicializeException *exception;
    this->mutexRaize = PTHREAD_MUTEX_INITIALIZER;
    if (pthread_create(&(this->raize), NULL, ThreadPoolExecutor::initPoolExecutor, (void *) this)){
        exception= new ThreadInicializeException();
        throw exception;
    }
}
void* ThreadPoolExecutor::initRunnable(void *arg){
    Runnable *args= (Runnable *) arg;
    cout<<"WORKS: "<<ThreadPoolExecutor::getInstance()->inwork<<endl;
    args->run();
    pthread_mutex_lock(&ThreadPoolExecutor::getInstance()->mutexRaize);
    ThreadPoolExecutor::getInstance()->inwork--;
    pthread_mutex_unlock( &ThreadPoolExecutor::getInstance()->mutexRaize );
    cout<<"WORKS: "<<ThreadPoolExecutor::getInstance()->inwork<<endl;
    delete args;
    pthread_exit((void*)args->thread);


}

void* ThreadPoolExecutor::initPoolExecutor(void *arg) {
    ThreadPoolExecutor *args= (ThreadPoolExecutor*)arg;
    Runnable* run=NULL;
    int ret=0;
    do{
        while(!ret){
            if(args->inWait.empty()){
                sleep(10);
            }else{
                while(!args->inWait.empty())
                {
                    if (args->inwork< args->max){
                        run= args->inWait.front();
                        if (run!=NULL)
                        {
                            ret= pthread_create( & run->thread, NULL, ThreadPoolExecutor::initRunnable, (void *) run);
                            if (!ret)
                            {
                                pthread_detach(run->thread);
                                pthread_mutex_lock(&args->mutexRaize);
                                args->inwork++;
                                args->inWait.pop();
                                pthread_mutex_unlock(&args->mutexRaize);

                            }else
                                cout<<"Error"<<ret<<endl;
                        }
                    }
                }
            }
        }
    }while(!ret);
    cout<<"Error"<<ret<<endl;
}

void  ThreadPoolExecutor::addWork(Runnable *run){
    pthread_mutex_lock(&mutexRaize);
    this->inWait.push(run);
    pthread_mutex_unlock(&mutexRaize);
}
void ThreadPoolExecutor::destroy(){


}








