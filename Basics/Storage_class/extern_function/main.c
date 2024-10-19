#include<stdio.h>


void file_myfunc();
void change_system_clock(int sys_clk);

int main(void)
{
	printf("Hello World\n");
	change_system_clock(3);
	file_myfunc();

	return 0;
}

void change_system_clock (int sys_clk)
{
	printf("system clock is %d\n", sys_clk);
}
