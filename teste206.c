// 28.06.26
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// lista encadeada
// ponteiro
// arquivo
// alocacao de memoria

    typedef struct no {
        int valor;
        struct no *prox;
    } no;
    
int main() {

    srand(time(NULL));

    no *no1 = malloc(sizeof(no));
    no *no2 = malloc(sizeof(no));
    no *no3 = malloc(sizeof(no));
    no *no4 = malloc(sizeof(no));
    no *no5 = malloc(sizeof(no));
    
    no1->prox = no2;
    no2->prox = no3;
    no3->prox = no4;
    no4->prox = no5;
    no5->prox = NULL;

    no1->valor = rand() % 50 + 1;
    no2->valor = rand() % 50 + 1;
    no3->valor = rand() % 50 + 1;
    no4->valor = rand() % 50 + 1;
    no5->valor = rand() % 50 + 1;

    no *atual;
    atual = no1;
    int cont = 1;

    FILE *arq;
    arq = fopen("teste206.txt", "w");

    if (arq == NULL) {
        printf("Falha ao abrir arquivo!\n");
    } else {
        printf("Arquivo aberto com sucesso!\n");
    }

    while (atual != NULL) {
        printf("No %d: %d\n", cont, atual->valor);
        fprintf(arq, "No %d: %d\n", cont, atual->valor);
        atual = atual->prox;
        cont++;
    }
        











    fclose(arq);

    free(no1);
    free(no2);
    free(no3);
    free(no4);
    free(no5);

    printf("Programa encerrado!\n");

    return 0;
}