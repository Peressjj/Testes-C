#include   <stdio.h> // De entrada e saída de dados
#include   <stdlib.h> // Usada em strtof(), para converter string em float, e em rand() e srand(), para gerar números aleatórios
#include   <time.h> // Usada para a função time(), que gera um número inteiro baseado no horário do sistema, utilizado para gerar um número aleatório
#include   <windows.h> // Usada para a função Sleep(), que pausa o programa por um tempo determinado
#include   <string.h>

// Constantes simbólicas definidas:
    #define   MAX_DESCRICAO  26
    #define   MAX_HISTORICO  500
    #define   QTDE_PRODUTOS  21
    #define   TIPO_LIMPEZA   1
    #define   TIPO_ALIMENTO  2
    #define   TIPO_PADARIA   3
    #define   TODOS_TIPOS    0
    #define   MAXCLIENTES    50
    #define   MAX_CARACTERES 150
    #define   MAX_USUARIOS   5


typedef struct Usuario{
    char nome[50];
    int  senha;
} Usuario;

Usuario listausuarios[MAX_USUARIOS];


int total_usuarios = 0;

void login();
void menuusuários();
void cadastrarusuario();
void exibelistausuario();
void SalvarUsuarioArquivo(Usuario u);
void excluirusuario();
void carregarUsuariosArquivo();


int main() {

    carregarUsuariosArquivo();
    int opcao = -1;

    if (total_usuarios != 0) {
        login();
    } 

    while (opcao != 0) {
        menuusuários();
        scanf("%d", &opcao);

        switch (opcao) {
            case 0: // Sair
                
            break;

            case 1: // Cadastrar usuário
                cadastrarusuario();
            break;

            case 2: // Lista usuarios  
                exibelistausuario();
            break;

            case 3: // excluir usuario
                excluirusuario();
            break;

            default:
                if (opcao != 0) {
                    printf("Opcao inválida\n");
                }
            break;
        }
    }

    return 0;
}

void login() {

    FILE *arq = fopen("teste197.txt", "r");

    if (arq == NULL) {
        printf("Nenhum usuario cadastrado!\n");
        return;
    }

    Usuario u;
    char nome[50];
    int senha;
    int encontrou = 0;

    while (1) {

        arq = fopen("teste197.txt", "r");

        if (arq == NULL) {
            printf("Nenhum usuario cadastrado!\n");
            return;
        }

        encontrou = 0;

        printf("\n\n-------------------------------------------------------------------\n");
        printf("|                                                                 |\n");
        printf("|                               LOGIN                             |\n");
        printf("|                                                                 |\n");
        printf("|   Usuario: ");

        fgets(nome, 50, stdin);
        nome[strcspn(nome, "\n")] = '\0';

        printf("|   Senha: ");
        scanf("%d", &senha);

        while (fscanf(arq, "%49[^;];%d\n", u.nome, &u.senha) == 2) {

            if (strcmp(nome, u.nome) == 0 && senha == u.senha) {
                encontrou = 1;
                break;
            }
        }

        fclose(arq);

        if (encontrou) {
            printf("\n|     Login realizado com sucesso!\n");
            Sleep(1000);
            break;
        }

        printf("\n|     Usuario ou senha incorretos! Tente novamente.\n");
        Sleep(1500);
    }

}

void menuusuários() {

    printf("\n\n-------------------------------------------------------------------\n");
    printf("|                                                                 |\n");
    printf("|                             USUÁRIOS                            |\n");
    printf("|                                                                 |\n");
    printf("|   1   →  Cadastrar novo usuário.                                |\n");
    printf("|                                                                 |\n");
    printf("|   2   →  Exibir lista de usuários.                              |\n");
    printf("|                                                                 |\n");
    printf("|   0   →  Sair. ↩                                                |\n");
    printf("|                                                                 |\n");
    printf("-------------------------------------------------------------------\n\n");
    printf("\nDigite a opção desejada: ");

}

