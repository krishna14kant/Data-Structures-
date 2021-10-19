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
    int n,z=0;
    cin>>n;
    string s;
    cin>>s;
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='0')z++;
    }
    //o=n-z;
    cout<<n-2*min(n-z,z);
    

    return 0;
}