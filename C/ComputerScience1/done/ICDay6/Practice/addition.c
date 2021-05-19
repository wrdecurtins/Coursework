#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[] )
{
	FILE *fp, *fp2;
	int a, b, c;

	if ( argc != 3 )
	{
		printf("Needs two arguements\n");
		exit(1);
	}

	fp = fopen ( argv[1] , "r" );
	fp2 = fopen ( argv[2] , "w" );

	if (fp == NULL)
	{
		printf("file not found\n");
		exit(1);
	}

	fscanf( fp, "%d %d", &a, &b );

	while ( !feof(fp) )
	{
		c = a + b;
		fprintf( fp2, "%d + %d = %d\n", a, b, c);
		fscanf( fp, "%d %d", &a, &b );
	}

	printf("Done\n");

	return 0;

}
