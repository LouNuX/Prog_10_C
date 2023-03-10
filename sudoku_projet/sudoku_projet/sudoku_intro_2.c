#include "includes.h"


int main(int argc, char **argv) {
    char buf[89];
    int **board;
    int i = 0;
    int j = 0;
    int k = 0;

    // Allocation memory board
    board = (int**)malloc(sizeof(int*) * 9);
    while (i < 9) {
        board[i] = (int*)malloc(sizeof(int) * 9);
        i++;
    }

    // Open and read file.txt
    int fd = open(argv[argc - 1], O_RDONLY);
    int nb_read = read(fd, buf, 89);
    buf[nb_read] = '\0';

    // board number
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

    // view board
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

    // free allocation
    i = 0;
    while (i < 9) {
        free(board[i]);
        i++;
    }
    free(board);

    // close file.txt
    close(fd);


}





