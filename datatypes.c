#include <stdio.h>

int main()
{
    
    
    unsigned char distanceA2B = 250;
    unsigned char distanceB2C = 20;
    
    unsigned short Total_Distance;
    
    Total_Distance = distanceA2B + distanceB2C;
    printf("The total distance is = %d",Total_Distance);

    /* ////////// Char = 8 bits ; Can accept values till 255 only; Beyond that we need to use short  /////////////
    unsigned char distanceA2B = 20;
    unsigned char distanceB2C = 20;
    
    unsigned char Total_Distance;
    
    Total_Distance = distanceA2B + distanceB2C;
    printf("The total distance is = %d",Total_Distance);
    */
  
    return 0;
}
