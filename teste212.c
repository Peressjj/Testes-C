// 29.06.26
#include <stdio.h>
#include <stdlib.h>
// pilha - stack


typedef struct no {
    int valor;
    struct no *prox;
} no;

int main() {

    no *topo = NULL;

    no *novo = (no*) malloc(sizeof(no));

    novo->valor = 10;

    novo->prox = topo;

    topo = novo;

    printf("\n\ntopo: %d\n", topo->valor);
    printf("Prox: %d\n\n", topo->prox);

    printf("Novo: %d\n", novo->valor);
    printf("Prox: %d\n\n", novo->prox);

    free(novo);



    printf("Programa encerrado!\n");

    return 0;
}