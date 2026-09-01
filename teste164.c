// 28.05.26
#include <stdio.h>
#include <string.h>
// strcat
// strncat

int main() {

    char nome[] = {"Joao"};
    char sobrenome[] = {"Peres"};
    char teste1[20], teste2[20];
    
    printf("Nome: ");
    puts(nome);
    printf("Sobrenome: ");
    puts(sobrenome);

    strcat(teste1, nome);
    strcat(teste1, sobrenome);

    strncat(teste2, nome, 3);
    strncat(teste2, sobrenome, 4);

    printf("\n\nstrcat // strncat\n");

    printf("Teste 1: ");
    puts(teste1);
    printf("Teste 2: ");
    puts(teste2);






    return 0;
}