// 30.05.26
#include <stdio.h>
#include <stdlib.h>

int main() {

    int *numeros;
    int maior, tamanho = 0;

    printf("\nInsira o tamanho da lista:\n");
    scanf("%d", &tamanho);

    numeros = malloc(tamanho * sizeof(int));

    if (numeros == NULL) {
        printf("Falha ao alocar memória.\n");
    }

    printf("Insira os numeros da lista:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Numero %d/%d: ", (i + 1), tamanho);
        scanf("%d", &*(numeros + i));
    }

    printf("\nLista de numeros:\n");

    for (int i = 0; i < tamanho; i++) {
        printf("Numero [%d]: %d\n", i, *(numeros + 1));
        if (numeros[i] > numeros[i + 1]) {
            maior = numeros[i];
        }
    }

    printf("Numero maior: %d\n", maior);

    


    free(numeros);







    return 0;
}