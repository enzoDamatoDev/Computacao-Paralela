#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Escreva um programa que leia 3 notas de um aluno e a m�dia das notas dos exerc�cios realizados por ele. Calcular a m�dia de aproveitamento, usando a f�rmula: MA = (N1 + N2*2 + N3*3 + ME)/7. A partir da m�dia, informar o conceito de acordo com a tabela: 
float exercicio2() {
  float n1, n2, n3, ME;
  printf("\nExerc�cio 2 - Lab01b\n");
  printf("Digite a nota N1:");
  scanf("%f", &n1);
  printf("Digite a nota N2:");
  scanf("%f", &n2);
  printf("Digite a nota N3:");
  scanf("%f", &n3);
  printf("Digite m�dia das atividades:");
  scanf("%f", &ME);
  float MA = (n1 + (n2 * 2) + (n3 * 3) + ME) / 7;
  if (MA >= 9) {
    printf("\nSua m�dia � %.2f e a classifica��o foi A.", MA);
  }
  if (MA < 9 && MA >= 7.5) {
    printf("\nSua m�dia � %.2f e a classifica��o foi B.", MA);
  }
  if (MA < 7.5 && MA >= 6) {
    printf("\nSua m�dia � %.2f e a classifica��o foi C.", MA);
  }
  if (MA < 6 && MA >= 4) {
    printf("\nSua m�dia � %.2f e a classifica��o foi D.", MA);
  }
  if (MA < 4) {
    printf("\nSua m�dia � %.2f e a classifica��o foi E.", MA);
  }
  return 0;
}

int main(void) {
  exercicio2();
  return 0;
}
