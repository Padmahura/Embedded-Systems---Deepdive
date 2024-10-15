/****************************************************************
  This code is an example to find the size of different data types in C
*****************************************************************/

#include <stdio.h>

int main()
{
    
    
    unsigned char distanceA2B = 250;
    unsigned char distanceB2C = 20;
    
    unsigned short Total_Distance;
    
    Total_Distance = distanceA2B + distanceB2C;
    printf("The total distance is = %d\n",Total_Distance);
    printf("The size of char datatype is = %ld\n",sizeof(char));
    printf("The size of short datatype is = %ld\n",sizeof(short));
    printf("The size of int datatype is = %ld\n",sizeof(int));
    printf("The size of total distance is = %ld\n",sizeof(Total_Distance));
    
    return 0;
}
