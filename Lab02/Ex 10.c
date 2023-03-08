#include <stdio.h>

#define MAX_LINHAS 100
#define MAX_COLUNAS 100

void multiply_row(int matrix[MAX_LINHAS][MAX_COLUNAS], int row, int num, int cols) {
    int j;
    for (j = 0; j < cols; j++) {
        matrix[row][j] *= num;
    }
}

void multiply_col(int matrix[MAX_LINHAS][MAX_COLUNAS], int col, int num, int rows) {
    int i;
    for (i = 0; i < rows; i++) {
        matrix[i][col] *= num;
    }
}
int main() {
    int matrix[MAX_LINHAS][MAX_COLUNAS];
    int linhas, cols;
    int i, j;

    printf("Digite o número de linhas: ");
    scanf("%d", &linhas);
    printf("Digite o número de colunas: ");
    scanf("%d", &cols);

    printf("Digite os elementos da matriz:\n");
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Multiplica a linha 1 por 2
    multiply_row(matrix, 1, 2, cols);

    // Multiplica a coluna 2 por 3
    multiply_col(matrix, 2, 3, linhas);

    printf("A matriz modificada é:\n");
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

