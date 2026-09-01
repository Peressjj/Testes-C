#include <stdio.h>

typedef struct {
    int senha;
} Cofre;

int main() {

    Cofre cofres[10];
    int opcao = 0;
    int numeroCofre;
    int senhaDigitada, confirmacao;
    int encontrado;

    // Inicializar todos os cofres como livres
    for (int i = 0; i < 10; i++) {
        cofres[i].senha = 0;
    }

    while (opcao != 3) {

        // Mostrar guarda-volumes
        printf("\nGUARDA VOLUMES:\n");
        printf("-----------------------------\n");

        for (int i = 0; i < 10; i++) {
            printf("| Cofre %02d ", i + 1);

            if (cofres[i].senha == 0) {
                printf("[🔓] |\n");
            } else {
                printf("[🔒] |\n");
            }
        }

        printf("-----------------------------\n");

        // Menu principal
        printf("\n1 - Trancar cofre");
        printf("\n2 - Abrir cofre");
        printf("\n3 - Sair");
        printf("\nEscolha: ");
        scanf("%d", &opcao);

        // TRANCAR COFRE
        if (opcao == 1) {

            printf("Escolha o número do cofre (1-10): ");
            scanf("%d", &numeroCofre);

            if (numeroCofre < 1 || numeroCofre > 10) {
                printf("Número inválido!\n");
            } 
            else if (cofres[numeroCofre - 1].senha != 0) {
                printf("Cofre já está em uso!\n");
            } 
            else {

                printf("Digite uma senha de 4 dígitos: ");
                scanf("%d", &senhaDigitada);

                if (senhaDigitada < 1000 || senhaDigitada > 9999) {
                    printf("Senha inválida! Deve ter 4 dígitos.\n");
                } 
                else {

                    printf("Confirme a senha: ");
                    scanf("%d", &confirmacao);

                    if (senhaDigitada == confirmacao) {
                        cofres[numeroCofre - 1].senha = senhaDigitada;
                        printf("Cofre trancado com sucesso!\n");
                    } else {
                        printf("Senhas não conferem!\n");
                    }
                }
            }
        }

        // ABRIR COFRE
        else if (opcao == 2) {

            printf("Digite a senha: ");
            scanf("%d", &senhaDigitada);

            encontrado = 0;

            for (int i = 0; i < 10; i++) {
                if (cofres[i].senha == senhaDigitada) {
                    cofres[i].senha = 0; // reset
                    printf("Cofre %02d aberto com sucesso!\n", i + 1);
                    encontrado = 1;
                }
            }

            if (!encontrado) {
                printf("Senha incorreta!\n");
            }
        }

        else if (opcao != 3) {
            printf("Opção inválida!\n");
        }
    }

    printf("Sistema encerrado.\n");

    return 0;
}