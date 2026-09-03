#include <stdio.h>
#include <string.h>

#define MAX 100
#define HASH_SENHA_MESTRA 530537523UL

enum op {
   SAIR,      // 0
   GRAVAR,    // 1
   EXIBIR,    // 2
   ATUALIZAR, // 3
   EXCLUIR    // 4
};

typedef struct chaves {
   char app[50];
   char login[50];
   char senha[50];
   char obs[350];
} chaves;

chaves listachaves[MAX];
int quantchaves = 0;

void menu();
void limpartela();
void salvarArquivo();
void gravar();
void carregar();
void removerQuebraDeLinha(char *texto);
void exibir();
void atualizar();
void excluir();
unsigned long calcularHash(const char *texto);

int main() {

   carregar();
   int opcao = -1;
   while (opcao != 0) {
      menu();
      scanf("%d", &opcao);

      switch (opcao) {
         case SAIR:
            limpartela();
            printf("Saindo!\n");
         break;

         case GRAVAR:
            limpartela();
            gravar();
         break;

         case EXIBIR:
            limpartela();
            exibir();
         break;

         case ATUALIZAR:
            limpartela();
            atualizar();
         break;

         case EXCLUIR:
            limpartela();
            excluir();
         break;
      
         default:
            if (opcao != SAIR) {
               printf("Opcao inválida!\n");
            }
         break;
      }
   }
   
   printf("Programa encerrado!\n");
   system("pause");
   return 0;
}

void menu() {

   printf("-------------------------------------------------\n");
   printf("|                                               \n|");
   printf("|                     Menu:                     \n|");
   printf("|                                               \n|");
   printf("|   (1) - Salvar chave.                         \n|");
   printf("|                                               \n|");
   printf("|   (2) - Vizualizar chave.                     \n|");
   printf("|                                               \n|");
   printf("|   (3) - Atualizar chave.                      \n|");
   printf("|                                               \n|");
   printf("|   (4) - Excluir chave.                        \n|");
   printf("|                                               \n|");
   printf("|   (0) - Sair.                                 \n|");
   printf("|                                               \n|");
   printf("-------------------------------------------------\n");

}

void limpartela() {

   printf("\n\n\n\n\n\n\n\n\n\n\n\n");

}

void gravar() {

   if (quantchaves >= MAX) {
      printf("Limite de %d chaves atingido!\n", MAX);
      return;
   }

   getchar();
   printf("Insira o nome do aplicativo: ");
   fgets(listachaves[quantchaves].app, 50, stdin);
   removerQuebraDeLinha(listachaves[quantchaves].app);

   printf("Insira o login do aplicativo: ");
   fgets(listachaves[quantchaves].login, 50, stdin);
   removerQuebraDeLinha(listachaves[quantchaves].login);

   printf("Insira a senha do aplicativo: ");
   fgets(listachaves[quantchaves].senha, 50, stdin);
   removerQuebraDeLinha(listachaves[quantchaves].senha);

   printf("Deseja adicionar alguma observacao? ");
   fgets(listachaves[quantchaves].obs, 350, stdin);
   removerQuebraDeLinha(listachaves[quantchaves].obs);

   quantchaves++;

   salvarArquivo();

   printf("Chave salva com sucesso!\n");
}

void carregar() {

   FILE *arq = fopen("teste222.bin", "rb");

   if (arq == NULL) {
      return; // arquivo ainda não existe, quantchaves continua 0
   }

   quantchaves = fread(listachaves, sizeof(chaves), MAX, arq);

   fclose(arq);
}

void removerQuebraDeLinha(char *texto) {
   texto[strcspn(texto, "\n")] = '\0';
}

void exibir() {

   char senhaDigitada[50];

   getchar();
   printf("Digite a senha mestra para visualizar as chaves: ");
   fgets(senhaDigitada, 50, stdin);
   removerQuebraDeLinha(senhaDigitada);

   if (calcularHash(senhaDigitada) != HASH_SENHA_MESTRA) {
      printf("Senha incorreta!\n");
      return;
   }

   FILE *arq = fopen("teste222.bin", "rb");

   if (arq == NULL) {
      printf("Nenhuma chave cadastrada.\n");
      return;
   }

   chaves temp;
   int i = 0;

   while (fread(&temp, sizeof(chaves), 1, arq) == 1) {
      printf("\n[%d]\n", i);
      printf("Aplicativo: %s\n", temp.app);
      printf("Login: %s\n", temp.login);
      printf("Senha: %s\n", temp.senha);
      printf("Observacao: %s\n", temp.obs);
      i++;
   }

   if (i == 0) {
      printf("Nenhuma chave cadastrada.\n");
   }

   fclose(arq);
}

