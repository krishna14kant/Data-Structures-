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
        string s;
        cin>>s;
        int o=0;
        for (int i = 0; i < s.length(); i++)
        {
            if(s[i]=='0')o++;
        }
        int n=s.length()-o;
        int df=min(o,n);
        if(df%2)cout<<"DA";
        else cout<<"NET";
        cout<<endl;

        
    }

    return 0;
}