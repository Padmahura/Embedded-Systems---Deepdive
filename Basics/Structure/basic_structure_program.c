/********************************************************************
This example program is to demonstrate how to use structure in a C program 
**********************************************************************/

#include <stdio.h>
#include <stdint.h>

struct carModel
{
	uint32_t carNumber ;   // Member elements - Does not require memory to create a structure ;
	uint32_t carPrice;
	uint32_t carMaxspeed;
	float carWeight;
};

int main()
{
	struct carModel carBMW={5677,20000,220,200}; // Method1 C89 standard
	struct carModel carFord={.carWeight=1000,.carPrice=14000,.carNumber=1234,.carMaxspeed=100};  // Method2 C99 standard using designated initializers

	printf("Details of the BMW \n");
	printf("Car Number %u \n",carBMW.carNumber);
	printf("Car Price %u \n",carBMW.carPrice);
	printf("Car Speed %u \n",carBMW.carMaxspeed);
	printf("Car Weight %f \n",carBMW.carWeight);

	printf("Details of the Ford \n");
	printf("Car Number %u \n",carFord.carNumber);
	printf("Car Price %u \n",carFord.carPrice);
	printf("Car Speed %u \n",carFord.carMaxspeed);
	printf("Car Weight %f \n",carFord.carWeight);

	//Read the structure variables
	uint32_t testnumber;
	testnumber = carFord.carNumber;
	printf(" Read the Car Ford Number %u \n",testnumber);

	//Write values to the structure variables
	carFord.carNumber = 3456;
	printf(" Modified Car Ford Number is %u \n",carFord.carNumber);
	
  // To know the size of the structure variable
	printf("Size of the carBMW struct variable %llu \n",sizeof(carBMW));

	return 0;
}


/*******************************************************************
*****************Console Output*************************************
  Details of the BMW 
Car Number 5677 
Car Price 20000 
Car Speed 220 
Car Weight 200.000000 
Details of the Ford 
Car Number 1234 
Car Price 14000 
Car Speed 100 
Car Weight 1000.000000 
 Read the Car Ford Number 1234 
 Modified Car Ford Number is 3456 
Size of the carBMW struct variable 16 
*****************************************************************/
