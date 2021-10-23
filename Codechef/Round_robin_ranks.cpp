#include <bits/stdc++.h>
// CODE WRITTEN BY KRISHNA_6431

void solve()
{
    long long a,b;
    cin >> a >> b;
    long long ans = 2*(a-b);
    long long temp = 2*((b-1)/2);
    ans += temp;
    cout << ans << endl;
}

int main()
{
    fast;

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int t;
    cin >> t;
    // int tc = 1;
    while (t--)
    {
        // cout << "Case #" << tc << ": ";
        // tc++;
        solve();
    }
    return 0;
}
