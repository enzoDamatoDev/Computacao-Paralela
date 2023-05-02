/* Grupo EEG - 5N
Enrique Granado 32107803
Enzo Damato 32125992
Gabriel Santos 32107439 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int size = 65536;
//int size = 10;
int alvo, indice=-1;
int *array;

void thread(){
	int atual = omp_get_thread_num();
	int tamanho = size/omp_get_num_threads();
	int resto = size%omp_get_num_threads();
	int inicio = atual*tamanho;
	int final = inicio+tamanho;
//	printf("%d %d %d\n",inicio,tamanho, final-1);
	int i;
	for(i=inicio;i<final;i++){
        if(array[i] == alvo){
			indice = i;
			printf("%d\n",indice);
			exit(0);
		}
	}

}

int main(int argc, char **argv){
	if(argc<2){ // verifica se foi passado o alvo
		printf("informe o alvo!");
		exit(1);
	}
	alvo = atoi(argv[1]); // salva o alvo
	
	int thread_count = omp_get_max_threads(); //verifica o numero maximo de threads
	if(thread_count>size){ // se o numero maximo for maior que o vetor, sera criada uma thread para cada item
		thread_count=size;
	}
	array = (int *)calloc( size, sizeof(int) ); //aloca o vetor
	if(array == NULL){ exit(1); } //verifica se o vetor foi alocado
	
	FILE *arquivo;
	char *nome = "/home/ubuntu/Computacao-Paralela/Lab06c/vetor1.txt";
	int i;
	arquivo = fopen(nome,"r");
	if(arquivo == NULL){
		printf("arquivo nao encontrado");
		exit(1);
	}
	
	for(i=0;i<size;i++){
		if(fscanf(arquivo, "%d", &array[i]) != 1){
			printf("erro ao ler arquivo na linha %d\n",i+1);
			exit(1);
		}
		//printf("%d\n",array[i]);
	}
	
	# pragma omp parallel num_threads (thread_count)
	thread();

	printf("%d\n",indice);
	return 0;
}
