#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void thisIsTheFunctionThatGetsInputFromTheUserAndImNotReallySureWhyWeNeedThisManyDifferentFunctionsButWhateverItsCoolTom( char input[20] );
void printGrid( char grid[][20] );
void assignValueToGrid( char grid[][20], char input[20] );
int checkBoardForWin( char grid[][20] );

int main()
{
	char grid[20][20], x, y, input[20];
	int winner = 0;

	thisIsTheFunctionThatGetsInputFromTheUserAndImNotReallySureWhyWeNeedThisManyDifferentFunctionsButWhateverItsCoolTom( input );
	assignValueToGrid( grid, input );

	printf("\n");

	printGrid( grid );
	winner = checkBoardForWin( grid );

	printf("\n");
//	printf("%c %d ", grid[0][0], winner);

	switch ( winner )
	{
		case 21:
			printf("X won, top row win\n");
			break;
		case 22:
			printf("X won, middle row win\n");
			break;
		case 23:
			printf("X won, bottom row win\n");
			break;
		case 24:
			printf("X won, left column win\n");
			break;
		case 25:
			printf("X won, middle column win\n");
			break;
		case 26:
			printf("X won, right column win\n");
			break;
		case 27:
			printf("X won, diagonal top left to bottom right win\n");
			break;
		case 28:
			printf("X won, diagonal top right to bottom left win\n");
			break;
		case 31:
			printf("O won, top row win\n");
			break;
		case 32:
			printf("O won, middle row win\n");
			break;
		case 33:
			printf("O won, bottom row win\n");
			break;
		case 34:
			printf("O won, left column win\n");
			break;
		case 35:
			printf("O won, middle column win\n");
			break;
		case 36:
			printf("O won, right column win\n");
			break;
		case 37:
			printf("O won, diagonal top left to bottom right win\n");
			break;
		case 38:
			printf("O won, diagonal top right to bottom left win\n");
			break;

		default:
			printf("It was a tie\n");
			break;
	}


	return 0;
}

int checkBoardForWin( char grid[][20] )
{
//	check x wins
	if ( ( grid[0][0] == 'x' ) || ( grid[0][0] == 'X' ) )
	{
		if ( ( ( grid[0][1] == 'x' ) && ( grid[0][2] == 'x' ) ) || ( ( grid[0][1] == 'X' ) && ( grid[0][2] == 'X' ) ) )
			return 21;
		if ( ( ( grid[1][1] == 'x' ) && ( grid[2][2] == 'x' ) ) || ( ( grid[1][1] == 'X' ) && ( grid[2][2] == 'X' ) ) )
			return 27;
		if ( ( ( grid[1][0] == 'x' ) && ( grid[2][0] == 'x' ) ) || ( ( grid[1][0] == 'X' ) && ( grid[2][0] == 'X' ) ) )
			return 24;
	}
	if ( ( grid[0][1] == 'x' ) || ( grid[0][1] == 'X' ) )
		if ( ( ( grid[1][1] == 'x' ) && ( grid[2][1] == 'x' ) ) || ( ( grid[1][1] == 'X' ) && ( grid[2][1] == 'X' ) ) )
			return 25;
	if ( ( grid[0][2] == 'x' ) || ( grid[0][2] == 'X' ) )
	{
		if ( ( ( grid[1][2] == 'x' ) && ( grid[2][2] == 'x' ) ) || ( ( grid[1][2] == 'X' ) && ( grid[2][2] == 'X' ) ) )
			return 26;
		if ( ( ( grid[1][1] == 'x' ) && ( grid[2][0] == 'x' ) ) || ( ( grid[1][1] == 'X' ) && ( grid[2][0] == 'X' ) ) )
			return 28;
	}
	if ( ( grid[1][0] == 'x' ) || ( grid[1][0] == 'X' ) )
		if ( ( ( grid[1][1] == 'x' ) && ( grid[1][2] == 'x' ) ) || ( ( grid[1][1] == 'X' ) && ( grid[1][2] == 'X' ) ) )
			return 22;
	if ( ( grid[2][0] == 'x' ) || ( grid[2][0] == 'X' ) )
		if ( ( ( grid[2][1] == 'x' ) && ( grid[2][2] == 'x' ) ) || ( ( grid[2][1] == 'X' ) && ( grid[2][2] == 'X' ) ) )
			return 23;
//	check o wins

	if ( ( grid[0][0] == 'o' ) || ( grid[0][0] == 'O' ) )
		if ( ( ( grid[0][1] == 'o' ) && ( grid[0][2] == 'o' ) ) || ( ( grid[0][1] == 'O' ) && ( grid[0][2] == 'O' ) ) )
			return 31;
		if ( ( ( grid[1][1] == 'o' ) && ( grid[2][2] == 'o' ) ) || ( ( grid[1][1] == 'O' ) && ( grid[2][2] == 'O' ) ) )
			return 37;
		if ( ( ( grid[1][0] == 'o' ) && ( grid[2][0] == 'o' ) ) || ( ( grid[1][0] == 'O' ) && ( grid[2][0] == 'O' ) ) )
			return 34;
	if ( ( grid[0][1] == 'o' ) || ( grid[0][1] == 'O' ) )
		if ( ( ( grid[1][1] == 'o' ) && ( grid[2][1] == 'o' ) ) || ( ( grid[1][1] == 'O' ) && ( grid[2][1] == 'O' ) ) )
			return 35;
	if ( ( grid[0][2] == 'o' ) || ( grid[0][2] == 'O' ) )
		if ( ( ( grid[1][2] == 'o' ) && ( grid[2][2] == 'o' ) ) || ( ( grid[1][2] == 'O' ) && ( grid[2][2] == 'O' ) ) )
			return 36;
		if ( ( ( grid[1][1] == 'o' ) && ( grid[2][0] == 'o' ) ) || ( ( grid[1][1] == 'O' ) && ( grid[2][0] == 'O' ) ) )
			return 38;
	if ( ( grid[1][0] == 'o' ) || ( grid[1][0] == 'O' ) )
		if ( ( ( grid[1][1] == 'o' ) && ( grid[1][2] == 'o' ) ) || ( ( grid[1][1] == 'O' ) && ( grid[1][2] == 'O' ) ) )
			return 32;
	if ( ( grid[2][0] == 'o' ) || ( grid[2][0] == 'O' ) )
		if ( ( ( grid[2][1] == 'o' ) && ( grid[2][2] == 'o' ) ) || ( ( grid[2][1] == 'O' ) && ( grid[2][2] == 'O' ) ) )
			return 33;

	return 0;
}

void printGrid( char grid[][20] )
{
	int x, y;

	for ( x = 0; x < 3; x++ )
	{
		for ( y = 0; y < 3; y++ )
			printf("%c ", grid[x][y]);
		printf("\n");
	}
}

void assignValueToGrid( char grid[][20], char input[20] )
{
	int k = 0, x, y;

	for ( x = 0; x < 3; x++ )
		for ( y = 0; y < 3; y++ )
		{
			grid[x][y] = input[k];
			k++;
		}

	for ( x = 0; x < 3; x++ )

		for ( y = 0; y < 3; y++ )
			if ( (grid[x][y] != 'x') && (grid[x][y] != 'X') && (grid[x][y] != 'o') && (grid[x][y] != 'O') )
				grid[x][y] = ' ';
}

void thisIsTheFunctionThatGetsInputFromTheUserAndImNotReallySureWhyWeNeedThisManyDifferentFunctionsButWhateverItsCoolTom( char input[20] )
{
	printf("TicTacToe Grid: ");
	fgets( input, 20, stdin);
}
