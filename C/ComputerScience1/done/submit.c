#!/bin/bash

URL=https://codegolf.hostbin.org/submit.php

if [ $# -ne 1 ]; then
	echo "Usage: $0 <file.c>"
	exit 0;
elif [ ! -f $1 ]; then
	echo "Cant read $1"
	exit 0;
fi

read -p "Username: " USER
read -s -p "Password: " PASS
echo ""

curl "$URL" --user "$USER:$PASS" --form "code=@$1"


#include <stdio.h>
#include <string.h>

int findvalue( int start, int end, char equation[] );

int main()
{
	int k, u;

	for ( k = 1; k <= 100; k++ )
	{
		char equation[50] = "";

		scanf("%[^\n]%*c", equation);

		for ( u = 0; u < 50; u++ )
		{
			if ( equation[u] == '+' )
				printf("%d\n", ( findvalue( 0, u-1, equation ) + findvalue( u+1, 50, equation )));
			else if ( equation[u] == '-' )
				printf("%d\n", ( findvalue( 0, u-1, equation ) - findvalue( u+1, 50, equation )));
			else if ( equation[u] == '*' )
				printf("%d\n", ( findvalue( 0, u-1, equation ) * findvalue( u+1, 50, equation )));
		}
	}

	return 0;
}

int findvalue( int start, int end, char equation[] )
{
	int k, value = 0, C = 0, L = 0, X = 0, V = 0, I = 0;
	//roman numeral values C = 100, L = 50, X = 10, V = 5, I = 1

	for ( k = start; k <= end; k++ )
	{
		if (( equation[k] == 'C' ) || ( equation[k] == 'c' ))
			C += 100;

		else if (( equation[k] == 'L' ) || ( equation[k] == 'l' ))
		{
			if (( equation[k + 1] == 'C' ) || ( equation[k + 1] == 'c' ))
			{
				L += 50;
				value -= L;
				L = 0;
			}

			else
				L += 50;
		}

		else if (( equation[k] == 'X' ) || ( equation[k] == 'x' ))
		{
			if (( equation[k + 1] == 'C' ) || ( equation[k + 1] == 'c' ) || ( equation[k + 1] == 'L' ) || ( equation[k + 1] == 'l' ))
			{
				X += 10;
				value -= X;
				X = 0;
			}

			else
				X += 10;
		}

		else if (( equation[k] == 'V' ) || ( equation[k] == 'v' ))
		{
			if (( equation[k + 1] == 'C' ) || ( equation[k + 1] == 'c' ) || ( equation[k + 1] == 'L' ) || ( equation[k + 1] == 'l' ) || ( equation[k + 1] == 'X' ) || ( equation[k + 1] == 'x' ))
			{
				V += 5;
				value -= V;
				V = 0;
			}

			else
				V += 5;
		}

		else if (( equation[k] == 'I' ) || ( equation[k] == 'i' ))
		{
			if (( equation[k + 1] == 'C' ) || ( equation[k + 1] == 'c' ) || ( equation[k + 1] == 'L' ) || ( equation[k + 1] == 'l' ) || ( equation[k + 1] == 'X' ) || ( equation[k + 1] == 'x' ) || ( equation[k + 1] == 'V') || ( equation[k + 1] == 'v'))
			{
				I += 1;
				value -= I;
				I = 0;
			}

			else
				I += 1;
		}

	}

	value += C + L + X + V + I;

	return value;
}
