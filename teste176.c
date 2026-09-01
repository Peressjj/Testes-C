// 02.06.2026
#include <stdio.h>
#include <stdlib.h>
// malloc
// calloc
// ponteiro

/* Utilizamos callor e mallorr para criar memória para duas variaveis e exibimos os valores
armazenados em cada uma, os valores de malloc sao aleatórias, já, a funcao calloc já inicializa 
a memória em 0 */

int main() {

    int *num_mal;
    int *num_cal;
    int quant = 5;
    
    num_mal = malloc(quant * sizeof(int));
    num_cal = calloc(quant, sizeof(int));

    if (num_mal == NULL || num_cal == NULL) {
        printf("Falha ao alocar memória!\n");
    }

    printf("Numeros malloc:\n");
    for (int i = 0; i < quant; i++) {
        printf("Num_mal[%d] = %d\n", i, num_mal[i]);
    }

    printf("\nNumeros calloc:\n");
    for (int i = 0; i < quant; i++) {
        printf("Num_cal[%d] = %d\n", i, num_cal[i]);
    }

    free(num_mal);
    free(num_cal);




    return 0;
}