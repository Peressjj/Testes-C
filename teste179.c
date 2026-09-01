// 03.06.26
#include <stdio.h>
#include <stdlib.h>

typedef struct aluno {
    char nome[50];
} aluno;

    aluno *lista_alunos;
    int quant_alunos = 0;

int main() {

    int opcao = -1;

    lista_alunos = calloc((quant_alunos + 1), sizeof(char));

    if (lista_alunos == NULL) {
        printf("Erro ao criar memória.\n");
    }

    while (opcao != 0) {
        printf("1 - Adicionar aluno: \n");
        printf("0 - Sair.\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                printf("Saindo.\n");
            break;

            case 1:
                printf("Insira o nome do aluno: ");
                getchar();
                fgets(lista_alunos[quant_alunos].nome, 50, stdin);
                // getchar();
                // scanf("%s", &lista_alunos[quant_alunos].nome);
                printf("\n\nLISTA DE ALUNOS:\n");
                quant_alunos++;
                for (int i = 0; i < quant_alunos; i++) {
                    printf("Aluno [%d] = %s\n", (i + 1), lista_alunos[i].nome);
                }
            break;

            default:
                if (opcao != 0) {
                    printf("Opcao inválida.\n");
                }
            break;
        }
    }

    free(lista_alunos);

    printf("Programa encerrado.\n");
    












    return 0;
}