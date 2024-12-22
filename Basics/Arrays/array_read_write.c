/**************************************
REad and Write in an array
***************************************/

#include <stdio.h>
#include <stdint.h>

int main() {

	uint8_t a[] = {0xF1,0xF2,0xF3,0xF4,0xF5,0xF6,0xF7,0xF8,0xF9,0xFA};

	//Write a Data
	*(a+1) = 0xFF;
	//a[1] = 0xFF;
	//printf("%x \n",*(a+1));

	// Read a data
	for(int i=0;i<10;i++){
		printf("%x \n",*(a+i));
	}


	return 0;
}
