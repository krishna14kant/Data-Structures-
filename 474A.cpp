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
        string e = "qwertyuiopasdfghjkl;zxcvbnm,./",
               s;
    char k;
    cin >> k >> s;
    int o = -1;
    if (k == 'L')
        o += 2;
    for (int i = 0; i < s.length(); i++)
    {
        int it=e.find(s[i]);
        cout<<e[it+o];
        /* code */
    }

    return 0;
}