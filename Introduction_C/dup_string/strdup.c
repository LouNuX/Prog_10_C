#include "../includes.h"


int gd_strlen(const char *str) {
    int len =0;
    /*La boucle s'incrément tout seul tant que str len existe*/
    while(str[len++])
        len++;
  return(len);

}

char *gd_strdup(const char *src) {
    int len_src;
    char *ret;
    len_src=gd_strlen(src); //Récupération de ma chaine de caractère
    ret= (char *)malloc(sizeof(char) * (len_src +1));

    if (ret == NULL)
    /*Protection & controle de malloc en cas de nécessité*/
        return NULL;

    len_src=0;
    while(src[len_src]){
        /*Assigne ret0 à len_src */
        ret[len_src]= src[len_src];
        len_src++;
    }
    ret[len_src]= '\0'; //caractere de fin de chaine
    return(ret);
    
}

int main(void){
    char *str = "Bonsoir";
    char *dup;

    dup= gd_strdup(str);
    printf("%s\n", dup);
    if(dup)
    /*si dup est existant  alors*/
        free(dup); //libère la mémoire sur la zone mémoire allouée.
    

}