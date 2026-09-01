#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//sorteador de nomes

int main() {

    srand(time(NULL));

    char nomes[25][50]; 
    strcpy(nomes[0], "Bulcao");
    strcpy(nomes[1], "Dranski");
    strcpy(nomes[2], "Diogo");
    strcpy(nomes[3], "Assis");
    strcpy(nomes[4], "De lara");
    strcpy(nomes[5], "Rafael Lima");
    strcpy(nomes[6], "P. Lima");
    strcpy(nomes[7], "Lucini");
    strcpy(nomes[8], "M. Vieira");
    strcpy(nomes[9], "Israel");
    strcpy(nomes[10], "Willian");
    strcpy(nomes[11], "Rodrigues");
    strcpy(nomes[12], "Arruda");
    strcpy(nomes[13], "Pedro");
    strcpy(nomes[14], "Calebi");
    strcpy(nomes[15], "Igor Franca");
    strcpy(nomes[16], "Neto");
    strcpy(nomes[17], "Jefferson");
    strcpy(nomes[18], "Pacheco");
    strcpy(nomes[19], "Peres");
    strcpy(nomes[20], "Thomsen");
    strcpy(nomes[21], "Leonardo");

    int total = 22;

    int opcao = 1;

    while (opcao != 0) {
        int numeroaleatorio = rand() % total;
        printf("1 - Sortear um nome.\n0 - Sair.\n");
        scanf("%d", &opcao);
        printf("O nome sorteado foi: %s\n", nomes[numeroaleatorio]);
    }

    printf("Programa encerrado. \n");














return 0;
}