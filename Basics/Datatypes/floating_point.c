/*******************************************
This program is to understand the floating point usage in C
********************************************/

# include <stdio.h>

int main()
{
	double number = 45.123567456 ;          // double is used for handling 9 digit precision size 
	printf("The number is %0.9lf \n", number);      // 0.9 is 9 digit precision ; lf is format specifier for double 
	printf("The number is %0.9e \n", number);

	return 0;

}
