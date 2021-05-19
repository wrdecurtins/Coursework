#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *infp;
	int num1, num2;

	infp = fopen( "myin.txt", "r" );
	if ( infp == NULL )
	{
		printf("Error: file   myin.txt  is not available\n");
		exit(1);
	}

	fscanf(infp, "%d", &num1 );
	printf("First number from file: %d\n", num1);

	fscanf(infp, "%d", &num1 );
	printf("Second number from file: %d\n", num1);

	return 0;
}
