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
int main()
{
    IOS int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int t = k;
        if (n > k)
            k=n-n%t;
        if (n > k)
        k+=t;
        int a = k / n;
        if (k % n != 0)
            a++;
        cout << a << endl;
    }

    return 0;
}