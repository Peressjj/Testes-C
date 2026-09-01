// 27.06.26
#include <stdio.h>
#include <stdlib.h>
// lista encadeada
// ponteiro

    typedef struct no {
        int valor;
        struct no *prox;
    } no;

int main() {

    no a = {1, NULL};
    no b = {2, NULL};
    no c = {3, NULL};
    no d = {4, NULL};
    no e = {5, NULL};

    a.prox = &b;
    b.prox = &c;
    c.prox = &d;
    d.prox = &e;
    e.prox = NULL;

    no *atual = &a;
    
    while (atual != NULL) {
        printf("No: %d\n", atual->valor);
        atual = atual->prox;
    }











    return 0;
}