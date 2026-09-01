#include <stdio.h>
// structs
// array em struct

void limpartela() {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

int main() {

    struct Carros {
        char nome[50];
        int ano;
        float motor;
    };

    struct Carros carro[3];

    int opcao = -1;
    int contveiculos = 0;

    while (opcao != 0) {
        limpartela();
        printf("\n1   -   inserir dados veículo 1.\n");
        printf("2   -   Inserir dados veiculo 2.\n");
        printf("3   -   Inserir dados veiculo 3.\n");
        printf("4   -   Mostrar veiculos.\n");
        printf("0   -   Sair.\n\n");
        
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                limpartela();
                printf("Insira o nome do veículo: \n");
                scanf("%s", &carro[0].nome);
                printf("Insira o ano do veículo: \n");
                scanf("%d", &carro[0].ano);
                printf("Insira a motorizacao do veículo: \n");
                scanf("%f", &carro[0].motor);
                printf("\n\nVeículo 1: \n");
                printf("Nome: %s\n", carro[0].nome);
                printf("Ano: %d\n", carro[0].ano);
                printf("Nome: %.1f\n", carro[0].motor);
                contveiculos++;
            break;
            case 2:
                limpartela();
                printf("Insira o nome do veículo: \n");
                scanf("%s", &carro[1].nome);
                printf("Insira o ano do veículo: \n");
                scanf("%d", &carro[1].ano);
                printf("Insira a motorizacao do veículo: \n");
                scanf("%f", &carro[1].motor);
                printf("\n\nVeículo 2: \n");
                printf("Nome: %s\n", carro[1].nome);
                printf("Ano: %d\n", carro[1].ano);
                printf("Nome: %.1f\n", carro[1].motor);
                contveiculos++;
            break;
            case 3:
                limpartela();
                printf("Insira o nome do veículo: \n");
                scanf("%s", &carro[2].nome);
                printf("Insira o ano do veículo: \n");
                scanf("%d", &carro[2].ano);
                printf("Insira a motorizacao do veículo: \n");
                scanf("%f", &carro[2].motor);
                printf("\n\nVeículo 3: \n");
                printf("Nome: %s\n", carro[2].nome);
                printf("Ano: %d\n", carro[2].ano);
                printf("Nome: %.1f\n", carro[2].motor);
                contveiculos++;
            break;
            case 4:
                limpartela();
                if (contveiculos == 0) {
                    printf("Nenhum veículo cadastrado até o momento.\n");
                    break;
                } else {
                    for (int i = 0; i < contveiculos; i++) {
                        printf("\nNome: %s\n", carro[i].nome);
                        printf("Ano: %d\n", carro[i].ano);
                        printf("Nome: %.1f\n", carro[i].motor);
                    }
                }    
            break;
            default:
                printf("Opcao inválida!");
            break;
        }
    }

    printf("\nPrograma encerrado.\n");
    
























    return 0;
}