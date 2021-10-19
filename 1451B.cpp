//🎃🎃🎃😎😎😁🤓☣☣☣☣☣dark_coder☣☣☣☣☣😎😎😁🤓🎃🎃🎃
#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define li long long int
#define pi pair<int, int>
int main()
{
    IOS int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        for (int i = 0; i < q; i++)
        {
            pi p;
            cin >> p.first >> p.second;
            int flag=0;
            for (int i = p.second; i < n; i++)
            {
                if(s[i]==s[p.second-1])flag=1;
            }
            for (int i = 0; i < p.first-1; i++)
            {
                if(s[i]==s[p.first-1])flag=1;
            }
            
            if(flag)cout<<"YES";
            else cout<<"NO";
            
            cout << endl;
        }
    }

    return 0;
}