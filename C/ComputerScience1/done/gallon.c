#include <stdio.h>

int main()
{
	//declare variables

	int gallons, pints, quarts;

	// get num of gallons

	printf("Gallon to quarts and pints converter\n");
	printf("How many gallons would you like to convert?:");
	scanf("%d", &gallons);

	// compute pints and quarts

	quarts = 4 * gallons;
	pints = 2 * quarts;

	// dispaly results

	printf("Gallons: %2d\n", gallons);
	printf("Quarts:  %2d\n", quarts);
	printf("Pints:   %2d\n", pints);

	//printf("In %d gallons there are %d quarts and %d pints\n", gallons, quarts, pints);

	return 0;
}
