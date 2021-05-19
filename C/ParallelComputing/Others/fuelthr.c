/*###########################################

***Answers and Timing***************

--mass1.dat--
Total Fuel F = 10
real    0m1.003s
user    0m0.004s
sys     0m0.004s

--mass2.dat--
Total Fuel F = 597
real    0m3.003s
user    0m0.004s
sys     0m0.004s

--gg--
Total Fuel F = 14991
real    0m17.005s
user    0m0.004s
sys     0m0.004s

--hh--
Total Fuel F = 546321\
real    2m41.018s
user    0m0.003s
sys     0m0.008s

***Code Explanation***************

This program reads the integers from an input file to populate
array M while keeping track of the total number of integers
inputed in N. We initialize 3 omp threads to do the work.
Those treads then are tasked with calling the threadTask
which does the dividing of work for the threads. A critical
section function gets the value that needs to be processed next
so I am using dynamic scheduling. Then for each thread works to-
gether to call findF for every element in M we and we add its
return to global the totalF variable, which resides in a critical
section. After the total fuel is calculated the main thread
figures out how many 100's are in totalF by subtracting 100
until totalF is less than 100 and counting each time. Then we
add 110 multiplied by the number of 100's to replace what we
subtracted and add 10 extra per 100. Then we have our final
value so we print it and exit.

###########################################*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <omp.h>

#define MAXN 10000


int M[MAXN] = {0};
int next = 0;
int totalF = 0;
int N = 0;

int findF( int M );

int get_next()
{
	int assign;
	assign = next;
	next++;
	if ( next > N )
		assign = -1;
	return assign;
}

void threadTask()
{
	int task;
	int F;

	#pragma omp critical
		task = get_next();
	while ( task != -1 )
	{
		sleep(1);
		F = findF(M[task]);
		totalF += F;
//		printf("%d: F = %d\n",task,F);
		#pragma omp critical
			task = get_next();
	}
}

int main( int argc, char ** argv)
{
	FILE *fptr;
	char filename[20];
	int k, getM, my_rank;
	int countHundreds = 0;

	sscanf(argv[1], "%s", &filename);

	fptr = fopen(filename,"r");

	if (fptr == NULL)
	{
		printf("Invalid file\n");
		exit(0);
	}

	fscanf(fptr, "%i", &getM);
	while( !feof (fptr) )
	{
		M[N] = getM;
		N++;
		fscanf(fptr, "%i", &getM);
	}
	fclose(fptr);
//	N--;

	omp_set_num_threads(3);
	#pragma omp parallel
		threadTask();

	while ( totalF > 100 )
	{
		totalF -= 100;
		countHundreds++;
	}

	totalF += (110 * countHundreds);

	printf("Total Fuel F = %d\n",totalF);

	return 0;
}

int findF( int M )
{
	double F;

	if ( M == 0 )
		return 1;

	F = (((double) M)/4) - 3;

	if ( F < 1 )
		return 1;

	return floor(F);
}
