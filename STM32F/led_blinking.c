/**********************************************************************************
This is a basic program to blink an LED(LD2) on the target NUCLEO-F401RE board 
***********************************************************************************/

#include <stdint.h>

void delay(void){
	for(uint32_t i=0; i<300000;i++);
}

int main(void)
{
	uint32_t *AHB1ENR = (uint32_t*)0x40023830;
	uint32_t *MODER = (uint32_t*)0x40020000;
	uint32_t *ODR =(uint32_t*)0x40020014;

	*AHB1ENR |= 0x01;  // Enable the clock

	uint32_t bitpos = 10;
	*MODER &= ~(1 << (bitpos+1));
	*MODER |= (1 << bitpos);  // Enable GPIO mode

	/* Loop forever */
	for(;;){
		*ODR |= (1 << 5);  // Enable GPIO output
		delay();
		*ODR &= (~(1 << 5));  // Enable GPIO output
		delay();

	}
}
