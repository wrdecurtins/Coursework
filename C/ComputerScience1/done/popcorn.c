#include <stdio.h>

int main()
{
	int quant;
	float subprice, totprice;

	printf("How many boxes of popcorn would you like to buy?:");

	scanf("%d", &quant);

	if (quant < 10)
	{

		subprice = quant * 1.5;
	}
	else
	{

		subprice = quant * 1.30;
	}

	printf("Subtotal:  $%6.2f\n", subprice);

	totprice = subprice + 5;

	printf("Delivery:  $%6.2f\n", 5.00);

	printf("TotalCost: $%6.2f\n", totprice);

	return 0;
}
