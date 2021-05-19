#include <stdio.h>

int main()
{
	int deg;

	printf("Enter the temperature of the water:\n");
	scanf("%d", &deg);

	printf("The Temp is %d F and water is ", deg);

	if ( deg <= 32 )
	{
		printf("Ice\n");
	}
	else if ( deg >= 212 )
	{
		printf("Steam\n");
	}
	else
	{
		printf("Liquid\n");
	}

	return 0;
}
