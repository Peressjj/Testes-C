#include <stdio.h>

int main() {

    int numeroum, numerodois, numerotres, numeroquatro, numerocinco, numeroseis, numerosete, numerooito, numeronove, numerodez;
    int positivo = 0;
    int negativo = 0;
    int zero = 0;
    int opcao;

    printf("Insira o numero 1:    \n");
    scanf("%d", &numeroum);
    numeroum % 2 == 0 ? printf("Numero %d é par.\n", numeroum) : printf("Numero %d é ímpar\n", numeroum);
    if (numeroum > 0) {
        printf("Numero 1 é positivo.\n\n");
        positivo++;
    } 
    else if (numeroum < 0) {
        printf("Numero 1 é negativo.\n\n");
        negativo++;
    }
    else if (numeroum == 0) {
        printf("Numero 1 é zero.\n\n");
        zero++;
    }


    printf("Insira o numero 2:    \n");
    scanf("%d", &numerodois);
    numerodois % 2 == 0 ? printf("Numero %d é par.\n", numerodois) : printf("Numero %d é ímpar\n", numerodois);
    if (numerodois > 0) {
        printf("Numero 2 é positivo.\n\n");
        positivo++;
    } 
    else if (numerodois < 0) {
        printf("Numero 2 negativo.\n\n");
        negativo++;
    }
    else if (numerodois == 0) {
        printf("Numero 2 é zero.\n\n");
        zero++;
    }    

    printf("Insira o numero 3:    \n");
    scanf("%d", &numerotres);
    numerotres % 2 == 0 ? printf("Numero %d é par.\n", numerotres) : printf("Numero %d é ímpar\n", numerotres);
    if (numerotres > 0) {
        printf("Numero 3 é positivo.\n\n");
        positivo++;
    } 
    else if (numerotres < 0) {
        printf("Numero 3 é negativo.\n\n");
        negativo++;
    }
    else if (numerotres == 0) {
        printf("Numero 3 é zero.\n\n");
        zero++;
    }

    printf("Insira o numero 4:    \n");
    scanf("%d", &numeroquatro);
    numeroquatro % 2 == 0 ? printf("Numero %d é par.\n", numeroquatro) : printf("Numero %d é ímpar\n", numeroquatro);
    if (numeroquatro > 0) {
        printf("Numero 4 é positivo.\n\n");
        positivo++;
    } 
    else if (numeroquatro < 0) {
        printf("Numero 4 é negativo.\n\n");
        negativo++;
    }
    else if (numeroquatro == 0) {
        printf("Numero 4 é zero.\n\n");
        zero++;
    }

    printf("Insira o numero 5:    \n");
    scanf("%d", &numerocinco);
    numerocinco % 2 == 0 ? printf("Numero %d é par.\n", numerocinco) : printf("Numero %d é ímpar\n", numerocinco);
    if (numerocinco > 0) {
        printf("Numero 5 é positivo.\n\n");
        positivo++;
    } 
    else if (numerocinco < 0) {
        printf("Numero 5 é negativo.\n\n");
        negativo++;
    }
    else if (numerocinco == 0) {
        printf("Numero 5 é zero.\n\n");
        zero++;
    }

    printf("Insira o numero 6:    \n");
    scanf("%d", &numeroseis);
    numeroseis % 2 == 0 ? printf("Numero %d é par.\n", numeroseis) : printf("Numero %d é ímpar\n", numeroseis);
    if (numeroseis > 0) {
        printf("Numero 1 é positivo.\n\n");
        positivo++;
    } 
    else if (numeroseis < 0) {
        printf("Numero 6 é negativo.\n\n");
        negativo++;
    }
    else if (numeroseis == 0) {
        printf("Numero 6 é zero.\n\n");
        zero++;
    }

    printf("Insira o numero 7:    \n");
    scanf("%d", &numerosete);
    numerosete % 2 == 0 ? printf("Numero %d é par.\n", numerosete) : printf("Numero %d é ímpar\n", numerosete);
    if (numerosete > 0) {
        printf("Numero 1 é positivo.\n\n");
        positivo++;
    } 
    else if (numerosete < 0) {
        printf("Numero 7 é negativo.\n\n");
        negativo++;
    }
    else if (numerosete == 0) {
        printf("Numero 7 é zero.\n\n");
        zero++;
    }

    printf("Insira o numero 8:    \n");
    scanf("%d", &numerooito);
    numerooito % 2 == 0 ? printf("Numero %d é par.\n", numerooito) : printf("Numero %d é ímpar\n", numerooito);
    if (numerooito > 0) {
        printf("Numero 8 é positivo.\n\n");
        positivo++;
    } 
    else if (numerooito < 0) {
        printf("Numero 8 é negativo.\n\n");
        negativo++;
    }
    else if (numerooito == 0) {
        printf("Numero 8 é zero.\n\n");
        zero++;
    }

    printf("Insira o numero 9:    \n");
    scanf("%d", &numeronove);
    numeronove % 2 == 0 ? printf("Numero %d é par.\n", numeronove) : printf("Numero %d é ímpar\n", numeronove);
    if (numeronove > 0) {
        printf("Numero 9 é positivo.\n\n");
        positivo++;
    } 
    else if (numeronove < 0) {
        printf("Numero 9 é negativo.\n\n");
        negativo++;
    }
    else if (numeronove == 0) {
        printf("Numero 9 é zero.\n\n");
        zero++;
    }

    printf("Insira o numero 10:    \n");
    scanf("%d", &numerodez);
    numerodez % 2 == 0 ? printf("Numero %d é par.\n", numerodez) : printf("Numero %d é ímpar\n", numerodez);
    if (numerodez > 0) {
        printf("Numero 10 é positivo.\n\n");
        positivo++;
    } 
    else if (numerodez < 0) {
        printf("Numero 10 negativo.\n\n");
        negativo++;
    }
    else if (numerodez == 0) {
        printf("Numero 10 é zero.\n\n");
        zero++;
    }

    printf(" Numero 1: %d\n Numero 2: %d\n Numero 3: %d\n Numero 4: %d\n Numero 5: %d\n Numero 6: %d\n Numero 7: %d\n Numero 8: %d\n Numero 9: %d\n Numero 10: %d\n\n", numeroum, numerodois, numerotres, numeroquatro, numerocinco, numeroseis, numerosete, numerooito, numeronove, numerodez);
    printf("Numeros positivos: %d\n", positivo);
    printf("Numeros negativos: %d\n", negativo);
    printf("Numeros iguais a zero: %d\n\n", zero);


return 0;
}