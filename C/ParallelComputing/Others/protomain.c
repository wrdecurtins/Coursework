#include <stdio.h>
#include <string.h>
#include <unistd.h>

unsigned long hash(char *str);


int main()
{
	unsigned long ans;
	unsigned long ans2;

//	ans = hash( "crab" );
	ans = hash( "1@&*" );
//	ans = hash( "a@&a" );
//	ans = hash( "aaaa" );
//	ans2 = hash( "b@aa" );
	ans2 = hash( "0a&*" );
	printf("%lu\n", ans);
	printf("%lu\n", ans2);


	return 0;
}
