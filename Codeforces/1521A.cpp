//🎃🎃🎃😎😎😁🤓☣☣☣☣☣dark_coder☣☣☣☣☣🤓😁😎😎🎃🎃🎃
#include <bits/stdc++.h>
using namespace std;
#define IOS         ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define li long long int
#define pi pair<int,int>
int main()
{
    IOS
    int t;
    cin>>t;
    while(t--)
    {
        li a,b;
        cin>>a>>b;
        
        if(b==1){cout<<"NO"<<endl;continue;}
        else cout<<"YES"<<endl;
        cout<<a<<" "<<a*b<<" "<<a*(b+1);
        
        cout<<endl;
    }

    return 0;
}