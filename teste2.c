#include <stdio.h>

    int main() {

        int idade = 0;
        char nome[50];

    printf("Qual seu nome?");
    scanf("%s", nome);

    printf("Seu nome é %s, %s quantos anos vc tem?", nome, nome);
    scanf("%d", &idade);
    
    printf("Olá %s, sua idade é %d", nome, idade);

    return 0;
    }