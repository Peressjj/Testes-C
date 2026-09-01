#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

srand(time(NULL));

    int vida1 = 200;
    int vida2 = 200;

    int opcao = -1;
    
    int dano1[50];
    int dano2[50];
    
    char personagem1[20];
    char personagem2[20];

    int danototal1 = 0;
    int danototal2 = 0;
    
    printf("Insira o nome do seu personagem: \n");
    scanf("%s", &personagem1);
    printf("Insira o nome do personagem rival: \n");
    scanf("%s", &personagem2);
    printf("Jogador %s  VS. jogador %s\n", personagem1, personagem2);

    int round = 0;
    int contador = 0;

    while (opcao != 0) {

        printf("1 - Lutar.\n");
        printf("0 - Sair.\n");
        scanf("%d", &opcao);
        
        int hit1 = rand() % 25 + 5;
        
        dano2[round] = hit1;
        danototal1 += dano1[round];
        
        int hit2 = rand() % 25 + 5;
        
        dano1[round] = hit2;
        danototal2 += dano2[round];
        
        printf("Round: %d\n\n", (contador + 1));
        contador++;
        printf("Após a luta, jogador %s, infringiu %d de dano ao jogador %s.\n", personagem1, hit1, personagem2);
        printf("O jogador %s infringiu %d de dano ao jogador %s\n\n", personagem2, hit2, personagem1);
        
        printf("Dano total do %s: %d\n", personagem1, danototal1);
        printf("Dano total do %s: %d\n\n", personagem2, danototal2);
        
        printf("Vida %s: %d\n", personagem1, (vida1 - danototal2));
        printf("Vida %s: %d\n", personagem2, (vida2 - danototal1));
        printf("\n\n");
        
        if (danototal2 >= 200) {
            printf("Fim de jogo. Jogador %s ganhou!\n\n\nParabens jogador %s!!!\n", personagem2, personagem2);
            break;
        } else if (danototal1 >= 200) {
            printf("Fim de jogo. Jogador %s ganhou!\n\n\nParabens jogador %s!!!\n", personagem1, personagem1);
            break;
        } else if (danototal2 >= 200 || danototal1 >= 200) {
            printf("EMPATE!");
            break;
        } else {
            continue;
        }
        round++;

    }

    printf("Programa encerrado. \n");






















return 0;
}