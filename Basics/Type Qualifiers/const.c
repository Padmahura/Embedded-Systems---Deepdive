/********************************************************************
This example program is to demonstrate how to use const type qualifier in c 
**********************************************************************/

#include <stdio.h>
#include <stdint.h>

int main () {

	uint8_t const data = 10;
	printf("%d \n",data);

	//data=50;
	uint8_t *address = &data;
	*address = 50;

	printf("%d \n",data);


	return 0;
}
