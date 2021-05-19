#include <stdio.h>

int main()
{
	int radius;
	float areaC, perimC, areaS, perimS;

	printf("What is the radius of the circle and the length of the square?:");
	scanf("%d", &radius);

	areaC = 3.14 * radius * radius;
	perimC = 3.14 * radius * 2;

	areaS = radius * radius;
	perimS = radius * 4;

	printf("The area of the Circle is %.2f and its perimeter is %.2f\n", areaC, perimC);
	printf("The area of the square is %.2f and its perimeter is %.2f\n", areaS, perimS);

	return 0;
}
