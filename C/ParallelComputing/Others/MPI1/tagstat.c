// p0 accepts mgs until everyone is done
// using tag & status
// Msg: 1 int    
// Status: 
//   Tag: (2)data (6)done
//   Source


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

	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	/////////////////////////////////////////////	

	int msg;

	if ( myrank == 0 )
	{
		printf("World size %d\n", world_size);
		int done = 1;
		int msgCount = 0;
		MPI_Status status;
		while ( done < world_size )
		{
			MPI_Recv(&msg, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG,
					MPI_COMM_WORLD, &status);
			printf("%d %d %d\n", status.MPI_SOURCE, 
							msg, status.MPI_TAG);
			if ( status.MPI_TAG == 2 )
				msgCount++;
			if ( status.MPI_TAG == 6 )
				done++;
		}
		printf("%d total messages\n", msgCount);
	}
	else
	{
		int setup[]={0,3,7,2,4,3};
		for ( int i = 0; i < setup[myrank]; i++ )
		{
			msg = myrank * 10 + i;
			MPI_Send(&msg, 1, MPI_INT, 0,
                             2, MPI_COMM_WORLD);
		}
		msg = 0;
		MPI_Send( &msg, 1, MPI_INT, 0,
                             6, MPI_COMM_WORLD);
	}

	/////////////////////////////////////////////	
	MPI_Finalize();
	return 0;
}





