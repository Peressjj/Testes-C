// 29.06.26
#include <stdio.h>
#include <stdlib.h>
// pilha - stack

/* O programa realiza push e pop */

typedef struct no {
    int valor;
    struct no *prox;
} no;

enum op {
    SAIR,
    PUSH,
    POP,
    EXIBIR
};

void menu();
void push(no **topo);
void pop(no **topo);
void exibir(no **topo);

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

    printf("---------------------------------\n");
    printf("|         PILHA - STACK         |\n");
    printf("|                               |\n");
    printf("|   1 - Gravar (push):          |\n");
    printf("|                               |\n");
    printf("|   2 - Retirar (pop):          |\n");
    printf("|                               |\n");
    printf("|   3 - Exibir:                 |\n");
    printf("|                               |\n");
    printf("|   0 - Sair.                   |\n");
    printf("|                               |\n");
    printf("---------------------------------\n");

}

void push(no **topo) {

    int num;
    printf("Insira um numero: ");
    scanf("%d", &num);

    no *novo;
    novo = malloc(sizeof(no));
    novo->valor = num;
    novo->prox = *topo;
    *topo = novo;

    printf("Numero %d adicionado a pilha com sucesso!\n", num);

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

    no *aux = *topo;
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
    
}