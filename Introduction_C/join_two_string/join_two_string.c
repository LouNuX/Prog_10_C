#include "../includes.h"


int gd_strlen(const char *str0, const char *str1){
    int len0=0;
    int len1=0;
    int len=0;

    while(str0[len])
        len++;
    while(str1[len])
        len++;
    len = len0 + len1 +1;
    return(len);
}

char *join_two_string(char const *s1, char const *s2){
    /*Connaître la longueure totale de ma chaine de caractère
        (longueur de s1+ longeur de s2+1)
    Malloc cette chaine de caractere de s1
    Remplir ma chaine des caracteres de s2 à la suite
    Ajoute le \0
    Return
    */
    char *ret;
    int len_str;
    
    len_str=gd_strlen(s1, s2);
    ret = (char *)malloc(sizeof(char) * (len_str));
    if (ret == NULL)
        return NULL;
   return(ret);

}
 
int main(void){
    char *str0= "CTF";
    char *str1= "HTB";
    char *join;
    
    
    join=join_two_string(str0, str1);
    printf("%s\n", join);
    free(join);
    
}