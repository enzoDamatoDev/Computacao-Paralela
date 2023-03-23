#include <stdio.h>
#include <stdlib.h>
#define SIZE 3 // Size of the matrix

int main(int argc, char **argv)
{
    if(argc < 2){
	   printf("insira o tamanho da matriz no segundo argumento!");
	   exit(1);
    } 
    int tam = atoi(argv[1]);
    printf("%d",tam);/*
    
    int row, col, i, 
    printf("Enter elements in matrix A of size %dx%d: \n", SIZE, SIZE);
    for(row=0; row<SIZE; row++)
    {
        for(col=0; col<SIZE; col++)
        {
            scanf("%d", &A[row][col]);
        }
    }

    printf("\nEnter elements in matrix B of size %dx%d: \n", SIZE, SIZE);
    for(row=0; row<SIZE; row++)
    {
        for(col=0; col<SIZE; col++)
        {
            scanf("%d", &B[row][col]);
        }
    }
    for(row=0; row<SIZE; row++)
    {
        for(col=0; col<SIZE; col++)
        {
            sum = 0;
            for(i=0; i<SIZE; i++)
            {
                sum += A[row][i] * B[i][col];
            }

            C[row][col] = sum;
        }
    }

    printf("\nProduct of matrix A * B = \n");
    for(row=0; row<SIZE; row++)
    {
        for(col=0; col<SIZE; col++)
        {
            printf("%d ", C[row][col]);
        }
        printf("\n");
    }*/

    return 0;
}
