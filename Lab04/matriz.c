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

#define ADDKEY 5
int main(int argc, char **argv)
{
	
    if(argc < 2){ // verifica se  foi passado o tamanho da matriz
	   printf("insira o tamanho da matriz no segundo argumento!\n");
	   exit(1);
    }
    
    int SIZE = atoi(argv[1]); //salva o tamanho da matriz
    int row, col,k=0,sum,A[SIZE][SIZE],B[SIZE][SIZE]; // inicia as variaveis7
    
    for(row=0; row<SIZE; row++) // inicia matriz A
    {
        for(col=0; col<SIZE; col++)
        {
            A[row][col] = k++;
	}
    }

     for(row=0; row<SIZE; row++)// inicia matriz B
    {
        for(col=0; col<SIZE; col++)
        {
            B[row][col] = k++;
        }
    }
    
    for(row=0; row<SIZE; row++) // imprime matriz A
    {
        for(col=0; col<SIZE; col++)
        {
            printf("%d ",A[row][col]);
        }
        printf("\n");
    }
    
    printf("\n");
    for(row=0; row<SIZE; row++) // imprime matriz B
    {
        for(col=0; col<SIZE; col++)
        {
            printf("%d ",B[row][col]);
        }
        printf("\n");
    }
    printf("\n");    

    int shmid,subShmid[SIZE]; // identificador da memória comum 
	int size = SIZE*SIZE*sizeof(int); // tamanho da memoria alocada
	int **mem; // ponteiro para a memoria comparilhada
	char *path="./";
	if (( shmid = shmget(ftok(path,ADDKEY), size, IPC_CREAT|SHM_R|SHM_W|0)) == -1) { // aloca a memoria ou retorna o id se ja estiver alocada
		printf("Ocorreu um erro durante a alocacao\n");
		return 1;
	}	
	
	
		if((mem = (int **)shmat(shmid,0,0))== (int **)-1){ // recupera o endereço de memoria compartilhada
			perror("Erro no shmat");
			exit(1);
		}
		for(k=0;k<SIZE;k++){ //aloca a segunda dimensao da matriz compartilhada

			subShmid[k] = shmget(IPC_PRIVATE, SIZE*sizeof(int*), IPC_CREAT|SHM_R|SHM_W|0);
			if((mem[k] = shmat(subShmid[k],0,0))== (int*)-1){ // recupera o endereço de memoria compartilhada
				perror("Erro no shmat");
				exit(1);
			}
		}	
    
    int id = fork(); // cria outro processo
	if(id == 0){// processo filho
		for(row=1; row<SIZE; row +=2) //multiplica as linhas impares
	    {
	        for(col=0; col<SIZE; col++)
	        {
	            sum = 0;
	            for(k=0; k<SIZE; k++)
	            {
	                sum += A[row][k] * B[k][col];
	            }
		  
	            mem[row][col] = sum;
	        }
	    }
	}else{// processo pai
	    for(row=0; row<SIZE; row +=2) //multiplica as linhas pares
	    {
	        for(col=0; col<SIZE; col++)
	        {
	            sum = 0;
	            for(k=0; k<SIZE; k++)
	            {
	                sum += A[row][k] * B[k][col];
	            }
		    
	            mem[row][col] = sum;
	        }
	    }
	    
	    wait(NULL); // espera o processo filho encerrar
	
	
	    printf("\nRESULTADO:\n"); //imprime o resultado
	    for(row=0; row<SIZE; row++)
	    {
	        for(col=0; col<SIZE; col++)
	        {
	            printf("%d ",mem[row][col]);
	        }
	        printf("\n");
	    }
	   
	    if ((shmctl(shmid, IPC_RMID, NULL)) == -1){ perror("Erro shmctl()") ; // destroi a memoria compartilhada
			printf("erro ao apagar\n");
			exit(1);
		}
		
		for(k=0;k<SIZE;k++){ // destroi a segunda dimensao da matriz compartilhada
			if ((shmctl(subShmid[k], IPC_RMID, NULL)) == -1){ perror("Erro shmctl()") ; // destroi a memoria compartilhada
				printf("erro ao apagar\n");
				exit(1);
			}
		}
		
	}
    
    return 0;
}
