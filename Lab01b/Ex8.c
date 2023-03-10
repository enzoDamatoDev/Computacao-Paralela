#include <stdio.h>
#include <stdlib.h>

// 6. Crie um programa capaz de criar a transposta de uma matriz. A matriz deve
// ser lida de teclado.

void transposta(int linhas, int colunas, int **matriz, int **matrizTransposta) {
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      	matrizTransposta[j][i] = matriz[i][j];
    }
  }
}

int main(void) {
  int linhas, colunas;
  printf("Matriz Transposta\n");
  printf("Digite o número de linhas: ");
  scanf("%d", &linhas);
  printf("Digite o número de colunas: ");
  scanf("%d", &colunas);

  int **matriz = (int **)malloc(sizeof(int *) * linhas);
  for (int i = 0; i < colunas; i++) {
    matriz[i] = (int *)malloc(sizeof(int) * colunas);
  }
  int **matrizTransposta = (int **)malloc(sizeof(int *) * colunas);
  for (int i = 0; i < linhas; i++) {
    matrizTransposta[i] = (int *)malloc(sizeof(int) * linhas);
  }
  

  for (int i = 0; i < colunas; i++) {
    printf("Digite as entradas para a linha %d: \n", i + 1);
    for (int j = 0; j < linhas; j++) {
      scanf("%d", &matriz[i][j]);
    }
  }
  transposta(linhas, colunas, matriz, matrizTransposta);
  for (int i = 0; i < colunas; i++) {
    for (int j = 0; j < linhas; j++) {
      printf(" %d", matrizTransposta[i][j]);
    }
    printf("\n");
  }
  return 0;
}
