// 30.05.26
#include <stdio.h>
#include <stdlib.h>
// malloc
// sizeof

/* O programa cria a quantidade de memoria que o usuario deseja e armazena
os numeros inseridos dentro do array */

int main() {

    int *numeros;
    int tamanho;

    printf("Insira o tamanho do array: ");
    scanf("%d", &tamanho);

    numeros = malloc(tamanho * sizeof(int));

    printf("Insira os numeros no array: \n");
    for (int i = 0; i < tamanho; i++) {
        printf("Numero %d: ", (i + 1));
        scanf("%d", &numeros[i]);
    }

    printf("Lista de numeros:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Numero [%d]: %d\n", i, numeros[i]);
        printf("Memoria: %zu bytes.\n\n", sizeof(numeros[i]));
    }


    free(numeros);








    return 0;
}