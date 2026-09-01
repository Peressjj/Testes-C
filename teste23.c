#include <stdio.h>
#include <string.h>
// struct

    struct Carro {
        char nome[50];
        int ano;
        float motor;
    };
    struct Carro c1;
    struct Carro c2;
    struct Carro c3;
    

    struct Moto {
        char name[50];
        int year;
        float eng;
    };
    struct Moto m1;
    struct Moto m2;
    struct Moto m3;
    


void menu() {
        printf("------------------------------------\n");
        printf("|                                  |\n");
        printf("|    1-Cadastrar carro.            |\n");
        printf("|    2-Cadastrar moto.             |\n");
        printf("|    3-Mostrar carros.             |\n");
        printf("|    4-Mostrar motos.              |\n");
        printf("|    0-Sair.                       |\n");
        printf("|                                  |\n");
        printf("------------------------------------\n");
    }

void cadastrocarro1() {
        printf("Insira o nome do carro: \n");
        scanf("%s", &c1.nome);

        printf("Insira o ano do carro: \n");
        scanf("%d", &c1.ano);

        printf("Insira a motorização do carro: \n");
        scanf("%f", &c1.motor);
}

void cadastrocarro2() {
        printf("Insira o nome do carro: \n");
        scanf("%s", &c2);

        printf("Insira o ano do carro: \n");
        scanf("%d", &c2.ano);

        printf("Insira a motorização do carro:\n");
        scanf("%f", &c2.motor);
}

void cadastrocarro3() {
        printf("Insira o nome do carro: \n");
        scanf("%s", &c3.nome);

        printf("Insira o ano do carro: \n");
        scanf("%d", &c3.ano);

        printf("Insira a motorização do carro:\n");
        scanf("%f", &c3.motor);
}


void cadastromoto1() {
    printf("Insira o nome da moto: \n");
    scanf("%s", &m1.name);

    printf("Insira o ano da moto \n");
    scanf("%d", &m1.year);

    printf("Insira a motorização da moto:\n");
    scanf("%f", &m1.eng);
}

void cadastromoto2() {
    printf("Insira o nome da moto: \n");
    scanf("%s", &m2.name);

    printf("Insira o ano da moto \n");
    scanf("%d", &m2.year);

    printf("Insira a motorização da moto:\n");
    scanf("%f", &m2.eng);
}

void cadastromoto3() {
    printf("Insira o nome da moto: \n");
    scanf("%s", &m3.name);

    printf("Insira o ano da moto \n");
    scanf("%d", &m3.year);

    printf("Insira a motorização da moto:\n");
    scanf("%f", &m3.eng);
}

void mostrarcarro() {
    printf("Nome: %s\n", c1.nome);
    printf("Ano: %d\n", c1.ano);
    printf("Motor: %.1f\n", c1.motor);
}

void mostrarmoto() {
    printf("Nome: %s\n", m1.name);
    printf("Ano: %d\n", m1.year);
    printf("Motor: %.0fcc.\n", m1.eng);
}


int main() {
    
    int opcao;

    while (opcao != 0) {
        menu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrocarro1();
            break;

            case 2:
                cadastromoto1();
            break;

            case 3:
                mostrarcarro();
            break;

            case 4:
                mostrarmoto();
            break;

        default:
            printf("Programa encerrado. ");
        break;
        }
    }
    
return 0;
}