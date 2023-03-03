#include <stdio.h>
#include <stdlib.h>

void soma(int matriz[][2]){
	int i;
	for(i=0;i<2;i++){
		matriz[1][i] = matriz[0][i]+matriz[1][i];
		matriz[0][i] = 0;
	}
}

void multiplica(int matriz[][2]){
	int i;
	for(i=0;i<2;i++){
		matriz[1][i] = matriz[0][i]*matriz[1][i];
		matriz[0][i] = 0;
	}
}
int main(){
	int i,j,escolha;
	int matriz[2][2];
	
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("numero [%d][%d] ",i,j);
			scanf("%d",&matriz[i][j]);
			
		}
	}
	printf("deseja somar ou multiplicar?(0 para soma, 1 para multiplacacao)");
	scanf("%d",&escolha);
	if(escolha){
		multiplica(matriz);
	}else{
		soma(matriz);
	}
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("%d ",matriz[i][j]);
			
		}
		printf("\n");
	}
	return 0;
}
