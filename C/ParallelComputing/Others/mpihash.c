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

	for ( int k = world_rank; k < ALPHABET; k += world_size )
	{

		unsigned long possans;
		char temp[MAXCHAR + 1] = "aaaa";

		temp[0] = possible[k];

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
						MPI_Finalize();
						return 0;
	               	}
		   	    }
	    	}
		 }
	}

	MPI_Finalize();

	return 0;
}
