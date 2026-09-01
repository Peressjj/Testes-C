//28.05.26
#include <stdio.h>
#include <string.h>
// strcat

/* loop for para juntar as strings da matriz de nomes */

int main() {

    char nomecompleto[30];
    char nome[5][10] = {
    {"Joao "},
    {"Vitor "},
    {"Peres "},
    {"dos "}, 
    {"Santos"}
    };


    for (int i = 0; i < 5; i++) {
        strcat(nomecompleto, nome[i]);
    }

    puts("Nome completo: ");
    puts(nomecompleto);









    return 0;
}