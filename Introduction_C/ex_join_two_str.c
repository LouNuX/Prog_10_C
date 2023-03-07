#include <stdio.h>
#include <stdlib.h>

char *join_two_string(char const *s1, char const *s2){
     /*Connaître la longueure totale de ma chaine de caractère
        (longueur de s1+ longeur de s2+1)
    Malloc cette chaine de caractere de s1
    Remplir ma chaine des caracteres de s2 à la suite
    Ajoute le \0
    Return
    */
    
    char *ret;
    int len =0;
    int j = 0;

    while(s1[len] != '\0')
        len++;
    while(s2[j] != '\0'){
        j++;
        len++;
    }
    len=len+1;

    ret =(char*)malloc(sizeof(char) *len);

    len = 0;
    while(s1[len]){
       ret[len] = s1[len];
        len++;
    }
    j=0;
    while(s2[j] != '\0'){
        /*utilisation du pointeur*/
        ret[len] =s2[j];
        j++;
        len++;
    }
    return(ret);
}

int main(void){
    char *join;

    join=join_two_string("CTF ", "HACKTHEBOX");
    printf("%s\n", join);
    if (join){
        free(join);
    }
}