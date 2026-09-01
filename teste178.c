// 03.06.26
#include <stdio.h>
#include <stdlib.h>
// calloc
// realloc

/* O sistema cria indices para armazenar numeros que o usuario insere instantaneamente */

int main() {

    int opcao = -1;
    int *numeros;
    numeros = calloc(3, sizeof(int));
    int quant = 0;

    if (numeros == NULL) {
        printf("ERRO!!!\n");
    }

    while (opcao != 0) {
        printf("    1 - Inserir um numero.\n    0 - Sair.\n\n");
        scanf("%d", &opcao);

        switch (opcao) {

            case 0:
                printf("Saindo.\n");
            break;

            case 1:
                numeros = realloc(numeros, (quant + 3) * sizeof(int));
                printf("Insira 3 numeros: \n");
                
                for (int i = quant; i < (quant + 3); i++) {
                    scanf("%d", &numeros[i]);
                }
                quant += 3;  

                printf("Lisda de numeros: \n");
                for (int i = 0; i < quant; i++) {
                    printf("Numeros [%d] = %d\n", i, numeros[i]);
                }
            break;
        
            default:
                printf("Opcao inválida.\n");
            break;
        }




    }

    printf("Programa encerrado.\n");

    free(numeros);
    
















    return 0;
}