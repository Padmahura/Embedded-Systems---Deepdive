/********************************************************************
This example program is to demonstrate the difference in memory allocation between structure and Union 
**********************************************************************/

//////////////////////////////////////// Structure //////////////////////////////////////////////
#include<stdio.h>
#include<stdint.h>
struct Address {
	uint16_t shortaddr;
	uint32_t longaddr;
};
int main() {
	struct Address addr;
	addr.shortaddr=0xABCD;
	addr.longaddr=0xFFFFAAAA;
	printf("Short Address : %x \n",addr.shortaddr);
	fflush(stdout);
	printf("Long Address : %x \n",addr.longaddr);
	fflush(stdout);
	printf("Size of Address is : %lld \n",sizeof(addr));
	return 0;
}
/*******************************************************************
*****************Console Output*************************************
Short Address : abcd 
Long Address : ffffaaaa 
Size of Address is : 8
*****************************************************************/

///////////////////////////////////////// Union ////////////////////////////////////////////////////
#include<stdio.h>
#include<stdint.h>
union Address {
	uint16_t shortaddr;
	uint32_t longaddr;
};
int main() {
	union Address addr;
	addr.shortaddr=0xABCD;
	addr.longaddr=0xFFFFAAAA;
	printf("Short Address : %x \n",addr.shortaddr);
	fflush(stdout);
	printf("Long Address : %x \n",addr.longaddr);
	fflush(stdout);
	printf("Size of Address is : %lld \n",sizeof(addr));
	return 0;
}
/*******************************************************************
*****************Console Output*************************************
Short Address : aaaa 
Long Address : ffffaaaa 
Size of Address is : 4 
*****************************************************************/




