#include <stdio.h>
#include <string.h>

int main()
{
	char line[100];
	int TotNumLines = 0, TotNumHas = 0, TotNumLet = 0;

	while ( fgets( line, 100, stdin ) != NULL )
	{
		int k, NumChar = 0, NumLet = 0, NumSpac = 0, NumHas = 0, NumCons = 0;

		TotNumLines++;

		for ( k = 0; k < strlen(line); k++ )
		{
			if ( line[k] == ' ' )
				NumSpac++;
			else
				NumChar++;

			if ( line[k] == '#' )
				NumHas++;
			else if ( line[k] <= 'z' && line[k] >= 'A' )
			{
				NumLet++;

				if (( line[k] - line[k+1] == -33 ) || ( line[k] - line[k+1] == -1 ))
					NumCons++;
			}
		}


		printf("Number of Characters       : %2d\n", (NumChar - 1));
		printf("Number of letters          : %2d\n", NumLet);
		printf("Number of spaces           : %2d\n", NumSpac);
		printf("Number of #                : %2d\n", NumHas);
		printf("Number of Consecutive chars: %2d\n\n\n", NumCons);

		TotNumHas += NumHas;
		TotNumLet += NumLet;

	}

	printf("Total number of lines  : %2d\n", TotNumLines);
	printf("Total number of #'s    : %2d\n", TotNumHas);
	printf("Total numver of Letters: %2d\n\n", TotNumLet);

	return 0;
}
