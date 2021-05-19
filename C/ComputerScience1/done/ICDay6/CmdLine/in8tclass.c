#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc,  char *argv[] )
{
	FILE *fp;
	char buff[100];
	int i, NL;
	char c;

	if (argc < 2)
	{
		printf("[ERROR]: use   %s  filename     to run program\n", argv[0]);
		exit(1);
	}

	fp = fopen( argv[1]   , "r");
	if (fp == NULL)
	{
		printf("[ERROR]: file  %s  not available\n", argv[1]);
		exit(1);
	}

	fscanf( fp, "%d", &NL);
	fscanf( fp, "%c", &c);
	for (i = 0; i < NL; ++i)
	{
		fgets( buff, 100, fp );
		printf("%d: %s\n", i, buff);
	}	

	return 0;
}
