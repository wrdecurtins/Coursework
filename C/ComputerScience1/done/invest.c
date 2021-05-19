#include <stdio.h>

int main()
{
	int Y, n;
	float M, I, grow, YearlyInvest;

	printf("Money   : ");
	scanf("%f", &M);
	printf("Years   : ");
	scanf("%d", &Y);
	printf("PayPerYe: ");
	scanf("%f", &YearlyInvest);
	printf("Interest: ");
	scanf("%f", &I);

	I = I / 100;
	grow = M;

	for ( n = 1; n <= Y; n++ )
		grow = (grow * I) + grow + YearlyInvest;

	printf("\nTotal Return: %5.2f\n", grow);

	return 0;
}
