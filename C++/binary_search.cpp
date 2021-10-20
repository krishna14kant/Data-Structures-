#include<iostream>
using namespace std;
int bsearch(int a[],int n,int s)
{
    int l=0,u=n-1;
    int mid,flag=0;
    while(l<=u)
    {
        mid=(l+u)/2;
        if(s==a[mid])
        {
            flag=1;
            break;
        }
        else
        {
            if(s>a[mid])
                l=mid+1;
            else if(s<a[mid])
                u=mid-1;
        }
    }
    if(flag==1)
    cout<<"Found at : "<<mid+1;
    else
    cout<<"not found";
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
    int s;
    cin>>s;
    bsearch(arr,n,s);
}