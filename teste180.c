// 05.06.26
#include <stdio.h>
// bubble sort

/* O programa é um algorítmo de ordenacao baseado em estruturas de repeticao
e estruturas condicionais */

int main() {

    int temp;
    int numeros[20] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 10, 15, 14, 13, 12, 11};

    printf("Numeros desordenados:\n");
    for (int i = 0; i < 16; i++) {
        printf("Numeros[%d] = %d\n", i, numeros[i]);
    }

    printf("\n\n\nOrdenando os numeros:\n");
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < (15 - i - 1); j++) {
            if (numeros[j] > numeros[j + 1]) {
                temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < 16; i++) {
        printf("Numeros[%d] = %d\n", i, numeros[i]);
    }







    return 0;
}