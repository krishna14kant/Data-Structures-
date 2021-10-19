//🎃🎃🎃😎😎😁🤓☣☣☣☣☣dark_coder☣☣☣☣☣🤓😁😎😎🎃🎃🎃
#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define li long long int
#define pi pair<int, int>
bool is_pow(li n)
{
    for (li i = 1;; i *= 2)
    {
        if (n < i)
            return 0;
        else if (n == i)
            return 1;
    }
}
li nrstpow(li n)
{
    for (li i = 1;; i *= 2)
    {
        if (n < i)
            return i / 2;
    }
}
li solve(li n)
{
    if (is_pow(n))
        return 1;
    else
    {
        return 1 + solve(n - nrstpow(n));
    }
}
int main()
{
    IOS
    li temp;
    cin >> temp;
    cout << solve(temp) << endl;

    return 0;
}