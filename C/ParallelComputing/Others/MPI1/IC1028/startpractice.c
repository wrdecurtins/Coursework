// sent X to all processes
// print it

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	// Initialize the MPI environment
	MPI_Init(NULL, NULL);

	// Find out rank, size
	int myrank;
	int world_size;
	int X;
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	/////////////////////////////////////////////
	if ( myrank == 0 )
	{
		int V[5] = {0, 8, 5, 2, 6};
		int s[5] = {0, 3, 7, 2, 4};
		int k;
		X = 19;

		for (k = 1; k < world_size; ++k)
		{
			MPI_Send(V+k, 1, MPI_INT, k, 0, MPI_COMM_WORLD);
		}
		for (k = 1; k < world_size; ++k)
		{
			MPI_Recv(&X, 1, MPI_INT, k, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			printf("From %d: %d\n", k, X);
		}
	}
	else
	{
		X = 33;
    	MPI_Recv(&X, 1, MPI_INT, 0, 0,
						MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("%d has X %d\n", myrank, X);
		sleep( 2 );
		int val;
		val = myrank * 1000 + X * 100 + myrank;
		MPI_Send( &val, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
	}


	/////////////////////////////////////////////
	MPI_Finalize();
	return 0;
}





