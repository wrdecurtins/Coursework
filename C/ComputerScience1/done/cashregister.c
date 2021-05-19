#include <stdio.h>

int main()
{
	int packs;
	float tax, subtotal, total;

	printf("How many packs of gum would you like to buy?:");

	scanf("%d", &packs);

	subtotal = packs * 1.75;
	tax = subtotal * 0.06;
	total = subtotal + tax;

	printf("Subtotal: $%6.2f\n", subtotal);
	printf("Tax:      $%6.2f\n", tax);
	printf("Total:    $%6.2f\n", total);

	return 0;
}
