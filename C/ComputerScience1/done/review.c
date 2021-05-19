#include <stdio.h>

int main()
{
	float Cost, Discount = 0, SubTotal, Tax, Total, TotalCost;
	int NumTypes, Quant, TotalQuant = 0, n;

	printf("\nHow many types?: ");
	scanf("%d", &NumTypes);

	if ( NumTypes > 4 )
	{	printf("Erroneous Input: You've been denied service\n");
		return 0;
	}

	for ( n = 1; n <= NumTypes; n++ )
	{
		printf("Item %d:\n", n);
		printf(" How many: ");
		scanf("%d", &Quant);

		if ( Quant > 24 )
			{
				printf("Erroneous Input: You've been denied service\n");
				return 0;
			}

		printf(" Item price: ");
		scanf("%f", &Cost);

		printf("\n--------------------\n\n");

		Cost = Cost * Quant;

		if ( Quant >= 10 )
		{
			printf("      Cost: %7.2f\n", Cost);

			Discount = Cost - ( .9 * Cost );
			printf("  Discount: %7.2f\n", Discount);
		}

		SubTotal = Cost - Discount;
		printf("  Subtotal: %7.2f\n", SubTotal);

		Tax = (SubTotal/100)*6;
		printf("       Tax: %7.2f\n", Tax);

		Total = SubTotal - Discount + Tax;
		printf("     Total: %7.2f\n", Total);

		TotalQuant += Quant;
		TotalCost += Total;
		printf("\n--------------------\n\n");
	}

	printf("Total Items:     %d\n", TotalQuant);
	printf(" Total Cost:%7.2f\n", TotalCost);

	return 0;
}
