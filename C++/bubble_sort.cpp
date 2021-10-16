#include<iostream>
using namespace std;
int bsort(int a[],int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int  j = 0; j < n-1; j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }
    for (int  i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    } 
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int  i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    bsort(arr,n);
}