/**********************************************************************************
This is an example program to demonstrate UART TX and RX using NUCLEO-F401RE board and ST header files and macros
***********************************************************************************/
#include <stdint.h>
#include "stm32f4xx.h"
#include<stdio.h>

#define SYS_FREQ 16000000
#define APB1_CLK SYS_FREQ
#define UART_BAUDRATE 9600

void uart2_init(void);
static uint16_t compute_uart_bd(uint32_t periphclk,uint32_t baudrate);
void uart2_write(int ch);
char uart2_read(void);

int main(void)
{
	uart2_init();
	char key;
	while(1)
	{
		key = uart2_read();
		if (key=='1')
		{
			printf("1 is pressed \n \r");
		}
		else
		{
			printf("2 is pressed \n \r");
		}
		//uart2_write('A');
		//printf("Hello \n\r");
	}
}

int __io_putchar(int ch)
{
	uart2_write(ch);
	return ch;
}
void uart2_init(void){
	//Enable Clock access to GPIOA
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

	//Enable Clock Access to UART2
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;

	//Set PA2 and PA3 MODE to Alternate Function Mode
	GPIOA->MODER &= ~GPIO_MODER_MODER2_0;
	GPIOA->MODER |= GPIO_MODER_MODER2_1;
	GPIOA->MODER &= ~GPIO_MODER_MODER3_0;
	GPIOA->MODER |= GPIO_MODER_MODER3_1;

	//Set PA2 and PA3 Alternate Function Type to UART_TX/RX(AF07)
	GPIOA->AFR[0] |= GPIO_AFRL_AFSEL2_0;
	GPIOA->AFR[0] |= GPIO_AFRL_AFSEL2_1;
	GPIOA->AFR[0] |= GPIO_AFRL_AFSEL2_2;
	GPIOA->AFR[0] &= ~GPIO_AFRL_AFSEL2_3;
	GPIOA->AFR[0] |= GPIO_AFRL_AFSEL3_0;
	GPIOA->AFR[0] |= GPIO_AFRL_AFSEL3_1;
	GPIOA->AFR[0] |= GPIO_AFRL_AFSEL3_2;
	GPIOA->AFR[0] &= ~GPIO_AFRL_AFSEL3_3;

	//Configure BaudRate
	USART2->BRR = compute_uart_bd(APB1_CLK,UART_BAUDRATE);

	//Configure Transfer Direction
	USART2->CR1 |= USART_CR1_TE;
	USART2->CR1 |= USART_CR1_RE;
	USART2->CR1 |= USART_CR1_UE;
}

static uint16_t compute_uart_bd(uint32_t periphclk,uint32_t baudrate)
{
	return ((periphclk+(baudrate/2U))/baudrate);
}

void uart2_write(int ch)
{
	// Check and confirm if Transmit Data register is empty
	while(!(USART2->SR & USART_SR_TXE)){}
	// Write Transmit Data register
	USART2->DR = (ch & 0xFF);
}

char uart2_read(void)
{
	// Check and confirm if Receive Data register is not empty
	while(!(USART2->SR & USART_SR_RXNE)){}
	// Read Receive Data register
	return USART2->DR;
}
