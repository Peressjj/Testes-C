#include <stdio.h>
#define SIZE 10 

int main() {

    int numero[SIZE];
    int posicao1 = 0;
    int posicao2 = 0;

    for (posicao1; posicao1 < SIZE; posicao1++) 
        numero[posicao1] = 2 + 2 * posicao1;
    

    printf("%d%13d\n", posicao1, numero[posicao1]);

    for (posicao2; posicao2 < SIZE; posicao2++) 
        printf("%8d%13d\n", posicao2, numero[posicao2]);


















    return 0;
}