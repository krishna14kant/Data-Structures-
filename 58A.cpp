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
    string req="hello",s;
    cin>>s;
    int j=0;
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]==req[j]){
            j++;
        }
    }
    if(j==5)
    cout<<"YES";
    else cout<<"NO";
    return 0;
}