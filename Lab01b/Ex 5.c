#include <stdio.h>
#include <stdlib.h>

int main(){
	int n,lin,col,i,j,escolha,mult;
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
	
	
	printf("Multiplicar por (0 para linha, 1 para coluna): ");
	scanf("%d",&escolha);
	
	while(escolha != 0 && escolha != 1){
		printf("Multiplicar por (0 para linha, 1 para coluna): ");
		scanf("%d",&escolha);
	}
	
	
	printf("Multiplicador: ");
	scanf("%d",&n);
	
	if(!escolha){
		printf("qual linha deseja multiplicar? ");
		scanf("%d",&mult);
		while(mult < 0 || mult >= lin){
			printf("minimo 0, maximo %d ",lin-1);
			scanf("%d",&mult);
		}
		for(i=0;i<col;i++){
			matriz[mult][i] = matriz[mult][i]*n;
		}
	
	}else{
		printf("qual coluna deseja multiplicar? ");
		scanf("%d",&mult);
		while(mult < 0 || mult >= col){
			printf("minimo 0, maximo %d ",col-1);
			scanf("%d",&mult);
		}
		for(i=0;i<lin;i++){
			matriz[i][mult] = matriz[i][mult]*n; 
		}
		
	}
	for(i=0;i<lin;i++){
		for(j=0;j<col;j++){
			printf("%d ",matriz[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