void cadastrarusuario() {

    if (total_usuarios >= MAX_USUARIOS) {
        printf("Limite de usuários atingido.\n");
        return;
    }

    printf("\n------------------------------------------------------------------------------\n");
    printf("|   CADASTRO DE USUÁRIOS                                                     |\n");
    printf("|                                                                            |\n");
    printf("|   Usuários cadastrados: %d                                                 |\n", total_usuarios);
    printf("|                                                                            |\n");
    printf("|   Insira o nome de usuário: ");
    getchar();
    fgets(listausuarios[total_usuarios].nome, 50, stdin);

    listausuarios[total_usuarios].nome[strcspn(listausuarios[total_usuarios].nome, "\n")] = '\0';  

    printf("|   Insira uma senha de pro seu usuário: ");
    scanf("%d", &listausuarios[total_usuarios].senha);

    printf("Validando...");
    Sleep(1000);

    int existe = 0;

    for (int i = 0; i < total_usuarios; i++) {
        if (strcmp(listausuarios[i].nome,listausuarios[total_usuarios].nome) == 0) {
            existe = 1;
            break;
        }
    }

    if (existe) {
        printf("Usuário já cadastrado.\n");
        return;
    } else {
        printf("Usuário cadastrado com sucesso.\n");
        total_usuarios++;
        SalvarUsuarioArquivo(listausuarios[(total_usuarios - 1)]);
    }

}

void exibelistausuario() {

    FILE *arq = fopen("teste197.txt", "r");

    if (arq == NULL) {
        printf("Nenhum usuario cadastrado.\n");
        return;
    }

    printf("Arquivo aberto com sucesso!\n");

    Usuario u;
    int contador = 0;

    printf("\n------------------------------------------------------------------------------\n");
    printf("|   LISTA DE USUARIOS                                                        |\n");
    printf("------------------------------------------------------------------------------\n");

    char linha[100];

    printf("\nConteudo do arquivo:\n");

    while (fscanf(arq, "%49[^;];%d\n", u.nome, &u.senha) == 2) {
        contador++;
        printf("| Usuario %d\n", contador);
        printf("| Nome: %s\n", u.nome);
        printf("| Senha: %d\n", u.senha);
        printf("------------------------------------------------------------------------------\n");
    }

    if (contador == 0) {
        printf("Nenhum usuario encontrado.\n");
    }

    fclose(arq);

}

void SalvarUsuarioArquivo(Usuario u) {

    FILE *arq = fopen("teste197.txt", "a");

    if (arq == NULL) {
        printf("ERRO ao abrir arquivo!\n");
        return;
    }

    fprintf(arq, "%s;%d\n", u.nome, u.senha);

    fclose(arq);

}

void excluirusuario() {

    char nome[50];
    int posicao = -1;

    printf("\nInsira o nome do usuario que deseja excluir: ");
    getchar();
    fgets(nome, 50, stdin);

    nome[strcspn(nome, "\n")] = '\0';

    // Procura o usuário
    for (int i = 0; i < total_usuarios; i++) {
        if (strcmp(nome, listausuarios[i].nome) == 0) {
            posicao = i;
            break;
        }
    }

    printf("Posicao encontrada: %d\n", posicao);

    if (posicao == -1) {
        printf("Usuario nao encontrado!\n");
        return;
    }

    // Move os usuários para preencher o espaço
    for (int i = posicao; i < total_usuarios - 1; i++) {
        listausuarios[i] = listausuarios[i + 1];
    }

    total_usuarios--;

    printf("Usuario excluido com sucesso!\n");

}

void carregarUsuariosArquivo() {

    FILE *arq = fopen("teste197.txt", "r");

    if (arq == NULL) {
        return;
    }

    total_usuarios = 0;

    while (fscanf(arq,"%49[^;];%d\n", listausuarios[total_usuarios].nome, &listausuarios[total_usuarios].senha) == 2) {
        total_usuarios++;
        if(total_usuarios >= MAX_USUARIOS) {
            break;
        }
    }

    fclose(arq);
}

