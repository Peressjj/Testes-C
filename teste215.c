// 29.06.26
#include <stdio.h>
#include <stdlib.h>
// fila

typedef struct no {
    int valor;
    struct no *prox;
} no;

int main() {

    no *inicio = NULL;
    no *fim = NULL;
    
    no *novo;
    novo = malloc(sizeof(no));
    novo->valor = 10;
    novo->prox = NULL;

    inicio = novo;
    fim = novo;

    novo = malloc(sizeof(no));

    novo->valor = 20;
    novo->prox = NULL;

    fim->prox = novo;
    fim = novo;

    no *aux = inicio;
    int cont = 1;

    while (aux != NULL) {
        printf("Posicao: %d\n", cont);
        printf("Valor:  %d\n\n", aux->valor);
        aux = aux->prox;
        cont++;
    }
    











    return 0;
}