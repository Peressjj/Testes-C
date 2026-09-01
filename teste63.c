#include <stdio.h>
// O usuário insere os numeros e o sistema os coloca na ordem

void ordemcrescente(int numeros[], int quantidade) {

    int ordem;

    for (int i = 0; i < quantidade - 1; i++) {
        for (int j = i; j < quantidade; j++) {
            if (numeros[i] > numeros[j]) {
                ordem = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = ordem;
            }
        }
    }
}

int main() {

    int numeros[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int tam = 10;

    printf("\nInsira os numeros: \n\n");
    for (int i = 0; i < tam; i++) {
        printf("Posicao %d: ", (i + 1));
        scanf("%d", &numeros[i]);
    }

    ordemcrescente(numeros, tam);

    printf("\n\nNumeros na ordem:\n\n");
    for (int i = 0; i < tam; i++) {
        printf("Numero %d: [%d]\n", (i + 1), numeros[i]);
    }





}