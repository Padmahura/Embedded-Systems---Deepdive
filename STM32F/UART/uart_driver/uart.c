#include <stdint.h>
#include "uart.h"

RCC_AHB1ENR_t *AHB1ENR = ADDR_AHB1ENR;
RCC_APB1ENR_t *APB1ENR = ADDR_APB1ENR;
GPIOx_MODER_t *GPIOA_MODER = ADDR_GPIOA_MODER;
GPIOx_AFRL_t *GPIOA_AFRL = ADDR_GPIOA_AFRL;
USART_BRR_t *USART2_BRR = ADDR_USART2_BRR;
USART_CR1_t *USART2_CR1 = ADDR_USART2_CR1;
USART_SR_t *USART2_SR = ADDR_USART2_SR;
USART_DR_t *USART2_DR = ADDR_USART2_DR;


int __io_putchar(int ch)
{
	uart2_write(ch);
	return ch;
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
