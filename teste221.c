// 26.08.26
#include <stdio.h>
#include <string.h>

   typedef struct pessoa {
      char nome[50];
      int idade;
   } pessoa;

   pessoa listapessoas[] = {
      {"Joao Peres", 20},
      {"Luis Lemos", 23},
      {"Vittor Sauer", 23},
      {"Wellington Rafael", 20},
      {"Kaue Pakagnan", 19} 
   };

int main() {

   printf("Lista de nomes:\n");
   for (int i = 0; i < 5; i++) {
      printf("Nome: %s\n", listapessoas[i].nome);
      printf("Idade: %d\n\n", listapessoas[i].idade);
   }

   FILE *arq;

   arq = fopen("teste221.json", "w");

   if (arq == NULL) {
      printf("Falha ao abrir arquivo!\n");
   } else {
      printf("Arquivo aberto com sucesso!\n");
   }

   fprintf(arq, "[\n");
   for (int i = 0; i < 5; i++) {
      if (i > 0) fprintf(arq, ",\n");
      fprintf(arq, "  {\"nome\": \"%s\", \"idade\": %d}",
         listapessoas[i].nome, listapessoas[i].idade);
   }

   fprintf(arq, "\n]\n");

   fclose(arq);

   printf("Arquivo teste221.json fechado!\n");








   return 0;
}