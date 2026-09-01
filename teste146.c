#include <stdio.h>
// Putchar

/* Exibicao de itens individuais de array com putchar */

int main() {

    char matriz[2][2] = {
    {'1', '2'},
    {'3', '4'}
    };

    printf("\nMatriz 1:\n");
    for (int i = 0; i < 2; i++) {
        printf("|\t%c\t%c\t|\n", matriz[i][0], matriz[i][1]);
    }

    printf("\nMatriz 1 com Putchar:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("[%d][%d] = ", i, j);
            putchar(matriz[i][j]);
            printf("\n");
        }
    }

    printf("\nMatriz tridimensional: \n");
    char matriz2[2][2][2] = { 
        {{'0', '1'}, 
        {'2', '3'}},

        {{'4', '5'}, 
        {'6', '7'}}
    };

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                printf("[%d][%d][%d] = ", i, j, k);
                putchar(matriz2[i][j][k]);
                printf("\n");
            }
        }
    }







return 0;
}