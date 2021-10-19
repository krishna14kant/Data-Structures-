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
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
int main()
{
    IOS int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(all(v), [](int x, int y)
             { return x % 2 < y % 2; });
        int ct=0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                
                ct+=gcd(v[i],v[j]*2)>1;
            }
            
        }
        cout<<ct<<endl;
        
    }

    return 0;
}