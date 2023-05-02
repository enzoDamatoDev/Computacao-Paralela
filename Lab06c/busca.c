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
	int inicio = atual*tamanho;
	//printf("%d %d %d\n",inicio,alvo, inicio+tamanho-1);
	int i;
	for(i=inicio;i<inicio+tamanho;i++){
                if(array[i] == alvo){
			indice = i;
			return;
		}
	}

}

int main(int argc, char **argv){
	alvo = atoi(argv[1]);
	int thread_count = omp_get_max_threads();

	if(thread_count>size){
		thread_count=size;
	}
	array = (int *)calloc( size, sizeof(int) );
	if(array == NULL){ exit(1); }
	int i;
	for(i=0;i<size;i++){
		array[i] = i;
	}
	# pragma omp parallel num_threads (thread_count)
	thread();

	printf("%d\n",indice);
	return 0;
}
