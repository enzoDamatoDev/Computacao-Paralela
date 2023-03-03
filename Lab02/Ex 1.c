#include <stdio.h>
#include <stdlib.h>

int main(){
	int n,i,j,menor=INT_MAX,linha,aux;
	printf("Ordem da matriz? ");
	scanf("%d",&n);
	int **ordem = (int **)malloc(sizeof(int*)*n);
	for(i=0;i<n;i++){
		ordem[i] = (int *)malloc(sizeof(int)*n);
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("numero [%d][%d] ",i,j);
			scanf("%d",&aux);
			ordem[i][j] = aux;
			if(aux<menor){linha=i;menor=aux;
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",ordem[i][j]);
		}
		printf("\n");
	}
	
	printf("%d",linha+1);
	return 0;
}
