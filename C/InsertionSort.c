#include<stdio.h>
#include<stdlib.h>
void main()
{
int i,j,n,key=0;
printf("Enter size of an array:");
scanf("%d",&n);
int a[n];
printf("Enter array elements:");
for(i=1;i<=n;i++)
{
scanf("%d",&a[i]);
}
for(j=2;j<=n;j++)
{
    key=a[j];
    i=j-1;
    while(i>0 && a[i]>key)
    {
        a[i+1]=a[i];
        i=i-1;
    }
    a[i+1]=key;
}
printf("Sorted array :");
for(i=1;i<=n;i++)
{
printf("%d ",a[i]);
}
}
