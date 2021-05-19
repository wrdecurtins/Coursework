#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv)
{
  int world_rank;
  int world_size;
  int number;
  int k;
  int arr[10] = {0};

  MPI_Init(NULL, NULL);
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  // Must have 2 processes
  if (world_size != 2)
  {
    fprintf(stderr, "World size must be 2 for %s\n", argv[0]);
    MPI_Abort(MPI_COMM_WORLD, 1);
  }


  if (world_rank == 0)
  {
    // If we are rank 0, set the number to 27 and send it to process 1
	for ( k = 0; k < 10; k++ )
	{
    	arr[k] = rand() % 50;
		printf("Proc 0 sent %d\n", arr[k]);
	}

    MPI_Send( arr, 10, MPI_INT, 1, 0, MPI_COMM_WORLD);
	usleep(1000);

  }
  else if (world_rank == 1)
  {
	MPI_Recv( arr, 10, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);


	printf("Proc 1 has: ");
	for ( k = 0; k < 10; k++ )
	{
		printf("%2d ", arr[k]);
	}
	printf("\n");
  }

  MPI_Finalize();

}
