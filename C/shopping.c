/*Shopping Cost
Tina is preparing a shopping list containing N items. She knows the quantity and price of each item on the list. The shop is offering a 20% discount on the items with a quantity of more than 100 units. Given the quantity and price of each of the N items, your task is to calculate how much each item will cost.

Example
Input
3
100 120
200 100
50 50
Output
12000.0
16000.0
2500.0*/

#include <stdio.h>


int main()
{
   int t;
   scanf("%d",&t);
   while(t)
   {
    int qty,price;
    float amount;
    scanf("%d %d",&qty,&price);
      if(qty>100)
        amount=(qty*price)-(0.2*qty*price);
      else
      {
       amount=qty*price;
      }
       printf("%.1f\n",amount);
      t--;
   }

    return 0;
}
