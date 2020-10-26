#include<stdio.h>
 
int main()
{
  int number, Square;
 
  printf(" Enter any integer Value :\n ");
  scanf("%d", &number);
  
  Square = number * number;
  
  printf(" Square of a given number %d is  =  %d\n", number, Square);
 
  return 0;
}
