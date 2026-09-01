#include <stdio.h>
/*
O sistema reorganiza os numeros em ordem crescente e conta quantas alteracoes foram 
feitas na sequencia
*/

int contador = 0;

void organizar(int numeros[], int tamanho) {

    int ordem;

    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = i; j < tamanho; j++) {
            if (numeros[i] > numeros[j]) {
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

    organizar(numeros, tamanho);
    printf("\n\nNumeros em ordem: \n\n");

    for (int i = 0; i < 5; i++) {
        printf("Numero %d: [%d]\n", (i + 1), numeros[i]);
    }
    printf("\nAlteracoes: %d\n", contador);









}