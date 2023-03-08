#include <stdio.h>

#define MAX_LINHAS 100
#define MAX_COLUNAS 100

int main() {
    int matrix[MAX_LINHAS][MAX_COLUNAS];
    int linhas, colunas;
    int i, j;

    // Lê as dimensões da matriz do teclado
    printf("Digite o número de linhas: ");
    scanf("%d", &linhas);
    printf("Digite o número de colunas: ");
    scanf("%d", &colunas);

    // Lê os elementos da matriz do teclado
    printf("Digite os elementos da matriz:\n");
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Cria a transposta da matriz
    int transposta[MAX_COLUNAS][MAX_LINHAS];
    for (i = 0; i < colunas; i++) {
        for (j = 0; j < linhas; j++) {
            transposta[i][j] = matrix[j][i];
        }
    }

    // Imprime a transposta da matriz
    printf("A transposta da matriz é:\n");
    for (i = 0; i < colunas; i++) {
        for (j = 0; j < linhas; j++) {
            printf("%d ", transposta[i][j]);
        }
        printf("\n");
    }

    return 0;
}

