#include <stdio.h>

int quantidadenotas;
int aprovados = 0;
int reprovados = 0;

void exibirnotas() {
    for (int i = 0; i < quantidadenotas; i++) {
        printf("Nota %d:  %d\n", i, notas[i]);
    }
    printf("\n\n\n");
}

void exibirmedia(int soma) {
    for (i = 0; i < quantidadenotas; i++) {
        soma += notas[i];
    }
    printf("A media das notas é: %d", (soma / quantidadenotas));
}

void contaraprovados() {
    for (int i = 0; i < quantidadenotas; i++) {
        if (notas[i] >= 60)  {
            aprovados++;
        } else {
            reprovados++;
        }
    }
    printf("Alunos aprovados: %d\n", aprovados);
    printf("Alunos reprovador: %d\n", reprovados);
}

int main() {
    printf("Quantas notas serao inseridas? ");
    while (quantidadenotas <= 0) {
        printf("A quantidade notas nao pode ser menor ou igual a zero!\n");
        scanf("%d", &quantidadenotas);
    }
    
    int notas[quantidadenotas];

    printf("insira as notas: \n");
    for (int i = 0; i < quantidadenotas; i++) {
        printf("Nota %d: ", i);
        scanf("%d", &notas[i]);
        printf("\n");
    }
    int opcao = 0;
    printf("\n\n\n");
    while (opcao != 0) {
        printf("1     -      Exibir todas as notas.\n");
        printf("2     -     Exibir média das notas\n.");
        printf("3     -     Contar alunos aprovados.\n");
        printf("0     -     Sair.\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                exibirnotas();
            break;

            case 2:
                exibirmedia(int soma);
            break;

            case 3:
                contaraprovados();
            break;
}

    printf("\nPrograma encerrado.\n");


return 0;

}