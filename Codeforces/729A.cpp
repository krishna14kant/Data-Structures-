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

    IOS int n;
    cin >> n;
    string s, ans;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'o' && s[i + 1] == 'g' && s[i + 2] == 'o' && i <= n - 3)
        {
            while (s[i] == 'o' && s[i + 1] == 'g' && s[i + 2] == 'o' && i <= n - 3)
            {
                i += 3;
                ans.push_back('*');
                ans.push_back('*');
                ans.push_back('*');
             cout<<i<<"% ";
            }
            while (s[i] == 'g' && s[i + 1] == 'o' && i <= n - 2)
            {
                i += 2;
            }
            cout<<i<<"& ";
            i--;
        continue;
        }
        if(i<n){
            ans.push_back(s[i]);
            cout<<i<<" ";
        }
    }
    cout << ans;

    return 0;
}