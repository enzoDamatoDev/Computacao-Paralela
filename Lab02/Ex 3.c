#include <stdio.h>

int main(){
	int max,i,j;
	printf("maximo: ");
	scanf("%d",&max);
	while((max%2)==0){
		printf("numero deve ser impar! ");
		scanf("%d",&max);
	}
	for(i=0;i<max;i++){
		for(j=i;j<max-i;j++){
			printf("%d",j+1);
		}
		printf("\n");
	}
	
	return 0;
}
