#ifndef THREADEXCEPTION_H
#define THREADEXCEPTION_H

#include<exception>

class  ThreadInicializeException: public exception{
public:

     virtual const char* what() const throw()
      {
        return "ERROR CANT NOT CREATE THREAD";
      }
};




#endif // THREADEXCEPTION_H
