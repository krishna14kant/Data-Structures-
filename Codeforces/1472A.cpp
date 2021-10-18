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
        int w,h,n,p=1,flag=1;
        cin>>w>>h>>n;
        while(h%2==0||w%2==0){
                p*=2;
                if(h%2==0)h/=2;
                else if(w%2==0) w/=2;
                else break;
        }
        if(p>=n){
                cout<<"YES"<<endl;
            }
        else cout<<"NO"<<endl;
    }

    return 0;
}