#include <stdio.h>
// funcao recursiva / recursividade
// prototipo de funcao

// funcao calcula a potencia de um numero

int calcpot(int n, int p);

int main() {

    int numero;
    int potencia = 0;
    int total;

    printf("Insira o numero\n");
    scanf("%d", &numero);

    printf("Insira a potencia: \n");
    scanf("%d", &potencia);
    
    total = calcpot(numero, potencia);

    printf("%d^%d = %d\n", numero, potencia, total);

    return 0;
}
 
int calcpot(int n, int p) {

    if (p <= 1) {
        return 1;
    }

    return n * calcpot(n, p - 1);
    
}