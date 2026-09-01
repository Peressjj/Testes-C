// 31.05.26
#include <stdio.h>
#include <stdlib.h>
// malloc
// ponteiro

int main() {

    int *numeros;
    int tamanho = 0;

    printf("Insira o tamanho da memoria: ");
    scanf("%d", &tamanho);

    numeros = malloc(tamanho * sizeof(int));

    printf("\nLista de numeros: \n");
    for (int i = 0; i < tamanho; i++) {
        *(numeros + i) = (i * i);
        printf("Numeros[%d] = %d\n", i, *(numeros + i));
    }
















    return 0;
}