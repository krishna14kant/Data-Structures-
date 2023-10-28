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
    li m,n,a;
    cin>>m>>n>>a;
    li r=m/a,c=n/a;
    if(m%a!=0)r++;
    if(n%a)c++;
    cout<<r*c;
    return 0;
}