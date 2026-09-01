#include <stdio.h>
#include <math.h>

int main() {

    float cateto1;
    float cateto2;
    char opcao;

    printf("Insira o valor do primeiro cateto: \n");
    scanf("%f", cateto1);

    printf("Insira o valor do segundo cateto: \n");
    scanf("%f", cateto2);

    do {
        printf("H - hipotenusa do cateto\n");
        printf("P - perímetro do cateto.\n");
        printf("A - Área do cateto.\n");
        printf("F - Finalizar.\n");
        scanf("%c", &opcao);

        switch (opcao) {
            case 'h':
                printf("A hipotenusa é: ", sqrt(pow(cateto1, 2) + pow(cateto2, 2)));
                break;
            case 'p':
                printf("O perímetro é: ", cateto1 + cateto2) + sqrt(pow(cateto1, 2) + pow(cateto2, 2));
                break;
            case 'a':
                printf("A área é", (cateto1 + cateto2) / 2); 
                break;
            case 'f':
                printf("Programa finalizado.");
                break;
            default:
                printf("Opcao invalida!");
        }
    } while (opcao != 'f' || 'F');

    return 0;
}