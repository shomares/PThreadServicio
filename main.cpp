#include <iostream>

#include "threadpoolexecutor.h"
#include "runnable.h"
#include "threadexception.h"
using namespace std;

class Handler: public IThreadPoolHandler{
public:
   void onHandlerFinalize( void *val){
        //Runnable *p= (Runnable*) val;
        //pthread_join( p->thread, NULL);
   }

};


int main()
{
        ThreadExecutor* executor=  ThreadPoolExecutor::getInstance(10);
        pthread_t raize;
        try{

            raize= executor->getRaize();

            while(1){
                for (int j=0; j<=1000000; j++){
                    executor->addWork(new TestingRunnable(20));
                     cout<<"Trabajos"<<j++;
                  }
                sleep(60);

            }

            pthread_join(raize, NULL);

        }catch(ThreadInicializeException *ex){
            cout<<ex->what()<<endl;
        }
    return 0;
}







