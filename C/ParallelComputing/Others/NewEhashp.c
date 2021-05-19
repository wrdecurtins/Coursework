#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

#define MAXCHAR 4

#define ALPHABET 39
char possible[ALPHABET+1] = "abcdefghijklmnopqrstuvwxyz1234567890@&*";
unsigned long ans;
unsigned long test;


unsigned long hash(char *str);

void *threadtask( void *param )
{
	long init;
	init = (long) param;

	unsigned long possans;

	char temp[MAXCHAR + 1] = "aaaa\0";

	temp[0] = possible[init];

	for ( int k = 1; k < MAXCHAR; k++ )
		temp[k] = possible[0];

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
				if ( possans == test )
				{
					printf("----> %s\n", temp);
					exit(0);
				}
			}
		}
	}
}

int main ( int argc, char *argv[] )
{
	void *status;

	sscanf(argv[1], "%llu", &test);

	printf("Testing... %lu\n", test );

	pthread_t tid[ALPHABET];

	for ( long x = 0; x < ALPHABET; x++ )
	{
		pthread_create( &tid[x], NULL, threadtask, (void *) x);
	}

	for ( int k = 0; k < ALPHABET; k++ )
	{
		pthread_join( tid[k], &status);
	}


	return 0;
}
