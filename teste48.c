#include <stdio.h>
// usuario insere os valores da matriz

int main() {

    int matriz[3][3];

    printf("\nInsira os valores da matriz: \n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\n\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("posicao %d x %d: [%d]\n", i, j, matriz[i][j]);
        }
    }






















return 0;
}