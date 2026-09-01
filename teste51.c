#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// programa conta quantos numeros pares e impar tem no programa

int main() {

    srand(time(NULL));
    int matriz[3][3] = {rand() % 20 + 1, rand() % 20 + 1, rand() % 20 + 1, rand() % 20 + 1, rand() % 20 + 1, rand() % 20 + 1, rand() % 20 + 1, rand() % 20 + 1, rand() % 20 + 1};
    int par = 0;
    int impar = 0;

    for (int i = 0; i < 3; i++) {
        printf("|\t%d\t%d\t%d\t|\n", matriz[i][0], matriz[i][1], matriz[i][2]);
    }

    printf("\n\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if ((matriz[i][j] % 2) == 0) {
                par++;
            } else {
                impar++;
            }
        }
    }

    printf("Numeros pares: %d\nNumeros impares: %d\n", par, impar);























return 0;
}