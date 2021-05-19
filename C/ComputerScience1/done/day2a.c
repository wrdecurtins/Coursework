
// Solve each step & test before moving to next
/*
Program:::
read a number, N, from the user

print values from 1 up to N

find sum 1 to N
*/


#include <stdio.h>

int main()
{

	int N, k, sum = 0;

	printf("Give me a number: ");
	scanf("%d", &N);
//read a number, N, from the user

	for ( k = 1; k <= N; k++ )
	{
		printf("%d ", k);
		sum += k;
	}
	printf("\n");
	printf("Sum = %d\n\n", sum);

//print values from 1 up to N

//find sum 1 to N

	return 0;
}



