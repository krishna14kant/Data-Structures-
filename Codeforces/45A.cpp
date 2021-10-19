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
        string a[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"},
               s;
    int n, i = 0;
    cin >> s >> n;
    while (a[i] != s)
        i++;
    int net = n + i;
    if (net >= 12)
        net %= 12;
    cout << a[net];

    return 0;
}