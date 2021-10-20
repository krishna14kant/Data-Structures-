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
int sod(int n)
{
    if (n == 0)
        return 0;
    else
        return sod(n / 10) + n % 10;
}
int main()
{
    IOS int t;
    cin >> t;
    while (t--)
    {
        int r = 0, b, a=0, i = 9;
        cin >> b;
        if (b > 45)
        {
            cout << "-1" << endl;
        }
        else
        {
            while (r < b)
            {
                a = 10 * a + i;
                i--;
                r=sod(a);
            }
            while (r!=b)
            {
                a--;
                r=sod(a);
            }
            string s=to_string(a);
            sort(all(s));
            cout<<s<<endl;
            
        }
    }
    //cout<<sod(43);
    return 0;
}