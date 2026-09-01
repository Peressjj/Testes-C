// 08.07.26
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} no;

int main() {

    no *topo = NULL;
    no *novo;
    novo = malloc(sizeof(no));
    novo->prox = topo;
    novo->valor = 10;
    topo = novo;
    printf("Valor adicionado: %d\n", novo->valor);

    novo = malloc(sizeof(no));
    novo->prox = topo;
    novo->valor = 20;
    topo = novo;
    printf("Valor adicionado: %d\n", novo->valor);

    novo = malloc(sizeof(no));
    novo->prox = topo;
    novo->valor = 30;
    topo = novo;
    printf("Valor adicionado: %d\n", novo->valor);

    novo = malloc(sizeof(no));
    novo->prox = topo;
    novo->valor = 40;
    topo = novo;
    printf("Valor adicionado: %d\n", novo->valor);

    novo = malloc(sizeof(no));
    novo->prox = topo;
    novo->valor = 50;
    topo = novo;
    printf("Valor adicionado: %d\n", novo->valor);


    int cont = 1;
    no *aux;
    aux->prox = topo;
    printf("Lista de valores:\n");
    while (aux != NULL) {
        printf("Numero %d: %d\n", cont, aux->valor);
        cont++;
        aux = aux->prox;
    }
    








    printf("\n\nPrograma encerrado!\n");

    return 0;
}