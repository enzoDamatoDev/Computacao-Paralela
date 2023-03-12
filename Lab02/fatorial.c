#include <stdio.h>
#include <unistd.h>

int main()
{
   int num, pip[2]; 
   pipe(pip); //cria o pipe
   printf ("Enter the number: ");
   scanf ("%d", &num);
   int id = fork(); // divide os processos
   int i;
	if(id == 0){ // processo filho cuida dos numeros pares
		int j = num;
		close(pip[0]);
		
		for (i=1; j > 1; j = j -2) {
		     i=i*j;
		}
		write(pip[1], &i, sizeof(j)); // escreve resposta no pipe
		close(pip[1]);
		
	}else{ // processo pai cuida dos numeros impares
		int j = num-1;
		for (i=1; j > 1; j = j -2) {
			 i=i*j;
		}
		int impar;
		
		close(pip[1]);
		read(pip[0],&impar,sizeof(impar)); //le a resposta do processo filho
		close(pip[0]);
		int final = impar*i; // multiplica as duas respostas
		printf("The factorial of %d is %d\n",num,final);
	}
	return 0;
}
