#include <stdio.h>
int coins(int d[],int n,int val) {
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(d[j]<d[j+1])
            {
                int temp1=d[j];
                d[j]=d[j+1];
                d[j+1]=temp1;
            }
        }
    }
    int a=0;
    while(val!=0)
    {
        int g=0;
        for(int i=0;i<n;i++)
        {
            if(d[i]>g && d[i]<=val)
                g=d[i];
        }
        if(g==0)
        {
            break;
        }
        else{
            val=val-g;
            a++;
        }
    }
    return a;
}

int main() {
   int n;
   printf("Enter number of denominations\n");
   scanf("%d",&n);
   int dnm[n];
   printf("Enter the denominations given:\n");
   for(int i=1;i<=n;i++)
    scanf("%d",&dnm[i]);
   int value;
   printf("Enter the sum to be calculated from the given denominations\n");
   scanf("%d",&value);
   printf("The minimum number of coins of any denomination that sum up to %d is %d",value,coins(dnm,n,value));
   return 0;
}
