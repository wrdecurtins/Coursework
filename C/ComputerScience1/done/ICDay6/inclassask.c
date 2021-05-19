#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *fp;
	char buff[100];
	int i, NL;
	char c;
	char fname[25];

	printf("What file? ");
	scanf( "%s", fname);

	fp = fopen(fname, "r");
	if (fp == NULL)
	{
		printf("[ERROR]: file  %s  not available\n", fname);
		exit(1);
	}

	fscanf( fp, "%d", &NL);
	fscanf( fp, "%c", &c);
	//fscanf( fp, "%d ", &NL);
	//space after %d tells to read all trailing white space
	//fscanf( fp, "%d\n", &NL);
	for (i = 0; i < NL; ++i)
	{
		fgets( buff, 100, fp );
		printf("%d: %s\n", i, buff);
	}	

	return 0;
}
