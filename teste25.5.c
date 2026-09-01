#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numero;
    int chute;
    int tentativas = 0;

    srand(time(NULL)); // S: semente        rand: gera um numero aleatório
    numero = rand() % 25 + 1; // Número aleatório de 1 a 25

    printf("Tente adivinhar o numero de 1 a 25. Voce tem 5 tentativas.\numero");

    for(tentativas = 1; tentativas <= 5; tentativas++) {
        printf("Tentativa %d: ", tentativas);
        scanf("%d", &chute);

        if(chute == numero)
            break;
        else if(chute > numero)
            printf("Menor!\n");
        else
            printf("Maior!\n");
    }

    switch(tentativas) {
        case 1:
            printf("Incrivel! Acertou de primeira!\n");
            break;
        case 2:
        case 3:
        case 4:
        case 5:
            if(chute == numero)
                printf("Parabens! Voce acertou em %d tentativas.\n", tentativas);
            else
                printf("Nao foi dessa vez! O numero era %d.\n", numero);
            break;
        default:
            printf("Nao foi dessa vez! O numero era %d.\n", numero);
    }

    return 0;
}