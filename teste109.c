#include <stdio.h>
// Recursividade / funcoes recursivas

/* o codigo pega um numero fornecido pelo usuario e faz uma contagem regressiva */

void contagemregressiva(int n);

int main() {

    int numero;
    printf("Insira um numero: \n");
    scanf("%d", &numero);

    contagemregressiva(numero);


}

void contagemregressiva(int n) {
    if (n == 0) {
        return;
    } else {
        n -= 1;
        printf("%d\n", n);
        contagemregressiva(n); 
    }
    


}