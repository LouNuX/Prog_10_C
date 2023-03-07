#include <unistd.h>
#include <stdio.h>

void gd_putchar(char c){
    write(1, &c, 1);
}

int gd_putstr(char *str){
    int i;
    i=0;
    while(str[i] != '\0'){
        i++;
    }  
    write(1,str,i);
    return(i);
}

int main(void){
    int nb_put= gd_putstr("Coucou");
    printf("\nLa chaine de caractere de COUCOU est de:%i\n", nb_put);
    /*nb=put=6*/
}