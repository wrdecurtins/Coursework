#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mpi.h>
#include <string.h>

#define MAXCHAR 4
#define ALPHABET 39

unsigned long hash( char *str );
char possible[ALPHABET+1] = "abcedfghijklmnopqrstuvxyz1234567890@&*";
char FALSE[] = "f";

int work( unsigned long Hash, int init , int world_rank);

int main( int argc, char** argv )
{
	if ( argc != 2 )
	{
		printf("Invalid number of arguements\n");
		exit(1);
	}

	unsigned long Hash;
	sscanf(argv[1], "%llu", &Hash);

	int world_rank;
	int world_size;

	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	if (world_rank == 0)
	{
		printf("Testing... %llu\n", Hash );
	}
	int k = world_rank;
//	for ( int k = world_rank; k < ALPHABET; k += world_size )
	while ( k < ALPHABET )
	{
//		if ( k % world_size == world_rank )
			if( work(Hash, k, world_rank) )
			{
//				MPI_Finalize();
				return 0;
			}
		printf("world_size = %d\n", world_size);
		k+= world_size;
	}

//	printf("ERROR, hash unfound\n");

	MPI_Finalize();

	return 0;
}

int work( unsigned long Hash, int init , int world_rank)
{
	unsigned long possans;
	char temp[MAXCHAR + 1] = "aaaa";

	temp[0] = possible[init];

	printf("Proc %d testing %c\n", world_rank, temp[0]);

	for ( int k = 0; k < ALPHABET; k++ )
    {
       	temp[1] = possible[k];
        for ( int h = 0; h < ALPHABET; h++ )
        {
            temp[2] = possible[h];
   	        for ( int m = 0; m < ALPHABET; m++ )
       	    {
           	    temp[3] = possible[m];
               	possans = hash(temp);

                if ( possans == Hash )
   	            {
					printf("----> %s\n", temp);
					return 0;
               	}
	   	    }
    	}
	 }
	 return 1;
}
