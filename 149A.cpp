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
    int k,w=0,sum=0;
    cin>>k;
    vector<int>v;
    for (int i = 0; i < 12; i++)
    {
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    sort(all(v));
    
    for (int i = 0; i < 12; i++)
    {
        if(sum>=k)break;
        w++;
        sum+=v.back();
        v.pop_back();
        /* code */
    }
    if(sum<k)cout<<-1;
    else cout<<w;
    
    

    return 0;
}