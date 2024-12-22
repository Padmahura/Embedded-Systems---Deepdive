/**************************************
Initialize an array and perform a mathematical operation on all the array elements
***************************************/

#include <stdio.h>
#include <stdint.h>

void displayarray(uint8_t *pointerArray, uint32_t len);

int main() {

	uint8_t a[] = {0xF1,0xF2,0xF3,0xF4,0xF5,0xF6,0xF7,0xF8,0xF9,0xFA};

	// To calculate the length of array
	uint32_t length_of_array = sizeof(a)/sizeof(uint8_t);

	displayarray(a,length_of_array);
	displayarray(&a[0],length_of_array);   // Same as above statement

	displayarray(a+5,length_of_array-5);   // To display last 5 elements in the array
	displayarray(&a[5],length_of_array-5);   // To display last 5 elements in the array

	return 0;

}

void displayarray(uint8_t *pointerArray, uint32_t len) {

	for (int i=0;i<len;i++)	{
			//printf("%x \n",pointerArray[i]);
			printf("%x \n",*(pointerArray+i));
		}

}
