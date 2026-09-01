// 30.05.26
#include <stdio.h>
#include <stdlib.h>
// malloc
// ponteiro

/* O sistema pede ao usuario para que insira os numeros na variavel depois 
exibe uma soma desses numeros */

int main() {

    int *numeros;
    int soma = 0;

    numeros = malloc(5 * sizeof(int));

    if (numeros == NULL) {
        printf("Falha ao alocar memória.\n");
    }

    printf("Insira os numeros na memória: \n");
    for (int i = 0; i < 5; i++) {
        printf("Numero %d: ", (i + 1));
        scanf("%d", &*(numeros + i));
    }

    printf("Lista de numeros:\n");
    for (int i = 0; i < 5; i++) {
        printf("Numero [%d] = %d\n", i, *(numeros + i));
        soma += *(numeros + i);
    }

    printf("Soma dos numeros: %d\n", soma);


    free(numeros);



















    return 0;
}