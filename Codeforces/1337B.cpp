//🎃🎃🎃😎😎😁🤓☣☣☣☣☣dark_coder☣☣☣☣☣😎😎😁🤓🎃🎃🎃
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
        int x,n,m;
        cin>>x>>n>>m;
        for (int i = 0; i < n; i++)
        {
            if(x<=20)break;
            x=x/2+10;
        }
        for (int i = 0; i < m; i++)
        {
            x-=10;
        }
        if(x<=0)cout<<"YES";
        else cout<<"NO";
        cout<<endl;
        
        
    }

    return 0;
}