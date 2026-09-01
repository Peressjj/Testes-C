#include <stdio.h>
// funcao recursiva / recursividade 

/* O codigo pega um numero que o usuario inseriu e faz uma contagem
de zero até ele */

void contar(int n, int z);

int main() {

    int numero;
    int zero = 0;
    printf("Insira um numero: \n");
    scanf("%d", &numero);

    contar(numero, zero);

}

void contar(int n, int z) {

    if (z == n) {
        return;
    } else {
        z += 1;
        printf("%d\n", z);
        contar(n, z);
    }
    



}