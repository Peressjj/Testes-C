// 03.07.26
#include <stdio.h>
#include <stdlib.h>
// pilha / stack
// arquivo
// ponteiro

typedef struct no {
    int valor;
    struct no *prox;
} no;

enum op {
    SAIR,   // 0
    PUSH,   // 1
    POP,    // 2
    EXIBIR  // 3
};

void menu();
void push(no **topo);
void pop(no **topo);
void exibir(no **topo);
void push_arq(no **topo);
void pop_arq();

int main() {

    no *topo = NULL;

    int opcao = -1;

    while (opcao != 0) {
        menu();
        scanf("%d", &opcao);
        switch (opcao) {
            case SAIR:
                printf("Saindo!\n");
            break;

            case PUSH:
                push(&topo);
                push_arq(&topo);
            break;

            case POP:
                pop(&topo);
            break;

            case EXIBIR:
                exibir(&topo);
            break;
        
            default:
                if (opcao != SAIR) {
                    printf("Opcao inválida!\n");
                }
            break;
        }
    }
    


    printf("Programa encerrado!\n");
    return 0;
}

void menu() {

    printf("\n ________________________________________________\n");
    printf("|                      MENU                      |\n");
    printf("|                                                |\n");
    printf("|   1 - PUSH:                                    |\n");
    printf("|                                                |\n");
    printf("|   2 - POP:                                     |\n");
    printf("|                                                |\n");
    printf("|   3 - EXIBIR:                                  |\n");
    printf("|                                                |\n");
    printf("|   0 - Sair:                                    |\n");
    printf("|                                                |\n");
    printf(" ________________________________________________\n");

}

void push(no **topo) {

    int num;
    printf("Insira o numero que deseja adicionar a pilha: ");
    scanf("%d", &num);

    no *novo;
    novo = malloc(sizeof(no));

    novo->valor = num;
    novo->prox = *topo;

    *topo = novo;

    printf("\nNumero %d adicionado a pilha com sucesso!\n", num);

}

void pop(no **topo) {

    if (*topo == NULL) {
        printf("Pilha vazia!\n");
        return;
    }

    no *aux = *topo;

    *topo = (*topo)->prox;

    free(aux);

}

void exibir(no **topo) {

    FILE *arq;
    char linha[100];

    arq = fopen("teste217.txt", "r");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    while (fgets(linha, sizeof(linha), arq) != NULL) {
        printf("%s", linha);
    }

    fclose(arq);
}

void push_arq(no **topo) {
    
    int cont = 1;
    
    FILE *arq;
    
    no *aux = *topo;

    arq = fopen("teste217.txt", "w");

    while (aux != NULL) {
        fprintf(arq, " ___________________\n");
        fprintf(arq, "|                  |\n");
        fprintf(arq, "|   Caixa: %-4d  |\n", cont);
        fprintf(arq, "|                  |\n");
        fprintf(arq, "|   Valor: %-5d |\n", aux->valor);
    if (aux->prox == NULL) {
        fprintf(arq, "|   Prox: NULL |\n");
    } else {
        fprintf(arq, "|   Prox: %-6d |\n", (cont + 1));
    }
        fprintf(arq, "|                  |\n");
        fprintf(arq, " ___________________\n");
    aux = aux->prox;
    cont++;
}
    
    fclose(arq);

}

void pop_arq() {}