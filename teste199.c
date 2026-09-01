// 22.06.26
#include <stdio.h>
// arquivos

int main() {

    FILE *arq;

    char nome[50];
    printf("Insira um nome: ");
    fgets(nome, 50, stdin);

    int idade;
    printf("Insira a idade: ");
    scanf("%d", &idade);

    arq = fopen("teste199.txt", "w");

    if (arq == NULL) {
        printf("Falha ao abrir arquivo!\n");
    } else {
        printf("Arquivo aberto com sucesso!\n");
    }

    fprintf(arq, "Nome: %s\n", nome);
    fprintf(arq, "Idade: %d\n", idade);

    fclose(arq);

    printf("Leitura do arquivo: \n");

    arq = fopen("teste199.txt", "a");

    while(fscanf(arq,"%49[^;];%d", nome, &idade)==2) {
        printf("Nome: %s\n Idade: %d\n", nome, idade);
    } 

    









    printf("Programa encerrado!\n");

    return 0;
}