#include <stdio.h>

int main() {

    int conta;
    char nome[50];
    float saldo;
    FILE *cfPtr; // Ponteiro para FILE

    if ((cfPtr = fopen("teste127.arquivo.dat", "r+")) == NULL) {
        printf("O arquivo nao pode ser aberto.\n");
        return 1;
    } 

    printf("Digite a conta, o nome e o saldo: ");
    printf("\t(Ctrl + Z (Windows) para encerrar.)\n");

    while (scanf("%d %49s %f", &conta, nome, &saldo) == 3) {
        fprintf(cfPtr, "%d %s %.2f\n", conta, nome, saldo);
        printf("Conta de %s cadastrada com sucesso!\n", nome);
    }

    fclose(cfPtr);
    printf("Dados gravados com sucesso em teste127.arquivo.dat\n");
    


return 0;
}