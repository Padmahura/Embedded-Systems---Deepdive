/********************************************************************
This example program is to demonstrate how to use strings in c
**********************************************************************/

#include <stdio.h>
#include <stdint.h>
#include <string.h>

void displaystring(char str[]);
int main() {

	char name[] = "Padma Vathi";
	char len = sizeof(name);

	displaystring(name);

	return 0;
}

void displaystring(char str[]){   // Call by value
	printf("String Output: ");
	fflush(stdout);
	puts(str);
}
