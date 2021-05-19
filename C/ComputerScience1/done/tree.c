#include <stdio.h>

void tree( int treesize );

int main()
{
	int treesize;

	printf("How large is the tree?: ");
	scanf("%d", &treesize);

	if (( treesize < 4 ) && ( treesize > 40 ))
		printf("\nBad tree");
	else
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

		tree( treesize );
	}
	return 0;
}

void tree( int treesize )
{

}
