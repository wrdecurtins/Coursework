// same as gather... but everyone gets the answers


#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) 
{
	// Initialize the MPI environment
	MPI_Init(NULL, NULL);

	// Find out rank, size
	int myrank;
	int world_size;
	int vals[100];
	int myvals[100];
	int res[100];
	int N, M, X, i;
	int tsum = 0;
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	/////////////////////////////////////////////	
	if ( myrank == 0 )
	{
		N = 16;
		for ( i = 0; i < N; ++i )
		{
			vals[i] = 10 + i;
			printf("%2d ", vals[i]);
		}
		printf("\n");
	}

    MPI_Scatter(vals, 4, MPI_INT,
				myvals, 4, MPI_INT,
				0, MPI_COMM_WORLD);

	for ( i = 0; i < 4; ++i ) 
	{
		printf("Proc: %2d    i: %2d     val: %2d\n", 
					myrank, i, myvals[i]);
		tsum += myvals[i];
	}
	printf("%d:    sum: %d\n", myrank, tsum);	
	
	MPI_Allgather( &tsum, 1, MPI_INT,
				res, 1, MPI_INT,
				MPI_COMM_WORLD);

	for ( i = 0; i < 4; ++i )
		printf("Proc: %d   RES: %d -- %3d\n", myrank, i, res[i]);	
	

	/////////////////////////////////////////////	
	MPI_Finalize();
	return 0;
}





