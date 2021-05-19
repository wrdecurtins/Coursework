#include <stdio.h>

int main()

{
	int age;

	printf("What is your age?\n");

	scanf("%d", &age);

	if ( age < 18 )
	{
	printf("You are not old enough to vote or drink\n");
	}
	else if ( age < 21 )
	{
	printf("You are old enough to vote and die for your country but not old enough to drink\n");
	}
	else if ( age >= 21 )
	{
	printf("You are old enough to vote and drink, have fun\n");
	}

	return 0;
}
