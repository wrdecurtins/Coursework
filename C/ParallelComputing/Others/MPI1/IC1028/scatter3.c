// same as scatter
//   but all nodes use the same call to MPI_Scatter


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
	int N, M, X, i;
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

	int mysum = 0;
	for ( i = 0; i < 4; ++i )
	{
		mysum += myvals[i];

		printf("Proc: %2d    i: %2d     val: %2d\n",
					myrank, i, myvals[i]);
	}
	if ( myrank > 0 )
		MPI_Send(&mysum,1,MPI_INT,0,0,MPI_COMM_WORLD);
	else
	{
		for ( i = 1; i < 4; i++ )
		{
			MPI_Recv(&mysum,1,MPI_INT,i,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
			printf("%d partial %d\n", i, mysum);
		}
	}

	/////////////////////////////////////////////
	MPI_Finalize();
	return 0;
}





