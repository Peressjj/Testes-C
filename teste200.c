// 23.06.26
#include <stdio.h>
#include <string.h>
// arquivos

typedef struct Pessoa {
    char nome[50];
    int idade;
    float altura;
} Pessoa;


int main() {

    FILE *arq;

    Pessoa p1[3];
    
    strcpy(p1[0].nome, "Peres");
    strcpy(p1[1].nome, "Cabeli");
    strcpy(p1[2].nome, "Chapeco");

    p1[0].idade = 20;
    p1[1].idade = 21;
    p1[2].idade = 19;

    p1[0].altura = 1.80;
    p1[1].altura = 1.70;
    p1[2].altura = 1.73;

    
    arq = fopen("teste200.txt", "w");
    
    if (arq == NULL) {
        printf("Falha ao abrir arquivo!\n");
    } else {
        printf("Arquivo aberto com sucesso!\n");
    }
    
    printf("Insira um nome: ");
    fgets(p1[0].nome, 50, stdin);
    printf("Insira a idade: ");
    scanf("%d", &p1[0].idade);
    printf("Insira a altura: ");
    scanf("%f", &p1[0].altura);
    
    for (int i = 0; i < 3; i++) {
        fprintf(arq, "Pessoa %d\n", (i + 1));
        fprintf(arq, "Nome: %s\n", p1[i].nome);
        fprintf(arq, "Idade: %d\n", p1[i].idade);
        fprintf(arq, "Altura: %.2f\n\n", p1[i].altura);
    }


    fprintf(arq, "Nome: %s", p1[0].nome);
    fprintf(arq, "Idade: %d\n", p1[0].idade);
    fprintf(arq, "Altura: %.2f\n\n", p1[0].altura);
    
    fclose(arq);

    arq = fopen("teste200.dat", "wb");

    fwrite(&p1, sizeof(Pessoa), 3, arq);
    
    fclose(arq);










    printf("\n\nPrograma encerrado!\n");

    return 0;
}