void atualizar() {

   char senhaDigitada[50];

   getchar();
   printf("Digite a senha mestra para atualizar uma chave: ");
   fgets(senhaDigitada, 50, stdin);
   removerQuebraDeLinha(senhaDigitada);

   if (calcularHash(senhaDigitada) != HASH_SENHA_MESTRA) {
      printf("Senha incorreta!\n");
      return;
   }

   if (quantchaves == 0) {
      printf("Nenhuma chave cadastrada.\n");
      return;
   }

   for (int i = 0; i < quantchaves; i++) {
      printf("\n[%d]\n", i);
      printf("Aplicativo: %s\n", listachaves[i].app);
      printf("Login: %s\n", listachaves[i].login);
      printf("Senha: %s\n", listachaves[i].senha);
      printf("Observacao: %s\n", listachaves[i].obs);
   }

   int indice;
   printf("\nDigite o numero [i] da chave que deseja atualizar: ");
   scanf("%d", &indice);

   if (indice < 0 || indice >= quantchaves) {
      printf("Indice invalido!\n");
      return;
   }

   getchar();
   printf("Novo nome do aplicativo: ");
   fgets(listachaves[indice].app, 50, stdin);
   removerQuebraDeLinha(listachaves[indice].app);

   printf("Novo login: ");
   fgets(listachaves[indice].login, 50, stdin);
   removerQuebraDeLinha(listachaves[indice].login);

   printf("Nova senha: ");
   fgets(listachaves[indice].senha, 50, stdin);
   removerQuebraDeLinha(listachaves[indice].senha);

   printf("Nova observacao: ");
   fgets(listachaves[indice].obs, 350, stdin);
   removerQuebraDeLinha(listachaves[indice].obs);

   salvarArquivo();

   printf("Chave atualizada com sucesso!\n");
}

void excluir() {

   char senhaDigitada[50];

   getchar();
   printf("Digite a senha mestra para excluir: ");
   fgets(senhaDigitada, 50, stdin);
   removerQuebraDeLinha(senhaDigitada);

   if (calcularHash(senhaDigitada) != HASH_SENHA_MESTRA) {
      printf("Senha incorreta!\n");
      return;
   }

   int opcaoExcluir = -1;

   while (opcaoExcluir != 3) {

      if (quantchaves == 0) {
         printf("Nenhuma chave cadastrada.\n");
         return;
      }

      printf("\n--- Excluir ---\n");
      printf("(1) - Excluir individualmente\n");
      printf("(2) - Excluir tudo\n");
      printf("(3) - Voltar\n");
      printf("Escolha uma opcao: ");
      scanf("%d", &opcaoExcluir);

      if (opcaoExcluir == 1) {

         for (int i = 0; i < quantchaves; i++) {
            printf("\n[%d]\n", i);
            printf("Aplicativo: %s\n", listachaves[i].app);
            printf("Login: %s\n", listachaves[i].login);
            printf("Senha: %s\n", listachaves[i].senha);
            printf("Observacao: %s\n", listachaves[i].obs);
         }

         int indice;
         printf("\nDigite o numero [i] da chave que deseja excluir: ");
         scanf("%d", &indice);

         if (indice < 0 || indice >= quantchaves) {
            printf("Indice invalido!\n");
         } else {

            for (int i = indice; i < quantchaves - 1; i++) {
               listachaves[i] = listachaves[i + 1];
            }

            quantchaves--;

            salvarArquivo();

            printf("Chave excluida com sucesso!\n");
         }

      } else if (opcaoExcluir == 2) {

         char confirmacao[50];

         getchar();
         printf("Digite \"excluirtudo\" para confirmar a exclusao de TODAS as chaves: ");
         fgets(confirmacao, 50, stdin);
         removerQuebraDeLinha(confirmacao);

         if (strcmp(confirmacao, "excluirtudo") == 0) {
            quantchaves = 0;
            salvarArquivo();
            printf("Todas as chaves foram excluidas!\n");
         } else {
            printf("Confirmacao incorreta. Nada foi excluido.\n");
         }

      } else if (opcaoExcluir != 3) {
         printf("Opcao invalida!\n");
      }
   }
}

void salvarArquivo() {

   FILE *arq = fopen("teste222.bin", "wb");
   if (arq == NULL) {
      printf("Falha ao abrir arquivo 'teste222.bin'!\n");
      return;
   }
   fwrite(listachaves, sizeof(chaves), quantchaves, arq);
   fclose(arq);
}

unsigned long calcularHash(const char *texto) {
   unsigned long hash = 5381;
   int c;

   while ((c = *texto++)) {
      hash = ((hash << 5) + hash) + c;
   }

   return hash;
}

