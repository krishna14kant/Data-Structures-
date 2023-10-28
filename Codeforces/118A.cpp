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
        string s,
        r, v = "aeiouy";
    cin >> s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    for (int i = 0; i < s.length(); i++)
    {
        char t = s[i];

        if (t != 'a' && t != 'e' && t != 'i' && t != 'o' && t != 'u' && t != 'y')
        {
            r.push_back('.');
            r.push_back(t);
        }
    }
    cout << r;

    return 0;
}