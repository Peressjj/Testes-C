#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

srand(time(NULL));

    // gerador de numeros aleatorios normal:
    int teste[10];

    for (int posicao = 0; posicao < 10; posicao++) {
        teste[posicao] = rand() % 10 + 1;
    }

    for (int posicao = 0; posicao < 10; posicao++) {
        printf("posicao %d: [%d]\n", posicao + 1, teste[posicao]);
    }

    printf("\n\n\n\n\n");

    // gerador de numeros aleatorios com intervalo personalizado:
    int teste2[10];

    for (int posicao = 0; posicao < 10; posicao++) {
        teste[posicao] = rand() % (10 - 20) + 10; // (menor - maior) + menor
        }

    for (int posicao = 0; posicao < 10; posicao++) {
        printf("Posicao %d: [%d]\n", posicao + 1, teste[posicao]);
    }

    printf("\n\n\n\n\n");

    // gerador de numeros aleatorios especificos (dado):
    int dado[6] = {1, 2, 3, 4, 5, 6};
    int opcao;
    while (opcao != 0) {
        int face = rand() % 6;
        printf("\n");
        scanf("%d", &opcao);
        printf("Face do dado: %d\n", dado[face]);
    }
    
    

return 0;
}