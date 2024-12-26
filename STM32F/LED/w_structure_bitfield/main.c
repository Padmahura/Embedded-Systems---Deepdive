/**********************************************************************************
This is a basic program to blink an LED(LD2) on the target NUCLEO-F401RE board using structure and bit-field
***********************************************************************************/
#include <stdint.h>
#include "main.h"
void delay(void){
	for(uint32_t i=0; i<300000;i++);
}
int main(void)
{
	RCC_AHB1ENR_t *AHB1ENR = (RCC_AHB1ENR_t*)0x40023830;
	GPIOx_MODER_t *GPIOA_MODER = (GPIOx_MODER_t*)0x40020000;
	GPIOx_ODR_t *GPIOA_ODR = (GPIOx_ODR_t*)0x40020014;

	AHB1ENR->GPIOAEN=1;  // Enable clock for GPIOA
	GPIOA_MODER->MODER5=0x01;   // Configure GPIO mode 01
	while(1){
		GPIOA_ODR->ODR5=1;   // Enable output
		delay();
		GPIOA_ODR->ODR5=0;   // Disable output
		delay();
	}
}
