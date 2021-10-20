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
    int n, k, l, c, d, p, nl, np, a[3];
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;
    a[0]=k*l/nl;a[1]=c*d;a[2]=p/np;
    sort(a,a+3);
    cout<<a[0]/n;

    return 0;
}