#include <stdio.h>
#include <stdlib.h>
// ponteiro

/* Revisao para prova */

int main() {

    // ponteiro para um inteiro
    int *ptr;

    // Aloca memoria para 1 inteiro
    ptr = (int *)malloc(sizeof(int));

    // Verifica se deu certo
    if (ptr == NULL) {
        printf("ERRO!!!\n");
        return 1;
    } else {
        printf("Alocado com sucesso.\n\n");
    }

    // armazena valor na memoria alocada
    *ptr = 100;

    printf("Valor: %d\n", *ptr);
    printf("Endereco: %p\n", ptr);

    free(ptr);

    printf("\n\nfree(ptr)\n");
    printf("Valor: %d\n", *ptr);
    printf("Endereco: %p\n", ptr);


















return 0;
}