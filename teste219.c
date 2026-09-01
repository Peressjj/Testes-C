// 08.07.26
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} no;

int main() {

    no *inicio;
    no *fim;

    fim = NULL;
    inicio = NULL;

    no *novo;

    novo = malloc(sizeof(no));
    novo->prox = inicio;
    novo->valor = 10;

    inicio = novo;
    fim = novo;

    novo = malloc(sizeof(no));
    novo->prox = inicio;
    novo->valor = 20;

    fim->prox = novo;
    fim = novo;

    novo = malloc(sizeof(no));
    novo->prox = inicio;
    novo->valor = 30;

    fim->prox = novo;
    fim = novo;

    int cont = 1;
    no *aux;
    aux->prox = inicio;

    puts("Lista de numeros:");
    while (aux != NULL) {
        printf("Numero %d: %d\n", cont, aux->valor);
        cont++;
        aux = aux->prox;
    }
    





    printf("\nPrograma encerrado!\n\n");

    return 0;
}