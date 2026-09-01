#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// ordena crescentemente numeros aleatórios

void ordenarnumeros(int numeros[], int tamaho) {

    
    int ordem;

    for (int i = 0; i < tamaho - 1; i++) {
        for (int j = i; j < tamaho; j++) {
            if (numeros[i] > numeros[j]) {
                ordem = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = ordem;
            }
        }
    }
}

int main() {

    srand(time(NULL));

    int array[9] = {rand() % 50 + 1, rand() % 50 + 1, rand() % 50 + 1, rand() % 50 + 1, rand() % 50 + 1, rand() % 50 + 1, rand() % 50 + 1, rand() % 50 + 1, rand() % 50 + 1};
    int variv = 9;

    ordenarnumeros(array, variv);

    for (int i = 0; i < variv; i++) {
        printf("%d\t\n", array[i]);
    }























return 0;
}