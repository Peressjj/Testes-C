// 30.05.26
#include <stdio.h>
#include <stdlib.h>

int main() {

    int *numeros;

    numeros = malloc(5 * sizeof(int));

    printf("Insira os numeros: \n");
    for (int i = 0; i < 10; i++) {
        printf("Numero %d: ", (i + 1));
        scanf("%d", &numeros[i]);
    }

    printf("Lista de numeros:\n");
    for (int i = 0; i < 10; i++) {
        printf("Numero [%d]: %d\n", i, numeros[i]);
    }


    free(numeros);











    return 0;
}