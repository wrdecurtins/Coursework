// sent a portion of the list to each node
//   List of 16; each gets 6
// show what each gets


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


    	MPI_Scatter(vals, 4, MPI_INT,
					myvals, 4, MPI_INT,
					0, MPI_COMM_WORLD);
	}
	else
	{
    	MPI_Scatter(vals, 4, MPI_INT,
					myvals, 4, MPI_INT,
					0, MPI_COMM_WORLD);
	}


	for ( i = 0; i < 4; ++i )
	{
		printf("Proc: %2d    i: %2d     val: %2d\n",
					myrank, i, myvals[i]);
	}

	/////////////////////////////////////////////
	MPI_Finalize();
	return 0;
}





