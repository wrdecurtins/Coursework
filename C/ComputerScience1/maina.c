
int main()
{
	struct boxtype *one, *two;
	int i, x;

	one = NULL; 
	two = NULL; 

	for ( i = 0; i < 7; ++i )
	{
		x = rand() % 80 + 1;
		one = insertFront( one, x );
		two = insertBack( two, x );
	}

	int tot = 99;

	while ( !isEmpty( two ) )
	{
		x = two->val;
		tot += x%29;
		two = removeFront( two );
	}

	while ( !isEmpty( one ) )
	{
		x = one->val;
		tot += x%29;
		one = removeBack( one );
	}
	printf("%d\n", tot);

	return 0;
}
