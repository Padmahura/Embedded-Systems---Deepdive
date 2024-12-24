/********************************************************************
This example program is to demonstrate how to use strings in c
**********************************************************************/

#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main() {

	char name[] = "Padma Vathi";
	char len = sizeof(name);

	for (int i=0;i<len;i++){

		printf("%c",*(name+i));   // Using pointers
		fflush(stdout);
	}

	return 0;
}
