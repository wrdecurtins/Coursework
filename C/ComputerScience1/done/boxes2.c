#include <stdio.h>

int main()
{
	int row, col, r, c, spaces;
	printf("row: ");
	scanf("d", &row);
	printf("col: ");
	scanf("d", &col);
	//row = 5;
	//col = 7;

	for ( r = 1; r <= row; r += 1 )
	{
		for ( c = 1; c <= col; c += 1 )
			if ( r == 1 || r == row )
				printf("@");

			if ( r != 1 && r != row )
				{
					printf("@");

					for ( spaces = 1; spaces <= col - 2; spaces++ )
						printf(" ");

					printf("@");
				}
		printf("\n");
	}

	return 0;
}
