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
    IOS int n;
    cin >> n;
    int a[n + 1];
    for (int i = 2; i <= n; i++)
    {
        /* code */
        cin >> a[i];
    }
    int temp = n;
    vector<int> v;
    while (temp != 1)
    {
        v.push_back(temp);
        temp = a[temp];
    }
    v.push_back(1);
    for (int i = v.size() - 1; i >= 0; i--)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}