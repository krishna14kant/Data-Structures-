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
        int n;
        cin>>n;
        vector<int>v;
        v.push_back(n);
        for (int i = 1; i < n; i++)
        {
            v.push_back(i);
        }
        for (int i = 0; i < n; i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
        
        
    }

    return 0;
}