/**********************************************************************************
This is a basic program to print a character on UART terminal using NUCLEO-F401RE board
***********************************************************************************/
/////////////////////////////////// main.c ///////////////////////////////////////////
/********************* UART Transmit **********************************/

#include <stdint.h>
#include "main.h"

#define SYS_FREQ 16000000
#define APB1_CLK SYS_FREQ
#define UART_BAUDRATE 115200

RCC_AHB1ENR_t *AHB1ENR = ADDR_AHB1ENR;
RCC_APB1ENR_t *APB1ENR = ADDR_APB1ENR;
GPIOx_MODER_t *GPIOA_MODER = ADDR_GPIOA_MODER;
GPIOx_AFRL_t *GPIOA_AFRL = ADDR_GPIOA_AFRL;
USART_BRR_t *USART2_BRR = ADDR_USART2_BRR;
USART_CR1_t *USART2_CR1 = ADDR_USART2_CR1;
USART_SR_t *USART2_SR = ADDR_USART2_SR;
USART_DR_t *USART2_DR = ADDR_USART2_DR;

void uart2_tx_init(void);
static uint16_t compute_uart_bd(uint32_t periphclk,uint32_t baudrate);
void uart2_write(int ch);


int main(void)
{
	uart2_tx_init();
	while(1)
	{
		uart2_write('B');
	}
}

void uart2_tx_init(void){
	//Enable Clock access to GPIOA
	AHB1ENR->GPIOAEN=1;

	//Enable Clock Access to UART2
	APB1ENR->USART2EN=1;

	//Set PA2 and PA3 MODE to Alternate Function Mode
	GPIOA_MODER->MODER2=0x2;
	GPIOA_MODER->MODER3=0x2;

	//Set PA2 and PA3 Alternate Function Type to UART_TX(AF07)
	GPIOA_AFRL->AFRL2=0x7;
	GPIOA_AFRL->AFRL3=0x7;

	//Configure BaudRate
	USART2_BRR->DIV=compute_uart_bd(APB1_CLK,UART_BAUDRATE);

	//Configure Transfer Direction
	USART2_CR1->TE=1;
	USART2_CR1->UE=1;
}

static uint16_t compute_uart_bd(uint32_t periphclk,uint32_t baudrate)
{
	return ((periphclk+(baudrate/2U))/baudrate);
}

void uart2_write(int ch)
{
	// Check and confirm if Transmit Data register is empty
	while(!(USART2_SR->TXE & 0x1)){}
	// Write Transmit Data register
	USART2_DR->DATA = (ch & 0xFF);
}

///////////////////////////////////// main.h ////////////////////////////////////////////////
#ifndef MAIN_H_
#define MAIN_H_
#include <stdint.h>

#define ADDR_AHB1ENR ((RCC_AHB1ENR_t*)0x40023830)
#define ADDR_APB1ENR ((RCC_APB1ENR_t*)0x40023840)
#define ADDR_GPIOA_MODER ((GPIOx_MODER_t*)0x40020000)
#define ADDR_GPIOA_AFRL ((GPIOx_AFRL_t*)0x40020020)
#define ADDR_GPIOA_ODR ((GPIOx_ODR_t*)0x40020014)
#define ADDR_USART2_SR ((USART_SR_t*)0x40004400)
#define ADDR_USART2_DR ((USART_DR_t*)0x40004404)
#define ADDR_USART2_BRR ((USART_BRR_t*)0x40004408)
#define ADDR_USART2_CR1 ((USART_CR1_t*)0x4000440C)

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
	uint32_t TIM2EN :1;
	uint32_t TIM3EN :1;
	uint32_t TIM4EN :1;
	uint32_t TIM5EN :1;
	uint32_t RESERVED1 :7;
	uint32_t WWDGEN :1;
	uint32_t RESERVED2 :2;
	uint32_t SPI2EN :1;
	uint32_t SPI3EN :1;
	uint32_t RESERVED3 :1;
	uint32_t USART2EN :1;
	uint32_t RESERVED4 :3;
	uint32_t I2C1EN :1;
	uint32_t I2C2EN :1;
	uint32_t I2C3EN :1;
	uint32_t RESERVED5 :4;
	uint32_t PWREN :1;
	uint32_t RESERVED6 :3;
}RCC_APB1ENR_t;

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
	uint32_t AFRL0 :4;
	uint32_t AFRL1 :4;
	uint32_t AFRL2 :4;
	uint32_t AFRL3 :4;
	uint32_t AFRL4 :4;
	uint32_t AFRL5 :4;
	uint32_t AFRL6 :4;
	uint32_t AFRL7 :4;
}GPIOx_AFRL_t;

typedef struct {
	uint32_t AFRH8 :4;
	uint32_t AFRH9 :4;
	uint32_t AFRH10 :4;
	uint32_t AFRH11 :4;
	uint32_t AFRH12 :4;
	uint32_t AFRH13 :4;
	uint32_t AFRH14 :4;
	uint32_t AFRH15 :4;
}GPIOx_AFRH_t;

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

typedef struct {
	uint32_t PE :1;
	uint32_t FE :1;
	uint32_t NF :1;
	uint32_t ORE:1;
	uint32_t IDLE :1;
	uint32_t RXNE :1;
	uint32_t TC :1;
	uint32_t TXE :1;
	uint32_t LBD :1;
	uint32_t CTS :1;
	uint32_t RESERVED :20;
}USART_SR_t;

typedef struct {
	uint32_t DATA :9;
	uint32_t RESERVED :23;
}USART_DR_t;

typedef struct {
	uint32_t DIV :16;
	//uint32_t DIV :12;
	uint32_t RESERVED :16;
}USART_BRR_t;

typedef struct {
	uint32_t SBK :1;
	uint32_t RWU :1;
	uint32_t RE :1;
	uint32_t TE :1;
	uint32_t IDLEIE :1;
	uint32_t RXNEIE :1;
	uint32_t TCIE :1;
	uint32_t TXEIE :1;
	uint32_t PEIE :1;
	uint32_t PS :1;
	uint32_t PCE :1;
	uint32_t WAKE :1;
	uint32_t M :1;
	uint32_t UE :1;
	uint32_t RESERVED1 :1;
	uint32_t OVER8 :1;
	uint32_t RESERVED2 :16;
}USART_CR1_t;

#endif /* MAIN_H_ */

