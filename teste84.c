#include <stdio.h>
// recursividade

long fat(long);

int main() {

    long numero;
    printf("Insira um numero: \n");
    scanf("%d", &numero);
    for (int i = 0; i < numero; i++) {
        printf("%d!\n+", (numero - i));
    }
    printf("=\n%d", fat(numero));

    return 0;
}

long fat(long n) {
    if (n <= 1) {
        return 1;
    } else {
        return (n * fat(n - 1));
    } 
}