#include <stdio.h>
#include <string.h>

int main()
{
	char s[20], t[20];

	printf("Enter word: ");
//	scanf("%s", s);
	fgets(s,20,stdin);
	s[strlen(s)-1] = '\0';
	printf("Entered: -->%s<--\n", s);


	return 0;
}
