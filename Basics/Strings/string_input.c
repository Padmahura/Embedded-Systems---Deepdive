/********************************************************************
This example program is to demonstrate how to use strings in c
**********************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main() {

	char str[40];
	printf("Type the name: ");
	fflush(stdout);
	scanf("%[^\n]s",str);   // scanset --> this will include spaces in string input
	printf("%s\n",str);


	return 0;
}
