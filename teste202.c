// 27.06.26
#include <stdio.h>
#include <stdlib.h>
// lista encadeada

struct no {
    int valor;
    struct no *proximo;
};

int main() {

    struct no *a = malloc(sizeof(struct no));
    struct no *b = malloc(sizeof(struct no));
    struct no *c = malloc(sizeof(struct no));

    a->valor = 10; a->proximo = b;
    b->valor = 20; b->proximo = c;
    c->valor = 30; c->proximo = NULL;

    struct no *atual = a;
    while (atual != NULL) {
        printf("No: %d\n", atual->valor);
        atual = atual->proximo;
    }
    
    free(a);
    free(b);
    free(c);











    return 0;
}