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
        int n, flag = 1;
        cin >> n;
        string s = "";
        for (int i = 0; i < n; i++)
        {
            string temp;
            cin >> temp;
            s += temp;
        }
        int a[26] = {0};
        for (int i = 0; i < s.length(); i++)
        {
            a[s[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (a[i] % n != 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}