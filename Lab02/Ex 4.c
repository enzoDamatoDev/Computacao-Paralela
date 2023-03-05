#include <stdio.h>
#include <string.h>


//Exercício 4 - Crie um progama capaz de ler dois nomes de pessoas e imprimi-los em ordem alfabética. Faça isto com string de C e de C++
//#include <stdlib.h>   NÃO UTILIZADO
// https://www.pucsp.br/~so-comp/cursoc/aulas/c520.html

char ordem(char a[100], char b[100]) {    
    if(strcmp(a, b))
        printf("Ordem alfabetica:\n %s\n %s\n", a,b);
    else
        printf("Ordem alfabetica:\n %s.\n %s.\n", b,a);
  return 0;
}

int main () {
  char str1[100], str2[100];
  printf("Digite o primeiro nome: ");
  gets(str1);
  printf("Digite o segundo nome: ");
  gets(str2);
  char ordem();
  ordem(str1, str2);
  return 0;
}
