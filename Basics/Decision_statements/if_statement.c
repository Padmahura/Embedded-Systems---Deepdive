/**************************************************
Single liner if statment usage without curly braces
***************************************************/
# include <stdio.h>

int main ()
{
	int age;
	printf("Enter the age: ");
	fflush(stdout);
	scanf("%d",&age);

	if (age<60)
		printf("Not qualified for Senior Citizen\n");
	if (age>=60)
		printf("Qualified for Senior Citizen \n");

	return 0;
}
