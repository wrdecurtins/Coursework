#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>

int main()
{
	int i = 0;
	omp_set_num_threads(5);

	printf("just me\n");
	#pragma omp parallel sections 
	{
		#pragma omp section
		{
		sleep(1);
		printf("a  call fun1() %d\n", omp_get_thread_num());
		sleep(1);
		}
		#pragma omp section
		{
		sleep(1);
		printf("b  call fun2() %d\n", omp_get_thread_num());
		sleep(1);
		}
		#pragma omp section
		{
		sleep(1);
		printf("c  call fun3() %d\n", omp_get_thread_num());
		sleep(1);
		}
	}

	printf("to the end\n");
	return 0;
}

