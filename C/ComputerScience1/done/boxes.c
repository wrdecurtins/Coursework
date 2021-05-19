#include <stdio.h>

int main()
{
	int row, col, r, c;

	row = 3;
	col = 5;

	for ( r = 1; r <= row; r += 1 )
	{
		for ( c = 1; c <= col; c += 1 )
			printf("@");
		printf("\n");
	}

	return 0;
}
