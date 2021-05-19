#include <stdio.h>
#include <string.h>

int main()
{
	char word [100];
	int len, k, counta = 0;

	printf("Whats is your word, word?: ");
	scanf("%s", word);

	len = strlen( word );

	for ( k = 0; k < len; k += 1 )
	{
		if ( word[k] == 'a' )
			counta += 1;
	}

	printf("This is how many a's: %d\n", counta);
	return 0;
}
