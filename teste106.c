#include <stdio.h>
// struct

/* sistema de notas de alunos */

typedef struct Aluno {
    char nome[50];
    float nota1;
    float nota2;
} Aluno;

    Aluno listaalunos[5] = {
        {"Fulano 1", 0, 0},
        {"Fulano 2", 0, 0},
        {"Fulano 3", 0, 0},
        {"Fulano 4", 0, 0},
        {"Fulano 5", 0, 0}
    };

int main() {

    int opcao = -1;

    while (opcao != 0) {
        printf("|   1 - Cadastrar nome dos 5 alunos:\n");
        printf("|   2 - Lancar nota 1 dos 5 alunos:\n");
        printf("|   3 - Lancar nota 2 dos 5 alunos:\n");
        printf("|   4 - Mostrar aprovados e reprovados:\n");
        printf("|   0 - Sair.\n");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            for (int i = 0; i < 5; i++) {
                printf("Aluno %d:   ", (i + 1));
                scanf("%s", &listaalunos[i].nome);
                printf("\nNome do aluno %s cadastrado com sucesso!\n", listaalunos[i].nome);
            }

            for (int i = 0; i < 5; i++) {
                printf("\nAluno %d: %s\n\n", (i + 1), listaalunos[i].nome);
            }    
        break;

        case 2: 
            for (int i = 0; i < 5; i++) {
                printf("Insira a nota 1 do aluno %s: ", listaalunos[i].nome);
                scanf("%f", &listaalunos[i].nota1);
            }

            for (int i = 0; i < 5; i++) {
                printf("Aluno %s, nota 1: %.2f\n", listaalunos[i].nome, listaalunos[i].nota1);
            }
        break;
        
        case 3: 
            for (int i = 0; i < 5; i++) {
                printf("Insira a nota 2 do aluno %s: ", listaalunos[i].nome);
                scanf("%f", &listaalunos[i].nota2);
            }

            for (int i = 0; i < 5; i++) {
                printf("Aluno %s, nota 2: %.2f\n", listaalunos[i].nome, listaalunos[i].nota2);
            }
        break;

        case 4:
            for (int i = 0; i < 5; i++) {
                printf("Nota 1 de %s: %.2f\n", listaalunos[i].nome, listaalunos[i].nota1);
                printf("Nota 2 de %s: %.2f\n", listaalunos[i].nome, listaalunos[i].nota2);
            }

            printf("Aprovados: \n\n");
            for (int i = 0; i < 5; i++) {
                if (((listaalunos[i].nota1 + listaalunos[i].nota2) / 2) > 60) {
                    printf("Aluno %s aprovado.\n", listaalunos[i].nome);
                }
            }

            printf("Reprovados: \n\n");
            for (int i = 0; i < 5; i++) {
                if (((listaalunos[i].nota1 + listaalunos[i].nota2) / 2) < 60) {
                    printf("Aluno %s reprovado.\n", listaalunos[i].nome);
                }
            
            }
            printf("\n\n");
        break;

        default:
            break;
        }





    }
    
    printf("Programa encerrado.\n");



}