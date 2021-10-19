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
        int a, b, c;
        cin >> a >> b >> c;
        int mx = max(a, max(b, c));
        
        if((mx==a&&mx==b)||(mx==b&&mx==c)||(mx==c&&mx==a)){
            
                a=mx-a+1;
                b=mx-b+1;
                c=mx-c+1;
        }
        else {
             if (a == mx)
            {
                a = 0;
                b = mx - b + 1;
                c = mx - c + 1;
            }
            else if (b == mx)
            {
                b = 0;
                c = mx - c + 1;
                a = mx - a + 1;
            }
            else
            {
                c = 0;
                b = mx - b + 1;
                a = mx - a + 1;
            }
        }
    cout << a << " " << b << " " << c << endl;
    }

    return 0;
}