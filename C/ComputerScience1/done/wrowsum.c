#include <stdio.h>
#include <stdlib.h>

#define ROW 5
#define COL 7

void printA2( int a[ROW][COL] )
{
	int r,c;

	for ( r = 0; r < ROW; ++r )
	{
		printf("[ ");
		for ( c = 0; c < COL; ++c )
			printf("%2d ", a[r][c]);
		printf(" ]\n");
	}
}

void fillMatrix( int a[ROW][COL], int high )
{
	int r, c;
	for ( r = 0; r < ROW ; r++ )
		for ( c = 0; c < COL; c++ )
			a[r][c] = rand() % high + 1;
}

int rowSum( int a[ROW][COL], int rownum )
{
	int c, sumOfRow = 0;

	for ( c = 0; c < COL; c++ )
		sumOfRow += a[rownum][c];

	return sumOfRow;
}

int colSum( int a[ROW][COL], int colnum )
{
	int r, sumOfCol = 0;

	for ( r = 0; r < ROW; r++ )
		sumOfCol += a[r][colnum];

	return sumOfCol;
}



int main()
{
	int grid[ROW][COL], rownum, colnum;

	fillMatrix( grid, 10 );
	printA2( grid );


	printf("Row Number to add up?: ");
	scanf("%d", &rownum);
	printf("Sum of row %d: %2d\n", rownum, rowSum( grid, rownum ));

	printf("Column Number to add up?: ");
	scanf("%d", &colnum);
	printf("Sum of column %d: %2d\n", colnum, colSum( grid, colnum ));

	return 0;
}

