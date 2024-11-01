/**************************************************
An example to use conditional operator instead of if else statement 
***************************************************/
# include <stdio.h>

int main ()
{
	int age;
	printf("Enter the age: ");
	fflush(stdout);
	scanf("%d",&age);

  (age<60)	?	printf("Not qualified for Senior Citizen\n") : printf("Qualified for Senior Citizen \n");   // If age < 60 ; prints first statement , else prints second statement 

	return 0;
}
