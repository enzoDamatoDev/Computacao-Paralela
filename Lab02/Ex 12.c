#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 12. Faça uma função que retorne a posição de um dado caracter dentro de uma
// string.


void ex12(char* str, int* posicao, int* qtd, char x) {
  for(int i = 0; i < 50; i++) {
        if(str[i] == x) {
            posicao[*qtd] = i;
            (*qtd)++;
        }

        if(str[i] == '\n') {
            break;
        }
    }
}
    
int main(void) {
  char str[50], x;
  int posicao[50], qtd = 0;
  printf("Digite a palavra: ");
  for(int i = 0; i < 100; i++) {
        scanf("%c", &str[i]);

        if(str[i] == '\n') {
            break;
        }
    }
  printf("Escolha 1 caracter para saber a posicao da palavra %s", str);
  scanf("%c", &x);
  
  ex12(str,posicao,&qtd,x);

  printf("A posicao do '%s' eh: ", &x);
  for (int i = 0; i <qtd; i++) {
    printf(" %d",posicao[i]);  
  }
  return 0;
}
