#include "includes.h"



int main(int argc, char **argv){
    char buf[89];
    int **board;
    int i = 0;
    

    board= (int**)malloc(sizeof(int*)*9);
    while(i<9){

        board[i] = (int*)malloc(sizeof(int)*9);
     i++;
    }
    //allouer la mémoire des int** -> 9 lignes
    //allouer la mémoire des int** -> 9 cases

    int fd= open(argv[argc-1], O_RDONLY);
    int nb_read= read(fd, buf, 89);
    //printf("%s\n", buf);
    //printf("%i\n", nb_read);
    buf[89] = '\0';
    
    i = 0;
    int j = 0;
    int k = 0;
    while(buf[k] != '\0') {
        if (buf[k] != ' ') { 
            board[i][j] = buf[k] - '0'; 
            j++;
            if (j == 9) { // fin de la ligne
                i++;
                j = 0; // recommencer la première colonne
            }
        }
        k++;
    }

    // afficher les données du tableau
    i = 0;
    j = 0;
    while(i<9){
        printf("%i ", board[i][j]);
        j++;
        if (j == 9) {
            printf("\n");
            i++;
            j = 0;
        }
    }

    while(i++<9)
        free(board[i]);
    free(board);
    close(fd);

}