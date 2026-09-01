#include <stdio.h>

int main() {

    int opcao = -1;
    
    int numeroum;
    int numerodois;
    
    
    printf("Insira um numero: \n");
    scanf("%d", &numeroum);

    printf("Insira outro numero: \n");
    scanf("%d", &numerodois);
    
    
    
    while (opcao != 0) {

        printf("Escolha a operação: \n");
        printf("1 - SOMA\n");
        printf("2 - SUBTRAÇÃO\n");
        printf("3 - MULTIPLICAÇÃO\n");
        printf("4 - DIVISÃO\n");
        printf("0 - SAIR\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("A soma dos dois numero é: %d\n", numeroum + numerodois);
            break;
            
            case 2:
                printf("A subtração dos dois numero é: %d\n", numeroum - numerodois);
            break;
            
            case 3:
                printf("O produto dos dois numero é: %d\n", numeroum * numerodois);
            break;
            
            case 4:
                if (numeroum == 0 || numerodois == 0) {
                printf("ERRO!!!");
                } else { 
                    printf("O resto é: %d", numeroum / numerodois);
                }
            break;
            
            default:
                printf("Programa encerrado.");
            break;
        }
    
    }


    return 0;
}