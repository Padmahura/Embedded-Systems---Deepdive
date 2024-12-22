/**************************************
An example of how array works 
***************************************/


# include <stdio.h>
# include "stdint.h"

int main () {
	uint8_t a[10] = {25,50,75,100};
	int len = 5;
	uint8_t b[len];

	// Printing the contents of array
	for (int i=0;i<10;i++)	{
		printf("%d \n",a[i]);
	}

	// To calculate the length of array
	uint32_t length_of_array = sizeof(a)/sizeof(uint8_t);
	printf("Length of Array: %d \n",length_of_array);

	// Store values in array
		for (int i=0;i<len;i++)	{
			b[i] = i*5;
			printf("%d \n",b[i]);
		}
	return 0;
}
