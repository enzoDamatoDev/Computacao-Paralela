/* Grupo EEG - 5N
Enrique Granado 32107803
Enzo Damato 32125992
Gabriel Santos 32107439 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>


void hello (){
	int my_rank = omp_get_thread_num();
	int thread_count = omp_get_num_threads();

	printf("hello from %d od %d\n",my_rank,thread_count);
}


int main(int argc, char **argv){
	int thread_count = atoi(argv[1]);
	# pragma omp parallel num_threads ( thread_count ) 
	hello();

	return 0;
}
