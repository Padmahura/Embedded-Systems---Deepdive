/********************************************************
A simple read write operation using pointers 
**********************************************************/

# include <stdio.h>

int main()

{

	char data = 0x45;
	char *address = &data;

	printf(" The address of data is %p \n",address);
	printf (" Read Data value is 0x%x \n",*address);   // Read operation

	char modified_data = 0x23;
	*address = modified_data;                         // Write operation
	printf (" Readback the modified data 0x%x \n",data);  // Reading the modified written data

	return 0;

}

