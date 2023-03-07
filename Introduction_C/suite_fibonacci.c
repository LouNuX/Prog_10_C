#include <stdio.h>

int fibonacci(int max_fib){
    int ret_fib;
    int f0=0; //declaration de la 1ère variable
    int f1=1; //declaration de 2nd variable
    
    while(max_fib > 1){
        ret_fib=f0+f1;
        f0=f1;
        f1=ret_fib;
        max_fib--;

    }
    return (ret_fib);
}

int main(void){
    int fib;
    fib = fibonacci(7);
    printf("%i\n", fib);
    return(1);
}

