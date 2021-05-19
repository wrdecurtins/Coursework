#include <stdio.h>

int main()
{
    int input = 1, Total = 0, Minor = 0, Retire = 0;

    while ( input > 0 )
    {
        printf("Enter an age: ");
        scanf("%d", &input);

		if ( input > 0 )
		{
			Total += 1;
        	if ( input < 18 )
            	Minor += 1;
        	if ( input >= 65 )
            	Retire += 1;
		}
    }

    printf("Total :%2d\n", Total);
	printf("Minors:%2d\n", Minor);
	printf("Retire:%2d\n", Retire);

    return 0;
}



