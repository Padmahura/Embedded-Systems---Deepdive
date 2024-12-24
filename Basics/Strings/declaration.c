/********************************************************************
This example program is to demonstrate how to use strings in c
**********************************************************************/


#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main() {

	char str[] = "Hello World";
	printf("%s \n",str);
	int len2 = sizeof(str);  // includes null character
	int len = strlen(str);  // Excludes null character
	printf("%d \n",len);
	printf("%d \n",len2);


	return 0;
}
