#include <stdio.h>
// Soma dos elementos da matriz

int main() {

    int matriz[2][2];

    printf("\nInsira os valores da matriz: \n\n");

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }


    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("Posicao %d x %d: [%d]\n", i, j, matriz[i][j]);
        }
    }

        int soma = 0;
        
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            soma += matriz[i][j];
        }
    }
    



    printf("A soma dos termos da matriz é: %d", soma);





















return 0;
}