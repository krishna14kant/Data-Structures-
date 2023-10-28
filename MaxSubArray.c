/*
maximum subarray problem using divide and conquer method.
n is the length of the array.
*/

#include <stdio.h>
#include <limits.h>


int max(int a, int b){
    if(a>b)
        return a;
    else
        return b;
}


int max2(int a, int b, int c){
    return max(max(a, b), c);
}

int maxCrossingSum(int a[], int l, int m, int h){

    int s = 0;
    int left_s = INT_MIN;
    for (int i = m; i >= l; i--)
    {
        s = s + a[i];
        if (s > left_s)
          left_s = s;
    }


    s = 0;
    int right_s = INT_MIN;
    int i = m+1;
    while(i<=h)
    {
        s = s + a[i];
        if (s > right_s)
          right_s = s;
        i++;
    }


    return max2(left_s + right_s, left_s, right_s);
}


int maxSubarraySum(int a[], int l, int h)
{

   if (l == h)
     return a[l];


   int m = (l + h)/2;


   return max2(maxSubarraySum(a, l, m),
              maxSubarraySum(a, m+1, h),
              maxCrossingSum(a, l, m, h));
}


int main()
{
   int n;

   printf("Enter the size of the array: ");
   scanf("%d",&n);

   int a[n];

   printf("Enter the array elements: \n");
   for(int i=0 ; i<n ; i++){
    scanf("%d",&a[i]);
   }

   int max_s = 0;
   max_s = maxSubarraySum(a, 0, n-1);
   printf("Maximum sub-array sum is %d\n", max_s);

   return 0;
}
