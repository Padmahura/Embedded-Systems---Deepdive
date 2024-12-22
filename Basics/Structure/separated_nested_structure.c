/********************************************************
This code is an example to demonstrate the Seperated Nested structure
*********************************************************/

# include <stdio.h>

//Seperate Nested structure
struct var{
		int dd;
		int yyyy;
	}var_Doj;

struct Employee{
	int id;
	struct var var1;
}var_Employee;

int main()
{
	var_Employee.id=120;
	var_Employee.var1.dd = 22;
	var_Employee.var1.yyyy = 2024;
	printf("Employee Id:%d \n",var_Employee.id);
	printf("Year Joined:%d \n",var_Employee.var1.yyyy);
}
