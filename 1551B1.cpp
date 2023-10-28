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
        string inp,s="";
        cin>>inp;
        sort(all(inp));
        int n=inp.length();
        int freq[n]={0},k=-1;
        for (int i = 0; i < n; i++)
        {
            if(inp[i]!=s.back()){
                k++;
                s.push_back(inp[i]);
                freq[k]++;
            }else{
                freq[k]++;
            }
        }//o{n}
        int m=0,u=0;
        for (int i = 0; i < s.length(); i++)
        {
            /* code */
            if(freq[i]>1)m++;
            else u++;
        }
        cout<<u/2+m<<endl;
        
    }

    return 0;
}