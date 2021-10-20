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
    IOS
        string s;
    int n;
    cin >> n >> s;
    int mx = -1, nt=0;
    char f[2]={s[0],s[1]};
    for (int i = 0; i < n; i++)
    {
        nt = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (s[i] == s[j] && s[i + 1] == s[j + 1])
                nt++;
        }
        if (nt > mx)
        {
            mx = nt;
            f[0]=s[i];
            f[1]=s[i + 1];
        }
        
    }
    cout<<f[0]<<f[1];
    return 0;
}