#include <stdio.h>

int main()
{
	int quant;
	float price, subtotal, discount, handling, total;

	printf("What is the price of the item?:");
	scanf("%f", &price);

	printf("How many items are you buying?:");
	scanf("%d", &quant);

	subtotal = price * quant;
	handling = 1.59 * quant;

	if (subtotal > 100)
		discount = subtotal * .2;
	else
		discount = 0;

	total = subtotal + handling - discount;

	printf("Subtotal: $%6.2f\n", subtotal);
	printf("Discount: $%6.2f\n", discount);
	printf("Handling: $%6.2f\n", handling);
	printf("Total:    $%6.2f\n", total);

	return 0;
}
