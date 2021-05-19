// same as gather
//  scatter:  NULL for sender array for non-0
//   gather:  NULL for recieve for non-0


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

	if (myrank == 0)
    MPI_Scatter(vals, 4, MPI_INT,
				myvals, 4, MPI_INT,
				0, MPI_COMM_WORLD);
	else
    MPI_Scatter(NULL, 0,0,
				myvals, 4, MPI_INT,
				0, MPI_COMM_WORLD);

	for ( i = 0; i < 4; ++i ) 
	{
		printf("Proc: %2d    i: %2d     val: %2d\n", 
					myrank, i, myvals[i]);
		tsum += myvals[i];
	}
	printf("%d:    sum: %d\n", myrank, tsum);	

	if (myrank == 0)	
	MPI_Gather( &tsum, 1, MPI_INT,
				res, 1, MPI_INT,
				0, MPI_COMM_WORLD);
	else
	MPI_Gather( &tsum, 1, MPI_INT,
				NULL, 0,0,
				0, MPI_COMM_WORLD);



	// what if everyone prints, not just 0?
	if ( myrank == 0 )
	{
		for ( i = 0; i < 4; ++i )
			printf("%d RES: %d -- %3d\n", myrank, i, res[i]);	
	}
	

	/////////////////////////////////////////////	
	MPI_Finalize();
	return 0;
}





