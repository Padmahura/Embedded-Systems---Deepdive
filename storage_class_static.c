/****************************************************************
  This code is an example to understand the storage class STATIC
  STATIC - A private variable that does not lose its existence even if the execution control goes out of the scope of that variable (or) a global variable that is private to a function
*****************************************************************/

#include <stdio.h>

void myfunc();

int main()
{
    myfunc();
    myfunc();
    myfunc();
    return 0;
}
void myfunc()
{
    static int count=0;
    count+=1;
    printf("The count is %d \n",count);
}
