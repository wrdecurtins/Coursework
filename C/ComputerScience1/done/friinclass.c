#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int EvenOdd( int a[] ), k, h, whichCase;
void ReverseString( char a[] );

int main()
{
	int nums[100] = {1, 2 ,3 , 4, 6, 0};
	char sting[] = "Good morning and welcome to class";


	whichCase = EvenOdd(nums);

	if ( whichCase == 'e' )
		printf("Even\n");
	else if ( whichCase == 'o' )
		printf("Odd\n");
	else if ( whichCase == 'z' )
		printf("Neither\n");


	ReverseString(sting);

	return 0;

}

void ReverseString( char a[] )
{
	int k, h = 0;
	char b[strlen(a)];

	for( k = (strlen(a) - 1); k >= 0; k-- )
	{
		b[h] = a[k];
		h++;
	}

	printf("1: %s\n", a);
	printf("2: %s\n", b);
}

int EvenOdd( int a[] )
{
	int k = 0, even = 0, odd = 0, num;

	while ( a[k] != 0 )
	{
		if ( a[k] < 0 )
			a[k] *= -1;

		num = a[k] % 2;

		if( num == 0 )
			even++;
		else
			odd++;

		k++;
	}

	if ( even > odd )
		return 'e';
	else if ( odd > even )
		return 'o';
	else
		return 'z';
}
