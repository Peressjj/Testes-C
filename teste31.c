#include <stdio.h>
#define LINHA 3
#define COLUNA 3

/* Define uma matriz 3x3, utlizando array bidimenssional*/


int main() {
    
    
    int matriz[LINHA][COLUNA];

    // Preenchendo a matriz com valores do usuário
    printf("\n\nDigite os elementos da matriz Linha x Coluna:\n");
    for (int posicaolinha = 0; posicaolinha < LINHA; posicaolinha++) {
        for (int posicaocoluna = 0; posicaocoluna < COLUNA; posicaocoluna++) {
            printf("Elemento Linha:%d   x   Coluna:%d: ", posicaolinha + 1, posicaocoluna + 1);
            scanf("%d", &matriz[LINHA][COLUNA]);
        }
    }

    // Exibindo a matriz
    printf("\nMatriz inserida:\n");
    for (int posicaolinha = 0; posicaolinha < LINHA; posicaolinha++) {
        for (int posicaocoluna = 0; posicaocoluna < COLUNA; posicaocoluna++) {
            printf("%d\t", matriz[LINHA][COLUNA]);      
        }
        printf("\n\n");
    }

    return 0;
}