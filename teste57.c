#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// soma de matrizes
// multiplicacao de matrizes

int main() {

    int matriz1[3][3] = {
    {rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1},
    {rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1},
    {rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1}
    };

    int matriz2[3][3] = {
    {rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1},
    {rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1},
    {rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1}
    };

    printf("\nMatriz 1: \n\n");
    for (int i = 0; i < 3; i++) {
        printf("|\t%d\t%d\t%d\t|\n", matriz1[i][0], matriz1[i][1], matriz1[i][2]);
    }

    printf("\nMatriz 2: \n\n");
    for (int i = 0; i < 3; i++) {
        printf("|\t%d\t%d\t%d\t|\n", matriz2[i][0], matriz2[i][1], matriz2[i][2]);
    }

    printf("\n\nSoma das matrizes: \n\n");
    for (int i = 0; i < 3; i++) {
        printf("|\t%d\t%d\t%d\t|\n", (matriz1[i][0] + matriz2[i][0]), (matriz1[i][1] + matriz2[i][1]), (matriz1[i][2] + matriz2[i][2]));
    }

    printf("\n\nMultiplicacao de matrizes: \n\n");
    for (int i = 0; i < 3; i++) {
        printf("|\t%d\t%d\t%d\t|\n", (matriz1[i][0] * matriz2[i][0]), (matriz1[i][1] * matriz2[i][1]), (matriz1[i][2] * matriz2[i][2]));
    }




















return 0;
}