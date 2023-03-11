#include <stdio.h>
#include <unistd.h>

int main()
{
   int num, pip[2];
   pipe(pip);
   printf ("Enter the number: ");
   scanf ("%d", &num);
   int id = fork();
   int i;
	if(id == 0){
		int j = num;
		close(pip[0]);
		
		for (i=1; j > 1; j = j -2) {
		     i=i*j;
		}
		write(pip[1], &i, sizeof(j));
		close(pip[1]);
		
	}else{
		int j = num-1;
		for (i=1; j > 1; j = j -2) {
			 i=i*j;
		}
		int impar;
		
		close(pip[1]);
		read(pip[0],&impar,sizeof(impar));
		close(pip[0]);
		int final = impar*i;
		printf("The factorial of %d is %d\n",num,final);
	}
	return 0;
}
