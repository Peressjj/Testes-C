#include <stdio.h>
// o sistema reorganiza os numeros em ordem decrescente

void ordemdecrescente(int numeros[], int quantidade) {

    int ordem;

    for (int i = 0; i < quantidade - 1; i++) {
        for (int j = i; j < quantidade; j++) {
            if (numeros[i] < numeros[j]) {
                ordem = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = ordem;
            }
        }
    }
}

int main() {

    int numeros[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int  tamanho = 10;

    printf("Insira os numeros: \n\n");
    for (int i = 0; i < 10; i++) {
        printf("Posicao %d: [%d]", (i + 1), numeros[i]);
        scanf("%d", &numeros[i]);
    }

    ordemdecrescente(numeros, tamanho);

    printf("\n\nNumeros reorganizados: \n\n");
    for (int i = 0; i < 10; i++) {
        printf("Posicao %d: [%d]\n", (i + 1), numeros[i]);
    }









return 0;
}