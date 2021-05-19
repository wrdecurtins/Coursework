#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mpi.h>

int main( int argc, char** argv )
{
	if ( argc != 2 )
	{
		printf("Invalid number of arguements\n");
		exit(1);
	}

	int N;
	sscanf(argv[1], "%i", &N);

	int world_rank;
	int world_size;
	int token;

	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);


	if (world_rank == 0)
	{
		token = 100;
		printf("Token starting value: %d\n", token);
		printf("Running %d Token laps...\n", N);
		for ( int k = 1; k <= N; k++ )
		{
			sleep(1);
			printf("Lap %d-----------------------------------\n\n", k);
			printf("Proc 0 sending token %d to Proc 1\n", token);
			MPI_Send(&token, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
			MPI_Recv(&token, 1, MPI_INT, world_size - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			token += 100;
		}
	}
	else
	{
		for ( int k = 1; k <= N; k++ )
		{
			MPI_Recv(&token, 1, MPI_INT, world_rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			usleep(500);
			if (world_rank == world_size - 1)
			{
				MPI_Send(&token, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
				printf("Proc %d sending token %d to Proc 0\n", world_rank, token);
			}
			else
			{
				MPI_Send(&token, 1, MPI_INT, world_rank + 1, 0, MPI_COMM_WORLD);
				printf("Proc %d sending token %d to Proc %d\n", world_rank, token, world_rank + 1);
			}
		}
	}

	MPI_Finalize();

	return 0;
}
