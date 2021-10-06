#include <iostream>
using namespace std;
void steps(int n, char s, char a, char d)
{
    if (n == 1)
    {
        cout << n << s << d << endl;
        return;
    }
    steps(n - 1, s, d, a);
    cout << n << s << d << endl;
    steps(n - 1, a, s, d);
}
int main()
{
    int n;
    cin >> n;
    steps(n, 'A', 'B', 'C');
    return 0;
}
