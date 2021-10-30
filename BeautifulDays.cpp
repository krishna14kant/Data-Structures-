// https://www.hackerrank.com/challenges/beautiful-days-at-the-movies

#include <bits/stdc++.h>
using namespace std;
int reverse(int a)
{
    int revnum;
    string rev = to_string(a);
    reverse(rev.begin(), rev.end());
    revnum = stoi(rev);
    return revnum;
}

int main()

{
    int i, j, k, count = 0;
    cin >> i >> j >> k;
    int temp = i;
    for (int n = i; n <= j; n++)
    {
        int sub = abs(i - reverse(i));
        if (sub % k == 0)
        {
            count++;
        }
        i++;
    }
    cout << count;
    return 0;
}
