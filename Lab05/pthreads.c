#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


int tamanho;
int **A;
int **B;
int **C;

void *calcula(void* id){
	int sum,*row = (int*)id,col,k;
	//for(row=1; row<tamanho; row +=2) //multiplica as linhas impares
	//{
	        for(col=0; col<tamanho; col++)
	        {
	            sum = 0;
	            for(k=0; k<tamanho; k++)
	            {
	                sum += A[*row][k] * B[k][col];
	            }
		  
	            C[*row][col] = sum;
	        }
	//}
	return NULL;
}

int main(int argc, char **argv){
	long thread;
	pthread_t *threadh;
	tamanho = atoi(argv[1]);
	int i,j;
	A = (int **)malloc(tamanho*sizeof(int *));
	for(i=0;i<tamanho;i++){
		A[i] = (int *)malloc(tamanho*sizeof(int));
	}

	B = (int **)malloc(tamanho*sizeof(int *));
	for(i=0;i<tamanho;i++){
		B[i] = (int *)malloc(tamanho*sizeof(int));
	}

	C = (int **)malloc(tamanho*sizeof(int *));
	for(i=0;i<tamanho;i++){
		C[i] = (int *)malloc(tamanho*sizeof(int));
	}

	threadh = malloc (tamanho*sizeof(pthread_t));
	
	for(thread =0; thread<tamanho;thread++){
		pthread_create(&threadh[thread],NULL,calcula,(void *)thread);
	}

	printf("oi da main");

	for(thread =0;thread<tamanho;thread++){
		pthread_join(threadh[thread],NULL);
	}
	free(threadh);
	for(i=0;i<tamanho;i++){
		for(j-0;j<tamanho;j++){
			printf("%d ",C[i][j]);
		}
		printf("\n");
	}
	return 0;
}
