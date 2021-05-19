#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *fp;
	char buff[100];

	fp = fopen("inphrase", "r");
	if (fp == NULL)
	{
		printf("[ERROR]: file  inphrase  not available\n");
		exit(1);
	}

/*
	while (  fgets( buff, 100, fp ) != NULL )
	{
		printf("Read: %s", buff);
	}
*/

	fgets( buff, 100, fp );
	while (  ! feof( fp )  )
	{
		printf("Read: %s", buff);
		fgets( buff, 100, fp );
	}


	return 0;
}
