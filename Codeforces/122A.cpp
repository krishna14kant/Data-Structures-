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
    int n;
    cin>>n;
    for (int i = 1; i <; i++)
    {
        if(n%i==0){
            int temp=n/i;
            string s=to_string(temp),si=to_string(i);
            if(all_of(all(s),[] (char c){return c=='7'||c=='4';})){
                cout<<"YES";
                return 0;
            }
        }
        else continue;
    }cout<<"NO";
    

    return 0;
}