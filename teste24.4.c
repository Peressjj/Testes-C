#include <stdio.h>

    int banana = 0;
    int maca = 0;
    int uva = 0; 

void menu() {
    printf("----------------------------------------------------------\n");
    printf("|                                                        |\n");
    printf("|                        Produtos:                       |\n");
    printf("|                                                        |\n");
    printf("|    Banana._______________%d Un.                        |\n", banana);
    printf("|    (1)        +1 Banana                                |\n");
    printf("|    (2)        -1 Banana                                |\n");
    printf("|                                                        |\n");
    printf("|    Maçã._________________%d Un.                        |\n", maca);
    printf("|    (3)        +1 Maca                                  |\n");
    printf("|    (4)        -1 Maca                                  |\n");
    printf("|                                                        |\n");
    printf("|    Uva.__________________%d Un.                        |\n", uva);
    printf("|    (5)        +1 Uva                                   |\n");
    printf("|    (6)        -1 Uva                                   |\n");
    printf("|                                                        |\n");
    printf("|    (0) Sair.                                           |\n");
    printf("|                                                        |\n");
    printf("----------------------------------------------------------\n");
}


int main() {

    int opcao;

    while (opcao != 0) {
        menu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                banana++;
            break;
            case 2:
                (banana >= 1) ? banana-- : printf("ERRO!!!\n\nA quantidade de bananas nao pode ser negativa.\n\n");
            break;

            case 3:
                maca++;
            break;
            case 4:
                (maca >= 1) ? maca-- : printf("ERRO!!!\n\nA quantidade de macas nao pode ser negativa.\n\n");
            break;

            case 5:
                uva++;
            break;
            case 6:
                (uva >= 1) ? uva-- : printf("ERRO!!!\n\nA quantidade de uvas nao pode ser negativa.\n\n");
            break;
        
        default:
            printf("Programa encerrado.\n\n");
            break;
        }
    }

return 0;
}