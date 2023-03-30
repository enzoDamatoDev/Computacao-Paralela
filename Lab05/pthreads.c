#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


int tamanho;
int **A;
int **B;
int **C;

void *calcula(void* id){
	printf("oi da thread %ld de %d\n",(long) id, numThreads);
	return NULL;
}

int main(int argc, char **argv){
	long thread;
	pthread_t *threadh;
	tamanho = atoi(argv[1]);
	int i;
	A = (int *)malloc(tamanho*sizeof(int *));
	for(i=0;i<tamanho;i++){
		A[i] = (int)malloc(tamanho*sizeof(int));
	}

	threadh = malloc (numThreads*sizeof(pthread_t));
	
	for(thread =0; thread<numThreads;thread++){
		pthread_create(&threadh[thread],NULL,hello,(void *)thread);
	}

	printf("oi da main");

	for(thread =0;thread<numThreads;thread++){
		pthread_join(threadh[thread],NULL);
	}
	free(threadh);
	return 0;
}
