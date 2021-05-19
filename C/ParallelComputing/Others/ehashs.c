#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHAR 4
//#define MAXCHAR 5

#define ALPHABET 26
char possible[] = "abcdefghijklmnopqrstuvwxyz";

unsigned long hash(char *str);

int main( int argc, char *argv[] )
{
	unsigned long ans;
	unsigned long test;

	if ( argc != 2 )
	{
		printf("Invalid number of arguments\n");
		return 0;
	}

	sscanf(argv[1], "%llu", &test);

//	printf("Testing... %lu\n", (unsigned long) argv[1]);
	printf("Testing... %lu\n", test);

	char temp[MAXCHAR+1] = "bean\0";

//	printf("%lu\n", hash("bean"));
//	printf("%s, %lu\n", temp, hash(temp));

	for ( int i = 0; i < MAXCHAR; i++ )
	{
		temp[i] = possible[0];
	}

	char end[MAXCHAR];

	for ( int i = 0; i < MAXCHAR; i++ )
	{
		end[i] = possible[ALPHABET-1];
	}


	for ( int i = 0; i < ALPHABET; i++ )
	{
		temp[0] = possible[i];
		for ( int k = 0; k < ALPHABET; k++ )
		{
			temp[1] = possible[k];
			for ( int h = 0; h < ALPHABET; h++ )
			{
				temp[2] = possible[h];
				for ( int m = 0; m < ALPHABET; m++ )
				{
					temp[3] = possible[m];
//					printf("%s\n", temp);

/*				for ( int x = 0; x < ALPHABET; x++ )
				{
					temp[4] = possible[x];*/
					ans = hash(temp);
					if (ans == test)
					{
						printf("%s \n", temp);
						return 0;
					}

			//	}

				}
			}
		}
	}





	printf("%s \n", temp);


	return 0;
}
