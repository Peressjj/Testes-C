#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// atribuindo valores aleatórios nas matrizes com rand

int main() {

    srand(time(NULL));

    int matriz[3][3];

    matriz[0][0] = rand() % 20 + 1;
    matriz[0][1] = rand() % 20 + 1;
    matriz[0][2] = rand() % 20 + 1;
    matriz[1][0] = rand() % 20 + 1;
    matriz[1][1] = rand() % 20 + 1;
    matriz[1][2] = rand() % 20 + 1;
    matriz[2][0] = rand() % 20 + 1;
    matriz[2][1] = rand() % 20 + 1;
    matriz[2][2] = rand() % 20 + 1;

    printf("\n\nMatrizes com valores aleatórios: \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("posicao %d x %d: [%d]\n", i, j, matriz[i][j]);
        }
    }

    














return 0;
}