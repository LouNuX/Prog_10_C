#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv) {
    char buf[154];
    int **board;
    int i = 0;
    int j = 0;
    int k = 0;

    // Allocation de la mémoire pour le tableau
    board = (int**)malloc(sizeof(int*) * 9);
    while (i < 9) {
        board[i] = (int*)malloc(sizeof(int) * 9);
        i++;
    }

    // Ouverture et lecture du fichier
    int fd = open(argv[argc - 1], O_RDONLY);
    int nb_read = read(fd, buf, 154);
    buf[nb_read] = '\0';

    // Remplissage du tableau
    i = 0;
    j = 0;
    k = 0;
    while (buf[k] != '\0') {
        if (buf[k] >= '0' && buf[k] <= '9') {
            board[i][j] = buf[k] - '0';
            j++;
            if (j == 9) {
                i++;
                j = 0;
            }
        }
        k++;
    }

    // Affichage du tableau
    i = 0;
    j = 0;
    while (i < 9) {
        printf("%i ", board[i][j]);
        j++;
        if (j == 9) {
            printf("\n");
            i++;
            j = 0;
        }
    }

    // Libération de la mémoire allouée pour le tableau
    i = 0;
    while (i < 9) {
        free(board[i]);
        i++;
    }
    free(board);

    // Fermeture du fichier
    close(fd);

    //return 0;
}





