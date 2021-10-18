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
        int n,a,b;
        cin>>n>>a>>b;
        string s="";
        int t=0;
        for (int i = 0; i < n; i++)
        {
            char temp= 'a'+t;
            if(t==b-1)
            t=0;
            else t++;
            s.push_back(temp);
        }
        cout<<s<<endl;
        
    }

    return 0;
}