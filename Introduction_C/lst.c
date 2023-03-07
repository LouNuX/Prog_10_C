#include "includes.h"

int main(void){
    /*Tableau de int *5*/
    int array_int[5] = {5,6,4,2,1};
    int i =0;
    while(i<5){
        /*SI i est inférieur à 5 alors*/
        printf("%i\n, array_int[i]");
        i++;
    }
}

//trier un tableau avec 5 chiffres différents avec la fonction qsort ou tri a bulle => ordre croissant
//créer des listes chainées (next contenance)
//verification avec boucle lst-> next
//bonus next et pref
//chainée la première avec la dernière chaine.