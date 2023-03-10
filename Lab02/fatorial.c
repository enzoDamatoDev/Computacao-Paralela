#include <stdio.h>
#include <unistd.h>
#include  <sys/types.h>

int main()
{
   int num, pip[2];
   pipe(pip);
   printf ("Enter the number: ");
   scanf ("%d", &num);
   int id = fork();
   int i,j = num;
	if(id == 0){
		close(pip[0]);
		
		for (i=1; j > 1; j = j -2) {
		     i=i*j;
		}
		write(pip[1], &j, sizeof(j));
		close(pip[1]);
		
	}else{
		for (i=2; j > 1; j = j -2) {
			 i=i*j;
		}
		int impar;
		
		close(pip[1]);
		read(pip[0],&impar,sizeof(impar));
		close(pip[0]);
		
		int final = impar*j;
		printf("The factorial of %d is %d\n",num,final);
		wait(NULL);
	}
	return 0;
}
