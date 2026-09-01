#include <stdio.h>

int main() {

// Exercicio 4

    float nota1;
    float nota2;

    printf("EXERCICIO 04:\n\nInsira a primeira nota do aluno: \n");
    scanf("%f", &nota1);
    printf("Insira a segunda nota do aluno: \n");
    scanf("%f", &nota2);

    float notafinal = (nota1 + nota2) / 2;
    printf("Nota: %f", notafinal);

    if (notafinal >= 60) {
    printf("Aluno aprovado\n");
    } else {
    printf("Aluno reprovado\n");
    }



// Exercicio 5

    int year;

    printf("EXERCICIO 05:\n\nInsira sua idade: \n");
    scanf("%d", &year);

    if (year >= 18){
    printf("Maior de idade.\n");
    } else {
    printf("Menor de idade.\n");
    }



// Exercicio 6

    int numero;

    printf("EXERCICIO 06:\n\nInsira um número");
    scanf("%i", &numero);

    if (numero > 0) {
    printf("Número positivo.\n");
    } else if (numero < 0) {
    printf("Numero negativo.\n");
    } else if (numero == 0) {
    printf("Número igual a zero.\n");
    }
    else {
    printf("ERRO!!!");
    }



// Exercício 7

    float peso;
    float altura;

    printf("EXERCICIO 07:\n\nInsira seu peso (em KG), vamos calcular seu IMC como adulto. \n");
    scanf("%f", &peso);

    printf("Insira sua altura (em metros): \n");
    scanf("%f", &altura);

    float imc = peso / (altura * altura);

    if (imc <= 18.5) {
    printf("Seu IMC é igual a %d, vc está abaixo do peso\n", imc);
    }
    else if (imc <= 24.9) {
    printf("Seu IMC é igual a %d, vc está com o peso normal.\n", imc);
    }
    else if (imc <= 29.9) {
    printf("Seu IMC é igual a %d, vc está acima do peso.\n", imc);
    }
    else if (imc >= 30) {
    printf("Seu IMC é %d, voce está obeso.\n", imc);
    } else {
    printf("ERRO!");
    }

return 0;
}