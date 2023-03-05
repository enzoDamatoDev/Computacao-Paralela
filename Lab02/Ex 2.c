#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Escreva um programa que leia 3 notas de um aluno e a média das notas dos exercícios realizados por ele. Calcular a média de aproveitamento, usando a fórmula: MA = (N1 + N2*2 + N3*3 + ME)/7. A partir da média, informar o conceito de acordo com a tabela: 
float exercicio2() {
  float n1, n2, n3, ME;
  printf("\nExercício 2 - Lab01b\n");
  printf("Digite a nota N1:");
  scanf("%f", &n1);
  printf("Digite a nota N2:");
  scanf("%f", &n2);
  printf("Digite a nota N3:");
  scanf("%f", &n3);
  printf("Digite média das atividades:");
  scanf("%f", &ME);
  float MA = (n1 + (n2 * 2) + (n3 * 3) + ME) / 7;
  if (MA >= 9) {
    printf("\nSua média é %.2f e a classificação foi A.", MA);
  }
  if (MA < 9 && MA >= 7.5) {
    printf("\nSua média é %.2f e a classificação foi B.", MA);
  }
  if (MA < 7.5 && MA >= 6) {
    printf("\nSua média é %.2f e a classificação foi C.", MA);
  }
  if (MA < 6 && MA >= 4) {
    printf("\nSua média é %.2f e a classificação foi D.", MA);
  }
  if (MA < 4) {
    printf("\nSua média é %.2f e a classificação foi E.", MA);
  }
  return 0;
}

int main(void) {
  exercicio2();
  return 0;
}
