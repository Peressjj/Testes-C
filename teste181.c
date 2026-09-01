// 06.06.26
#include <stdio.h>
#include <stdlib.h>
// bublle sort
// realloc
// ponteiro
// prototipo de funcao

/* O sistema pega numeros que o usuario insere, aloca memoria para armazena-los,
os reorganiza utilizando bubble sort */

void exibemenu();
int adicionarnumero(int **n);
int exibelistanumeros(int *n, int c);
int reorganizar(int *n, int c);
int remover(int *n, int c);

int cont = 0;

int main() {
    
    int *numeros = NULL;
    int opcao = -1;

    while (opcao != 0) {
        exibemenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: // adicionar numero
                adicionarnumero(&numeros);
            break;

            case 2: // remover numero
                reorganizar(numeros, cont);
            break;

            case 3: // exibe lista de numeros
                exibelistanumeros(numeros, cont);
            break;

            case 4: // remover numeros
                exibelistanumeros(numeros, cont);
                remover(numeros, cont);
            break;
        
            default:
                if (opcao != 0) {
                    printf("Opcao inválida!");
                }
            break;
        }
    }
    

    printf("\n\nPrograma encerrado.\n");
    free(numeros);


    return 0;
}

void exibemenu() {

    printf("-------------------------------------------\n");
    printf("|                  MENU:                  |\n");
    printf("|                                         |\n");
    printf("|   1 - Adicionar um numero:              |\n");
    printf("|                                         |\n");
    printf("|   2 - Reorganizar numeros:              |\n");
    printf("|                                         |\n");
    printf("|   3 - Exibir lista de numeros:          |\n");
    printf("|                                         |\n");
    printf("|   4 - Remover numeros:                  |\n");
    printf("|                                         |\n");
    printf("|   0 - Sair.                             |\n");
    printf("|                                         |\n");
    printf("-------------------------------------------\n");

}

int adicionarnumero(int **n) {

    *n = realloc(*n, (cont + 1) * sizeof(int));

    if (n == NULL) {
        printf("Falha ao alocar memória.\n");
    } else {
        printf("\n[_]\n");
    }

    printf("Insira um numero: ");
    scanf("%d", &(*n)[cont]);

    printf("Numero[%d] = %d\n", cont, (*n)[cont]);

    cont++;
}

int exibelistanumeros(int *n, int c) {

        printf("-------------------------------------------\n");
        printf("|            LISTA DE NUMEROS:            |\n");
        printf("|                                         |\n");
    for (int i = 0; i < cont; i++) {
        printf("|   Numeros[%d] = %d\n", i, *(n + i));             
    }
        printf("|                                         |\n");
        printf("-------------------------------------------\n");

}

int reorganizar(int *n, int c) {

    int temp = 0;
    printf("Reorganizando...\n");
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < (c - i - 1); j++) {
            if (n[j] > n[j + 1]) {
                temp = n[j];
                n[j] = n[j + 1];
                n[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < c; i++) {
        printf("Numeros[%d] = %d\n", i, n[i]);
    }

}

int remover(int *n, int c) {

    int op;
    printf("Insira o numero do índice que deseja remover: \n");
    scanf("%d", &op);

    n[op] = 0;

    printf("\n|   Numeros[%d] = %d\n\n", op, n[op]);

} 