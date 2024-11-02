/********************************************
Swapping two numbers using pass by reference function
*********************************************/

# include <stdio.h> 


void swap ( int *a , int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;  
}

int main ()
{
  int x = 10, y = 20 , *p ; 
  p = &x ; 
  swap(p , &y); 
  printf("the swapped values of x is %d and Y is %d \n", x , y);

  return 0;

  }
