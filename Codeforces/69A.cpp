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
    int n,sum=0;
    cin>>n;
    int a[3]={0};
    for (int i = 0; i < n; i++)
    {
        int t;
        cin>>t;
        a[0]+=t;
        cin>>t;
        a[1]+=t;
        cin>>t;
        a[2]+=t;
    }
    if(!a[0]&&!a[1]&&!a[2])cout<<"YES";
    else cout<<"NO";

    return 0;
}