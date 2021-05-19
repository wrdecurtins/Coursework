#include <stdio.h>

int main( int argc, char *argv[])
{
	int i;
	int x;
	FILE *fp;

	fp = fopen( argv[1], "r");

	fscanf( fp, "%d", &x );
	while ( !feof(fp) )
	{
		printf("Read %d\n", x);
		fscanf( fp, "%d", &x );
	}

	return 0;
}
