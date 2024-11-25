/********************************************************
This code is an example to demonstrate unaligned storage of Structure (No padding)
*********************************************************/

#include <stdio.h>
#include <stdint.h>

struct Dataset
{
	char data1;
	int data2;
	char data3;
	short data4;
}__attribute__((packed));

int main () {
	struct Dataset data;
	data.data1=0x11;
	data.data2=0x5555ffff;
	data.data3=0xCC;
	data.data4=0xABCD;
	printf("The size of struct variable %llu \n", sizeof(data));

	uint8_t *ptr;
	ptr = (uint8_t*)&data;
	uint32_t sizeofdata = sizeof(data);

	printf("Memory address content \n");
	for (uint32_t i = 0 ; i < sizeofdata ; i++)
	{
		printf("%p		%x \n",ptr,*ptr);
		ptr++;
	}
	return 0;
}


/*******************************************************************
*****************Console Output*************************************
  The size of struct variable 8 
Memory address content 
00000026287ff878		11 
00000026287ff879		ff 
00000026287ff87a		ff 
00000026287ff87b		55 
00000026287ff87c		55 
00000026287ff87d		cc 
00000026287ff87e		cd 
00000026287ff87f		ab 
  ******************************************************************/
