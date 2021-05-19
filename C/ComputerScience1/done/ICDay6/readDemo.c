#include <stdio.h>

int main()
{
	FILE *infp;
	int num1, num2;

	infp = fopen( "myin.dat", "r" );

	fscanf(infp, "%d", &num1 );
	printf("First number from file: %d\n", num1);

	fscanf(infp, "%d", &num1 );
	printf("Second number from file: %d\n", num1);

	return 0;
}
