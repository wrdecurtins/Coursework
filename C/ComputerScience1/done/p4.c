#include <stdio.h>
#include <string.h>

int main()
{
	char s[20], t[20];

	printf("Enter word: ");
	scanf("%s", s);
	printf("Entered: -->%s<--\n", s);
	printf("Making a copy\n");
	strcpy(t, s);
	printf("t is now %s\n", t);
	printf("Adding on some *s\n");
	strcat( t, "** ** **");
	printf("t is now %s\n", t);

	return 0;
}
