#include <stdio.h>
#include <string.h>

int isVowel( char c )
{
	if ( c == 'a' )
		return 1;
	else if ( c == 'e' )
		return 1;
	else if ( c == 'i' )
		return 1;
	else if ( c == 'o' )
		return 1;
	else if ( c == 'u' )
		return 1;
	else
		return 0;
}


int main()
{
	char letter;

	scanf("%c", &letter);

	printf("%d\n", isVowel( letter ));

}
