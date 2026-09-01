#include <stdio.h>
// fgets

/* O programa é um sistema simples que armazena e mostra nome de clientes armazenados
em array */

int nomescadastrados = 0;
void menu() {

    printf("-------------------------------------------\n");
    printf("|   Menu:                                 |\n");
    printf("|                                         |\n");
    printf("|   1 - Cadastrar nomes:                  |\n");
    printf("|                                         |\n");
    printf("|   2 - Exibir lista de nomes:            |\n");
    printf("|                                         |\n");
    printf("|   0 - Sair.                             |\n");
    printf("|                                         |\n");
    printf("-------------------------------------------\n");

}

int main() {

    char nomes[15][50];

    int opcao = -1;
    while (opcao != 0) {
        menu();
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 0:
            printf("Saindo, ");
            break;
            
            case 1: // Cadastrar nomes
                getchar();
                printf("Insira o nome do cliente %d: ", (nomescadastrados + 1));
                fgets(nomes[nomescadastrados], 50, stdin);
                printf("Nome salvo!\n");
                nomescadastrados++;
            break;

            case 2: // exibir lista de nomes
                    printf("-------------------------------------------\n");
                    printf("|   Nomes cadastrados: %d                  |\n", nomescadastrados);
                    printf("|                                         |\n");
                for (int i = 0; i < nomescadastrados; i++) {
                    printf("|   %d - %-31s                            |\n", (i + 1), nomes[i]);        
                }
                    printf("|                                         |\n");
                    printf("-------------------------------------------\n\n\n");
            break;
            
            default:
                printf("Opcao inválida.\n");
            break;
        }
    }
    
    printf("programa encerrado.\n");






}