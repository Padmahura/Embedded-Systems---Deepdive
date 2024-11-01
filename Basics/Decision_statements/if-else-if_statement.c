/***********************************************************
This is an example code for usage of if-else-if statement in C
************************************************************/
# include <stdio.h>

int main ()
{
	int age;
	printf("Enter the age: ");
	fflush(stdout);
	scanf("%d",&age);

  if (age >= 60)
	{
		printf("Senior Citizen category");
	}
	else if (age < 25)
		{
			printf(" Youngsters category ");
		}
	else if ((age >=25) && (age < 60))
	{
		printf ("Middle aged category");
	}

	return 0;
}
