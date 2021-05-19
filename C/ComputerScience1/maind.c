
int main()
{
	struct boxtype *two;
	int i, x;

	two = NULL; 

	srand(331);
	for ( i = 0; i < 9; ++i )
	{
		x = rand() % 200 + 1;
		printf("%d ", x);
		two = insertBack( two, x );
	}
	printf("\n");


	int mv;
	struct boxtype *ml;
	for ( i = 0; i < 2; ++i )
	{
		mv = maxVal( two );
		ml = maxLoc( two );
		printf("%d ", mv);
		two = removeThisOne( two, ml );
	}
	printf("\n");
	return 0;
}
