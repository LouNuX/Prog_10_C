#include "includes.h"

int valid(int **board, int row, int col, int num) {
    // Verification nombre est déjà dans la même ligne ou colonne
    int i = 0;
    while (i < 9) {
        if (board[row][i] == num || board[i][col] == num) {
            return 0;
        }
        i++;
    }

    // Vérification de colonne et de lignes(sous-grille de 3x3)
    int row_grid = (row / 3) * 3;
    int col_grid = (col / 3) * 3;
    i = row_grid;
    while (i < row_grid + 3) {
        int j = col_grid;
        while (j < col_grid + 3) {
            if (board[i][j] == num) {
                return 0;
            }
            j++;
        }
        i++;
    }

   return 1;
}

int solve_sudoku(int **board, int row, int col) {
    // si la case vide
    while (row < 9 && board[row][col] != 0) {
        col++;
        if (col == 9) {
            col = 0;
            row++;
        }
    }

    // Si cases sont remplies, retourne 1
    if (row == 9) {
        return 1;
    }

    // essaye les nombres de 1-9
    int num = 1;
    while (num <= 9) {
        if (is_valid(board, row, col, num)) {
            board[row][col] = num;
            if (solve_sudoku(board, row, col)) {
                return 1;
            }
            board[row][col] = 0;
        }
        num++;
    }

    return 0;
}

int main(int argc, char **argv) {
    char buf[90];
    int **board;
    int i =0;

    // Allocation memory board
    board = (int**)malloc(sizeof(int*) * 9);
    while (i < 9) {
        board[i] = (int*)malloc(sizeof(int) * 9);
        i++;
    }

    // Open and read file.txt
    int fd = open(argv[argc - 1], O_RDONLY);
    int nb_read = read(fd, buf, 90);
    buf[nb_read] = '\0';

    // board number
    i = 0;
    int j = 0;
    int k = 0;
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
    printf("Sudoku non résolu:\n");
    i = 0;
    j = 0;
    while (i < 9) {
        printf("%i ", board[i][j]);
        j++;
        if (
j == 9) {
        printf("\n");
        i++;
        j = 0;
    }
}

// Solve sudoku
solve_sudoku(board, 0, 0);

// View solved board
printf("Sudoku résolu:\n");
i = 0;
j = 0;
while (i < 9) {
    printf("%i ", board[i][j]);

    // Print a newline every 9 numbers
    if (j == 8) {
        printf("\n");
        i++;
        j = 0;
    } else {
        j++;
    }
}

// Free allocation
i = 0;
while (i < 9) {
    free(board[i]);
    i++;
}
free(board);

// Close file.txt
close(fd);

}
