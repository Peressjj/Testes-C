#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// mega sena sem repetir numeros;

int main() {

    srand(time(NULL));

    int numeros[6];
    int contador = 0;

    while (contador < 6) {
        int numero = rand() % 60 + 1;
        int repetido = 0;

        for (int i = 0; i < contador; i++) {
            if (numeros[i] == numero) {
                repetido = 1;
                break;
            }
        }
        if (!repetido) {
        numeros[contador] = numero;
        contador++;
        }
    }
    
    for (int i = 0; i < 6; i++) {
        printf("Numero %d: [%d]\n", i, numeros[i]);
    }















return 0;
}