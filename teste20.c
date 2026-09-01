#include <stdio.h>

int main() {

    int opcao;
    int numero;
    int multiplicando = 0;
    
    while (opcao != 0) {
        printf("---------------------------------------------------------\n");
        printf("|   TABUADA:\n                                          |\n");
        printf("|   1- Escolha um numero para vizualizar sua tabuada.   |\n");
        printf("|   0- Sair.                                            |\n");
        printf("---------------------------------------------------------\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Escolha um número: \n");
                scanf("%d", &numero);
                for (multiplicando = 0; multiplicando < 11; multiplicando++) {
                    printf("%d   x   %d   =   %d\n", numero, multiplicando, (numero * multiplicando));
                }   
            break;
        
        default:
            printf("Programa encerrado.\n");
            break;
        }

    }
    





























return 0;
}