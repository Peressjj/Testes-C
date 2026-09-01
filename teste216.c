// 29.06.26
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} no;

enum op {
    SAIR,
    ENQUEUE,
    DEQUEUE,
    EXIBIR
};

void menu();
void enqueue(no **inicio, no **fim);
void dequeue();
void exibir(no *inicio);

int main() {

    no *inicio = NULL;
    no *fim = NULL;

    int opcao = -1;
    while (opcao != SAIR) {
        menu();
        scanf("%d", &opcao);

        switch (opcao) {
            case SAIR:
                printf("Saindo!\n");
            break;
            
            case ENQUEUE: // gravar
                enqueue(inicio, fim);
            break;

            case DEQUEUE: // remover

            break;

            case EXIBIR:
                exibir(inicio);
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

    printf("----------------------------------\n");
    printf("|                                |\n");
    printf("|          FILA - QUEUE          |\n");
    printf("|                                |\n");
    printf("|   1 - Adicionar numero:        |\n");
    printf("|                                |\n");
    printf("|   2 - Retirar numero:          |\n");
    printf("|                                |\n");
    printf("|   3 - Exibir numeros:          |\n");
    printf("|                                |\n");
    printf("|   0 - Sair;                    |\n");
    printf("|                                |\n");
    printf("----------------------------------\n");

}

void enqueue(no **inicio, no **fim) {

    int num;
    printf("\n\nInsira o numero que deseja gravar: ");
    scanf("%d", &num);

    no *novo;
    novo = malloc(sizeof(no));

    novo->valor = num;
    novo->prox = NULL;

    if (*inicio == NULL) {
        *inicio = novo;
        *fim = novo;
    } else {
        (*fim)->prox = novo;
        *fim = novo;
    }

    printf("\nNumero %d adicionado a fila com sucesso!\n", num);

}

void dequeue() {







}

void exibir(no *inicio) {

    no *aux = inicio;
    int cont = 1;

    while (aux != NULL) {
        printf("_____________________\n");
        printf("|   Posicao: %-4d |\n", cont);
        printf("|   Valor: %-d |\n", aux->valor);
        printf("|   Proximo: %-4d |\n", (cont + 1));
        printf("|___________________|\n");
        aux = aux->prox;
        cont++;
    }
    
}

