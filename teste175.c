//31.05.2026
#include <stdio.h>
#include <stdlib.h>
// realloc

    typedef struct aluno {
        char nome[50];
        int nota1, nota2, nota3;
    } aluno;
    
    aluno *lista_alunos = NULL;
    int quant_alunos = 0;

void exibemenu() {
    
    printf("-----------------------------------------------\n");    
    printf("|                                             |\n");
    printf("|    1 - Cadastrar aluno:                     |\n");
    printf("|                                             |\n");
    printf("|    2 - Exibir lista de alunos:              |\n");
    printf("|                                             |\n");
    printf("|    0 - Sair.                                |\n");
    printf("|                                             |\n");
    printf("-----------------------------------------------\n");
    
}

void cadastraraluno() {

    lista_alunos = realloc(lista_alunos, (quant_alunos + 1) * sizeof(aluno));

    aluno *temp = realloc(lista_alunos, (quant_alunos + 1) * sizeof(aluno));

    if (temp == NULL) {
        printf("Falha ao alocar memória\n");
        return;
    }

    lista_alunos = temp;

    printf("-------------------------------------------------\n");    
    printf("|              CADASTRO DE ALUNOS:              |\n");
    printf("|                                               |\n");
    printf("|    Alunos cadastrados: %d                     |\n", quant_alunos);
    printf("|                                               |\n");
    printf("|    Insira o nome do aluno:                    |\n");
    getchar();
    fgets(lista_alunos[quant_alunos].nome, 50, stdin);
    printf("|    Insira a nota3 1: ");
    scanf("%d", &lista_alunos[quant_alunos].nota1);
    printf("|    Insira a nota 2: ");
    scanf("%d", &lista_alunos[quant_alunos].nota2);
    printf("|    Insira a nota 3: ");
    scanf("%d", &lista_alunos[quant_alunos].nota3);
    printf("|                                               |\n");
    printf("|   Aluno cadastrado com sucesso!               |\n");
    printf("|                                               |\n");
    printf("-------------------------------------------------\n");  
    
    quant_alunos++;
}

void exibelistaaluno() {

    int nota_final[quant_alunos];


            printf("-------------------------------------------------\n");    
            printf("|                LISTA DE ALUNOS:               |\n");
            printf("|                                               |\n");
            printf("|   Alunos cadastrados: %d                      |\n", quant_alunos);
            printf("|                                               |\n");
            printf("|   ALUNOS APROVADOS:                           |\n");
    for (int i = 0; i < quant_alunos; i++) {
        nota_final[i] = 0;
        nota_final[i] += lista_alunos[i].nota1;
        nota_final[i] += lista_alunos[i].nota2;
        nota_final[i] += lista_alunos[i].nota3;
        nota_final[i] = (nota_final[i] / 3);
        if (nota_final[i] >= 60) {
            printf("| Nome: %s", lista_alunos[i].nome);
            printf("| Média: %d\n", nota_final[i]);

        }
    }
            printf("|                                               |\n");
            printf("|   ALUNOS REPROVADOS:                          |\n");
    for (int i = 0; i < quant_alunos; i++) {
        nota_final[i] = 0;
        nota_final[i] += lista_alunos[i].nota1;
        nota_final[i] += lista_alunos[i].nota2;
        nota_final[i] += lista_alunos[i].nota3;
        nota_final[i] = (nota_final[i] / 3);
        if (nota_final[i] <= 59) {
            printf("| Nome: %s", lista_alunos[i].nome);
            printf("| Média: %d\n", nota_final[i]);
        }
    }
            printf("|                                               |\n");
            printf("-------------------------------------------------\n");    

}

int main() {

    int opcao = -1;
    while (opcao != 0) {
        exibemenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: // cadastrar alunos
                cadastraraluno();
            break;
            
            case 2: // exibir lista de alunos
                exibelistaaluno();
            break;

            default:
                if (opcao == 0) {
                    printf("\n");
                } else {
                    printf("Opcao inválida.\n");
                }
            break;
        }
    }
        
    printf("Programa encerrado.\n");
    free(lista_alunos);









    return 0;
}