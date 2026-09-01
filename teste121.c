#include <stdio.h>
// Ponteiro

/* Dois ponteiros que apontam pra mesma variável */

int main() {

    int numero = 10;

    int *Ptr1;
    int *Ptr2;

    Ptr1 = &numero; 
    Ptr2 = &numero;

    printf("Numero: %d\n", numero);
    printf("Endereco 1: %p\n", Ptr1);
    printf("Endereco 2: %p\n", Ptr2);
    printf("Numero Ptr 1: %d\n", *Ptr1);
    printf("Numero Ptr 1: %d\n", *Ptr2);











return 0;
}