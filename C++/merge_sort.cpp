#include<iostream>
using namespace std;
int A[40],lb,ub,mid;
int mergesort(A,lb,ub)
{
    if(lb<ub)
    {
        mid=(lb+ub)/2;
        mergesort(A,lb,mid);
        mergesort(A,mid+1,ub);
        merge(A,lb,mid,ub);
    }
}
void merge(A,lb,mid,ub)
{
    int i,j,k,b[40];
    i=lb;
    j=mid+1;
    k=lb;
    while(i<=mid&&j<=ub)
    {
        if(A[i]<=A[j])
        {
            b[k]=A[i];
            k++;
            i++;
        }
        else
        {
            {
                b[k]=a[j];
                k++;
                j++;
            }
        }}

        if(i>mid)
        {
            while(j<=ub)
            {
            b[k]=A[j];
            j++;
            k++;
            }
        }
        else
        {
            {
                while(i<=mid)
                {
                    b[k]=a[i];
                    i++;
                    k++;
                }
            }
        }

    }

int main()
{
    int n;
    cout<<"write no of element";
    cin>>n;
    int A[n],i;
    cout<<"write element of array";
    for(i=0;i<n;i++)
    cin>>A[i];
    mergesort(A,0,n-1);
    return 0;
    for(i=0;i<n;i++)
        cout<<b[i];
}
