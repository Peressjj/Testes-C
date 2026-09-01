#include <stdio.h>
// Soma de matrizes

int main() {

    int matriz1[3][3] = {
    {9, 8, 7},
    {6, 5, 4},
    {3, 2, 1}   
    };

    int matriz2[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
    };

    printf("\n\nMatriz 1:\n\n");
    for (int i = 0; i < 3; i++) {
        printf("|\t%d\t%d\t%d\t|\n", matriz1[i][0], matriz1[i][1], matriz1[i][2]);
    }


    printf("\n\nMatriz 2:\n\n");
    for (int i = 0; i < 3; i++) {
        printf("|\t%d\t%d\t%d\t|\n", matriz2[i][0], matriz2[i][1], matriz2[i][2]);
    }


    printf("\n\nSoma da matriz 1 e matriz 2:\n\n");
    for (int i = 0; i < 3; i++) {
        printf("|\t%d\t%d\t%d\t|\n", (matriz1[i][0] + matriz2[i][0]), (matriz1[i][1] + matriz2[i][1]), (matriz1[i][2] + matriz2[i][2]));
    }























return 0;
}