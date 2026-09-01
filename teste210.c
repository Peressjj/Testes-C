// 28.06.26
#include <stdio.h>
// arquivos
// fwrite
// fread

    typedef struct pessoa {
        char nome[50];
        int idade;
    } pessoa;

    pessoa listapessoas[3] = {
        {"Joao Peres", 20},
        {"Henrique Thomsen", 20},
        {"Rubens de Lara", 24}
    };

    pessoa listapessoas2[3];

int main() {

    FILE *arq;

    arq = fopen("teste210.txt", "w");

    if (arq == NULL) {
        printf("Falha ao abrir arquivo!\n");
    } else {
        printf("Arquivo aberto com sucesso!\n");
    }

    for (int i = 0; i < 3; i++) {
        fprintf(arq, "Pessoa[%d] = %s\n", i, listapessoas[i].nome);
        fprintf(arq, "Idade: %d\n\n", listapessoas[i].idade);
    }

    fclose(arq);
    printf("Arquivo 'teste210.txt' fechado!\n");

    printf("\nGravando struct no arquivo.\n\n");

    arq = fopen("teste210.dat", "wb");

    if (arq == NULL) {
        printf("Falha ao abrir arquivo!\n");
    } else {
        printf("Arquivo aberto com sucesso!\n");
    }

    for (int i = 0; i < 3; i++) {
        fwrite(&listapessoas[i], sizeof(pessoa), 1, arq);
    }

    fclose(arq);
    printf("Arquivo 'teste210.dat' fechado!\n");

    arq = fopen("teste210.dat", "rb");

    if (arq == NULL) {
        printf("Falha ao abrir arquivo!\n");
    } else {
        printf("Arquivo aberto com sucesso!\n");
    }

    for (int i = 0; i < 3; i++) {
        fread(&listapessoas2[i], sizeof(pessoa), 1, arq);
    }

    printf("\nLista de pessoas 1:\n");
    for (int i = 0; i < 3; i++) {
        printf("Pessoa[%d] = %s\n", i, listapessoas[i].nome);
        printf("Idade: %d\n", listapessoas[i].idade);
    }

    printf("\nLista de pessoas 2:\n");
    for (int i = 0; i < 3; i++) {
        printf("Pessoa[%d].nome = %s\n", i, listapessoas2[i].nome);
        printf("Idade: %d\n", listapessoas2[i].idade);
    }

    fclose(arq);
    printf("Arquivo 'teste210.dat' fechado!\n");


    printf("\n\nPrograma encerrado!\n");

    return 0;
}