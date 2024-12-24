/********************************************************************
This example program is to demonstrate how to use strings in c
**********************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main() {

	char str[40];
	printf("Enter the name: ");
	fflush(stdout);
	fgets(str,sizeof(str),stdin);  // this gets the entire sentence we type until we press enter
	printf("Name: ");
	puts(str);

	return 0;
}
