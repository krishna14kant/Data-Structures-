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
int a[1000000] = {0};
int main()
{
    IOS int n, k, h = 0, mh = -1;
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '#')
        {
            a[i]++;
        }
        if (a[i] == 1&&i>0)
            a[i] += a[i-1];
        if (a[i] >= k)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}