#include <stdio.h>
// Ponteiro

/* O ponteiro aponta para uma posicao do array */

int main() {

    int numeros[5] = {10, 20, 30, 40, 50};

    for (int i = 0; i < 5; i++) {
        printf("%d  ", numeros[i]);
    }

    int *Ptr1;

    Ptr1 = &numeros[0];

    printf("\n\nEndereco Ptr: %p\n", Ptr1);
    printf("Valor de Ptr: %d\n\n", *Ptr1);

    for (int i = 0; i < 5; i++) {
        printf("Valor do Ptr de numeros[%d]: %d\n", i, *(Ptr1 + i));
    }

    printf("\nEndereco de memória dos índices %%p:\n\n");
    for (int i = 0; i < 5; i++) {
        printf("Numeros [%d]: %p\n", i, (Ptr1 + i));
    }

    printf("\nEndereco de memória dos índices %%d:\n\n");
    for (int i = 0; i < 5; i++) {
        printf("Numeros [%d]: %d bytes\n", i, (Ptr1 + i));
    }
















return 0;
}