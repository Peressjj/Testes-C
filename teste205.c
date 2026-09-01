// 28.06.26
#include <stdio.h>
#include <stdlib.h>
// lista encadeada
// arquivos

    typedef struct no {
        int valor;
        struct no *prox;
    } no;

int main() {

    no *no1 = malloc(sizeof(no));

    printf("No 1: %d\n", no1->valor);

    no1->prox = NULL;

    no *atual;

    atual = no1;

    int cont = 0;

    while (atual != NULL) {
        printf("No %d: %d\n", (cont + 1), atual->valor);
        atual = atual->prox;
        cont++;
    }

    FILE *arq;

    arq = fopen("teste205.txt", "w");

    if (arq == NULL) {
        printf("Falha ao abrir arquivo!\n");
    } else {
        printf("Arquivo aberto com sucesso!\n");
    }

    fprintf(arq, "No atual %d: %d\n", (cont + 1), atual);

    fclose(arq);
    
    free(no1);












    printf("Programa encerrado!\n");

    return 0;
}