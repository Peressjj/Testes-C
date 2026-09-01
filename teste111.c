#include <stdio.h>
// recursividade / funcao recursiva

/* o programa pega o numero que o usuario inseriu e faz o somatorio 
dele desde zero até ele */

void somar(int n, int z, int t);

int main() {

    int numero; 
    int total = 0;
    int zero = 0;
    printf("\nInsira um numero: \n");
    scanf("%d", &numero);

    printf("∑%d = ", numero);
    somar(numero, zero, total);
    
    
}

void somar(int n, int z, int t) {
    
    if (z == n) {
        printf(" = %d\n", t);
        return;
    } else {
        z += 1;
        t += z;
        printf(" + %d", z);
        somar(n, z, t);
    }

  

}