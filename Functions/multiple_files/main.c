# include <stdio.h>
# include "math.h"


int main()
{
	//int a = 50 , b = 20;
	int a = 0x0FFF1111 , b = 0x00FF1111;
	printf("The sum is %d \n", math_add(a,b));
	printf("The product is %llx \n", math_mult(a,b));
	printf("The difference is %d \n", math_sub(a,b));
	printf("The divided value is %f \n", math_div(a,b));
	return 0;
}
