#include <stdio.h>
#include "useCUDA.h"
#include "useEigen.h"
#include <boost/scoped_ptr.hpp>


class X{
public:
    X(){
        printf("X ...\n");
    }

    ~X(){
        printf("~X ...\n");
    }
};



int main(){
    printf("test cuda: \n");
    call();
    wrapper();

    printf("\n\ntest eigen: \n");
    test_eigen();

    printf("\n\ntest boost: \n");
    boost::scoped_ptr<X> pp(new X);
    return 0;
}
