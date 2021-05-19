#include <stdio.h>
#include <omp.h>

int main()
{
	int i = 0;
	omp_set_num_threads(5);

	printf("just me\n");
	#pragma omp parallel 
	{
		printf("a\n");
	}

	printf("still just one\n");
	#pragma omp parallel num_threads(3)
	{
		printf("b\n");
	}
	printf("to the end\n");
	return 0;
}

