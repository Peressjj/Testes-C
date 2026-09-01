/*
r = abre para leitura
w = cria arquivo para gravacao
a = abre ou cria arquivo para gravacao no final do arquivo
r+ = leitura e gravacao
w+ = cria arquivo para atualizacao
a+ = abre ou cria arquivo para atualizacao, gravacao feita no final do arquivo 
*/

#include <stdio.h>

int main() {

    int conta;
    char nome[50];
    float saldo;
    FILE *cfPtr;

    if ((cfPtr = fopen("teste129.arquivo.dat", "r")) == NULL) {
        printf("O arquivo nao poder ser criado.\n");
    } else {
        printf("%-10s%-13s%s\n", "conta", "Nome", "Saldo");
        while (fscanf(cfPtr, "%d%s%f", &conta, nome, &saldo) == 3) {
            printf("%-10d%-13s%7.2f\n", conta, nome, saldo);
        }
        fclose(cfPtr);
    }

    return 0;

}