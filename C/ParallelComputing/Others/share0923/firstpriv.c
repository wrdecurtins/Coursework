#include <stdio.h>
#include <omp.h>

int main()
{
	int i = 0;
	int me;
	int fun = 13;
	omp_set_num_threads(5);

	#pragma omp parallel  private(me)  firstprivate(fun) 
	{
		me = omp_get_thread_num();
		printf("Hi, from %d   fun %d\n", me, fun);

		#pragma omp barrier

			fun = fun + 10;
			printf("Alone, %d   fun %d\n", me, fun);

		#pragma omp barrier

		printf("Bye, from %d   fun %d\n", me, fun);
	}
	return 0;
}

