#include <stdio.h>
#include <string.h>

int main()
{
	char s[20];
	int n, k;

	printf("Enter word: ");
	scanf("%s", s);
	printf("Entered: -->%s<--\n", s);
	n = strlen( s );

	printf("-----\n");
	for ( k = 0; k < n; ++k )
		printf("%c\n", s[k]);
	printf("-----\n");
	for ( k = 0; k < n; ++k )
		printf("%c ", s[k]);
	printf("\n");
	printf("-----\n");
	for ( k = 0; k < n; ++k )
		printf("%2d: %c  %3d\n", k, s[k], s[k]);
	printf("-----\n");


	return 0;
}
