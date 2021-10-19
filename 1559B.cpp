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
        int n, flag = 1, fi;
        cin >> n;
        string s;
        cin >> s;
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i - 1] == 'B' && s[i] == '?')
                s[i] = 'R';
            else if (s[i - 1] == 'R' && s[i] == '?')
                s[i] = 'B';
        }
        reverse(s.begin(), s.end());
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i - 1] == 'B' && s[i] == '?')
                s[i] = 'R';
            else if (s[i - 1] == 'R' && s[i] == '?')
                s[i] = 'B';
        }
        reverse(s.begin(), s.end());
        if (s[0] == '?')
        {
            for (int i = 0; i < n; i++)
            {
                if (i % 2)
                    s[i] = 'R';
                else
                    s[i] = 'B';
            }
        }
        cout << s << endl;
    }

    return 0;
}