#include <stdio.h>

    int main() {
    
    char nome[50];
    int idade = 0;

    printf("Olá, qual seu nome?");
    scanf("%s", nome);

    printf("%s, quantos anos voce tem?", nome);
    scanf("%d", &idade);

    if (idade >= 18) {
    printf("%s, voce tem %d anos, portanto, é maior de idade.", nome, idade);
}   else {
    printf("%s, voce tem %d anos, portanto voce é menor de idade.", nome, idade);
}

    return 0;
    };