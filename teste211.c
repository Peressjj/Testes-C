// 28.06.26
#include <stdio.h>
#include <string.h>
// arquivos
// busca

    typedef struct pessoa {
        char nome[50];
        int idade;
    } pessoa;
    
    pessoa listapessoas[3] = {
        {"Joao_Peres", 20},
        {"Henrique_Thomsen", 20},
        {"Rubens_de_Lara", 24}
    };

int main() {

    FILE *arq;

    arq = fopen("teste211.txt", "w");

    if (arq == NULL) {
        printf("Falha ao abrir arquivo 'teste211.txt'!\n");
    } else {
        printf("Arquivo 'teste211.txt' aberto com sucesso!\n");
    }

    for (int i = 0; i < 3; i++) {
        fprintf(arq, "%s %d\n\n", listapessoas[i].nome, listapessoas[i].idade);
    }

    fclose(arq);
    printf("Arquivo 'teste211.txt' fechado!\n");

    printf("Abrindo o arquivo para busca:\n");

    arq = fopen("teste211.txt", "r");

    if (arq == NULL) {
        printf("Falha ao abrir arquivo 'teste211.txt'!\n");
    } else {
        printf("Arquivo 'teste211.txt' aberto com sucesso!\n");
    }

    char nome[50];
    int idade;
    char procurado[50];
    printf("\nDigite o nome da pessoa que deseja procurar: ");
    scanf("%49s", &procurado);
    printf("Procurado: %s\n", procurado);

    while (fscanf(arq, "%49s %d", nome, &idade) == 2) {
        if (strcmp(nome, procurado) == 0) {
            printf("\nPessoa encontrada!\n");
            printf("Nome: %s\n", nome);
            printf("Idade: %d\n", idade);
            break;
        } else {
            printf("Pessoa nao encontrada!\n");
        }
    }
    
    
    
    
    
    
    
    
    fclose(arq);
    printf("\n\nArquivo 'teste211.txt' fechado!\n");
    
    printf("\n\nPrograma encerrado!\n");
    return 0;
}