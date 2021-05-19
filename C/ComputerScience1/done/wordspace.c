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

	for (k = 0; k < len; k++ )
	{
		printf("%c", word[k]);
		if ( k != len - 1 )
			printf("-", word[k]);
	}
		printf("\n");
	return 0;
}
