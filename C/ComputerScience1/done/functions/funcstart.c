// Introduction to Functions
// 11/3/17

#include <stdio.h>
#include <string.h>

// say hi
void say_hi()
{
	printf("Hi");
}

// N dashes
void dashes( int N )
{
}

// sum 1 to N
//sumto


// roll a 6-sided dice
//roll


// get a random upper-case letter
//getUpper


// draw a box that is N x N @
//box
void box( int N )
{
	int r, c;
	for ( r = 0; r < N; r++ )
	{
		for (c = 0; c < N; c++ )
			printf("@");
		printf("\n");
	}
}

int isEven( int num )
{
	if ( num % 2 == 0 )
		return 1;
	else
		return 0;
}

int isLetter( char c )
{
	if ( c >= 'a' && c <= 'z' )
		return 1;
	else if ( c >= 'A' && c <= 'Z' )
		return 1;
	else
		return 0;
}

int getnumber1to25()
{
	int val;


	while ( !( val >= 1 && val <= 25 ) )
	{
		printf("Enter number 1-25: ");
		scanf("%d", &val);

	}

	return val;
}






int main()
{
	int res, i, d1;
	char let;

	d1 = getnumber1to25();



//	let = '.';
//	res = isLetter( let );
//	if ( res )
//		printf("%c is a letter\n", let);
//	else
//		printf("%c is not a letter\n", let);

//	scanf("%d", &d1);
//	res = isEven( d1 );

//	if ( res == 1 )
//		printf("Even");
//	else
//		printf("odd");

	//say_hi();
	//dashes(10);
	//res = sumto(6);
	//printf("Sum 1 to 6 is %d\n", res);
	//dashes(10);
	//for (i = 0; i < 5; ++i)
	//{
	//	let = getUpper();
	//	printf("%c ", let);
	//}
	//printf("\n");
	//dashes(10);
	//box(5);
	//dashes(10);
	//box(3);

	return 0;
}
