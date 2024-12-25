/**********************************************************************************
This is a basic program to blink an LED(LD2) on the target NUCLEO-F401RE board using structure and bit-field and pre-processors for addressing
***********************************************************************************/
/////////////////////////////////// main.c ///////////////////////////////////////////
#include <stdint.h>
#include "main.h"
void delay(void){
	for(uint32_t i=0; i<300000;i++);
}
int main(void)
{
	RCC_AHB1ENR_t *AHB1ENR = AHB1ENR_addr;
	GPIOx_MODER_t *GPIOA_MODER = GPIOA_MODER_addr;
	GPIOx_ODR_t *GPIOA_ODR = GPIOA_ODR_addr;

	AHB1ENR->GPIOAEN=1;  // Enable clock for GPIOA
	GPIOA_MODER->MODER5=0x01;   // Configure GPIO mode 01
	while(1){
		GPIOA_ODR->ODR5=1;   // Enable output
		delay();
		GPIOA_ODR->ODR5=0;   // Disable output
		delay();
	}
}

///////////////////////////////////// main.h ////////////////////////////////////////////////
#ifndef MAIN_H_
#define MAIN_H_
#include <stdint.h>

#define AHB1ENR_addr ((RCC_AHB1ENR_t*)0x40023830)
#define GPIOA_MODER_addr ((GPIOx_MODER_t*)0x40020000)
#define GPIOA_ODR_addr ((GPIOx_ODR_t*)0x40020014)

typedef struct {
	uint32_t GPIOAEN :1;
	uint32_t GPIOBEN :1;
	uint32_t GPIOCEN :1;
	uint32_t GPIODEN :1;
	uint32_t GPIOEEN :1;
	uint32_t RESERVED1 :2;
	uint32_t GPIOHEN :1;
	uint32_t RESERVED2 :4;
	uint32_t CRCEN :1;
	uint32_t RESERVED3 :8;
	uint32_t DMA1EN :1;
	uint32_t DMA2EN :1;
	uint32_t RESERVED4 :9;
}RCC_AHB1ENR_t;

typedef struct {
	uint32_t MODER0 :2;
	uint32_t MODER1 :2;
	uint32_t MODER2 :2;
	uint32_t MODER3 :2;
	uint32_t MODER4 :2;
	uint32_t MODER5 :2;
	uint32_t MODER6 :2;
	uint32_t MODER7 :2;
	uint32_t MODER8 :2;
	uint32_t MODER9 :2;
	uint32_t MODER10 :2;
	uint32_t MODER11 :2;
	uint32_t MODER12 :2;
	uint32_t MODER13 :2;
	uint32_t MODER14 :2;
	uint32_t MODER15 :2;
}GPIOx_MODER_t;

typedef struct {
	uint32_t ODR0 :1;
	uint32_t ODR1 :1;
	uint32_t ODR2 :1;
	uint32_t ODR3 :1;
	uint32_t ODR4 :1;
	uint32_t ODR5 :1;
	uint32_t ODR6 :1;
	uint32_t ODR7 :1;
	uint32_t ODR8 :1;
	uint32_t ODR9 :1;
	uint32_t ODR10 :1;
	uint32_t ODR11 :1;
	uint32_t ODR12 :1;
	uint32_t ODR13 :1;
	uint32_t ODR14 :1;
	uint32_t ODR15 :1;
	uint32_t RESERVED :16;
}GPIOx_ODR_t;
#endif /* MAIN_H_ */

