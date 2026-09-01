#include <stdio.h>
// exercicio descritivo da prova mes 2

int main() {

    int linhas, colunas;
    
    printf("Insira a quantidade de linhas e colunas da matriz pomar: \n");



    while (linhas == 0 || colunas == 0) {

        printf("O numero de linhas e colunas nao pode ser zero!!!\n");

        scanf("%d", &linhas);
        printf("Linhas: %d", linhas);

        scanf("%d", &colunas);
        printf("Colunas: %d", colunas);
    }

    char matriz[linhas][colunas];

    printf("Insira:\nP - Pitanga.\nA - Acerola.\nG - Guabiroba.");

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%s", &matriz[i][j]);
        }
    }

     int pitanga = 0;
     int acerola = 0;
     int guabiroba = 0;

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (matriz[i][j] == "p") {
                pitanga++;
            } else if (matriz[i][j] == "a") {
                acerola++;
            } else if (matriz[i][j] == "g") {
                guabiroba++;
            }
        }
    }

    printf("\n\nMatriz do pomar: \n\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Posicao   %d   x   %d:   [%d]\n", i, j, matriz[i][j]);
        }
    }

    printf("\nQuantidade total de frutas:\n\n");
    printf("Pitanga: %d\n", pitanga);
    printf("Acerola: %d\n", acerola);
    printf("Guabiroba: %d", guabiroba);

    int opcao = 0;

    while (opcao != 0) {
        printf("1 -  escolher linha\n0 - Sair.");
        scanf("%d", &opcao);

        int linhaescolhida = 0;

        printf("Escolha a linha:  ");

        while (linhaescolhida > linhas) {
            printf("A linha escolhida nao pode ser maior que a quantidade de linhas.\n");
            scanf("%d", &linhaescolhida);
        }

    int pitangalinha = 0;
    int acerolalinha = 0;
    int guabirobalinha = 0;

    for (int j = 0; j < colunas; j++) {
        printf("%s\t", matriz[linhaescolhida][j]);
        if (matriz[linhaescolhida][j] == "p") {
            pitangalinha++;
        } else if (matriz[linhaescolhida][j] == "a") {
            acerolalinha++;
        } else if (matriz[linhaescolhida][j] == "g") {
            guabirobalinha++;
        } else {
            break;
        }
    }

    printf("Frutas na linha %d:\n\n", linhaescolhida);
    printf("Pitanga: %d\n", pitangalinha);
    printf("Acerola: %d\n", acerolalinha);
    printf("Guabiroba: %d", guabirobalinha);

return 0;
}