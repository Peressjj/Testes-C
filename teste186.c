#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// bubble sort
// ponteiro
// malloc

/* O programa ordena os numeros e conta quantas alteracoes ele faz */

int main() {

    int cont = 0;
    int temp = 0;
    int *numeros = NULL;
    numeros = malloc(5 * sizeof(int));

    srand(time(NULL));

    printf("Numeros;\n");
    for (int i = 0; i < 5; i++) {
        numeros[i] = rand() % 10 + 1;
        printf("Numeros[%d] = %d\n", i, *(numeros + i));
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < (5 - i - 1); j++) {
            if (numeros[j] > numeros[(j + 1)]) {
                printf("\n");
                temp = numeros[j];
                numeros[j] = numeros[(j + 1)];
                numeros[(j + 1)] = temp;
                cont++;
                for (int k = 0; k < 5; k++) {
                    printf("%d\t", *(numeros + k));
                }
            }
        }
    }

    printf("\n\nLista reorganizada:\n");
    for (int i = 0; i < 5; i++) {
        printf("Numeros[%d] = %d\n", i , *(numeros + i));
    }

    printf("\nAlteracoes: %d\n", (cont - 1));

    free(numeros);











    return 0;
}