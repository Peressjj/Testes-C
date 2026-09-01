// 27.06.26
#include <stdio.h>
#include <stdlib.h>
// lista encadeada
// ponteiro
// alocacao de memoria


    typedef struct no {
        int valor;
        struct no *prox;
    } no;

int main() {

    no *no1 = calloc(1, sizeof(no));
    no *no2 = calloc(1, sizeof(no));
    no *no3 = calloc(1, sizeof(no));
    no *no4 = calloc(1, sizeof(no));
    no *no5 = calloc(1, sizeof(no));
    no *no6 = calloc(1, sizeof(no));
    no *no7 = calloc(1, sizeof(no));
    no *no8 = calloc(1, sizeof(no));
    no *no9 = calloc(1, sizeof(no));
    no *no0 = calloc(1, sizeof(no));

    no *atual;
    atual = no1;
    int cont = 0;

    no1->prox = no2;
    no2->prox = no3;
    no3->prox = no4;
    no4->prox = no5;
    no5->prox = no6;
    no6->prox = no7;
    no7->prox = no8;
    no8->prox = no9;
    no9->prox = no0;

    while (atual != NULL) {
        printf("No[%d] = %d\n", (cont + 1), atual->valor);
        atual = atual->prox;
        cont++;
    }
    













    return 0;
}