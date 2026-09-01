// 06.06.26
#include <stdio.h>
#include <stdlib.h>
// bublle sorte
// ponteiro
// malloc

/* O algoritmo de ordenacao bubble sorte reordena a sequencia de
numeros do array */

int main() {

    int temp = 0;
    int *numeros = NULL;
    numeros = malloc(10 * sizeof(int));

    printf("Insira 10 numeros: \n");

    for (int i = 0; i < 10; i++) {
        printf("Numeros [%d] = ", i);
        scanf("%d", &*(numeros + i));
    }

    printf("Antes da ordenacao: \n");
    for (int i = 0; i < 10; i++) {
        printf("Numeros[%d] = %d\n", i, *(numeros + i));
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < (10 - i - 1); j++) {
            if (numeros[j] > numeros[(j + 1)]) {
                temp = numeros[j];
                numeros[j] = numeros[(j + 1)];
                numeros[(j + 1)] = temp;
            }
        }
    }

    printf("Depois da ordenacao:\n");
    for (int i = 0; i < 10; i++) {
        printf("Numeros[%d] = %d\n", i, *(numeros + i));
    }

    free(numeros);







    return 0;
}