#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// programa organiza os numeros em ordem crescente

void ordenar(int numeros[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            if (numeros[i] > numeros[j]) {
                int ordem = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = ordem;
            }
        }
    }
};

int main() {

    srand(time(NULL));
    int array[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int tamanho = 10;

    ordenar(array, tamanho);

    for (int i = 0; i < tamanho; i++) {
        printf("Numero %d: [%d]\n", (i + 1), array[i]);
    }



















return 0;
}