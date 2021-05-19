#include <stdio.h>

int main()
{
	int age, retire;

	printf("How old are you\n");

	scanf("%d", &age);

	retire = 65 - age;

	if ( age < 65 )
	{
	printf("You are %d years from retirement\n", retire);
	}
	else
	{
	printf("You are able to retire\n");
	}
	return 0;
}
