#include <stdio.h>

int main()
{
	int sum, x, t, cond;

	sum = 0;
	cond = 0;

	printf("How many numbers would you like to add?:");
	scanf("%d", &cond);

	while ( t < cond)
	{
	printf("Enter value: ");
	scanf("%d", &x);
	sum = sum + x;
	t = t + 1;
	}

	printf("Total: %d\n", sum);
	return 0;
}
