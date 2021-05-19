#include <stdio.h>
#include <omp.h>
#include <unistd.h>

int main()
{
	int tid;
	int i = 10;

	printf("main1\n");
	omp_set_num_threads(4);

	#pragma omp parallel private(tid)
	{
		i++;
		sleep(1);
		tid = omp_get_thread_num();
		printf("hi from %d num : %d\n",tid,i);
	}

	printf("middle\n");

	#pragma parallel
	{
		printf("hi again\n");
	}

	printf("main2\n");
	return 0;

}
