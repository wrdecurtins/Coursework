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
        int a=1,b=0,c=-1;
        float f=3.14;

        niceline( 6, '#', '-' );
        niceline( 10, '>', '=' );
        printf("%d\n", Add(Add(5,8),Mult(2,8)));
        int nums[] = {7,5,3,2,4,6,8,10,12};
        int many = 9;
        printf("%d\n", Add(Min(nums,3),Max(nums,3)));
        char phrase[100];
        b = 0;
        for ( a = 55; a <= 125; ++a)
                phrase[b++] = a;
        phrase[b-50] = '\0';
        many = numVowels( phrase );
        printf("%d\n", numVowels( phrase ));
        box( 5, 4, '+', '|' );

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

