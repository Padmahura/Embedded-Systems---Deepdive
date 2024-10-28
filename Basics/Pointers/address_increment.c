/***************************************
  Basic code to increment the address and print the value at each address
*****************************************/


# include <stdio.h>

long long int data = 0xfffeabcd11112345;

int main()
{
	int *address;
	address = (int*) &data;
	printf("Data stored in address %p is %x \n",address,*address);
	address += 1;
	printf("Data stored in address %p is %x \n",address,*address);
	address += 1;
	printf("Data stored in address %p is %x \n",address,*address);
	return 0;
}
