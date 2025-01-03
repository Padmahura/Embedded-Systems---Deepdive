/********************************************************************
This example program is to demonstrate how to use volatile type qualifier in Embedded c 
**********************************************************************/

#include <stdint.h>
#include <stdio.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{

	uint8_t volatile data1;
	uint8_t volatile data2;

	data1 = 50;
	data2 = data1;
	data2 = data1;
	//printf("%d \n", data2);



	/* Loop forever */
	for(;;);
}
