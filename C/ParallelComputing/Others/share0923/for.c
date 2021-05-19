#include <stdio.h>
#include <unistd.h>
#include <omp.h>

int main()
{	
	int i = 10;
	int tid = 99;
	printf("main1\n");

	omp_set_num_threads(5);

	#pragma omp parallel for private(tid)
    for (i = 0; i < 30; ++i)
    {
        tid = omp_get_thread_num();
        printf("%2d by %3d\n", i, tid);
	}
	
	printf("tid is %d\n", tid);
	printf("main2\n");
	return 0;
}

