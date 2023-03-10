#include <stdio.h>
#include <stdlib.h>

void modulo(int **matriz, int n,int m){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(matriz[i][j]<0){
				matriz[i][j] = -matriz[i][j];
			}
			
		}
	}
}

int main(){
	int lin,col,i,j;
	printf("Numero de linhas: ");
	scanf("%d",&lin);
	printf("Numero de colunas: ");
	scanf("%d",&col);
	int **matriz = (int **)malloc(sizeof(int*)*lin);
	for(i=0;i<col;i++){
		matriz[i] = (int *)malloc(sizeof(int)*col);
	}
	
	for(i=0;i<lin;i++){
		for(j=0;j<col;j++){
			printf("numero [%d][%d] ",i,j);
			scanf("%d",&matriz[i][j]);
			
		}
	}
	modulo(matriz,lin,col);
	for(i=0;i<lin;i++){
		for(j=0;j<col;j++){
			printf("%d ",matriz[i][j]);
			
		}
		printf("\n");
	}
	return 0;
}
