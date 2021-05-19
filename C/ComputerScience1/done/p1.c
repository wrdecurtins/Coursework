#include <stdio.h>
#include <string.h>

int main()
{
	char s1[10];
	char s2[10] = {'h','i'};
	char s3[10] = "hi";
	char s4[]   = "hi";

	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);
	printf("s3: %s\n", s3);
	printf("s4: %s\n", s4);
	return 0;
}
