#include <stdio.h>
// Ponteiro

/* Funcao em que a variavel apontada pelo ponteiro é somada */

void funcao(int *Ptr, int n);

int main() {

    int numero;
    int *Ptr;
    Ptr = &numero;
    printf("Insira um numero: ");
    scanf("%d", &numero);

    funcao(Ptr, numero);


}

void funcao(int *Ptr, int n) {
    printf("Soma: %d + %d = %d\n", *Ptr, *Ptr, (*Ptr * 2));
    

}