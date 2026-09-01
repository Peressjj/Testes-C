// 28.06.2026
#include <stdio.h>
#include <stdlib.h>
// lista encadeada
// ponteiro
// arquivo
// alocacao de memoria

typedef struct no {
    int valor;
    struct no *prox;
} no;

int main() {

    int numeros[5];
    int cont = 1;
    printf("Insira 5 numeros: \n");
    for (int i = 0; i < 5; i++) {
        printf("Numero %d: ", (i + 1));
        scanf("%d", &numeros[i]);
        printf("\n");
    }

    no *no1 = malloc(sizeof(no));
    no *no2 = malloc(sizeof(no));
    no *no3 = malloc(sizeof(no));
    no *no4 = malloc(sizeof(no));
    no *no5 = malloc(sizeof(no));

    no *atual = no1;
    no1->valor = numeros[0];
    no1->prox = no2;
    no2->valor = numeros[1];
    no2->prox = no3;
    no3->valor = numeros[2];
    no3->prox = no4;
    no4->valor =  numeros[3];
    no4->prox = no5;
    no5->valor = numeros[4];
    no5->prox = NULL;

    FILE *arq;

    arq = fopen("teste207.txt", "w");

    if (arq == NULL) {
        printf("Falha ao abrir arquivo!\n");
    } else {
        printf("Arquivo aberto com sucesso!\n");
    }

    while (atual != NULL) {
        printf("No %d: %d\n", cont, atual->valor);
        fprintf(arq, "\n\n__________________________\n");
        fprintf(arq, "|     Caixa: %-11d |\n", cont);
        fprintf(arq, "|                        |\n");
        fprintf(arq, "|  Valor: %-14d |\n", atual->valor);
        fprintf(arq, "|  Endereco: %-11d |\n", atual->prox);
        fprintf(arq, "|  %%p: %-17p |\n", atual->prox);
        fprintf(arq, "|  Prox: %-15d |\n", (cont + 1));
        fprintf(arq, "|________________________|\n");
        fprintf(arq, "\n\n");
        fprintf(arq, "⬇️");
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