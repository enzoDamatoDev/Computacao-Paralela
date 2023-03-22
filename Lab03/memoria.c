/* Grupo EEG - 4N
Enrique Granado 32107803
Enzo Damato 32125992
Gabriel Santos 32107439 */

#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

#define ADDKEY 3


int main() {	
	int shmid; // identificador da memória comum 
	int size = sizeof(int); // tamanho da memoria alocada
	int *mem; // ponteiro para a memoria comparilhada
	char *path="./";
	if (( shmid = shmget(ftok(path,ADDKEY), size, IPC_CREAT|SHM_R|SHM_W|0)) == -1) { // aloca a memoria ou retorna o id se ja estiver alocada
		printf("Ocorreu um erro durante a alocacao\n");
		return 1;
	}	
	
	if((mem = shmat(shmid,0,0))== (int*)-1){ // recupera o endereço de memoria compartilhada
		perror("Erro no shmat");
		exit(1);
	}
	
	printf("(pai)valor 1: "); // valor inicial
	scanf("%d", mem);
	
	printf("(pai)%d\n",mem[0]);
	
	int id = fork(); // cria outro processo
	
	if(id==0){ // processo filho
		int valor2;
		
		printf("(filho)valor 2 (+): "); // valor a ser somado
		scanf("%d", &valor2);
		(*mem) += valor2; // modifica o valor da memoria compartilhada
		printf("(filho)valor da memoria: %d\n",mem[0]);
	}else{
		wait(NULL); // espera o processo filho encerrar
		int valor3;
		
		printf("(pai)valor 3 (*): "); // valor a ser multiplicado
		scanf("%d", &valor3);
		(*mem) *= valor3; // modifica o valor da memoria compartilhada

		printf("(pai)valor final: %d\n",mem[0]);
	}


	if ((shmctl(shmid, IPC_RMID, NULL)) == -1){ perror("Erro shmctl()") ; // destroi a memoria compartilhada
		printf("erro ao apagar\n");
		exit(1);
	}
	exit(0);
}
