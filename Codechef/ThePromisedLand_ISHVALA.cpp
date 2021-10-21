#include <iostream>
#include <cmath>
using namespace std;
#define akka long long
int main()
{
    akka t;
    cin>>t;
    while (t--)
    {
        akka n,m,x,y,s;
        cin>>n>>m>>x>>y>>s;
        akka a[x+2],b[y+2];
        a[0]=0;
        b[0]=0;
        for (int i = 1; i <= x; i++)
        {
            cin>>a[i];
        }
        for (int j = 1; j <= y; j++)
        {
            cin>>b[j];
        }
        a[x+1]=n+1;
        b[y+1]=m+1;
        akka s1=0,s2=0;
        for (int i = 1; i < x+2; i++)
        {
            akka k = ((a[i]-a[i-1]-1));
            // cout<<a[i]<<" "<<a[i-1]<<endl;
            // cout<<k<<" ";
            k/=s;
            s1+=k;
            // cout<<s1<<endl;
        }
        // cout<<endl;
        for (int i = 1; i < y+2; i++)
        {
            akka k = (b[i]-b[i-1]-1);
            // cout<<k<<" ";
            k/=s;
            s2+=k;
            // cout<<s2<<endl;
        }
        // cout<<endl;
        // cout<<s1<<" "<<s2<<endl;
        akka r = s1*s2;
        cout<<r<<endl;
    }
    return 0;
}
