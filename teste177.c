// 03.06.26
#include <stdio.h>
#include <stdlib.h>
// realloc
// malloc
// calloc

/* O sistema cria 5 espacos de array utilizando malloc, depois utilizando a 
funcao realloc, cria mais 5 espacos adicionais para armazenar novos valores,
porém esses novos espacos criados nao sao inicializados em '0' */

int main() {

    int *numeros;
    int quant1 = 5;
    int quant2 = 10;

    numeros = calloc(quant1, sizeof(int));

    if (numeros == NULL) {
        printf("Erro ao alocar memória.\n");
    }

    for (int i = 0; i < quant1; i++) {
        printf("Numero [%d] = %d\n", i, numeros[i]);
    }

    puts("Nova quantidade:\n");

    numeros = realloc(numeros, quant2 * sizeof(int));

    for (int i = 0; i < quant2; i++) {
        printf("Numeros [%d] = %d\n", i, numeros[i]);
    }

    free(numeros);












}