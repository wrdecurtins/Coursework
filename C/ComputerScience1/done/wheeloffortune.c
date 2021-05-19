#include <stdio.h>
#include <string.h>

int main()
{
	char ans[100], guess[100];
	int len;
	int k;
	char c, extra;

	fgets( ans, 100, stdin );
	// remove \n at end
	len = strlen( ans );
	len--;
	ans[len] = '\0';

	printf("\n\n\n");
	printf("\n\n\n");
	printf("\n\n\n");
	printf("\n\n\n");
	printf("\n\n\n");
	printf("\n\n\n");
	printf("\n\n\n");
	printf("\n\n\n");
	printf("\n\n\n");
	printf("\n\n\n");
	printf("\n\n\n");
	printf("\n\n\n");
	printf("\n\n\n");

	for ( k = 0; k < len; k++ )
	{
		c = ans[k];
		if ( c == 'r' || c == 's' || c == 't' || c == 'l' || c == 'e' )
			printf("%c ", c);
		else if ( c ==' ' )
			printf("    ");
		else
			printf("_ ");
	}
	printf("\n\n\n");

	printf("Show one more letter: ");
	char junknl;
	scanf("%c%c", &extra, &junknl);

	for ( k = 0; k < len; k++ )
	{
		c = ans[k];
		if ( c == 'r' || c == 's' || c == 't' || c == 'l' || c == 'e' || c == extra )
			printf("%c ", c);
		else if ( c ==' ' )
			printf("    ");
		else
			printf("_ ");
	}

	printf("\n\n\n");

	printf("Solve the puzzle: ");

	fgets ( guess, 100, stdin );
	// remove \n at end
	len = strlen( guess );
	len--;
	guess[len] = '\0';

	if ( strcmp ( ans, guess ) == 0 )
		printf("\nCorrect, you win fabulous prizes\n");
	else
	{
		printf("\nSorry, nothing for you\n");
		printf("Correct answer is %s\n", ans);
	}

	printf("\n");
	return 0;

}
