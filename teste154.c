// 25/05/2026
#include <stdio.h>
#include <string.h>0
// strcpy
// ponteiro

/* Copia de string da variavel origem para a variavel destino, utilizando
strcpy e ponteiro */

int main() {

    char nome_origem[] = {"Peres"};

    char *Ptr = nome_origem;

    char nome_destino[50];

    printf("Nome origem: %s\n", nome_origem);
    printf("Nome destino: %s\n\n", nome_destino);
    printf("strcpy(nome_destino, Ptr);\n\n");

    strcpy(nome_destino, Ptr);
    
    printf("Nome origem: %s\n", nome_origem);
    printf("Nome destino: %s\n", nome_destino);

    return 0; 
}