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
        int n,o=0;
        cin>>n;
        n*=2;
        //vector<int>v;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin>>temp;
            //v.push_back(temp);
            if(temp%2!=0)o++;
        }
        if(o*2==n)cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    }

    return 0;
}