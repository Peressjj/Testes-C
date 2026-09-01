#include <stdio.h>
// parametro de funcoes
/* Usado quando a funcao vai receber um valor externo, ou seja, de fora da funcao, para nao declarar valores, locais
utilizamos parametros, que indica que ela recebera esses respectivos valore dentro da funcao principal*/


void funcao1(int a, int b) { 
    int soma = a + b;
    printf("%d", soma);
};

int main() {

    int a, b;
    printf("Insira o valor de A e B: \n");
    scanf("%d", &a);
    scanf("%d", &b);
    funcao1(a, b);


return 0;
}