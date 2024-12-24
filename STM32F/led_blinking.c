/**********************************************************************************
This is a basic program to turn on an LED(LD2) on the target NUCLEO-F401RE board 
***********************************************************************************/

#include <stdint.h>

int main(void)
{
	uint32_t *AHB1ENR = (uint32_t*)0x40023830;  // base addresss = 0x40023800 + offset = 0x30
	uint32_t *MODER = (uint32_t*)0x40020000;   // base address = 0x40020000 + offset = 0x00
	uint32_t *ODR =(uint32_t*)0x40020014;   // base address = 0x40020000 + offset = 0x14

	*AHB1ENR |= 0x01;  // Enable the clock

	uint32_t bitpos = 10;
	*MODER &= ~(1 << (bitpos+1));
	*MODER |= (1 << bitpos);  // Enable GPIO mode

	*ODR |= (1 << 5);  // Enable GPIO output

	/* Loop forever */
	for(;;);
}
