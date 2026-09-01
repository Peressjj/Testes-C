#include <stdio.h>

int main() {

    //Ecercicio 1
    
    int primeironumero;
    int segundonumero;
   
    printf("Insira um número: \n");
    scanf("%d", &primeironumero);

    printf("Insira o segundo número: \n");
    scanf("%d", &segundonumero);

    int resultadoa = primeironumero * segundonumero;

    printf("\nO produto é %d", resultadoa);

    //Exercício 2

    int terceironumero;
    int quartonumero;

    printf("Insira um número: \n");
    scanf("%d", &terceironumero);

    printf("Insira outro número \n");
    scanf("%d", &quartonumero);

    int resultadob = terceironumero - quartonumero;

    printf("\nA subtração entre os números é: %d", resultadob);

    //exercicio 3

    int quintonumero;
    float sextonumero;

    printf("Insira um número: \n");
    scanf("%d", &quartonumero);

    float resultado = quintonumero % 2;

    if (resultado == 0) {
    printf("Número par.\n");
    }else {
    printf("Número par. \n");
    }








return 0;
}