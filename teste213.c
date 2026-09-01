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


    no *novo = malloc(sizeof(no));
    novo->valor = 10;
    novo->prox = topo;
    topo = novo;
    
    novo = malloc(sizeof(no));
    novo->valor = 20;
    novo->prox = topo;
    topo = novo;

    novo = malloc(sizeof(no));
    novo->valor = 30;
    novo->prox = topo;
    topo = novo;

    novo = malloc(sizeof(no));
    novo->valor = 40;
    novo->prox = topo;
    topo = novo;

    novo = malloc(sizeof(no));
    novo->valor = 50;
    novo->prox = topo;
    topo = novo;
    
    printf("Topo: %d\n", topo->valor);
    printf("Novo: %d\n", novo->valor);

    no *aux = topo;
    int cont = 1;

    while (aux != NULL) {
            printf("\n__________________\n");
            printf("|   Caixa %-5d   |\n", cont);
            printf("|   Valor: %-4d   |\n", aux->valor);
            if (aux->prox != NULL) {
                printf("|   Prox: %-4d    |\n", (cont + 1));
            } else {
                printf("|   Prox: NULL    |\n");
            }
            printf("__________________\n\n");
            aux = aux->prox;
            cont++;
    }
    
    
    
    
    free(novo);

    printf("\n\nPrograma encerrado!\n");
    return 0;
}