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
    int n,m;
    cin>>n>>m;
    vector<int>ne;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin>>temp;
            ne.push_back(temp);
        
    }sort(all(ne));
    int sum=0;
    for (int i = 0; i < m; i++)
    {
        if(ne[i]>=0)break;
        sum+=(-1*ne[i]);
    }
    cout<<sum<<endl;
    
    

    return 0;
}