#include <stdio.h>
// funcao recursiva

/* o codigo pega o numero que o usuario inseriu e faz uma contagem de zero até
ele */

void somarnumeros(int n, int z);

int main() {

    int zero = 0;
    int numero;
    printf("Insira um numero: \n");
    scanf("%d", &numero);
    somarnumeros(numero, zero);


}

void somarnumeros(int n, int z) {

    if (z == n) {
        printf("\nNumero: %d\n", n);
        printf("Zero: %d\n", z);
    } else {
        printf("Zero: %d\n", z);
        z += 1;
        somarnumeros(n, z);
    }

}