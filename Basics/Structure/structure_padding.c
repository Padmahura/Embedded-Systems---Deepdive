/********************************************************************
This example program is to demonstrate hosw the padding works in a structure 
**********************************************************************/

#include <stdio.h>
#include <stdint.h>

struct Dataset
{
	char data1;
	int data2;
	char data3;
	short data4;
};

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


/************************************************************
*********************Console Output**************************
The size of struct variable 12 
Memory address content 
000000e3fefffb44		11 
000000e3fefffb45		0 
000000e3fefffb46		0 
000000e3fefffb47		0 
000000e3fefffb48		ff 
000000e3fefffb49		ff 
000000e3fefffb4a		55 
000000e3fefffb4b		55 
000000e3fefffb4c		cc 
000000e3fefffb4d		0 
000000e3fefffb4e		cd 
000000e3fefffb4f		ab 
**************************************************************/
