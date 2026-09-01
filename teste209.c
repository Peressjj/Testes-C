// 28.06.26
#include <stdio.h>
#include <stdlib.h>

    // CODIGO NAO FUNCIOANDO

// lista encadeada
// ponteiro
// ponteiro duplo
// enum
// alocacao de memoria

typedef struct no {
    int valor;
    struct no *prox;
} no;

enum opcoes {
    SAIR,
    GRAVAR,
    EXIBIR,
    GRAVARCOMECO
};

void menu(int quant_nos);
int gravar(int *cont, no **atual);
void exibir(no *no_1, no *no_2, no *no_3, no *no_4, no *no_5);
int gravarcomeco(no *no_1, no *no_2, no *no_3, no *no_4, no *no_5);
void iniciarlista(no *no_1, no *no_2, no *no_3, no *no_4, no *no_5);
void contarnos(no *atual, int quant_nos);

int main() {

    
    FILE *arq;
    int um = 1;
    int *cont = &um;
    int quant_nos = 0;
    
    no *no1 = calloc(1, sizeof(no));
    no *no2 = calloc(1, sizeof(no));
    no *no3 = calloc(1, sizeof(no));
    no *no4 = calloc(1, sizeof(no));
    no *no5 = calloc(1, sizeof(no));
    
    no1->prox = no2;
    no2->prox = no3;
    no3->prox = no4;
    no4->prox = no5;
    no5->prox = NULL;
    
    no *atual = no1;
    iniciarlista(no1, no2, no3, no4, no5);
    contarnos(atual, quant_nos);

    int opcao = -1;
    while (opcao != SAIR) {
        menu(quant_nos);
        scanf("%d", &opcao);

        switch (opcao) {
            case SAIR:
                printf("Saindo!\n");    
            break;
            
            case GRAVAR:
                if (um == 5) {
                    break;
                }
                gravar(cont, &atual);
            break;

            case EXIBIR:
                exibir(no1, no2, no3, no4, no5);
            break;

            case GRAVARCOMECO:
                gravarcomeco(no1, no2, no3, no4, no5);
            break;

            default:
                if (opcao != SAIR) {
                    printf("Opcao inválida!\n");
                }
            break;
        }
    }
    





    free(no1);
    free(no2);
    free(no3);
    free(no4);
    free(no5);

    printf("\nProgrma encerrado!\n\n");

    return 0;
}

void menu(int quant_nos) {

    printf("---------------------------------------\n");
    printf("|                                     |\n");
    printf("|   Nós: %d                          |\n", quant_nos);
    printf("|                                     |\n");
    printf("|   1 - Adiconar numero:              |\n");
    printf("|                                     |\n");
    printf("|   2 - Exibir lista:                 |\n");
    printf("|                                     |\n");
    printf("|   3 - Adicionar no comeco:          |\n");
    printf("|                                     |\n");
    printf("|   0 - Sair.                         |\n");
    printf("|                                     |\n");
    printf("---------------------------------------\n");

}

int gravar(int *cont, no **atual) {

    int num;
    printf("Insira o numero que deseja gravar:");
    scanf("%d", &num);

    FILE *arq;

    arq = fopen("teste209.txt", "a");

    if (arq == NULL) {
        printf("Erro ao abrir arquivo!\n");
    } else {
        printf("Arquivo aberto com sucesso!\n");
    }

    fprintf(arq, "No %d: %d\n", *cont, num);

    printf("No %d: %d\n", *cont, num);

    (*atual)->valor = num;
    *atual = (*atual)->prox;

    fclose(arq);
    (*cont)++;
}

void exibir(no *no_1, no *no_2, no *no_3, no *no_4, no *no_5) {

    FILE *arq;

    arq = fopen("teste209.txt", "r");

    int cont;
    int valor;

    while (fscanf(arq, "No %d: %d\n", &cont, &valor) == 2) {
        printf("No %d: %d\n", cont, valor);
    }

    printf("Valores da lista encadeada: \n");
    printf("No 1: %d\n", no_1);
    printf("No 2: %d\n", no_2);
    printf("No 3: %d\n", no_3);
    printf("No 4: %d\n", no_4);
    printf("No 5: %d\n\n", no_5);

    fclose(arq);
}

int gravarcomeco(no *no_1, no *no_2, no *no_3, no *no_4, no *no_5) {
    
    int num, aux;
    int cont, valor;
    printf("Insira o numero que deseja gravar:");
    scanf("%d", &num);

    no_5->valor = no_4->valor;
    no_4->valor = no_3->valor;
    no_3->valor = no_2->valor;
    no_2->valor = no_1->valor;
    no_1->valor = num;
    
    FILE *arq;
    
    arq = fopen("teste209.txt", "r");

    char numeros[5];

    while (fscanf(arq, "No %d: %d\n", &cont, &valor) == 2) {
        int i = 0;
        printf("No %d: %d\n", cont, valor);
        numeros[i] = valor;
    }

    for (int i = 0; i < 5; i++) {
        printf("No %d: %d\n", i, numeros[i]);
    }

    fclose(arq);

    printf("\n\nAdicionando numero!\n\n");

    for (int i = 0; i < 5; i++) {
        int temp, temp2;
        temp = numeros[i];
        numeros[i] = num;
        temp2 = numeros[(i + 1)];
    }

    arq = fopen("teste209.txt", "w");

    for (int i = 0; i < 5; i++) {
        fprintf(arq, "No %d: %d\n", (i + 1), numeros[i]);
    }

    fclose(arq);

}

void iniciarlista(no *no_1, no *no_2, no *no_3, no *no_4, no *no_5) {

    FILE *arq;
    int cont, valor;
    int numeros[5];

    arq = fopen("teste209.txt", "r");

    if (arq == NULL) {
        printf("Falha ao abrir arquivo e eniciar lista!\n");
    } else {
        printf("Lista iniciada!\n");
    }

    while (fscanf(arq, "No %d: %d\n", &cont, &valor) == 2) {
        numeros[(cont - 1)] = valor;
    }

    printf("Numeros da lista iniciada:\n");
    for (int i = 0; i < 5; i++) {
        printf("Numero[%d]: %d\n", i, numeros[i]);
    }

    no_1->valor = numeros[0];
    no_2->valor = numeros[1];
    no_3->valor = numeros[2];
    no_4->valor = numeros[3];
    no_5->valor = numeros[4];

    fclose(arq);
}

void contarnos(no *atual, int quant_nos) {

    int quant = 0;

    while (atual != NULL) {
        atual = atual->prox;
        quant++;
    }
    
    quant_nos = quant;

}