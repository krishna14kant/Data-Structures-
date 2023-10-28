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
        string s;
        cin >> s;
        int indi[6] = {20, 20, 20, 20, 20, 20}, flag1 = 1, flag2 = 1, flag3 = 1;
        reverse(all(s));
        for (int i = 0; i < s.length(); i++)
        {
            /* code */
            if (s[i] == '0' )
            {
                for (int j = i + 1; j < s.length(); j++)
                {
                    if ((s[j] == '5'||s[j]=='0')&& indi[5]==20)
                    {
                        indi[5] = j - 1;
                
                    }
                }
            }
            else if (s[i] == '5')
            {
                for (int j = i + 1; j < s.length(); j++)
                {
                    if ((s[j] == '2' || s[j] == '7') && (indi[4]==20))
                    {
                        indi[4] = j - 1;
                    }
                }
            }
        }
        cout << min(indi[3],min(indi[4],indi[5])) << endl;
    }

    return 0;
}