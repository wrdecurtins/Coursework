
int main()
{
	struct boxtype *one, *two;
	struct boxtype *p, *q;
	int i, x=14;

	one = NULL; 
	two = NULL; 

	for ( i = 10; i <= 80; i+=10 )
	{
		one = insertFront( one, i );
		two = insertBack( two, i );
	}

	two = removeFront( two );
	two = removeBack( two );
	one = removeFront( one );
	one = removeBack( one );
	p = getLoc( one, 50 );
	q = getLoc( two, 50 );
	x += listLength( p );
	x += listLength( q );
	printf("%d\n", x);
	return 0;
}
