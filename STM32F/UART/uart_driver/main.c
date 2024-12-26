/**********************************************************************************
This is an example code to use the UART(USART2 of STM32F401RE) drivers
***********************************************************************************/
#include <stdint.h>
#include "uart.h"
#include <stdio.h>

int main(void)
{
	uart2_tx_init();
	while(1)
	{
		//uart2_write('B');
		printf("Hello World - Debug \n\r");
	}
}
