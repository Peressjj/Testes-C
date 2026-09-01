#include <stdio.h>
// Ponteiro

/* Endereco de memoria e valor armazenado no endereco indicado
allteracao do valor do ponteiro qua altera o valor da variavel original */

int main() {

    int numero = 10;

    int *numPtr;
    
    numPtr = &numero;

    printf("\n\nNumero: %d\n", numero);
    printf("Endereco de memória do numero: %p\n", numPtr);
    printf("Valor de numPtr puxado: %d\n", *numPtr);

    *numPtr = 100;

    printf("\n\nAlteracoes: *numPtr = 100;\n");
    printf("Numero: %d\n", numero);
    printf("Endereco de memoria: %d (sem alteracao)\n", numPtr);
    printf("Valor puxado: %d\n", *numPtr);











    return 0;
}