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
int a[1000001];
int main()
{
    IOS int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    for (int i = 1; i <= n; i++)
    {
        a[i] = a[i - 1] + s[i-1] - 'a' + 1;
    }

    while (q--)
    {
        pi p;
        cin >> p.first >> p.second;
        cout << a[p.second] - a[p.first-1] << endl;
    }

    return 0;
}

//