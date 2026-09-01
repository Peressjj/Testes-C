#include <stdio.h>

int fat(int n);

int main() {

    int numero;

    printf("Insira um numero: \n");
    scanf("%d", &numero);

    int resultado = fat(numero);

    printf("Resultado: %d! = %d\n", numero, resultado);
}

int fat(int n) {

    if (n <= 1) {
        return 1;
    } else {
        return n * fat(n - 1);
    }


}