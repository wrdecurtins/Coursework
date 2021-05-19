#include <stdio.h>
#include <stdlib.h>

int main()
{
	int k, num, sum, over10, sumover10;

	sum = 0;
	over10 = 0;
	sumover10 = 0;

	for ( k = 0 ; k < 20 ; k += 1 )
	{
		//printf("Enter value: ");
		//scanf("%d", &num);

		num = rand() % 21 + 5;
		printf("%d ", num);

		sum += num;
		if ( num > 10 )
		{
			over10 += 1;
			sumover10 += num;
		}
	}
	printf("\n");

	printf("Total is %d\n", sum);
	printf("%d value(s) over 10\n", over10);
	printf("The total value of numbers over 10 is: %d\n", sumover10);

	return 0;
}
