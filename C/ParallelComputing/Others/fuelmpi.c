/*###########################################

***Answers and Timing***************

--mass1.dat--
Total Fuel F = 10
real    0m1.878s
user    0m0.228s
sys     0m0.195s

--mass2.dat--
Total Fuel F = 597
real    0m3.909s
user    0m0.212s
sys     0m0.251s

--gg--
Total Fuel F = 14991
real    0m17.891s
user    0m0.199s
sys     0m0.239s

--hh--
Total Fuel F = 546321
real    2m41.887s
user    0m0.193s
sys     0m0.169s

***Code Explanation***************
This program reads the integers from an input file to populate
array M while keeping track of the total number of integers
inputed in N. After initializing the MPI environment, the main
process broadcasts the array M to all other processes. Then for
each element in M the threads call the findF function if than M
value modulo world_size is equal to the that threads rank. The
Threads store these values into a local totalF value, which is
returned to the main thread via an MPI_Gather. The main thread
compiles these values into an array, which is then added up to
get the real final total. After the total fuel is calculated we
figure out how many 100's are in totalF by subtracting 100
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
#include <mpi.h>

#define MAXN 10000

int findF( int M );

int main( int argc, char ** argv)
{
	FILE *fptr;
	char filename[20];
	int F, k, getM;
	int N;
	int totalF = 0;
	int allTotalF[3] = {0};
	int countHundreds = 0;
	int M[MAXN] = {0};

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

	int world_rank;
	int world_size;

	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	if (world_size != 3 && world_rank == 0)
	{
		printf("There must be three processes for this assignment\n");
		MPI_Finalize();
		exit(0);
	}

	MPI_Bcast(M,N,MPI_INT,0,MPI_COMM_WORLD);

	for ( k = 0; k < N; k++ )
	{
		if ((k % world_size) == world_rank )
		{
			sleep(1);
			F = findF(M[k]);
			totalF += F;
			//printf("%d: F = %d\n",k,F);
		}
	}

	MPI_Gather(&totalF,1,MPI_INT,allTotalF,1,MPI_INT,0,MPI_COMM_WORLD);

	if ( world_rank == 0)
	{
		totalF = 0;
		for ( k = 0; k < 3; k++ )
			totalF += allTotalF[k];
		while ( totalF > 100 )
		{
			totalF -= 100;
			countHundreds++;
		}
		totalF += (110 * countHundreds);
		printf("Total Fuel F = %d\n",totalF);
	}

	MPI_Finalize();

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
