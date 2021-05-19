#include <stdio.h>

int main()
{
	int times, num, count7;

	count7 = 0;

	for (times = 1, times <= 10; times += 1)
	{
		printf("Enter value: ");
		scanf("%d", &num);

		if (num == 7 )
			count7 += 1;
	}

	printf("There were %d 7s in the list\n", count7);

	return 0;
}
