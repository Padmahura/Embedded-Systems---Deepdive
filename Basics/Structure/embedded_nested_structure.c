/********************************************************
This code is an example to demonstrate the Embedded nested structure
*********************************************************/

# include <stdio.h>

//Embedded Nested structure
struct Employee
{
	int id;
	struct{
		int dd;
		int yyyy;
	}var_Doj;
}var_Employee;

int main()
{
	var_Employee.id=120;
	var_Employee.var_Doj.dd = 22;
	var_Employee.var_Doj.yyyy = 2024;
	printf("Employee Id:%d \n",var_Employee.id);
	printf("Year Joined:%d \n",var_Employee.var_Doj.yyyy);
}
