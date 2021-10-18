// C program to find median of two sorted arrays

#include<stdio.h>

int Calculate_median(int a1[], int a2[], int n)
{
int i = 0;
int j = 0;
int cnt;
int x = -1, y = -1;

for (cnt = 0; cnt <= n; cnt++)
{
if (i == n)
{
x = y;
y = a2[0];
break;
}
else if (j == n)
{
x = y;
y = a1[0];
break;
}

if (a1[i] < a2[j])
{
/* Store the prev median */
x = y;
y = a1[i];
i++;
}
else
{
/* Store the prev median */
x = y;
y = a2[j];
j++;}
}
}
int main()
{
int n, i;
printf(“Enter the size: “);
scanf(“%d”,&n);
int a1[n], a2[n];
printf(“\n Enter the first Array elements: \n”);
for(i=0; i<n; i++)
scanf(“%d”,&a1[i]);
printf(“\n Enter the Second Array elements: \n”);
for(i=0; i<n; i++)
scanf(“%d”,&a2[i]);

printf(“Median: %d”, Calculate_median(a1, a2, n));
return 0;
}
