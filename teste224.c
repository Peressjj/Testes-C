#include <stdio.h>
#include <windows.h>

enum opcoes {
   SAIR,
   OP1,
   OP2
};

int senhaSalvas = 0;

void menu();
void verificacao();

int main() {
   SetConsoleOutputCP(CP_UTF8);

   int opcao = -1;

   verificacao();
   while (opcao != SAIR) {
      menu();
      scanf("%d", &opcao);
      switch (opcao) {
         case SAIR:
            printf("Saindo\n");
         break;

         case OP1:
            printf("Opcao 1\n");
         break;

         case OP2:
            printf("Opcao 2\n");
         break;

         default:
            if (opcao != SAIR && opcao != OP1 && opcao != OP2 || opcao != -1) {
               printf("Opcao inválida\n");
            }   
         break;
      }
   }
   
   printf("Programa encerrado!\n");











}

void menu() {

   printf("--------------------------------\n");
   printf("|             MENU             |\n");
   printf("|                              |\n");
   printf("|   1 - Opção 1.               |\n");
   printf("|                              |\n");
   printf("|   2 - Opção.                 |\n");
   printf("|                              |\n");
   printf("|   0 - Sair.                  |\n");
   printf("|                              |\n");
   printf("--------------------------------\n");

}

void verificacao() {

   char resposta;

   if (senhaSalvas == 0) {
      printf("Nenhuma senha mestra salva, deseja inserir? (S/N)\n");
      scanf("%c", &resposta);
      printf("%c", resposta);
      if (resposta == 'S' || resposta == 's') {
         printf("SIM");
      } else if (resposta == 'N' || resposta == 'n') {
         printf("NAO");
      }
   }

}