/* Grupo EEG - 5N
Enrique Granado 32107803
Enzo Damato 32125992
Gabriel Santos 32107439 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int size = 65536; // tamanho do array
int alvo, indice=-1; // alvo a ser localizado e indice do alvo
int *array; // o array
int thread_count; // numero maximo de threads

void thread(){
	int atual = omp_get_thread_num(); // id da thread atual
	int tamanho = size/omp_get_num_threads(); // numero de casas a serem percorrdas pela thread
	int resto = size%omp_get_num_threads(); // verifica se ha indices nao alocados para nenhuma thread
	int inicio = atual*tamanho; // indice inicial da thread atual
	int final = inicio+tamanho; // indice final da thread atual
	int i;
	for(i=inicio;i<final;i++){ // percorrendo o array
	        if(array[i] == alvo){ // encontrou o alvo
			indice = i; // salva o indice
			printf("%d\n",indice); 
			exit(0); // encerra o programa
		}
	}
	if(atual < resto){ // se ha indices nao verificados aloca um indice para a thread atual
		i = (size-1)-(atual%resto); 
		if(array[i] == alvo){
                        indice = i;
                        exit(0);
                }
	}

}

void serial(){ // busca em serial
	int i;
	for(i=0;i<size;i++){
		 if(array[i] == alvo){
                        indice = i;
                        break;
                }
	}
	printf("%d\n",indice);
        exit(0);
}

int main(int argc, char **argv){

	if(argc<3){ // verifica se foi passado o alvo
		printf("informe o alvo e o caminho!");
		exit(1);
	}
	alvo = atoi(argv[1]); // salva o alvo
	
	thread_count = omp_get_max_threads(); //verifica o numero maximo de threads
	if(thread_count>size){ // se o numero maximo for maior que o vetor, sera criada uma thread para cada item
		thread_count=size;
	}
	array = (int *)calloc( size, sizeof(int) ); //aloca o vetor
	if(array == NULL){ exit(1); } //verifica se o vetor foi alocado
	
	FILE *arquivo;
//	char *nome = "/home/ubuntu/Computacao-Paralela/Lab06c/vetor1.txt";
	char *nome = argv[2];
	int i;
	arquivo = fopen(nome,"r");
	if(arquivo == NULL){ //verifica se o arquivo existe
		printf("arquivo nao encontrado");
		exit(1);
	}	
	for(i=0;i<size;i++){ //le linha a linha do arquivo
		if(fscanf(arquivo, "%d", &array[i]) != 1){
			printf("erro ao ler arquivo na linha %d\n",i+1);
			exit(1);
		}
	}
	
	if(argc==4){ // opcao para rodar serial
                alvo = atoi(argv[1]);
                serial();
        }

	# pragma omp parallel num_threads (thread_count) // inicia sempre o numero maximo de threads
	thread();

	return 0;
}
