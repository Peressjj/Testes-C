// 07.06.26
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// bubble sort
// malloc
// ponteiro

/* O programa reordena os numeros em ordem decrescente */

int main() {

    srand(time(NULL));
    int *numeros = NULL;
    int temp;
    numeros = malloc(10 * sizeof(int));

    for (int i = 0; i < 10; i++) {
        *(numeros + i) = rand() % 20 + 1;
    }

    printf("Numeros antes da ordenacao: \n");
    for (int i = 0; i < 10; i++) {
        printf("Numero[%d] = %d\n", i, *(numeros + i));
    }


    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < (11 - i - 1); j++) {
            if (numeros[j] < numeros[(j + 1)]) {
                temp = numeros[(j + 1)];
                numeros[(j + 1)] = numeros[j];
                numeros[j] = temp;    
            }
        }
    }

    printf("Numeros em ordem decrescente: \n");
    for (int i = 0; i < 10; i++) {
        printf("Numeros[%d] = %d\n", i, *(numeros + i));
    }

    free(numeros);





    return 0;
}