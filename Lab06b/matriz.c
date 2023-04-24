/* Grupo EEG - 4N
Enrique Granado 32107803
Enzo Damato 32125992
Gabriel Santos 32107439 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

//variaveis globais: tamanho das matrizes e as matrizes em si
int tamanho;
int **A;
int **B;
int **C;

void calcula(){ // funcao que ira rodar em cada thread (multiplicacao da linha de seu id)
	int row = omp_get_thread_num();
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
	        
	return;
}

void calculaSerial(){ // funcao para multiplicar as matrizes em serial
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
	return;
}
void inicializar(){ // aloca e preenche as matrizes
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
	tamanho = atoi(argv[1]);
	if(tamanho == 0){ // se o primeiro argumento do programa for 0, o calculo sera serial
		tamanho = atoi(argv[2]);
		inicializar();
		calculaSerial();
	}else{
		inicializar(); // inicializa as matrizes
		# pragma omp parallel num_threads ( tamanho ) 
		calcula();
	}
	return 0;
}
