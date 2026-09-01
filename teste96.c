#include <stdio.h>
// prototipo de funcao
// funcao recursiva / recursividade

// a funcao faz uma contagem regressiva no numero fornecido pelo usuario

void contagemregressiva(int n);

int main() {

    int numero;
    printf("Insira um numero: \n");
    scanf("%d", &numero);
    contagemregressiva(numero);

}

void contagemregressiva(int n) {
    if (n < 0) {
        return;
    }

    printf("Numero: %d\n", n);
    contagemregressiva(n - 1);
}