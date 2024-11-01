/**************************************
Initialize an array and perform a mathematical operation on all the array elements
***************************************/

# include <stdio.h>

int main ()
{
  int a[10] = {0,1,2,3,4};
	int i = 0;

	// Convert all array elements to multiples of 5
  printf("Modified array values are : \n");
  while (i <5) {
		a[i] *= 5 ;
		printf(" %d \n", a[i]);
		i++;
	}
  
return 0;
}
