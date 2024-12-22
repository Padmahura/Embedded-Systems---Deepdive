/********************************************************
This code is an example to demonstrate the call by value function using structure variable
*********************************************************/
# include <stdio.h>
struct data
{
	char Data1;
	int Data2;
	char Data3;
	short Data4;
}varData;

void displayElements (struct data varData)
{
		//Write Data
		varData.Data1 = 0x22;

		//Read Data
		char Data5 = varData.Data1;

		printf("Stored value in Data1 \n");
		printf("%x \n",varData.Data1);
		printf("%x \n",Data5);
}
int main()
{
	varData.Data1 = 0x11;
	varData.Data2 = 0xAAAABBBB;
	varData.Data3 = 0xFF;
	varData.Data4 = 0xA5A5;
	printf("Stored value in Data1 \n");
	printf("%x \n",varData.Data1);

	displayElements (varData);   // Call by value function
	return 0;
}
