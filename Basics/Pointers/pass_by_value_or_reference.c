/******************************************************
This is a code example to illustrate Pointers and Functions together
using Pass by Value and PAss by reference 
*******************************************************/

# include <stdio.h> 

int x = 5 , y ;

// Pass by Value function ; Here a copy of the value of x variable is made to the local varible n ; Original value of x is never changed ; 
int squaring_value (int n)
{
  return n = n * n;
}

// Pass by reference funtion ; After function call , the value of x is modified 
int squaring_reference ( int *n)
{
  return *n = *n * *n ;
}

int main ()
{
  y = squaring_value(x); 
  printf(" The squared result of PAss by Value function is : %d \n ", y);
  printf("The value of x after calling Pass by value function: %d \n ", x);
  printf(" The squared result of PAss by Reference function is : %d \n ", squaring_reference(&x));
  printf("The value of x after calling Pass by Reference function: %d \n ", x);

  return 0;

}

