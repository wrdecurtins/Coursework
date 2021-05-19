#include <stdio.h>

int main()
{
	char products[25][20];
	float prices[25];
	int p;

	for ( p = 0; p < 3; ++p )
	{
		printf("Product name: ");
		scanf("%s", products[p]);
		printf("Product price: ");
		scanf("%f", &prices[p]);

	}

	printf("Show items:\n");
	for (p = 0; p < 3; ++p )
		printf("%s %.2f\n", products[p], prices[p]);

	return 0;
}
