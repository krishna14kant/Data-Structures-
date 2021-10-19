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
    IOS li n, k;
    cin >> n >> k;
    li a[n], b[n];
    for (li i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (li i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    
    li times[n], wwt[k] = {0};

    for (li i = 0; i < n; i++)
    {
        if (wwt[a[i] - 1] == 0)
        {
            wwt[a[i] - 1] = b[i];
            b[i] = INT_MAX;
        }
        else
        {
            if (wwt[a[i] - 1] < b[i])
                swap(wwt[a[i] - 1], b[i]);
        }
    }
    sort(b, b + n);
    li ct = 0;
    for (li i = 0; i < k; i++)
    {
        if (wwt[i] == 0)
            ct++;
    }
    li sum = 0;
    for (li i = 0; i < ct; i++)
    {
        sum += b[i];
    }
    // cout << ct << endl;
    // for (int i = 0; i < k; i++)
    // {
    //     cout << wwt[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << b[i] << " ";
    // }
    // cout << endl;

    cout << sum;

    return 0;
}