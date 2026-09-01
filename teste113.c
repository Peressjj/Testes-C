#include <stdio.h>
// funcao recursiva / recursividade / recursao

/* o programa soma os numeros de um array de inteiros */

int soma(int numeros[], int total, int i);

int main() {

    int total = 0;
    int i = -1;
    int numeros[4] = {1, 2, 3};

    soma(numeros, total, i);

}

int soma(int numeros[], int total, int i) {

    
    if (numeros[(i + 1)] == '\0') {
        printf("Total: %d\n", total);
    } else {
        printf("Numero: %d\nTotal: %d\n", numeros[i], total);
        i++;
        total += numeros[i];
        soma(numeros, total, i);
    }


}