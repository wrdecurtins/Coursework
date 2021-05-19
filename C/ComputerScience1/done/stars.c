#include <stdio.h>

int main()
{
	int stars, row, r, c;

	row = 4;
	stars = 0;

	for ( r = 1; r <= row; r++ )
	{
		stars += 1;

		for ( c = 1; c <= stars; c++ )
			printf("*");

		printf("\n");
	}
	return 0;
}
