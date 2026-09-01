// 30.05.26
#include <stdio.h>
#include <stdlib.h>
// ponteiro
// malloc
// sizeof

/* O programa cria a memoria do tamanho que o usuario deseja, armazena e mostra
usanfo loop for e ponteiro */

int main() {

    int *numeros;
    int tamanho;

    printf("Insira o tamanho da memoria: ");
    scanf("%d", &tamanho);

    numeros = malloc(tamanho * sizeof(int));

    printf("Insira os numeros da lista:\n");

    for (int i = 0; i < tamanho; i++) {
        printf("Numero %d: ", (i + 1));
        scanf("%d", &*numeros + i);
    }

    printf("\nLista de numeros:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Numero [%d] = %d\n", i, (*numeros + i));
    }


    free(numeros);









    return 0;
}