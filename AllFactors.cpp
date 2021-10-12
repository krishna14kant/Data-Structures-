#include<iostream>
using namespace std;
//printing all factors of N
int main()
{
    int n,i;
    cin>>n;
    for(i=1;i*i<n;i++)
    {
        if(n%i==0)
        {
            cout<<i<<" "<<n/i<<" ";
        }
    }
    if(i*i==n)
    cout<<i<<endl;
    return 0;
}
