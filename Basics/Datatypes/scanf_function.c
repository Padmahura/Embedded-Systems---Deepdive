/**************************************************
  This program is to understand the scanf functions 
***************************************************/


# include <stdio.h>

int main()
{
	int a,b,c;
	printf("enter the value of a: ");
	fflush(stdout);     
	scanf("%d",&a);


	printf("enter the value of b: ");
	fflush(stdout);
	scanf("%d",&b);


	printf("enter the value of c: ");
	fflush(stdout);
	scanf("%d",&c);
	int d = (a+b+c)/3;

	printf("The average value is: %d",d);
	getchar();
	getchar();

	return 0;

}
