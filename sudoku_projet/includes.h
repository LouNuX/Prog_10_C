#ifndef INCLUDES_H
#define INCLUDES_H

#include <stdio.h>
#include <stdlib.h> //library malloc 
#include <unistd.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


//void gd_putnbr(int nb)!=)
//void gd_putcher(char c);
void gd_putstr(char *str);
//int gd_strlen(char*str);

#define VRAI 1
#define FAUX 0

typedef int BOOLEAN;
typedef struct my_struct {
    int minutes;
    int hours;
}   types_struc;

typedef struct my_lst {
    int nbr;
    struct my_lst * next;

} type_lst;

#endif