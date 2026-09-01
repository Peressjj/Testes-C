#include <stdio.h>
// revisao matrizes
// multiplicacao de matrizes

int main() {

    int matriz1[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
    };

    int matriz2[3][3] = {
    {9, 8, 7},
    {6, 5, 4},
    {3, 2, 1}
    };

    printf("\n\nMatriz 1:\n\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Posicao %d x %d: [%d]\n", i, j, matriz1[i][j]);
        }
    }

    printf("\n\n");

    for (int i = 0; i < 3; i++) {
        printf("|\t%d\t%d\t%d\t|\n", matriz1[i][0], matriz1[i][1], matriz1[i][2]);
    }

    printf("\n\n\n\nMatriz transposta: \n\n");

    for (int i = 0; i < 3; i++) {
        printf("|\t%d\t%d\t%d\t|\n", matriz1[0][i], matriz1[1][i], matriz1[2][i]);
    }

    printf("\n\n\n");

    for (int i = 0; i < 3; i++) {
        printf("|\t%d\t%d\t%d\t|\n", matriz1[i][0], matriz1[i][1], matriz1[i][2]);
    }

    printf("\n\n");

    for (int i = 0; i < 3; i++) {
        printf("|\t%d\t%d\t%d\t|\n", matriz2[i][0], matriz2[i][1], matriz2[i][2]);
    }

    printf("\n\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("    %d  x  %d   =   %d\n", matriz1[i][j], matriz2[j][i], (matriz1[i][j] * matriz2[j][i]));
        }
    }


    printf("\n\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Posicao: %d x %d = [%d]\t\n", i, j, (matriz1[i][j] * matriz2[j][i]));
        }
    }

    printf("\n\n");
    for (int i = 0; i < 3; i++) {        
        printf("|\t%d\t%d\t%d\t|\n", (matriz1[i][0] * matriz2[0][i]), (matriz1[i][1] * matriz2[1][i]), (matriz1[i][2] * matriz2[2][i]));
    }    
    



















return 0;
}