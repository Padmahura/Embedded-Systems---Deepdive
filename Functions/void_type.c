#include <stdio.h>
void add();
void mult();

int main()
{
    
    add();
    mult();
    return 0;
}


void add()
{
    int a=50,b=60;
    int c = a+b;
    printf("The sum is C %d \n",c);
}

void mult()
{
    int a=50,b=60;
    int c = a*b;
    printf("The product is C %d \n",c);
}
