// 07.06.26
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// bubble sort
// ponteiro
// malloc

int main() {

    int *numeros = NULL;
    int cont = 0;
    int temp = 0;
    numeros = malloc(10 * sizeof(int));
    srand(time(NULL));

    printf("Numeros:\n");
    for (int i = 0; i < 10; i++) {
        numeros[i] = rand() % 50 + 1;
        printf("Numeros[%d] = %d\n", i, *(numeros + i));
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < (10 - i - 1); j++) {
            if (numeros[j] > numeros[(j + 1)]) {
                temp = numeros[j];
                numeros[j] = numeros[(j + 1)];
                numeros[(j + 1)] = temp;
                cont++;
            }
        }
    }

    printf("\n\nNumeros organizados:\n");
    for (int i = 0; i < 10; i++) {
        printf("Numeros[%d] = %d\n", i, *(numeros + i));
    }

    printf("\nAlteracoes: %d\n", cont);

    free(numeros);




    return 0;
}