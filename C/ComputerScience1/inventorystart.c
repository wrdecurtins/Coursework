#include <stdio.h>
#include <string.h>

struct product
{
	char productName[25];
	int quantity;
	float price;
};


// read all products from file into items array
// return number of items
int getInventory( struct product items[] )
{
	FILE *stuff;
	int n = 0;

	stuff = fopen( "products", "r");

	fscanf( stuff, "%s %d %f", items[n].productName, &items[n].quantity, &items[n].price );
	while ( !feof( stuff ) )
	{
		n++;
		fscanf( stuff, "%s %d %f", items[n].productName, &items[n].quantity, &items[n].price );
	}
	return n;
}



// print out the inventory, there are N items
// print a number in front of each line
void showInventory( struct product items[], int N  )
{
	int i;
    for (i = 0; i < N; ++i)
	{
		printf("%d: %15s %2d %5.2f\n", i+1, items[i].productName, items[i].quantity, items[i].price);
	}
}


// interactive; ask user what product
//  decrease inventory quantity by 1
// for best results, make sure item # is in range
void buySomething(  struct product items[], int N  )
{
	int pick;

	printf("\n\n");
	// print the list to show choices
    showInventory( items, N );

	// ask which item
	scanf("%d", &pick);

	// decrease quantity
	pick--;

	if ( items[pick].quantity == 0 )
	{
		printf("Sorry, sold out\n"
	}
	else
	{
		items[pick].quantity--;

		// print new quantity
		printf("Update: %s now %d\n", items[pick].productName, items[pick].quantity);
	}
}



int main()
{
	int N;

	struct product mylist[10];
// call the functions to show they work

	N = getInventory( mylist );
	buySomething( mylist, N );
	showInventory( mylist, N );

	return 0;
}

