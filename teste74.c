#include <stdio.h>
#include <string.h>
// strlen = conta quantos caracteres há na funcao

int main() {

    char texto[50] = "Teste";
    
    int caracteres = strlen(texto);

    
    printf("\n%s\n", texto);
    printf("%d\n\n", caracteres);

    char nome[50];
    printf("Insira um nome: ");
    scanf("%s", &nome);

    for (int i = 0; i < strlen(nome); i++) {
        printf("%c\n", nome[i]);
    }

    printf("Caracteres: %d\n", strlen(nome));





















return 0;
}