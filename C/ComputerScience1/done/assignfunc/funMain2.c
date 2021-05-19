#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//first set of funtions take two parameters
int Add( int num1, int num2 );
int Mult( int num1, int num2 );
int IAvg( int num1, int num2 );
float FAvg( float num1, float num2 );
int Big( int num1, int num2 );
int Small( int num1, int num2 );

//second set of functions take two parameters 1 array and$
int Max( int aray[], int size );
int Min( int aray[], int size );
int Sum( int aray[], int size );

//third set of functions isVowel and numVowels
int isVowel( char c );
int numVowels( char s[] );

//final set of functions
void niceline( int num, char a, char b );
void box( int row, int col, char a, char b );

int main()
{
        int a,b,c;
        float f;

        a = 5;
        b = 10;
        printf("Using values %d and %d\n", a, b);
        c = Add(a,b);
        printf("Add   %d\n", c );
        c = Mult(a,b);
        printf("Mult  %d\n", c );
        c = IAvg(a,b);
        printf("IAvg  %d\n", c );
        f = FAvg(a,b);
        printf("FAvg  %.2f\n", f );
        c = Big(a,b);
        printf("Big   %d\n", c );
        c = Small(a,b);
        printf("Small %d\n", c );

        int nums[12] = {22,43,35,8,43,17,54,41,29,48,36,19};
        int many = 12;

        for ( a = 0; a < many; ++a )
                printf("%2d ", nums[a]);
        printf("\n");

        printf("max: %2d\n", Max(nums,many));
        printf("min: %2d\n", Min(nums,many));
        printf("sum: %2d\n", Sum(nums,many));

        char phrase[] = "DSU ... in Madison SD since 1881";
        printf("String::  %s\n", phrase );
        many = numVowels( phrase );
        printf("There are %d vowels\n", many);

        niceline( 6, 'a', 'b' );
        niceline( 7, '2', '1' );
        box( 4, 5, '@', ' ' );
        box( 6, 3, ' ', '#' );

        return 0;
}

int Add( int num1, int num2 )
{
    return ( num1 + num2 );
}

int Mult( int num1, int num2 )
{
    return ( num1 * num2 );
}

int IAvg( int num1, int num2 )
{
    return ( (num1 + num2) / 2 );
}

float FAvg( float num1, float num2)
{
    return ( (num1 + num2) / 2.00 );
}

int Big( int num1, int num2 )
{
    if ( num1 >= num2 )
        return num1;
    else
        return num2;
}

int Small( int num1, int num2 )
{
    if ( num1 <= num2 )
        return num1;
    else
        return num2;
}

int Max( int aray[], int size )
{
    int k, max = -1;

    for ( k = 0; k < size; k++ )
        if ( aray[k] > max )
            max = aray[k];
    return max;
}

int Min( int aray[], int size )
{
    int k, min = 99;

    for ( k = 0; k < size; k++ )
        if ( aray[k] < min )
            min = aray[k];
    return min;
}

int Sum( int aray[], int size )
{
    int k, sum = 0;

    for ( k = 0; k < size; k++ )
        sum += aray[k];
    return sum;
}

int isVowel( char c )
{
    if ( c == 'a' || c == 'A' )
        return 1;
    else if ( c == 'e' || c == 'E' )
        return 1;
    else if ( c == 'i' || c == 'I' )
        return 1;
    else if ( c == 'o' || c == 'O' )
        return 1;
    else if ( c == 'u' || c == 'U' )
        return 1;
    else
        return 0;
}

int numVowels( char s[] )
{
    int k, num = 0;

    for ( k = 0; k < strlen(s); k++ )
        if( isVowel(s[k]) == 1 )
            num++;

    return num;
}

void niceline( int num, char a, char b )
{
    int k;

    for ( k = 1; k <= num; k++ )
        if ( k == 1 )
            printf("%c", a);
        else if ( k == num )
            printf("%c\n", a);
        else
            printf("%c", b);
}

void box( int row, int col, char a, char b )
{
    int k;

    for ( k = 1; k <= row; k++ )
    {
        if ( k == 1 || k == row )
            niceline( col, a, a );
        else
            niceline( col, a, b );
    }
}

