
// MPI practice prorgram 10/25

//for exactly 4 nodes
// pass the token around to each process
//  0 to 1 to 2 to 3 ... and back to 0


#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	// Initialize the MPI environment
	MPI_Init(NULL, NULL);

	// Find out rank, size
	int my_rank;
	int world_size;
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	/* sample code from your example last class 
	MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD); 
	MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	 */
/////////////////////////////////////////////
	int token;

	if ( my_rank == 0 )
	{
		printf("Proc %d of %d \n", my_rank, world_size);
		token = 42;
		MPI_Send(&token, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
		printf("Proc 0 sent token to 1\n");
		MPI_Recv(&token, 1, MPI_INT, 3, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

	}
	else if ( my_rank == 1 )
	{
		printf("Proc %d of %d \n", my_rank, world_size);
		MPI_Recv(&token, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		MPI_Send(&token, 1, MPI_INT, 2, 0, MPI_COMM_WORLD);
		printf("Proc 1 sent token to 2\n");
	}
	else if ( my_rank == 2 )
	{
		printf("Proc %d of %d \n", my_rank, world_size);
		MPI_Recv(&token, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		MPI_Send(&token, 1, MPI_INT, 3, 0, MPI_COMM_WORLD);
		printf("Proc 2 sent token to 3\n");
	}
	else if ( my_rank == 3 )
	{
		printf("Proc %d of %d \n", my_rank, world_size);
		MPI_Recv(&token, 1, MPI_INT, 2, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		MPI_Send(&token, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
		printf("Proc 3 sent token to 0\n");
	}

/////////////////////////////////////////////
	MPI_Finalize();
	return 0;
}

