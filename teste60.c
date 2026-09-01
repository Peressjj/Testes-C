#include <stdio.h>
// inversao de matrizes

int main() {

    int matriz[3][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {7, 8, 9}
    };

    printf("\nPosicao normal: \n\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Posicao: [%d]\n", matriz[i][j]);
        }
    }

    printf("\nMatriz na chave: \n\n");
    for (int i = 0; i < 3; i++) {
        printf("|\t%d\t%d\t%d\t|\n", matriz[i][0], matriz[i][1], matriz[i][2]);
    }

    printf("\n\nMatriz normal invertida: \n\n");
    for (int i = 2; i >= 0; i--) {
        for (int j = 2; j >= 0; j--) {
            printf("Posicao: %d\n", matriz[i][j]);
        }
    }

    printf("\n\nMatriz na chave invertida: \n\n");
    for (int i = 2; i >= 0; i--) {
        printf("|\t%d\t%d\t%d\t|\n", matriz[i][2], matriz[i][1], matriz[i][0]);
    }






















return 0;
}