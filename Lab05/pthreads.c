#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//variaveis globais: tamanho das matrizes e as matrizes em si
int tamanho;
int **A;
int **B;
int **C;

void *calcula(void* id){ // função que irá rodar em cada thread (multiplicação da linha de seu id)
	long row = (long)id;
	int sum=0,col,k;
	
    for(col=0; col<tamanho; col++)
    {
        sum = 0;
        for(k=0; k<tamanho; k++)
        {
            sum += A[row][k] * B[k][col];
        }
  
        C[row][col] = sum;
    }
	        
	return NULL;
}

void calculaSerial(int tamanho){ // função para multiplicar as matrizes em serial
	int i,j,k,sum;
	for(i=0;i<tamanho;i++){
		for(j=0;j<tamanho;j++){
			sum=0;
			for(k=0;k<tamanho;k++){
				sum += A[i][k] * B[k][j];
			}
			C[i][j] = sum;
		}
	}
}
void inicializar(int tamanho){ // aloca e preenche as matrizes
	int i,j,count=0;
	A = (int **)malloc(tamanho*sizeof(int *));
	for(i=0;i<tamanho;i++){
		A[i] = (int *)malloc(tamanho*sizeof(int));
		for(j=0;j<tamanho;j++){
			A[i][j] = count++;
		}
	}

	B = (int **)malloc(tamanho*sizeof(int *));
	for(i=0;i<tamanho;i++){
		B[i] = (int *)malloc(tamanho*sizeof(int));
		for(j=0;j<tamanho;j++){
			B[i][j] = count++;
		}
	}

	C = (int **)malloc(tamanho*sizeof(int *));
	for(i=0;i<tamanho;i++){
		C[i] = (int *)malloc(tamanho*sizeof(int));
	}
}

int main(int argc, char **argv){
	if(argc<2){ // verifica se foi passado o tamanho da matriz
		printf("informe o tamanho da matriz!");
		exit(1);
	}
	long thread;
	pthread_t *threadh;
	tamanho = atoi(argv[1]);
	int i,j;	
	inicializar(tamanho); // inicializa as matrizes
	
	threadh = malloc (tamanho*sizeof(pthread_t));
	
	for(thread =0; thread<tamanho;thread++){
		pthread_create(&threadh[thread],NULL, calcula,(void *)thread); // inicializa as threads
	}

	for(thread =0;thread<tamanho;thread++){
		pthread_join(threadh[thread],NULL); // espera o encerramento das threads
	}
	free(threadh); // libera o espaço das threads
	
	
	if(tamanho == 0 && argc == 3){ // se o primeiro argumento do programa for 0, o calculo sera serial
		tamanho = atoi(argv[2]);
		inicializar(tamanho);
		calculaSerial(tamanho);
	}
	return 0;
}
