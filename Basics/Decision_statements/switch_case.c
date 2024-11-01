/**********************************************
  An example to use Switch Case statement
**********************************************/


#include <stdio.h>

int main(){
	int value;
	printf("Enter the value :");
	fflush(stdout);
	scanf("%d",&value);
	switch(value){
	case 1 :
		printf("Case 1 is executed");
		break;
	case 2:
		printf("Case 2 is executed");
		break;
	case 3:
		printf("Case 3 is executed");
		break;
	default:
		printf("Default Case is executed");
		break;
	}
	return 0;


}
