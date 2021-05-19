#include <stdio.h>
#include <string.h>

int main()
{

	char word[25];
	int k, len, line;

	printf("enter a word: ");
	scanf("%s", word);

	printf("Your string is %s\n", word);

	len = strlen( word );

	for ( line = 1; line <= len; line++ )
	{
		for (k = 0; k <= line; k++ )
		{
			printf("%c", word[k]);
		}
		printf("\n");
	}
	return 0;
}
