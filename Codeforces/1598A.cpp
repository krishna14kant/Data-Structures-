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
        int n;string a,b;
        cin>>n>>a>>b;
        int flag=1;
        for (int i = 0; i < n; i++)
        {
            if((a[i]-48)*(b[i]-48)==1){
                flag=0;
            }
        }
        if(flag)cout<<"YES";
        else cout<<"NO";
        cout<<endl;
        

        
    }

    return 0;
}