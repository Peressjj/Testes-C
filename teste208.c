// 28.05.26
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// list encadeada
// ponteiro
// srand
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

    no1->valor = rand() % 100 + 1;
    no1->prox = no2;
    no2->valor = rand() % 100 + 1;
    no2->prox = no3;
    no3->valor = rand() % 100 + 1;
    no3->prox = no4;
    no4->valor = rand() % 100 + 1;
    no4->prox = no5;
    no5->valor = rand() % 100 + 1;
    no5->prox = NULL;

    FILE *arq;

    arq = fopen("teste208.txt", "w");

    if (arq == NULL) {
        printf("Falha ao abrir arquivo!\n");
    } else {
        printf("Arquivo aberto com sucesso!\n");
    }

    no *atual = no1;

    while (atual != NULL) {
        fprintf(arq, "%d\n", atual->valor);
        atual = atual->prox;
    }
    
    fclose(arq);
    
    arq = fopen("teste208.txt", "r");

    int valores[5];

    for (int i = 0; i < 5; i++) {
        fscanf(arq, "%d", &valores[i]);
        printf("Valores[%d] = %d\n", i, valores[i]);
    }

    fclose(arq);
    
    int num;
    printf("Escrva um numero para buscar: ");
    scanf("%d", &num);

    no *atual2;
    atual2 = no1;

    while (atual2 != NULL) {
        if (num == atual2->valor) {
            printf("Atual 2: %d\n", atual2->valor);
            break;
        } else {
            atual2 = atual2->prox;
        }
    }
    







    free(no1);
    free(no2);
    free(no3);
    free(no4);
    free(no5);

    printf("Programa encerrado!\n");

    return 0;
}