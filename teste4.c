#include <stdio.h>

int main () {   

    int idade = 0;
    char nome[20];
    float altura = 0;


    printf("======= CADASTRO DE CLIENTE =======\n");

    printf("Digite sua idade: ");
    scanf("%d", &idade);
        
    printf("Digite seu nome: ");    
    scanf("%s", nome);    
        
    printf("Digite sua altura: ");    
    scanf("%f", &altura);    

    printf("\n======= FICHA DE CLIENTE =======\n NOME: %s\n IDADE: %d\n ALTURA: %f\n", nome, idade, altura);

    // Classificacao por idade
    if (idade < 18) {
        printf("Menor de idade\n");
    }

    else if (idade < 60) {
        printf("Adulto\n");
    }

    else {
        printf("Idoso\n");
    }

    // Classificacao por altura
    if (altura < 1.6) {
        printf("Baixo\n");
    }

    else if (altura <= 1.8) {
        printf("Médio\n");
    }
   
    else {
        printf("Alto\n\n\n");
    }

    return 0;        
}