// MPI practice program 10/28

// what does it do??

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) 
{
	// Initialize the MPI environment
	MPI_Init(NULL, NULL);

	// Find out rank, size
	int world_rank;
	int world_size;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	/* sample code from your example on Monday
    MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	*/

	/////////////////////////////////////////////	
	if ( world_rank == 0 )
	{
		int vals[] = {0,1,2,3,4};
		int k, res = 0, tmp;

		for ( k = 1; k <= 4; ++k )
    		MPI_Send(vals+k, 1, MPI_INT, k, 0, MPI_COMM_WORLD);

		for ( k = 1; k <= 4; ++k )
		{
    		MPI_Recv(&tmp, 1, MPI_INT, k, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			res = res + tmp;
		}
		printf("Final answer: %d\n", res);

	}
	else
	{
		int innum, outnum;
    	MPI_Recv(&innum, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		outnum = innum * innum;
    	MPI_Send(&outnum, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
	}
	

	/////////////////////////////////////////////	
	MPI_Finalize();
	return 0;
}





