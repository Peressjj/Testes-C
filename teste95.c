#include <stdio.h>

//prototipo de funcao


void exibirnumeros(int numexib1, int numexib2);
void somarnumeros(int numsom1, int numsom2);
void mostrarmaior(int nummaior1, int nummaior2);

int main() {

    int numero1, numero2 = 0;
    printf("Insira os valores de dois numeros: \n");
    scanf("%d", &numero1);
    scanf("%d", &numero2);

    int opcao = -1;
    while (opcao != 0) {
        printf("|   1 - Exibir numeros.\n");
        printf("|   2 - Somar numeros.\n");
        printf("|   3 - Mostrar numeros.\n");
        printf("\n|     0 - Sair.\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                exibirnumeros(numero1, numero2);
            break;

            case 2:
                somarnumeros(numero1, numero2);
            break;

            case 3:
                mostrarmaior(numero1, numero2);
            break;

            default:
                printf("Opcao inválida!\n");
            break;
        }
    }
    printf("\nPrograma encerrado.\n\n");
}

void exibirnumeros(int numexib1, int numexib2) {
    printf("\nNumero 1: %d\n", numexib1);
    printf("Numero 2: %d\n\n", numexib2);
}

void somarnumeros(int numsom1, int numsom2) {
    printf("\nNumero 1: %d\n", numsom1);
    printf("Numero 2: %d\n", numsom2);
    printf("\nA soma dos dois numeros é: %d\n\n", (numsom1 + numsom2));
}

void mostrarmaior(int nummaior1, int nummaior2) {
    int maior = 0;
    if (nummaior1 > nummaior2) {
        maior += nummaior1;
    } else if (nummaior2 > nummaior1) {
        maior += nummaior2;
    } else {
        printf("Erro!!!");
    }

    printf("Numero 1: %d\n", nummaior1);
    printf("Numero 2: %d\n", nummaior2);
    printf("O maior numero é: %d\n\n", maior);
}