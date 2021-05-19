#include <stdio.h>

int main( int argc, char *argv[])
{
	int i;
	int x;
	FILE *fp;

	fp = fopen( argv[1], "r");

	while ( !feof(fp) )
	{
		fscanf( fp, "%d", &x );
		printf("Read %d\n", x);
	}

	return 0;
}
