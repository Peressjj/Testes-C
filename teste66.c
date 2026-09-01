#include <stdio.h>

    int contador = 0;

void organizar(int numeros[], int tamanho) {

    int ordem;

    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = i; i < tamanho; j++) {
            if (numeros[i] > numeros[j]) {
                printf("Troca %d    <-  ->      %d", numeros[i], numeros[j]);
                ordem = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = ordem;
                contador++;
            }
        }
    }
}

int main() {

    int numeros[5] = {0, 0, 0, 0, 0};
    int tamanho = 5;

    printf("\n\nInsira os numeros: \n\n");
    for (int i = 0; i < 5; i++) {
        printf("Numero %d: [%d]", (i + 1), numeros[i]);
        scanf("%d", &numeros[i]);
    }

    printf("\n\n");
    organizar(numeros, tamanho);
    printf("\n\n");
    
    printf("\n\nNumeros reorganizados: \n\n");
    for (int i = 0; i < 5; i++) {
        printf("Numero %d: [%d]\n", (i + 1), numeros[i]);
    }






}