// 30.05.26
#include <stdio.h>
#include <stdlib.h>
// Alocacao de memoria dinamica
// malloc

/* O sistema cria a memoria pro usuario inserir os dados para serem 
armazenados na variavel */

int main() {

    int *numeros;
    int quantidade = 5;

    numeros = malloc(quantidade * sizeof(int));

    printf("Insira 5 numeros: \n");
    for (int i = 0; i < 5; i++) {
        printf("Numero %d: ", (i + 1));
        scanf("%d", &numeros[i]);
    }

    printf("\nLista de numeros:\n");
    for (int i = 0; i < 5; i++) {
        printf("Numero [%d]: %d\n", i, numeros[i]);
    }


    free(numeros);











    return 0;
}