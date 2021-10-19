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
bool iscompo(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 1;
    }
    return 0;
}
int main()
{
    IOS int t;
    cin >> t;
    while (t--)
    {
        int n, sum = 0;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            sum += v[i];
        }
        if (iscompo(sum))
        {
            cout << n << endl;
            for (int i=1;i<=n;i++)
                cout <<  i<< " ";
        }
        else
        {
            bool flag = 1;
            cout << n - 1 << endl;
            for (int i = 0; i < n; i++)
            {
                if (v[i] % 2 == 1 && flag)
                    flag = 0;
                else
                    cout << i+1 << " ";
            }
        }

        cout << endl;
    }

    return 0;
}