
#include <stdio.h>
#include <string.h>

int main()
{
	char phrase[25];
	int len;
	int count = 0;

	printf("Hint: type in   green chair   to win\n\n\n\n");
	printf("Enter phrase: ");
	fgets( phrase, 25, stdin);
	len = strlen( phrase );
	len--;
	phrase[len] = '\0';

	printf("Your input: %s\n", phrase);
	printf("Lenght is %d\n", len);

	if ( strcmp( phrase, "green chair" ) == 0 )
		printf("Correct\n");
	else
		printf("Sorry you did not follow instructions\n");


	return 0;
}
