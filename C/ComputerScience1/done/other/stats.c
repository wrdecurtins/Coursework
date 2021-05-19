#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
	int playerstats[6] = {0}, con = 0, str = 1, dex = 2, intl = 3, wis = 4, cha = 5;
	//declares player stats array and sets a value for each placeholder
	int clas, hascores, dierolls[4] = {0}, finalrolls[6] = {0}, k, r;
	//declares class variable and array made to store die roll values

	srand( time( NULL ) );

	char name[20];
	printf("What is your name?: ");
	scanf("%s", name);
	//asks for name of character and stores it

	printf("\n 1: Barbarian\n");
	printf(" 2: Bard\n");
	printf(" 3: Druid\n");
	printf(" 4: Cleric\n");
	printf(" 5: Fighter\n");
	printf(" 6: Wizard\n");
	printf(" 7: Monk\n");
	printf(" 8: Paladin\n");
	printf(" 9: Ranger\n");
	printf("10: Sorcerer\n");
	printf("11: Rogue\n");
	printf("12: Warlock\n\n");
	printf("Which class would you like to play as?:");
	scanf("%d", &clas);
	//asks the player which class they would like to play as

	printf("\n\n1: Roll\n");
	printf("2: Standard\n");
	printf("3: Manually\n");
	printf("How will you decide ability scores?: ");
	scanf("%d", &hascores);
	//asks the player how they want to decide their ability scores

	if ( hascores == 2 )
	{
		finalrolls[0] = 15;
		finalrolls[1] = 14;
		finalrolls[2] = 13;
		finalrolls[3] = 12;
		finalrolls[4] = 10;
		finalrolls[5] = 8;
	}
	//sets all ability scores to default values

	else if ( hascores == 1 )
	{
		for ( k = 0; k < 6; k++ )
		{
			for ( r = 0; r < 4; r++ )
				dierolls[r] = rand() % 6 + 1;
			//this for statement rolls four d6's to determine an ability score

			if ( dierolls[0] <= dierolls[1] && dierolls[0] <= dierolls[2] && dierolls[0] <= dierolls[3] )
				dierolls[0] = 0;
			else if ( dierolls[1] <= dierolls[0] && dierolls[1] <= dierolls[2] && dierolls[1] <= dierolls[3] )
				dierolls[1] = 0;
			else if ( dierolls[2] <= dierolls[0] && dierolls[2] <= dierolls[1] && dierolls[2] <= dierolls[3] )
				dierolls[2] = 0;
			else if ( dierolls[3] <= dierolls[1] && dierolls[3] <= dierolls[2] && dierolls[3] <= dierolls[0] )
				dierolls[3] = 0;
			//if statements check for the lowest roll and replace it with a zero effectively removing it

			for ( r = 0; r < 4; r++ )
				finalrolls[k] += dierolls[r];
			//adds the highest three dice to make an ability score and stores it
		}
	}

	else if ( hascores == 3 )
	{
		printf("\nEnter your ability scores:\n");

		for ( k = 0; k < 6; k++ )
		{
			printf("%d: ", k + 1);
			scanf("%d", &finalrolls[k]);
		}
	}
	//allows user to manually enter ability scores
	if ( hascores != 3 )
	{
		for ( k = 0; k < 6; k++ )
			printf("\n%d: %d", k + 1, finalrolls[k]);
	}

	printf("\nChoose how to allocate your rolls:\n\n");

	printf("Strength : ");
	scanf("%d", playerstats[str]);
	printf("Dexterity: ");


	return 0;
}
