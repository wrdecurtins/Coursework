// sent X to all processes
// print it

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
	int X;
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	/////////////////////////////////////////////
	if ( myrank == 0 )
		X = 19;
	else
		X = 33;

   	MPI_Bcast(&X, 1, MPI_INT, 0, MPI_COMM_WORLD);
	printf("%d has X %d\n", myrank, X);

	/////////////////////////////////////////////
	MPI_Finalize();
	return 0;
}





