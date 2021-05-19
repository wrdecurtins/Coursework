#include <stdio.h>

int main()
{
	int num, count, total, n;
	count = 1;
	total = 0;

	printf("Please enter a number: ");
	scanf("%d", &num);
	printf("\n");

	//while loop version
	while ( count <= num )
	{
		printf("%d ", count);

		total += count;
		count += 3;
	}

	printf("\n");
	printf("Total value: %d\n\n", total);

	total = 0;

	//for loop version

	for ( count = 1; count <= num; count += 3  )
	{
		printf("%d ", count);
		total += count;
	}

	printf("\n");
	printf("Total Value: %d\n\n", total);

	return 0;
}
