#include <stdio.h>
int add(int a , int b);
float div(int a, int b);

int main()
{
    
    int c=add(10,20);
    float d=div(8,3);
    printf("The sum is %d \n",c);
    printf("The divided value is %f \n",d);
    return 0;
}


int add(int a , int b)
{
    int c = a+b;
    return c;
    
}

float div(int a, int b)
{
    float d=(float)a/b;    // Type casting
    return d;
}
