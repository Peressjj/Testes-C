#include <stdio.h>
// soma individual das linhas da matriz
// soma individual das colunas da matriz

int main() {

    int matriz[2][3];

    printf("Insira os valore da matriz: \n");

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\n\n");
    for (int i = 0; i < 2; i++) {
        printf("|\t%d\t%d\t%d\t|\n", matriz[i][0], matriz[i][1], matriz[i][2]);
    }

    int linha1 = 0;
    int linha2 = 0;
    int coluna1 = 0;
    int coluna2 = 0;
    int coluna3 = 0;

    for (int j = 0; j < 3; j++) {
        linha1 += matriz[0][j];
    }

    for (int j = 0; j < 3; j++) {
        linha2 += matriz[1][j];
    }

    printf("\nSoma da linha 1: %d\nSoma da linha 2: %d\n", linha1, linha2);

    printf("\n\nSoma das colunas: \n");
    for (int i = 0; i < 2; i++) {    
        printf("|\t%d\t%d\t%d\t|\n", matriz[i][0], matriz[i][1], matriz[i][2]);
    }

    for (int i = 0; i < 2; i++) {
        coluna1 += matriz[i][0];
    }

    for (int i = 0; i < 2; i++) {
        coluna2 += matriz[i][1];
    }

    for (int i = 0; i < 2; i++) {
        coluna3 += matriz[i][2];
    }

    printf("\nSoma da coluna 1: %d\nSoma da coluna 2: %d\nSoma da coluna 3: %d\n", coluna1, coluna2, coluna3);





















return 0;
}