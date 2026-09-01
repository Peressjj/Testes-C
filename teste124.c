#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// mega sena sem repetir numeros;

int main() {

    srand(time(NULL));

    int numeros[50];
    int contador = 0;

    while (contador < 50) {
        int numero = rand() % 8888 + 1111;
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
    
    for (int i = 0; i < 50; i++) {
        printf("Numero %d: [%d]\n", i, numeros[i]);
    }


return 0;
}