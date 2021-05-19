#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[])
{
	int i;
	FILE *fp;


	if (argc < 2)
	{
		printf("Error: run with   %s  filename  \n", argv[0]);
		exit(1);
	}


	fp = fopen( argv[1], "w");

	if (fp == NULL)
	{
		printf("Error: file %s not available\n", argv[1]);
		exit(1);
	}


	for ( i = 1; i <= 10; ++i )
	{
		fprintf(fp, "%d\n", i);
	}

	printf("Thank you, data saved to %s\n", argv[1]);

	return 0;
}
