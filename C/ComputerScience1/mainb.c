
int main()
{
	struct boxtype *two;
	int i, x;

	two = NULL; 

	for ( i = 0; i < 20; ++i )
	{
		x = rand() % 200 + 1;
		two = insertBack( two, x );
	}

	int tot = 99;
	int n = 11;

	int mv;
	struct boxtype *ml;
	while ( !isEmpty( two ) )
	{
		mv = maxVal( two );
		ml = maxLoc( two );
		if ( mv % 2 )
			tot = tot + mv + n;
		else
			tot = tot - mv + n;
		n++;
		two = removeThisOne( two, ml );
	}
	printf("%d\n", tot);
	return 0;
}
