#include <iostream>
using namespace std;

void calculateTotalEvenPairs(long long int A, long long int B) 
{
    long long ans = 0;
    long long A_even, A_odd, B_even, B_odd;
    if ( A % 2 ) A_odd = A/2 + 1;
    else A_odd = A/2;
    A_even = A/2;
    B_even = B/2;
    if (B%2) B_odd = B/2 + 1;
    else B_odd = B/2;
    ans = A_even * B_even + A_odd * B_odd;
    cout<< ans << endl;
}

int main() 
{
    int T;
    long long int A, B;
    cin >> T;
    for (int i = 0; i < T ; i++)
    {
        cin >> A >> B;
        calculateTotalEvenPairs(A, B);
    }
}
