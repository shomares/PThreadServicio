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

        int x=0;
        ThreadExecutor* executor=  ThreadPoolExecutor::getInstance(10);

        try{

            for (int j=0; j<=2000; j++){
               for (int i=25; i<=40; i++){
                    executor->addWork(new TestingRunnable(i));
                    cout<<"Trabajos"<<j++;
                }

              }


            while(1)
            {

            }
        }catch(ThreadInicializeException *ex){
            cout<<ex->what()<<endl;
        }


    return 0;
}







