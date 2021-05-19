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
	int ordering;
	int who[4] = {0,1,2,3};
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	/////////////////////////////////////////////
	if ( myrank == 0 )
	{
		N = 16;
		for ( i = 0; i < N; ++i )
		{
			vals[i] = (i * 21 + 20) %17;
			printf("%2d ", vals[i]);
		}
		printf("\n");
		MPI_Scatter(vals, 4, MPI_INT, myvals, 4, MPI_INT, 0, MPI_COMM_WORLD);
	}
	else
	{
		MPI_Scatter(NULL, 0, 0, myvals, 4, MPI_INT, 0, MPI_COMM_WORLD);
	}
	printf("My first data %d %d\n", myrank, myvals[0]);

	int justmine = 0;
	for ( i = 0; i < 4; i++ )
		justmine += myvals[i];
	printf("My sum %d  %d\n", myrank, justmine);

	int partsum[100];
	MPI_Gather(&justmine, 1, MPI_INT, partsum, 1, MPI_INT, 2, MPI_COMM_WORLD);

	if ( myrank == 2 )
	{
	printf("%d has: ", myrank);
	for ( i = 0; i < 4; i++ )
		printf("%d ", partsum[i]);
	printf("\n");



	int x, y , tmp;
	int who[4] = {0,1,2,3};

	for ( x = 0; x < 4; x++ )
	{
		for ( y = 0; y < 3; y++ )
		{
			tmp = partsum[y];
			partsum[y] = partsum[y+1];
			partsum[y+1] = tmp;
		}
	}

	for ( i = 0; i < 4; i++ )
		printf("%d ", partsum[i]);
	printf("\n");

	for ( i = 0; i < 4; i++ )
		printf("%d ", who[i]);
	printf("\n");

//	for ( i = 0; i < 4; i++ )
//		MPI_Send( &i, 1, MPI_INT, who[i], 0, MPI_COMM_WORLD);

	}

//	int ordering;
//	MPI_Recv( &ordering, 1, MPI_INT, 2, 0, MPI_COMM_WORLD, MPI_SATUS_IGNORE);
	else
		MPI_Scatter(who,1,MPI_INT,&ordering,1,MPI_INT,2,MPI_COMM_WORLD);

	printf("My ordering is %d	reported by %d\n", ordering, myrank);

	/////////////////////////////////////////////
	MPI_Finalize();
	return 0;
}





