#include <stdio.h>


    int pasta01[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int pasta02[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    

void menu() {
    printf("-----------------------------------------\n");
    printf("|                                       |\n");
    printf("|   Escolha a pasta:                    |\n");
    printf("|                                       |\n");
    printf("|   (1) - Arquivo 01;                   |\n");
    printf("|   (2) - Arquivo 02;                   |\n");
    printf("|   (0) - Sair.                         |\n");
    printf("|                                       |\n");
    printf("-----------------------------------------\n\n");
}

void menuop1() {
    printf("-----------------------------------------\n");
    printf("|                                       |\n");
    printf("|   Arquivo 01:                         |\n");
    printf("|                                       |\n");
    printf("|   [1] =   %d                          |\n", pasta01[0]);
    printf("|   [2] =   %d                          |\n", pasta01[1]);
    printf("|   [3] =   %d                          |\n", pasta01[2]);
    printf("|   [4] =   %d                          |\n", pasta01[3]);
    printf("|   [5] =   %d                          |\n", pasta01[4]);
    printf("|   [6] =   %d                          |\n", pasta01[5]);
    printf("|   [7] =   %d                          |\n", pasta01[6]);
    printf("|   [8] =   %d                          |\n", pasta01[7]);
    printf("|   [9] =   %d                          |\n", pasta01[8]);
    printf("|   [10] =   %d                         |\n", pasta01[9]);
    printf("|                                       |\n");
    printf("|   (1) - Adicionar valor.              |\n");
    printf("|   (0) - Voltar.                       |\n");
    printf("|                                       |\n");
    printf("-----------------------------------------\n\n");
}

void menuop2() {
    printf("-----------------------------------------\n");
    printf("|                                       |\n");
    printf("|   Arquivo 02:                         |\n");
    printf("|                                       |\n");
    printf("|   [1] =   %d                          |\n", pasta02[0]);
    printf("|   [2] =   %d                          |\n", pasta02[1]);
    printf("|   [3] =   %d                          |\n", pasta02[2]);
    printf("|   [4] =   %d                          |\n", pasta02[3]);
    printf("|   [5] =   %d                          |\n", pasta02[4]);
    printf("|   [6] =   %d                          |\n", pasta02[5]);
    printf("|   [7] =   %d                          |\n", pasta02[6]);
    printf("|   [8] =   %d                          |\n", pasta02[7]);
    printf("|   [9] =   %d                          |\n", pasta02[8]);
    printf("|   [10] =   %d                         |\n", pasta02[9]);
    printf("|                                       |\n");
    printf("|   (1) - Adicionar valor.              |\n");
    printf("|   (2) - Voltar.                       |\n");
    printf("|                                       |\n");
    printf("-----------------------------------------\n\n");
}

void subop1() {
    printf("Escolha o arquivo: \n");
    printf("(1) - Arquivo 01.   Valor armazenado:   %d\n", pasta01[0]);
    printf("(2) - Arquivo 02.   Valor armazenado:   %d\n", pasta01[1]);
    printf("(3) - Arquivo 03.   Valor armazenado:   %d\n", pasta01[2]);
    printf("(4) - Arquivo 04.   Valor armazenado:   %d\n", pasta01[3]);
    printf("(5) - Arquivo 05.   Valor armazenado:   %d\n", pasta01[4]);
    printf("(6) - Arquivo 06.   Valor armazenado:   %d\n", pasta01[5]);
    printf("(7) - Arquivo 07.   Valor armazenado:   %d\n", pasta01[6]);
    printf("(8) - Arquivo 08.   Valor armazenado:   %d\n", pasta01[7]);
    printf("(9) - Arquivo 09.   Valor armazenado:   %d\n", pasta01[8]);
    printf("(10) - Arquivo 10.  Valor armazenado:   %d\n", pasta01[9]);
    printf("(0) - Sair.\n\n");
}

void subop2() {
    printf("Escolha o arquivo: \n");
    printf("(3) - Arquivo 03.   Valor armazenado:   %d\n", pasta02[0]);
    printf("(2) - Arquivo 02.   Valor armazenado:   %d\n", pasta02[1]);
    printf("(1) - Arquivo 01.   Valor armazenado:   %d\n", pasta02[2]);
    printf("(4) - Arquivo 04.   Valor armazenado:   %d\n", pasta02[3]);
    printf("(5) - Arquivo 05.   Valor armazenado:   %d\n", pasta02[4]);
    printf("(6) - Arquivo 06.   Valor armazenado:   %d\n", pasta02[5]);
    printf("(7) - Arquivo 07.   Valor armazenado:   %d\n", pasta02[6]);
    printf("(8) - Arquivo 08.   Valor armazenado:   %d\n", pasta02[7]);
    printf("(9) - Arquivo 09.   Valor armazenado:   %d\n", pasta02[8]);
    printf("(10) - Arquivo 10.  Valor armazenado:   %d\n", pasta02[9]);
    printf("(0) - Sair\n\n");
}



int main() {

    int opcao;

    int opsub1;
    int arqesc1;

    int opsub2;
    int arqesc2;
    

    while (opcao != 0) {
        menu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                subop1();
                printf("(1) - Adicionar valor ao arquivo\n");
                printf("(0) - Sair.");
                scanf("%d", &opsub1);
                if (opsub1 == 1) {
                    printf("Escolha o arquivo e adicione o valor a adicionar:\n\n");
                    scanf("%d", &arqesc1);
                    switch (arqesc1) {
                    case 1:
                        scanf("%d", &pasta01[0]);    
                    break;
                    case 2:
                        scanf("%d", &pasta01[1]);    
                    break;
                    case 3:
                        scanf("%d", &pasta01[2]);    
                    break;
                    case 4:
                        scanf("%d", &pasta01[3]);    
                    break;
                    case 5:
                        scanf("%d", &pasta01[4]);    
                    break;
                    case 6:
                        scanf("%d", &pasta01[5]);    
                    break;
                    case 7:
                        scanf("%d", &pasta01[6]);    
                    break;
                    case 8:
                        scanf("%d", &pasta01[7]);    
                    break;
                    case 9:
                        scanf("%d", &pasta01[8]);    
                    break;
                    case 10:
                        scanf("%d", &pasta01[9]);    
                    break;
                    default:
                        printf("Opcao invalida!");
                    break;
                    }
                    printf("\n");
                    }
                else if (opsub1 == 0) {
                break;
                }
                else {
                    printf("ERRO!!!");
                }
            break;

            case 2:
                subop2();  
                printf("(1) - Adicionar valor ao arquivo\n");
                printf("(0) - Sair.");
                scanf("%d", &opsub2);
                if (opsub2 == 1) {
                    printf("Escolha o arquivo e adicione o valor a adicionar:\n\n");
                    scanf("%d", &arqesc2);
                    switch (arqesc2) {
                    case 1:
                       scanf("%d", &pasta02[0]);      
                    break;
                    case 2:
                        scanf("%d", &pasta02[1]);    
                    break;
                    case 3:
                        scanf("%d", &pasta02[2]);    
                    break;
                    case 4:
                        scanf("%d", &pasta02[3]);    
                    break;
                    case 5:
                        scanf("%d", &pasta02[4]);    
                    break;
                    case 6:
                        scanf("%d", &pasta02[5]);    
                    break;
                    case 7:
                        scanf("%d", &pasta02[6]);    
                    break;
                    case 8:
                        scanf("%d", &pasta02[7]);    
                    break;
                    case 9:
                        scanf("%d", &pasta02[8]);    
                    break;
                    case 10:
                        scanf("%d", &pasta02[9]);    
                    break;
                    default:
                        printf("Opcao invalida!");
                    break;
                    }
                    printf("\n");  
                    }
                else if (opsub1 == 0) {
                break;
                }
                else {
                    printf("ERRO!!!");
                }    
            break;

            default:
                printf("Programa encerrado.\n\n");
            break;
        }
    }
return 0;
}