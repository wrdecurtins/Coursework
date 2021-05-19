#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <omp.h>

int main()
{
	int i = 0;
	int me;
	srand(time(NULL));
	omp_set_num_threads(5);

	#pragma omp parallel  private(me) 
	{
		me = omp_get_thread_num();
		printf("Hi, from %d\n", me);
//		sleep(1);
		usleep(rand()%10);  // just a small sleep to show issue

//		#pragma omp barrier

		printf("Bye, from %d\n", me);
	}
	return 0;
}

