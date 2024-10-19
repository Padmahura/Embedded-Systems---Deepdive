#include <stdio.h>

int privatedata;
void file_myfunc();

int main()
{
    privatedata = 50;
    printf("Privatedata %d\n", privatedata);
    file_myfunc();
    printf("Privatedata %d\n", privatedata);
}
